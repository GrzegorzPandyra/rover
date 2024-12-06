#ifndef PWR_MON_H
#define PWR_MON_H

#include <vector>

namespace pwr_mon{
    void init(void);
    void run(void);
    std::vector<std::string> export_data(void);
}

#endif