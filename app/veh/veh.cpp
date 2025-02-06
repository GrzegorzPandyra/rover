#include <iostream>
#include <vector>
#include "veh.hpp"
#include "ui_logging.hpp"
#include "tacho.hpp"

using namespace veh;

static struct {
    PRND_T prnd;
    float rps;
} mgr;

void veh::init(void){
    LOG("SWC [veh] init\n");
    mgr.prnd = PRND_N;
}

void veh::run(void){
    mgr.rps = tacho::get_speed();
}

void veh::shift_up(void){
    if(PRND_D3 > mgr.prnd){
        mgr.prnd = static_cast<PRND_T>(static_cast<int>(mgr.prnd) + 1);
    }
}
void veh::shift_down(void){
    if(PRND_R < mgr.prnd){
        mgr.prnd = static_cast<PRND_T>(static_cast<int>(mgr.prnd) - 1);
    }
}

PRND_T veh::get_gear(void){
    return mgr.prnd;
}

void veh::set_gear(PRND_T gear){
    mgr.prnd = gear;
}

std::vector<std::string> veh::export_data(void){
    std::vector<std::string> result;
    const char PRND_STR[][3] = {"R", "N", "D1", "D2", "D3"};
    result.push_back("PRND");
    result.push_back(PRND_STR[mgr.prnd]);
    result.push_back("RPS");
    result.push_back(std::to_string(mgr.rps).substr(0, 4));
    return result;
}