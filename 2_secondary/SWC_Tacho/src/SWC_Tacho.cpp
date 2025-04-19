/* Std library includes */
#include <string>
/* SWC includes */
#include "Tacho_RPSIf.hpp"
#include "Tacho_SysIf.hpp"
#include "ThreadMgr_ClientIf.hpp"
#include "Logger_ClientIf.hpp"
/* Other includes */
#include "TachoCfg.hpp"
#include "PeriodicCall.hpp"
#include "WiringPi.hpp"

namespace SWC::Tacho
{
    namespace 
    {
        void Run(void);
        void CalculateRPSCbk(void);
        struct 
        {
            SWC::Types::SwcContext swcCtx =
            {
                Cfg::SWC_NAME, 
                Cfg::SWC_SYSTEM_TYPE,
                SWC::Types::INIT,
                Run
            };

            PeriodicCall pCall = {CalculateRPSCbk, Cfg::TRIGGER_PERIOD};
            float rps;
            WiringPi::PinState lastState;
            uint16_t slotCounter;
            std::chrono::milliseconds timeCounter;
        } ccb; /* Component Control Block */ 
        
        void Run(void)
        {
            ccb.pCall.Run();
        }

        void CalculateRPSCbk(void){
            WiringPi::PinState state = WiringPi::GetPin(Cfg::TACHO_PIN);
            if(state != ccb.lastState){
                ccb.slotCounter++;
            }
            ccb.lastState = state;
            ccb.timeCounter += Cfg::TRIGGER_PERIOD;

            if(ccb.timeCounter >= Cfg::CALCULATION_PERIOD){
                ccb.rps = (float)ccb.slotCounter/(float)Cfg::NUM_BOARD_SLOTS;
                ccb.slotCounter = 0u;
                ccb.timeCounter = std::chrono::milliseconds::zero();
            }
        }
    }
    
}

namespace SWC::Tacho::SysIf {
    using namespace GlobalTypes;

    GlobalTypes::CallResult Init(void){
        using namespace WiringPi;

        ThreadMgr::ClientIf::RegisterSWC(&ccb.swcCtx);
        SetPinMode(Cfg::TACHO_PIN, PM_INPUT);

        ccb.lastState = PIN_LOW;
        ccb.slotCounter = 0;
        ccb.timeCounter = std::chrono::milliseconds::zero();

        INFO(std::string(Cfg::SWC_NAME) + " SWC init complete");
        return GlobalTypes::CALL_OK;
    }
}

namespace SWC::Tacho::RPS {
    float GetRPS(void){
        return ccb.rps;
    }
}