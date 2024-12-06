/*
   ToDo
*/
#include <iostream>
#include "pwr_mon.hpp"
#include "../../app/ui/ui_logging.hpp"
#include "pwr_mon_cfg.hpp"
#include "ina226.hpp"
#include "ina3221.hpp"

using namespace pwr_mon;

static struct {
    INA3221 ina3221 = INA3221(PWR_MON_INA3221_I2C_ADDR);
    INA226 ina226_1 = INA226(PWR_MON_INA226_I2C_ADDR_1);
    INA226 ina226_2 = INA226(PWR_MON_INA226_I2C_ADDR_2);
    INA226 ina226_3 = INA226(PWR_MON_INA226_I2C_ADDR_3);
    int16_t ina3221_value[3] = {0};
    int16_t ina226_1_value = 0;
    int16_t ina226_2_value = 0;
    int16_t ina226_3_value = 0;
} mgr;

void pwr_mon::init(void){
    LOG("SWC [pwr_mon] init\n");
    mgr.ina226_1.init();
    mgr.ina226_2.init();
    mgr.ina226_3.init();
    mgr.ina3221.init();
}

void pwr_mon::run(void){
    mgr.ina3221_value[0] = mgr.ina3221.read_voltage(INA3221::Channel::CHANNEL_1);
    mgr.ina3221_value[1] = mgr.ina3221.read_voltage(INA3221::Channel::CHANNEL_2);
    mgr.ina3221_value[2] = mgr.ina3221.read_voltage(INA3221::Channel::CHANNEL_3);
    mgr.ina226_1_value = mgr.ina226_1.read_bus_voltage();
    mgr.ina226_2_value = mgr.ina226_2.read_bus_voltage();
    mgr.ina226_3_value = mgr.ina226_3.read_bus_voltage();
}

std::vector<std::string> pwr_mon::export_data(void){
    std::vector<std::string> result;

    /* Result has to be property-value pair */
    result.push_back("Power cell #1 (Motor#1)");
    if(mgr.ina226_1_value != INA226::DataStatus::ERROR)
        result.push_back(std::to_string(mgr.ina226_1_value));
    else
        result.push_back("ERROR");

    result.push_back("Power cell #2 (Motor#2)");
    if(mgr.ina226_1_value != INA226::DataStatus::ERROR)
        result.push_back(std::to_string(mgr.ina226_2_value));
    else
        result.push_back("ERROR");

    result.push_back("Power cell #3 (ICs)    ");
    if(mgr.ina226_1_value != INA226::DataStatus::ERROR)
        result.push_back(std::to_string(mgr.ina226_3_value));
    else
        result.push_back("ERROR");

    result.push_back("Power rails            ");
    result.push_back(std::to_string(mgr.ina3221_value[0])+" / "+std::to_string(mgr.ina3221_value[1])+" / "+std::to_string(mgr.ina3221_value[2]));
    return result;
}