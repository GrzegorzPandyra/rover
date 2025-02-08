#ifndef LOGGER_H
#define LOGGER_H

#include <deque>
#include <mutex>
#include "ILogger.hpp"
#include "IComponent.hpp"

class Logger : public ILogger, public IComponent {
    public:
        Logger(const Logger&) = delete;
        ~Logger();
        static void Log(Message msg);
        static void Log(std::string origin, std::string content);
        static void Log(std::string content);
        static Logger& GetInstance(void);
        static int PreInit();
        int Init();
        int DeInit();
        int Run();
        int Stop();

    private:
        Logger(SystemType st, std::string name);
        static Logger* m_loggerPtr;
        std::deque<Message> m_dataBuffer;
        std::mutex m_mtx;
        virtual void PureVirt(void){};
};

#endif