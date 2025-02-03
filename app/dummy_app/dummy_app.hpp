#ifndef DUMMY_APP_H
#define DUMMY_APP_H

#include <vector>

namespace dummy_app{
    void dummy_app_init(void);
    void dummy_app_run(void);
    void dummy_app_run2(void);
    std::vector<std::string> get_mon_data(void);
}

#endif