/* Std library includes */
#include <string>
#include <vector>
/* SWC includes */
#include "Pwtr_MotorControlIf.hpp"
#include "Pwtr_SysIf.hpp"
#include "Logger_ClientIf.hpp"
#include "ThreadMgr_ClientIf.hpp"
#include "StatMon_ClientIf.hpp"
#include "Fan_FanControlIf.hpp"
#include "WiringPi.hpp"
/* Other includes */
#include "PwtrCfg.hpp"
#include "PWMChannel.hpp"


namespace SWC::Pwtr {
    namespace {
        void Run(void);
        std::vector<std::string> MonitorData(void);

        struct {
            SWC::Types::SwcContext swcCtx = {
                SWC::Pwtr::Cfg::SWC_NAME, 
                SWC::Pwtr::Cfg::SWC_SYSTEM_TYPE,
                SWC::Types::INIT,
                Run
            };

            PWMChannel motorPWM = {
                Cfg::DC_MOTOR_PWM_PIN,
                Cfg::PWM_MIN_VAL,
                Cfg::PWM_MAX_VAL,
                Cfg::PWM_DEF_VAL,
                Cfg::PWM_INC_STEP
            };

            MotorControlIf::MotorRotation motorDirection = MotorControlIf::STOP;
        } ccb; /* Component Control Block */

        void Run(void){
            ccb.motorPWM.Run();
        }

        std::vector<std::string> MonitorData(void)
        {
            using std::string;
            using std::to_string;

            std::vector<std::string> result;

            result.push_back(string("Motor PWM : ") + to_string(ccb.motorPWM.GetValue())        + "     ");
            result.push_back(string("Fan Speed : ") + to_string(Fan::FanControl::GetFanSpeed()) + "     ");
            return result;
        }
    }
}

namespace SWC::Pwtr::SysIf {
    GlobalTypes::CallResult Init(){
        using namespace SWC::Pwtr;
        SWC::ThreadMgr::ClientIf::RegisterSWC(&ccb.swcCtx);
        SWC::StatMon::ClientIf::RegisterMonitor({
            Cfg::MON_WIN_X,
            Cfg::MON_WIN_Y,
            Cfg::MON_WIN_WIDTH,
            Cfg::MON_WIN_HEIGHT,
            MonitorData,
            Cfg::SWC_NAME
        });
        ccb.motorPWM.Init();

        WiringPi::SetPinMode(Cfg::DC_MOTOR_A, WiringPi::PinMode::PM_OUTPUT);
        WiringPi::SetPinMode(Cfg::DC_MOTOR_B, WiringPi::PinMode::PM_OUTPUT);

        WiringPi::SetPin(Cfg::DC_MOTOR_A, WiringPi::PinState::PIN_LOW);
        WiringPi::SetPin(Cfg::DC_MOTOR_B, WiringPi::PinState::PIN_LOW);

        INFO(std::string(Cfg::SWC_NAME) + " SWC init complete");
        return GlobalTypes::CALL_OK;
    }
}

namespace SWC::Pwtr::MotorControlIf {
    void Accelerate(void){
        ccb.motorPWM.Inc();
    }

    void Decelerate(void){
        ccb.motorPWM.Dec();
    }

    void Stop(void){
        ccb.motorPWM.SetValue(0);
    }

    /**
     * @brief This function controls ONLY the DIRECTION of current flow through the H-bridge driver.
     *        The power provided to the motor depends on separate PWM signal gating the driver output.
     */
    void SetMotorDirection(MotorRotation direction){
        using namespace WiringPi;
        switch (direction){
            case FORWARD:
                SetPin(Cfg::DC_MOTOR_A, PIN_LOW);
                SetPin(Cfg::DC_MOTOR_B, PIN_HIGH);
                break;
            case BACKWARD:
                SetPin(Cfg::DC_MOTOR_A, PIN_HIGH);
                SetPin(Cfg::DC_MOTOR_B, PIN_LOW);
                break;
            case STOP:
            default:
                SetPin(Cfg::DC_MOTOR_A, PIN_LOW);
                SetPin(Cfg::DC_MOTOR_B, PIN_LOW);
                break;
        }
        ccb.motorDirection = direction;
    }

    unsigned GetMotorPWM(void){
        return static_cast<unsigned>(ccb.motorPWM.GetValue());
    }
}