/* Std library includes */
/* SWC includes */
#include "Buzzer_BuzzIf.hpp"
#include "Buzzer_SysIf.hpp"
#include "ThreadMgr_ClientIf.hpp"
#include "Logger_ClientIf.hpp"
#include "WiringPi.hpp"
/* Other includes */
#include "BuzzerCfg.hpp"
#include "DelayedCall.hpp"

namespace SWC::Buzzer {
    namespace {
        void Run(void);
        void TurnOffBuzzerCbk(void);

        struct {
            SWC::Types::SwcContext swcCtx = {
                Cfg::SWC_NAME, 
                Cfg::SWC_SYSTEM_TYPE,
                SWC::Types::INIT,
                Run
            };

            DelayedCall buzzerTimeoutCall {TurnOffBuzzerCbk, Cfg::BUZZ_TIMEOUT_MS};
        } ccb; /* Component Control Block */ 

        void Run(void){
            ccb.buzzerTimeoutCall.Run();
        }

        void TurnOffBuzzerCbk(void){
            using namespace WiringPi;
            SetPin(Cfg::BUZZ_PIN, PIN_HIGH);
        }
    }
    
    
}

namespace SWC::Buzzer::SysIf
{
    GlobalTypes::CallResult Init(void)
    {
        using namespace WiringPi;

        SWC::ThreadMgr::ClientIf::RegisterSWC(&ccb.swcCtx);
        ccb.buzzerTimeoutCall.Init();
        SetPinMode(Cfg::BUZZ_PIN, PM_OUTPUT);
        SetPin(Cfg::BUZZ_PIN, PIN_HIGH);

        INFO(std::string(Cfg::SWC_NAME) + " SWC init complete");
        return GlobalTypes::CALL_OK;
    }
}

namespace SWC::Buzzer::Buzz
{
    void Buzz(){
        using namespace WiringPi;
        SetPin(Cfg::BUZZ_PIN, PIN_LOW);
        ccb.buzzerTimeoutCall.Set();
    }
}