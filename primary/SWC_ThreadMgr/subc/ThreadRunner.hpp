#ifndef THREAD_RUNNER_H
#define THREAD_RUNNER_H

#include <vector>
#include "ISWC.hpp"

class ThreadRunner 
{
    private:
        std::vector<ISWC*> & M_SWC_REGISTER;
    public:
        ThreadRunner(std::vector<ISWC*> &swc_register);
        ThreadRunner() = delete;
        ~ThreadRunner();
        void RunThread(ISWC::SystemType systype);


};

#endif