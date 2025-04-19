/* Std library includes */
#include <string>
#include <vector>
#include <array>
/* SWC includes */
#include "Lights_LightControlIf.hpp"
#include "Lights_SysIf.hpp"
#include "ThreadMgr_ClientIf.hpp"
#include "Logger_ClientIf.hpp"
#include "StatMon_ClientIf.hpp"
/* Other includes */
#include "LightsCfg.hpp"
#include "PWMChannel.hpp"

namespace SWC::Lights {
    namespace {
        void Run(void);
        std::vector<std::string> MonitorData(void);

        struct{
            SWC::Types::SwcContext swcCtx = {
                Cfg::SWC_NAME, 
                Cfg::SWC_SYSTEM_TYPE,
                SWC::Types::INIT,
                Run
            };

            std::array<PWMChannel, 3> lights = {
                PWMChannel(
                    Cfg::HEAD_LIGHT_PWM_PIN,
                    Cfg::PWM_MIN,
                    Cfg::PWM_MAX,
                    Cfg::PWM_DEF,
                    Cfg::PWM_STEP
                ),
                PWMChannel(
                    Cfg::ROOF_LIGHT_PWM_PIN,
                    Cfg::PWM_MIN,
                    Cfg::PWM_MAX,
                    Cfg::PWM_DEF,
                    Cfg::PWM_STEP
                ),
                PWMChannel(
                    Cfg::REAR_LIGHT_PWM_PIN,
                    Cfg::PWM_MIN,
                    Cfg::PWM_MAX,
                    Cfg::PWM_DEF,
                    Cfg::PWM_STEP
                )
            };

        } ccb; /* Component Control Block */ 
        
        void Run(void){
            using LightControl::LightType;
            ccb.lights[LightControl::HEADLIGHT].Run();
            ccb.lights[LightControl::ROOFLIGHT].Run();
            ccb.lights[LightControl::REARLIGHT].Run();
        }

        std::vector<std::string> MonitorData(void){
            using std::string;
            using std::to_string;

            std::vector<string> result;
            result.emplace_back(string("Head light PWM: ") + to_string(ccb.lights[LightControl::HEADLIGHT].GetValue() ) + string("     "));
            result.emplace_back(string("Roof light PWM: ") + to_string(ccb.lights[LightControl::ROOFLIGHT].GetValue() ) + string("     "));
            result.emplace_back(string("Rear light PWM: ") + to_string(ccb.lights[LightControl::REARLIGHT].GetValue() ) + string("     "));
            return result;
        }
    }
}

namespace SWC::Lights::SysIf {
    using namespace GlobalTypes;

    GlobalTypes::CallResult Init(void){
        ThreadMgr::ClientIf::RegisterSWC(&ccb.swcCtx);

        SWC::StatMon::ClientIf::RegisterMonitor({
            Cfg::MON_WIN_X,
            Cfg::MON_WIN_Y,
            Cfg::MON_WIN_WIDTH,
            Cfg::MON_WIN_HEIGHT,
            MonitorData,
            Cfg::SWC_NAME
        });

        ccb.lights[LightControl::HEADLIGHT].Init();
        ccb.lights[LightControl::ROOFLIGHT].Init();
        ccb.lights[LightControl::REARLIGHT].Init();
        
        INFO(std::string(Cfg::SWC_NAME) + " SWC init complete");
        return GlobalTypes::CALL_OK;
    }
}

namespace SWC::Lights::LightControl {
    PWMChannel::PWMValue GetLightPWM(LightType type){
        return ccb.lights[type].GetValue();
    }

    PWMChannel::PWMValue IncLightPWM(LightType type){
        return ccb.lights[type].Inc();
    }

    PWMChannel::PWMValue DecLightPWM(LightType type){
        return ccb.lights[type].Dec();
    }
}