/* Std library includes */
#include <string>
#include <vector>
#include <unordered_map>
#include <linux/joystick.h>
/* SWC includes */
#include "PadInput_SysIf.hpp"
#include "ThreadMgr_ClientIf.hpp"
#include "Logger_ClientIf.hpp"
#include "StatMon_ClientIf.hpp"
#include "Veh_InputIf.hpp"
#include "Buzzer_BuzzIf.hpp"
/* Other includes */
#include "PadInputCfg.hpp"

namespace SWC::PadInput {
    namespace {

        void Run(void);
        void ReadDeviceFile();
        void BtnXCbk(void);
        void BtnYCbk(void);
        void BtnACbk(void);
        void BtnBCbk(void);
        void BtnR1Cbk(void);
        void BtnR2Cbk(void);
        void BtnL1Cbk(void);
        void BtnL2Cbk(void);
        void BtnLStickCbk(void);
        void BtnRStickCbk(void);
        void BtnSelectCbk(void);
        void BtnStartCbk(void);
        void DPadHCbk(int val);
        void DPadVCbk(int val);
        void LStickHCbk(int val);
        void LStickVCbk(int val);
        void RStickHCbk(int val);
        void RStickVCbk(int val);

        struct {
            SWC::Types::SwcContext swcCtx = {
                Cfg::SWC_NAME, 
                Cfg::SWC_SYSTEM_TYPE,
                SWC::Types::INIT,
                Run
            };

            const std::unordered_map<uint8_t, GlobalTypes::GenericCbk> BTN_FUNCTION_MAP = {
                {Cfg::PAD_BTN_X         , BtnXCbk       },
                {Cfg::PAD_BTN_Y         , BtnYCbk       },
                {Cfg::PAD_BTN_A         , BtnACbk       },
                {Cfg::PAD_BTN_B         , BtnBCbk       },
                {Cfg::PAD_BTN_R1        , BtnR1Cbk      },
                {Cfg::PAD_BTN_R2        , BtnR2Cbk      },
                {Cfg::PAD_BTN_L1        , BtnL1Cbk      },
                {Cfg::PAD_BTN_L2        , BtnL2Cbk      },
                {Cfg::PAD_BTN_LSTICK    , BtnLStickCbk  },
                {Cfg::PAD_BTN_RSTICK    , BtnRStickCbk  },
                {Cfg::PAD_BTN_SELECT    , BtnSelectCbk  },
                {Cfg::PAD_BTN_START     , BtnStartCbk   },
            };

            const std::unordered_map<uint8_t, GlobalTypes::PadAxisCbk> AXIS_FUNCTION_MAP = {
                {Cfg::PAD_AXIS_LSTICK_H , LStickHCbk    },
                {Cfg::PAD_AXIS_LSTICK_V , LStickVCbk    },
                {Cfg::PAD_AXIS_RSTICK_H , RStickHCbk    },
                {Cfg::PAD_AXIS_RSTICK_V , RStickVCbk    },
                {Cfg::PAD_AXIS_DPAD_H   , DPadHCbk      },
                {Cfg::PAD_AXIS_DPAD_V   , DPadVCbk      },
            };

            FILE *padFile = nullptr;
            bool isPadConnected = false;
        } ccb; /* Component Control Block */ 
        
        void Run(void){
            ReadDeviceFile();
        }
        
        std::vector<std::string> MonitorData(void)
        {
            std::vector<std::string> result;

            if(!ccb.isPadConnected){
                result.emplace_back(" =Pad no connected= ");
            }

            result.emplace_back("^ Forward       : ^ ");
            result.emplace_back("< Turn Left     : < ");
            result.emplace_back("> Turn Right    : > ");
            result.emplace_back("V Backward      : V ");
            result.emplace_back("Stop            : Y ");
            result.emplace_back("PWM auto-dec    : X ");
            result.emplace_back("Shift up        : R1");
            result.emplace_back("Shift down      : R2");
            result.emplace_back("Fan PWM Inc     : L1");
            result.emplace_back("Fan PWM dec     : L2");
            result.emplace_back("Shutdown        : --");
            result.emplace_back("Buzzer          : A ");
            return result;
        }

        void ReadDeviceFile(){
            if(ccb.padFile == nullptr){
                ERROR("Invalid file handler");
                return;
            }

            /* This function uses concepts from linux/joystic.h library */
            /*Joystick::*/js_event eventData;
            int8_t eof = false;
            eof = fread(
                &eventData,
                sizeof(/*Joystick::*/js_event),
                1,
                ccb.padFile);
            switch (eventData.type){
                case /*Joystick::*/JS_EVENT_BUTTON:
                    if(eventData.value == Cfg::BUTTON_PRESSED){
                        auto mapping = ccb.BTN_FUNCTION_MAP.find(eventData.number);
                        if(mapping != ccb.BTN_FUNCTION_MAP.end()) 
                            mapping->second();
                    }
                    break;
                case /*Joystick::*/JS_EVENT_AXIS:
                    {
                        auto mapping = ccb.AXIS_FUNCTION_MAP.find(eventData.number);
                        if(mapping != ccb.AXIS_FUNCTION_MAP.end())
                            mapping->second(eventData.value);
                        break;
                    }
                default:
                    break;
            }
        }


        /***************************************************************
         *                 Button-handling callbacks
         ***************************************************************/
        void BtnXCbk(void){
            INFO("X");
            Veh::InputIf::TogglePWMAutoDecrement();
        }
        
        void BtnYCbk(void){
            INFO("Y");
            Veh::InputIf::Stop();
        }
        
        void BtnACbk(void){
            INFO("A");
            Buzzer::Buzz::Buzz();
        }
        
        void BtnBCbk(void){
            INFO("B");
        }
        
        void BtnR1Cbk(void){
            INFO("R1");
            Veh::InputIf::ShiftUp();
        }
        
        void BtnR2Cbk(void){
            INFO("R2");
            Veh::InputIf::ShiftDown();
        }
        
        void BtnL1Cbk(void){
            INFO("L1");
            Veh::InputIf::FanSpeedUp();
        }
        
        void BtnL2Cbk(void){
            INFO("L2");
            Veh::InputIf::FanSlowDown();
        }

        void BtnLStickCbk(void){
            INFO("Lstick");
        }

        void BtnRStickCbk(void){
            INFO("Rstick");
        }

        void BtnSelectCbk(void){
            INFO("select");
        }

        void BtnStartCbk(void){
            INFO("start");
        }

        void DPadHCbk(int val){
            if(val == Cfg::PAD_AXIS_MIN){
                INFO("DpadH - left");
                Veh::InputIf::TurnLeft();
            }
            if(val == Cfg::PAD_AXIS_MAX){
                INFO("DpadH - right");
                Veh::InputIf::TurnRight();
            }
            
        }

        void DPadVCbk(int val){
            if(val == Cfg::PAD_AXIS_MIN){
                INFO("DpadV - up");
                Veh::InputIf::Forward();
            }
            if(val == Cfg::PAD_AXIS_MAX){
                INFO("DpadV - down");
                Veh::InputIf::Backward();
            }
        }

        void LStickHCbk(int val){
            INFO("LStickHCbk");
        }

        void LStickVCbk(int val){
            INFO("LStickVCbk");
        }

        void RStickHCbk(int val){
            INFO("RStickHCbk");
        }

        void RStickVCbk(int val){
            INFO("RStickVCbk");
        }

    }
    
}

namespace SWC::PadInput::SysIf {
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

        ccb.padFile = fopen(Cfg::DEVICE_PATH,"w+b");
        if(ccb.padFile == nullptr){
            ERROR("Failed to get handle for pad device");
            ccb.isPadConnected = false;
            return GlobalTypes::CALL_ERROR;
        } else {
            INFO(std::string(Cfg::SWC_NAME) + " SWC init complete");
            ccb.isPadConnected = true;
            return GlobalTypes::CALL_OK;
        }
    }
}