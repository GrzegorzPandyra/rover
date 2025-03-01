#include <pthread.h>
#include <iostream>
#include "ThreadCreator.hpp"
// #include "Logger.hpp"

#define STATUS_OK 0

template <std::size_t thPoolSize>
ThreadCreator<thPoolSize>::ThreadCreator() : m_THREAD_POOL{THREAD_MGR_CFG_THREAD_LIST}
{
    CreateThreads();
    std::cout << __LINE__ <<" Thread creator created\n";
}

template <std::size_t thPoolSize>
ThreadCreator<thPoolSize>::~ThreadCreator()
{

}

template <std::size_t thPoolSize>
void ThreadCreator<thPoolSize>::CreateThreads(void)
{
    std::cout << __FILE__ << " Line " << __LINE__ <<" : Creating threads... \n";
    pthread_t pid = 0;
    int status;
    for(auto& th : m_THREAD_POOL)
    {
        status = pthread_create(&pid, NULL, th, NULL);
        if(STATUS_OK != status)
        {
            std::cout<<"ERROR: Failed to create thread - Init failed\n";
        }
    }
    std::cout << __LINE__ <<" Created all threads\n";
}

/* Explicit instantiation of class template with defined num threads */
template class ThreadCreator<THREAD_MGR_CFG_NUM_THREADS>;