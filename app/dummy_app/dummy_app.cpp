#include <iostream>
#include "dummy_app.hpp"

void dummy_app::dummy_app_init(void){
    std::cout << "SWC [dummy_app] init" << std::endl;
}

void dummy_app::dummy_app_run(void){
    std::cout << "Dummy app running\r" << std::endl;
}
void dummy_app::dummy_app_run2(void){
    std::cout << "Dummy app running 2\r" << std::endl;
}