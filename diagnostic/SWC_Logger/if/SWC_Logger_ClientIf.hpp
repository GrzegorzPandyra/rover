#ifndef SWC_LOGGER_CLIENTIF_H
#define SWC_LOGGER_CLIENTIF_H
#include <sstream>
#include "SWC_Types.hpp"

/* Convenience macros */
#define INFO(s)  (Log(INFO,     (s), __FILE__, __LINE__))
#define WARN(s)  (Log(WARNING,  (s), __FILE__, __LINE__))
#define ERROR(s) (Log(ERROR,    (s), __FILE__, __LINE__))

namespace SWC_Logger::ClientIf
{
    enum LogType
    {
        INFO,
        WARNING,
        ERROR
    };

    void Log(LogType lt, std::stringstream ss, std::string filepath, int line);
    void Log(LogType lt, std::string s,        std::string filepath, int line);
}

/*  Explicit ClientIf namespace for user convenience 
    because API is using macros                     */
using namespace SWC_Logger::ClientIf;

#endif