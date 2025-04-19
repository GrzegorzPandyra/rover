
/* Std library includes */
#include <string>
#include <vector>
#include <array>
/* SWC includes */
#include "Veh_ClientIf.hpp"
#include "Veh_SysIf.hpp"
#include "Veh_InputIf.hpp"
#include "Logger_ClientIf.hpp"
#include "ThreadMgr_ClientIf.hpp"
#include "StatMon_ClientIf.hpp"
#include "Pwtr_MotorControlIf.hpp"
#include "StSys_ServoControlIf.hpp"
#include "Tacho_RPSIf.hpp"
#include "Fan_FanControlIf.hpp"
/* Other includes */
#include "VehCfg.hpp"
#include "PeriodicCall.hpp"

namespace SWC::Veh {
    namespace {
        using namespace ClientIf;

        void Run(void);
        void AutoDecelerationCbk(void);
        struct {
            SWC::Types::SwcContext swcCtx = {
                Cfg::SWC_NAME, 
                Cfg::SWC_SYSTEM_TYPE,
                Types::INIT,
                Run
            };
            PRND currentGear = PRND_N;
            
            PeriodicCall AutoDeceleration {AutoDecelerationCbk, Cfg::AUTO_DECELERATE_PERIOD_MS};
        } ccb; /* Component Control Block */ 

        void Run(void){
            ccb.AutoDeceleration.Run();
        }

        std::vector<std::string> MonitorData(void){
            using std::string;
            using std::vector;
            using std::array;
            using std::to_string;

            vector<string> result;
            array<string, 5> gears = {"R", "N", "D1", "D2", "D3"};
            result.emplace_back(string("PRND :     ") + gears[ccb.currentGear]                      + "     ");
            result.emplace_back(string("RPS:       ") + to_string(SWC::Tacho::RPS::GetRPS())        + "     ");
            result.emplace_back(string("Auto-dec : ") + to_string(ccb.AutoDeceleration.IsEnabled()) + "     ");
            // result.push_back(std::to_string(mgr.rps).substr(0, 4));
            return result;
        }

        /* Overload increment/decrement operators to perform these ops on PRND enums */
        PRND& operator++(PRND& val)
        {
            const int i = static_cast<int>(val);
            val = static_cast<ClientIf::PRND>(i+1);
            return val;
        }

        PRND& operator--(PRND& val)
        {
            const int i = static_cast<int>(val);
            val = static_cast<PRND>(i-1);
            return val;
        }

        void AutoDecelerationCbk(void){
            unsigned pwm = Pwtr::MotorControlIf::GetMotorPWM();
            if(pwm > 0) Pwtr::MotorControlIf::Decelerate();            
        }
    }
}

namespace SWC::Veh::SysIf
{
    GlobalTypes::CallResult Init()
    {
        using namespace SWC::Veh;
        ThreadMgr::ClientIf::RegisterSWC(&ccb.swcCtx);
        StatMon::ClientIf::RegisterMonitor({
            Cfg::MON_WIN_X,
            Cfg::MON_WIN_Y,
            Cfg::MON_WIN_WIDTH,
            Cfg::MON_WIN_HEIGHT,
            MonitorData,
            Cfg::SWC_NAME
        });
        ccb.AutoDeceleration.Init();

        INFO(std::string(Cfg::SWC_NAME) + " SWC init complete");
        return GlobalTypes::CALL_OK;
    }
}

namespace SWC::Veh::ClientIf
{
    PRND ShiftUp(void)
    {
        if(ccb.currentGear < ClientIf::PRND_D3) ++ccb.currentGear;
        return ccb.currentGear;
    }

    PRND ShiftDown(void)
    {
        if(ccb.currentGear > ClientIf::PRND_R) --ccb.currentGear;
        return ccb.currentGear;
    }

    PRND GetGear(void)
    {
        return ccb.currentGear;
    }

    PRND SetGear(PRND gear)
    {
        ccb.currentGear = gear;
        return ccb.currentGear;
    }

}

namespace SWC::Veh::InputIf
{
    void Forward(void){
        unsigned pwm = Pwtr::MotorControlIf::GetMotorPWM();
        switch (ccb.currentGear){
            case PRND_D1:
                if(pwm < Cfg::GEAR_D1_PWM_MAX) {
                    Pwtr::MotorControlIf::SetMotorDirection(Pwtr::MotorControlIf::FORWARD);
                    Pwtr::MotorControlIf::Accelerate();
                    ccb.AutoDeceleration.Reset();
                }
                break;
            case PRND_D2:
                if(pwm < Cfg::GEAR_D2_PWM_MAX){
                    Pwtr::MotorControlIf::SetMotorDirection(Pwtr::MotorControlIf::FORWARD);
                    Pwtr::MotorControlIf::Accelerate();
                    ccb.AutoDeceleration.Reset();
                }
                break;
            case PRND_D3:
                if(pwm < Cfg::GEAR_D3_PWM_MAX){
                    Pwtr::MotorControlIf::SetMotorDirection(Pwtr::MotorControlIf::FORWARD);
                    Pwtr::MotorControlIf::Accelerate();
                    ccb.AutoDeceleration.Reset();
                }
                break;
            case PRND_R:
                if(pwm > 0) Pwtr::MotorControlIf::Decelerate();
                break;
            default:
                break;
        }
    }

    void Backward(void){
        unsigned pwm = Pwtr::MotorControlIf::GetMotorPWM();
        switch (ccb.currentGear){
            case PRND_D1:
            case PRND_D2:
            case PRND_D3:
                if(pwm > 0) Pwtr::MotorControlIf::Decelerate();
                break;
            case PRND_R:
                if(pwm < Cfg::GEAR_R_PWM_MAX){
                    Pwtr::MotorControlIf::SetMotorDirection(Pwtr::MotorControlIf::BACKWARD);
                    Pwtr::MotorControlIf::Accelerate();
                    ccb.AutoDeceleration.Reset();
                } 
                break;
            default:
                break;
        }
    }

    void TurnLeft(void){
        StSys::ServoControl::TurnLeft();
    }

    void TurnRight(void){
        StSys::ServoControl::TurnRight();
    }

    void Stop(void){
        Pwtr::MotorControlIf::SetMotorDirection(Pwtr::MotorControlIf::STOP);
        Pwtr::MotorControlIf::Stop();
        ccb.currentGear = PRND_N;
    }

    void ShiftUp(void){
        Veh::ClientIf::ShiftUp();
    }

    void ShiftDown(void){
        Veh::ClientIf::ShiftDown();
    }

    void TogglePWMAutoDecrement(void){
        if(ccb.AutoDeceleration.IsEnabled()) 
            ccb.AutoDeceleration.Disable();
        else 
            ccb.AutoDeceleration.Enable();
    }

    void FanSpeedUp(void){
        Fan::FanControl::IncFanSpeed();
    }

    void FanSlowDown(void){
        Fan::FanControl::DecFanSpeed();
    }
}