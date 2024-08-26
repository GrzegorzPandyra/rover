#include <iostream>
#include <vector>
#include "dummy_app.hpp"
#include "../ui/ui_logging.hpp"

void dummy_app::dummy_app_init(void){
    LOG("SWC [dummy_app] init\n");
}

void dummy_app::dummy_app_run(void){
    LOG("Dummy app running\n");
}
void dummy_app::dummy_app_run2(void){
    LOG("Dummy app running 2\n");
}

std::vector<std::string> dummy_app::get_mon_data(void){
    std::vector<std::string> result;
    result.push_back("=== OFFLINE ===");
    result.push_back("=== OFFLINE ===");
    return result;
}