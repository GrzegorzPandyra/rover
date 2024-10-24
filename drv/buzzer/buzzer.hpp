#ifndef BUZZER_H
#define BUZZER_H

#include <vector>

namespace buzzer{
    void init(void);
    void run(void);
    void buzz(uint16_t time_ms);
}

#endif