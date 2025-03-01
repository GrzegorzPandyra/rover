#ifndef SWC_REGISTRATOR_H
#define SWC_REGISTRATOR_H

#include <vector>
#include "ISWC.hpp"
#include "cfg/threads.hpp"

class SWCRegistrator {
    private:
        std::vector<ISWC*> & M_SWC_REGISTER;
    public:
        SWCRegistrator(std::vector<ISWC*> &swc_register);
        SWCRegistrator() = delete;
        ~SWCRegistrator();
        bool RegisterSWC(ISWC* swc);

        
};

#endif