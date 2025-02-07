#ifndef ICOMPONENT_H
#define ICOMPONENT_H

class IComponent
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
        IComponent(SystemType st) : SYSTEM_TYPE(st) {};
        virtual ~IComponent(){};
        virtual int Init() = 0;
        virtual int DeInit() = 0;
        virtual int Run() = 0;
        virtual int Stop() = 0;
        SystemType GetSystemType(void){return SYSTEM_TYPE;};
        void SetState(State s){m_state = s;};
        State GetState(void){return m_state;};
        
    private:
        const SystemType SYSTEM_TYPE;
        State m_state;

};

#endif