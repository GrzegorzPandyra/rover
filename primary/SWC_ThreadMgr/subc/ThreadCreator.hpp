#ifndef THREAD_CREATOR_H
#define THREAD_CREATOR_H

#include <array>
#include "cfg/threads.hpp"

template <std::size_t thPoolSize>
class ThreadCreator {
    public:
    typedef void* (*threadPtr)(void * args);
    ThreadCreator();
    ~ThreadCreator();
    private:
    std::array<const threadPtr, thPoolSize> m_THREAD_POOL;
    void CreateThreads(void);

        
};

#endif