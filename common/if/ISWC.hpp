#ifndef ISWC_H
#define ISWC_H

#include <string>

class ISWC
{
    public:
        enum SystemType
        {
          ST_PRIMARY,  
          ST_SECONDARY,  
          ST_AUXILIARY,  
          ST_DIAGNOSTIC  
        };
        enum State
        {
          STATE_INIT,
          STATE_UNINIT,
          STATE_STOP
        };
        ISWC(SystemType st, std::string name) : SYSTEM_TYPE(st), NAME(name) {};
        virtual ~ISWC(){};
        virtual int Init() = 0;
        virtual int DeInit() = 0;
        virtual int Run() = 0;
        virtual int Stop() = 0;
        SystemType GetSystemType(void) const {return SYSTEM_TYPE;};
        std::string GetName(void) const {return NAME;};
        void SetState(State s){m_state = s;};
        State GetState(void){return m_state;};
        
    private:
        const SystemType SYSTEM_TYPE;
        const std::string NAME;
        State m_state;

};

#endif