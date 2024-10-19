#include <iostream>
#include <vector>
#include "veh.hpp"
#include "../ui/ui_logging.hpp"
#include "../tacho/tacho.hpp"

using namespace veh;

static struct {
    PRND_T prnd;
    float rps;
} veh_mgr;

void veh::init(void){
    LOG("SWC [veh] init\n");
}

void veh::run(void){
    veh_mgr.rps = tacho::get_speed();
}

void veh::shift_up(void){
    if(D3 > veh_mgr.prnd){
        veh_mgr.prnd = static_cast<PRND_T>(static_cast<int>(veh_mgr.prnd) + 1);
    }
}
void veh::shift_down(void){
    if(R3 < veh_mgr.prnd){
        veh_mgr.prnd = static_cast<PRND_T>(static_cast<int>(veh_mgr.prnd) - 1);
    }
}

PRND_T veh::get_gear(void){
    return veh_mgr.prnd;
}

std::vector<std::string> veh::export_data(void){
    std::vector<std::string> result;
    char* prnd_strings[] = {"R3", "R2", "R1", "N", "D1", "D2", "D3"};
    const int PRND_ENUM_OFFSET = 3; /* offset negative PRND values */
    result.push_back("PRND");
    result.push_back(prnd_strings[(int)veh_mgr.prnd+PRND_ENUM_OFFSET]);
    result.push_back("RPS");
    result.push_back(std::to_string(veh_mgr.rps));
    return result;
}