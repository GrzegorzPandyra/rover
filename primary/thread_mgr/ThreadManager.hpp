#ifndef THREAD_MANAGER_H
#define THREAD_MANAGER_H

#include <vector>
#include "IComponent.hpp"

class ThreadManager : public IComponent {
    public:
        ThreadManager(const ThreadManager&) = delete;
        ~ThreadManager();
        static void RegComp(IComponent* comp);
        static ThreadManager& GetInstance(void);
        static int PreInit();
        int Init();
        int DeInit();
        std::vector<IComponent*>& GetCompVect(void);

    private:
        ThreadManager(SystemType st, std::string name);
        std::vector<IComponent*> m_compVect;
        static ThreadManager* m_threadManagerPtr;
        int Run();
        int Stop();
};

#endif