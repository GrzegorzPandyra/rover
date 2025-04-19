/* Std library includes */
#include <vector>
/* SWC includes */
#include "StSys_ServoControlIf.hpp"
#include "StSys_SysIf.hpp"
#include "ThreadMgr_ClientIf.hpp"
#include "Logger_ClientIf.hpp"
#include "StatMon_ClientIf.hpp"
/* Other includes */
#include "StSysCfg.hpp"
#include "PWMChannel.hpp"

namespace SWC::StSys {
    namespace {
        void Run(void);

        struct {
            SWC::Types::SwcContext swcCtx = {
                SWC::StSys::Cfg::SWC_NAME, 
                SWC::StSys::Cfg::SWC_SYSTEM_TYPE,
                SWC::Types::INIT,
                Run
            };

            PWMChannel leftPWM = {
                Cfg::LEFT_WHEEL_PWM_PIN,
                Cfg::PWM_MIN_VAL,
                Cfg::PWM_MAX_VAL,
                Cfg::PWM_DEF_VAL,
                Cfg::PWM_INC_STEP
            };

            PWMChannel rightPWM = {
                Cfg::RIGHT_WHEEL_PWM_PIN,
                Cfg::PWM_MIN_VAL,
                Cfg::PWM_MAX_VAL,
                Cfg::PWM_DEF_VAL,
                Cfg::PWM_INC_STEP
            };

        } ccb; /* Component Control Block */ 
        
        void Run(void){
            ccb.leftPWM.Run();
            ccb.rightPWM.Run();
        }

        std::vector<std::string> MonitorData(void){
            using std::string;
            using std::to_string;

            std::vector<string> result;
            result.emplace_back(string("Left  PWM: ") + to_string(ccb.leftPWM.GetValue() ) + string("     "));
            result.emplace_back(string("Right PWM: ") + to_string(ccb.rightPWM.GetValue()) + string("     "));
            return result;
        }
    }
}

namespace SWC::StSys::SysIf {
    GlobalTypes::CallResult Init(void){
        SWC::ThreadMgr::ClientIf::RegisterSWC(&ccb.swcCtx);
        SWC::StatMon::ClientIf::RegisterMonitor({
            Cfg::MON_WIN_X,
            Cfg::MON_WIN_Y,
            Cfg::MON_WIN_WIDTH,
            Cfg::MON_WIN_HEIGHT,
            MonitorData,
            Cfg::SWC_NAME
        });
        ccb.leftPWM.Init();
        ccb.rightPWM.Init();

        INFO(std::string(Cfg::SWC_NAME) + " SWC init complete");
        return GlobalTypes::CALL_OK;
    }
}

namespace SWC::StSys::ServoControl {
    void TurnLeft(void){
        INFO("Left");
        ccb.leftPWM.Dec();
        ccb.rightPWM.Dec();
    }
    
    void TurnRight(void){
        INFO("Right");
        ccb.leftPWM.Inc();
        ccb.rightPWM.Inc();
    }

    void Set(PWMChannel::PWMValue target){
        ccb.leftPWM.SetValue(target);
        ccb.rightPWM.SetValue(target);
    }
}