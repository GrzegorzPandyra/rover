#ifndef VEH_H
#define VEH_H

#include <vector>

namespace veh{

    enum PRND_T {
        PRND_R  = 0,
        PRND_N  = 1,
        PRND_D1 = 2,
        PRND_D2 = 3,
        PRND_D3 = 4
    };

    void init(void);
    void run(void);
    void shift_up(void);
    void shift_down(void);
    PRND_T get_gear(void);
    void set_gear(PRND_T gear);
    std::vector<std::string> export_data(void);
}

#endif /* VEH_H */
