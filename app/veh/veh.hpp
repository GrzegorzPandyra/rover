#ifndef VEH_H
#define VEH_H

#include <vector>

namespace veh{

    enum PRND_T {
        R3 = -3,
        R2,
        R1,
        N,
        D1,
        D2,
        D3
    };

    void init(void);
    void run(void);
    void shift_up(void);
    void shift_down(void);
    PRND_T get_gear(void);
    std::vector<std::string> export_data(void);
}

#endif /* VEH_H */
