/* Std library includes */
#include <string>
/* SWC includes */
#include "Template_ClientIf.hpp"
#include "Template_SysIf.hpp"
#include "ThreadMgr_ClientIf.hpp"
#include "Logger_ClientIf.hpp"
/* Other includes */
#include "TemplateCfg.hpp"

namespace SWC::Template
{
    namespace 
    {
        void Run(void);

        struct 
        {
            SWC::Types::SwcContext swcCtx =
            {
                Cfg::SWC_NAME, 
                Cfg::SWC_SYSTEM_TYPE,
                SWC::Types::INIT,
                Run
            };
        } ccb; /* Component Control Block */ 
        
        void Run(void)
        {
        }
    }
    
}

namespace SWC::Template::SysIf {
    using namespace GlobalTypes;

    GlobalTypes::CallResult Init(void){
        ThreadMgr::ClientIf::RegisterSWC(&ccb.swcCtx);
        INFO(std::string(Cfg::SWC_NAME) + " SWC init complete");
        return GlobalTypes::CALL_OK;
    }
}

namespace SWC::Template::ClientIf {
}