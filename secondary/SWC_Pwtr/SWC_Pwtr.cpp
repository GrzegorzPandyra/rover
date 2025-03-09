#include <string>
#include <vector>
#include "if/SWC_Pwtr_ClientIf.hpp"
#include "if/SWC_Pwtr_SysIf.hpp"
#include "if/SWC_Logger_ClientIf.hpp"
#include "if/SWC_ThreadMgr_ClientIf.hpp"
#include "if/SWC_StatMon_ClientIf.hpp"
#include "if/WiringPi.hpp"
#include "cfg/PwtrCfg.hpp"
#include "if/SWC_Veh_ClientIf.hpp"


namespace SWC_Pwtr
{
    namespace 
    {
        void Run(void);
        void MotorRotation(void);
        std::vector<std::string> MonitorData(void);

        SWC_Types::SWC swcData = {Run, PwtrCfg::SYSTEM_TYPE, PwtrCfg::SWC_NAME};

        void Run(void)
        {
            MotorRotation();
        }

        void MotorRotation(void){
            using namespace SWC_Veh::ClientIf;
            using namespace WiringPi;
            using namespace PwtrCfg;
            switch (GetGear()){
                case PRND_D1:
                case PRND_D2:
                case PRND_D3:
                    SetPin(DC_MOTOR_A, PS_HIGH);
                    SetPin(DC_MOTOR_B, PS_LOW);
                    break;
                case PRND_R:
                    SetPin(DC_MOTOR_A, PS_LOW);
                    SetPin(DC_MOTOR_B, PS_HIGH);
                    break;
                case PRND_N:
                default:
                    SetPin(DC_MOTOR_A, PS_LOW);
                    SetPin(DC_MOTOR_B, PS_LOW);
                    // mgr.motor_pwm.Set(PT_DRV_PWM_DEF_VAL);
                    break;
            }
        }

        std::vector<std::string> MonitorData(void)
        {
            std::vector<std::string> result;
            result.push_back("Motor PWM");
            // result.push_back(std::to_string(mgr.motor_pwm.Get()));
            result.push_back("PWM auto decrementation");
            // result.push_back(std::to_string(mgr.pwm_auto_dec));
            result.push_back("Fan PWM");
            // result.push_back(std::to_string(fan_ctrl::pwm().Get()));
            return result;
        }
    }
    
    namespace SysIf
    {
        SWC_Types::Status Stop()
        {
            return SWC_Types::STATUS_OK;
        }
    
        SWC_Types::Status Init()
        {
            SWC_ThreadMgr::ClientIf::RegisterSWC(&swcData);
            SWC_StatMon::ClientIf::RegisterMonitor({
                PwtrCfg::MON_WIN_X,
                PwtrCfg::MON_WIN_Y,
                PwtrCfg::MON_WIN_WIDTH,
                PwtrCfg::MON_WIN_HEIGHT,
                MonitorData,
                PwtrCfg::SWC_NAME
            });

            WiringPi::SetPinMode(PwtrCfg::DC_MOTOR_A, WiringPi::PinMode::PM_OUTPUT);
            WiringPi::SetPinMode(PwtrCfg::DC_MOTOR_B, WiringPi::PinMode::PM_OUTPUT);

            WiringPi::SetPin(PwtrCfg::DC_MOTOR_A, WiringPi::PinState::PS_LOW);
            WiringPi::SetPin(PwtrCfg::DC_MOTOR_B, WiringPi::PinState::PS_LOW);

            INFO("Powertrain SWC init complete");
            return SWC_Types::STATUS_OK;
        }
    }

    namespace ClientIf
    {

    }
}