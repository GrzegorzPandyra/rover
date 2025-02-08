#ifndef ILOGGER_H
#define ILOGGER_H

#include <string>

class ILogger
{
  public:
    struct Message
    {
      std::string origin;
      std::string content;
    };
    ILogger(){};
    virtual ~ILogger(){};
    static void Log(Message msg);
  protected:
    virtual void PureVirt(void) = 0;
  private:
};

#endif