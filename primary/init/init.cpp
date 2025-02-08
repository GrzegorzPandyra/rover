 #include <pthread.h>
 #include <iostream>
 #include <unistd.h>
 #include "ThreadManager.hpp"
 #include "Logger.hpp"

 #if __cplusplus < 201703L
 #error Invalid C++ version - expecting C++17 or higher
 #endif

 #define STATUS_OK 0

extern "C"{
    void* system_thread(void * data){
        std::cout<<"system thread running\n";
        while(1);
        return NULL;
    }

    void* system_thread2(void * data){
        std::cout<<"system2 thread running\n";
        while(1);
        return NULL;
    }
}

int main()
{
    pthread_t pid = 0;
    int status = pthread_create(&pid, NULL, system_thread, NULL);
    if(STATUS_OK != status){
        std::cout<<"ERROR: Failed to create System Manager thread - Init failed\n";
    } else {
        std::cout<<"INFO: Created System Manager thread with PID:"<<getpid()<<"\n";
        ThreadManager::GetInstance();
        ThreadManager::PreInit();
        ThreadManager::GetInstance().Init();
        ThreadManager::GetInstance();
        ThreadManager::RegComp(&ThreadManager::GetInstance());
        Logger::PreInit();
        Logger::Log(Logger::Message{"LoggerName", "dupa"});
        Logger::Log("LoggerName", "dupa2");
        Logger::Log("dupa3");
        Logger::GetInstance().Logger::Run();
        Logger::GetInstance().Logger::Run();
        Logger::GetInstance().Logger::Run();
        Logger::GetInstance().Logger::Run();
        Logger::GetInstance().Logger::Run();
        Logger::GetInstance().Logger::Run();
        while(1);
    }
    std::cout<<"INFO: === Shutdown complete ===";

    return 0;
}   