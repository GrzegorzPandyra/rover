#include <iostream>
#include "SWCRegistrator.hpp"
// #include "Logger.hpp"

SWCRegistrator::SWCRegistrator(std::vector<ISWC*> & swc_register) : M_SWC_REGISTER(swc_register)
{
    std::cout << __LINE__ <<" SWC registrator created\n";
}

SWCRegistrator::~SWCRegistrator()
{

}

bool SWCRegistrator::RegisterSWC(ISWC* swc)
{
    // m_threadManagerPtr->m_registrationMutex.lock();
    // m_threadManagerPtr->m_compVect.push_back(comp);
    // m_threadManagerPtr->m_registrationMutex.unlock();
    // Logger::Log(m_threadManagerPtr->GetName(), "Registered component "+comp->GetName());
    M_SWC_REGISTER.push_back(swc);
    return true;
}
