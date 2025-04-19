/* Std library includes */
#include <string>
/* SWC includes */
#include "Fan_FanControlIf.hpp"
#include "Fan_SysIf.hpp"
#include "ThreadMgr_ClientIf.hpp"
#include "Logger_ClientIf.hpp"
/* Other includes */
#include "FanCfg.hpp"
#include "PWMChannel.hpp"

namespace SWC::Fan {
    namespace {
        void Run(void);
        FanControl::FanSpeed& operator++(FanControl::FanSpeed& val);
        FanControl::FanSpeed& operator--(FanControl::FanSpeed& val);

        struct {
            SWC::Types::SwcContext swcCtx =
            {
                Cfg::SWC_NAME, 
                Cfg::SWC_SYSTEM_TYPE,
                SWC::Types::INIT,
                Run
            };

            PWMChannel fanPWM = {
                Cfg::FAN_PWM_PIN,
                Cfg::PWM_MIN,
                Cfg::PWM_MAX,
                Cfg::PWM_DEF_VAL,
                Cfg::PWM_INC_STEP
            };

            FanControl::FanSpeed fanSpeed = FanControl::FanSpeed::OFF;
        } ccb; /* Component Control Block */ 
        
        void Run(void){
            ccb.fanPWM.Run();
        }

        /* Overload increment/decrement operators to perform these ops on FanSpeed enums */
        FanControl::FanSpeed& operator++(FanControl::FanSpeed& val)
        {
            const int i = static_cast<int>(val);
            val = static_cast<FanControl::FanSpeed>(i+1);
            return val;
        }
    
        FanControl::FanSpeed& operator--(FanControl::FanSpeed& val)
        {
            const int i = static_cast<int>(val);
            val = static_cast<FanControl::FanSpeed>(i-1);
            return val;
        }
    }
    
}

namespace SWC::Fan::SysIf {
    using namespace GlobalTypes;

    GlobalTypes::CallResult Init(void){
        ThreadMgr::ClientIf::RegisterSWC(&ccb.swcCtx);
        ccb.fanPWM.Init();

        INFO(std::string(Cfg::SWC_NAME) + " SWC init complete");
        return GlobalTypes::CALL_OK;
    }
}

namespace SWC::Fan::FanControl {
    FanSpeed GetFanSpeed(void){
        return ccb.fanSpeed;
    }

    void SetFanSpeed(FanSpeed speed){
        ccb.fanSpeed = speed;
        using namespace Cfg;
        switch (ccb.fanSpeed) {
            case FanSpeed::OFF:
                ccb.fanPWM.SetValue(0);
                break;
            case FanSpeed::LOW:
                ccb.fanPWM.SetValue(PWM_MIN);
                break;
            case FanSpeed::MEDIUM:
                ccb.fanPWM.SetValue(PWM_MIN + 2*PWM_INC_STEP);
                break;
            case FanSpeed::HIGH:
                ccb.fanPWM.SetValue(PWM_MIN + 4*PWM_INC_STEP);
                break;
            case FanSpeed::MAX:
                ccb.fanPWM.SetValue(PWM_MAX);
                break;
            default:
                ccb.fanPWM.SetValue(0);
                break;
        }
    }

    void IncFanSpeed(void){
        if(ccb.fanSpeed == FanSpeed::MAX) return;

        ++ccb.fanSpeed;
        SetFanSpeed(ccb.fanSpeed);
    }

    void DecFanSpeed(void){
        if(ccb.fanSpeed == FanSpeed::OFF) return;

        --ccb.fanSpeed;
        SetFanSpeed(ccb.fanSpeed);
    }
}