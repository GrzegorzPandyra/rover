 #include <pthread.h>
 #include <iostream>
 #include <unistd.h>
 #include "ThreadManager.hpp"
 #include "Logger.hpp"

 #if __cplusplus < 201703L
 #error Invalid C++ version - expecting C++17 or higher
 #endif

 #define STATUS_OK 0

extern "C"
{
    static void* primary_thread(void * data);
    static void* secondary_thread(void * data);
    static void* auxiliary_thread(void * data);
    static void* diagnostic_thread(void * data);
}
static void InitializeSingletons(void);
static void CreateThreads(void);
static void RunThread(IComponent::SystemType st);

typedef void* (*threadPtr)(void * args);
std::array<const threadPtr, 4> threadPool = 
{
    primary_thread,
    secondary_thread,
    auxiliary_thread,
    diagnostic_thread    
};

extern "C"
{
    static void* primary_thread(void * data){
        Logger::Log("Init", "Primary thread started");
        RunThread(IComponent::ST_PRIMARY);
        return NULL;
    }

    static void* secondary_thread(void * data){
        Logger::Log("Init", "Secondary thread started");
        RunThread(IComponent::ST_SECONDARY);;
        return NULL;
    }

    static void* auxiliary_thread(void * data){
        Logger::Log("Init", "Auxiliary thread started");
        RunThread(IComponent::ST_AUXILIARY);
        return NULL;
    }
    
    static void* diagnostic_thread(void * data){
        Logger::Log("Init", "Diagnostic thread started");
        RunThread(IComponent::ST_DIAGNOSTIC);
        return NULL;
    }
}

static void InitializeSingletons(void)
{
    ThreadManager::PreInit();
    ThreadManager::GetInstance().Init();
    Logger::PreInit();
    Logger::GetInstance().Init();
}

static void CreateThreads(void)
{
    pthread_t pid = 0;
    int status;
    for(auto& th : threadPool)
    {
        status = pthread_create(&pid, NULL, th, NULL);
        if(STATUS_OK != status)
        {
            std::cout<<"ERROR: Failed to create thread - Init failed\n";
        }
    }
}

static void RunThread(IComponent::SystemType st)
{
    do
    {
        for(auto& comp : ThreadManager::GetInstance().GetCompVect())
        {
            if(st == comp->GetSystemType())
            {
                comp->Run();
            }
        }

    } while(true);
}

int main()
{
    
    InitializeSingletons();
    CreateThreads();

    while(true);  

    std::cout<<"INFO: === Shutdown complete ===\n";

    return 0;
}   