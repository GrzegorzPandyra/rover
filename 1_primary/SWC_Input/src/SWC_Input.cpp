/* Std library includes */
#include <ncurses.h>
#include <string>
#include <vector>
#include <unordered_map>
/* SWC includes */
#include "Input_ClientIf.hpp"
#include "Input_SysIf.hpp"
#include "Veh_InputIf.hpp"
#include "Logger_ClientIf.hpp"
#include "ThreadMgr_ClientIf.hpp"
#include "StatMon_ClientIf.hpp"
#include "Buzzer_BuzzIf.hpp"
#include "Lights_LightControlIf.hpp"
/* Other includes */
#include "InputCfg.hpp"
#include "GlobalTypes.hpp"


namespace SWC::Input {
    namespace {
        void Run(void);
        void ForwardCbk(void);
        void BackwardCbk(void);
        void TurnLeftCbk(void);
        void TurnRightCbk(void);
        void StopCbk(void);
        void PwmAutoDecrementCbk(void);
        void HardstartCbk(void);
        void ShiftUpCbk(void);
        void ShiftDownCbk(void);
        void ShutdownCbk(void);
        void BuzzerCbk(void);
        void IncFanSpeedCbk(void);
        void DecFanSpeedCbk(void);
        void HeadLightInc(void);
        void HeadLightDec(void);
        void RoofLightInc(void);
        void RoofLightDec(void);
        void RearLightInc(void);
        void RearLightDec(void);

        struct {
                Types::SwcContext swcCtx = {
                Cfg::SWC_NAME, 
                Cfg::SWC_SYSTEM_TYPE,
                Types::INIT,
                Run
            };

            const std::unordered_map<char, GlobalTypes::GenericCbk> FUNCTION_MAP = {
                {Cfg::KEY_FORWARD          , ForwardCbk           },
                {Cfg::KEY_BACKWARD         , BackwardCbk          },
                {Cfg::KEY_TURN_RIGHT       , TurnRightCbk         },
                {Cfg::KEY_TURN_LEFT        , TurnLeftCbk          },
                {Cfg::KEY_STOP             , StopCbk              },
                {Cfg::KEY_PWM_AUTO_DEC     , PwmAutoDecrementCbk  },
                {Cfg::KEY_HARDSTART        , HardstartCbk         },
                {Cfg::KEY_SHIFT_UP         , ShiftUpCbk           },
                {Cfg::KEY_SHIFT_DOWN       , ShiftDownCbk         },
                {Cfg::KEY_SHUTDOWN         , ShutdownCbk          },
                {Cfg::KEY_BUZZER           , BuzzerCbk            },
                {Cfg::KEY_FAN_SPEED_INC    , IncFanSpeedCbk       },
                {Cfg::KEY_HEADLIGHT_PWM_INC, HeadLightInc         },
                {Cfg::KEY_HEADLIGHT_PWM_DEC, HeadLightDec         },
                {Cfg::KEY_ROOFLIGHT_PWM_INC, RoofLightInc         },
                {Cfg::KEY_ROOFLIGHT_PWM_DEC, RoofLightDec         },
                {Cfg::KEY_REARLIGHT_PWM_INC, RearLightInc         },
                {Cfg::KEY_REARLIGHT_PWM_DEC, RearLightDec         }
            };
        } ccb; /* Component Control Block */ 

        void Run(void){
            char c = getch();
            auto mapping = ccb.FUNCTION_MAP.find(c);
            if(mapping != ccb.FUNCTION_MAP.end()) mapping->second();
        }

        std::vector<std::string> MonitorData(void)
        {
            using std::string;
            using std::to_string;

            std::vector<std::string> result;

            result.emplace_back(string("^ Forward       : ") + Cfg::KEY_FORWARD         );
            result.emplace_back(string("< Turn Left     : ") + Cfg::KEY_TURN_LEFT       );
            result.emplace_back(string("> Turn Right    : ") + Cfg::KEY_TURN_RIGHT      );
            result.emplace_back(string("V Backward      : ") + Cfg::KEY_BACKWARD        );
            result.emplace_back(string("Stop            : ") + Cfg::KEY_STOP            );
            result.emplace_back(string("PWM auto-dec    : ") + Cfg::KEY_PWM_AUTO_DEC    );
            result.emplace_back(string("Shift up        : ") + Cfg::KEY_SHIFT_UP        );
            result.emplace_back(string("Shift down      : ") + Cfg::KEY_SHIFT_DOWN      );
            result.emplace_back(string("Fan PWM Inc     : ") + Cfg::KEY_FAN_SPEED_INC   );
            result.emplace_back(string("Fan PWM dec     : ") + Cfg::KEY_FAN_SPEED_DEC   );
            result.emplace_back(string("Shutdown        : ") + Cfg::KEY_SHUTDOWN        );
            result.emplace_back(string("Buzzer          : ") + Cfg::KEY_BUZZER          );
            return result;
        }

        /***************************************************************
         *                 Button-handling callbacks
         ***************************************************************/

        void ForwardCbk(void){
            SWC::Veh::InputIf::Forward();
        }

        void BackwardCbk(void){
            SWC::Veh::InputIf::Backward();
        }

        void TurnLeftCbk(void){
            SWC::Veh::InputIf::TurnLeft();
        }

        void TurnRightCbk(void){
            SWC::Veh::InputIf::TurnRight();
        }

        void StopCbk(void){
            SWC::Veh::InputIf::Stop();
        }

        void PwmAutoDecrementCbk(void){
            Veh::InputIf::TogglePWMAutoDecrement();
        }

        void HardstartCbk(void){

        }

        void ShiftUpCbk(void){
            Veh::InputIf::ShiftUp();
        }

        void ShiftDownCbk(void){
            Veh::InputIf::ShiftDown();
        }

        void ShutdownCbk(void){
            INFO("Shutdown...");
            exit(0);
        }

        void BuzzerCbk(void){
            SWC::Buzzer::Buzz::Buzz();
        }

        void IncFanSpeedCbk(void){
            Veh::InputIf::FanSpeedUp();
        }

        void DecFanSpeedCbk(void){
            Veh::InputIf::FanSlowDown();
        }

        void HeadLightInc(void){
            Lights::LightControl::IncLightPWM(Lights::LightControl::HEADLIGHT);
        }

        void HeadLightDec(void){
            Lights::LightControl::DecLightPWM(Lights::LightControl::HEADLIGHT);
        }

        void RoofLightInc(void){
            Lights::LightControl::IncLightPWM(Lights::LightControl::ROOFLIGHT);
        }

        void RoofLightDec(void){
            Lights::LightControl::DecLightPWM(Lights::LightControl::ROOFLIGHT);
        }

        void RearLightInc(void){
            Lights::LightControl::IncLightPWM(Lights::LightControl::REARLIGHT);
        }

        void RearLightDec(void){
            Lights::LightControl::DecLightPWM(Lights::LightControl::REARLIGHT);
        }
    }
}

namespace SWC::Input::SysIf {
    GlobalTypes::CallResult Init(){
        ThreadMgr::ClientIf::RegisterSWC(&ccb.swcCtx);
        SWC::StatMon::ClientIf::RegisterMonitor({
            Cfg::MON_WIN_X,
            Cfg::MON_WIN_Y,
            Cfg::MON_WIN_WIDTH,
            Cfg::MON_WIN_HEIGHT,
            MonitorData,
            Cfg::SWC_NAME
        });

        INFO(std::string(Cfg::SWC_NAME) + " SWC init complete");
        return GlobalTypes::CALL_OK;
    }
}

namespace SWC::Input::ClientIf {

}