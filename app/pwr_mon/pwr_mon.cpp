/*
   ToDo
*/
#include <iostream>
#include <sstream>
#include <iomanip>
#include "pwr_mon.hpp"
#include "../../app/ui/ui_logging.hpp"
#include "pwr_mon_cfg.hpp"
#include "ina226.hpp"
#include "ina3221.hpp"

using namespace pwr_mon;
std::string format_data(float val);

static struct {
    INA3221 ina3221 = INA3221(PWR_MON_INA3221_I2C_ADDR);
    INA226 ina226_1 = INA226(PWR_MON_INA226_I2C_ADDR_1);
    INA226 ina226_2 = INA226(PWR_MON_INA226_I2C_ADDR_2);
    INA226 ina226_3 = INA226(PWR_MON_INA226_I2C_ADDR_3);
    float ina3221_ch1_value = 0.0f;
    float ina3221_ch2_value = 0.0f;
    float ina3221_ch3_value = 0.0f;
    float ina226_1_value = 0.0f;
    float ina226_2_value = 0.0f;
    float ina226_3_value = 0.0f;
} mgr;

void pwr_mon::init(void){
    LOG("SWC [pwr_mon] init\n");
    
    uint16_t cfg = 
    (0<<INA3221::CFG_MODE1)|
    (1<<INA3221::CFG_MODE2)|
    (1<<INA3221::CFG_MODE3)|
    (1<<INA3221::CFG_CH1_EN)|
    (1<<INA3221::CFG_CH2_EN)|
    (1<<INA3221::CFG_CH3_EN)|
    (0<<INA3221::CFG_AVG0)|
    (0<<INA3221::CFG_AVG1)|
    (1<<INA3221::CFG_AVG2);

    // mgr.ina226_1.init(cfg);
    // mgr.ina226_2.init(cfg);
    INA226::Status ina226_init_status = mgr.ina226_3.init(cfg);
    if(ina226_init_status == INA226::Status::STATUS_DIE_ID_ERROR)
        LOG("INA226 DIE ID ERROR\n");
    else if(ina226_init_status == INA226::Status::STATUS_MFG_ID_ERROR)
        LOG("INA226 MFG ID ERROR\n");

    INA3221::Status ina3221_init_status = mgr.ina3221.init(cfg);
    if(ina3221_init_status == INA3221::Status::STATUS_DIE_ID_ERROR)
        LOG("INA3221 DIE ID ERROR\n");
    else if(ina3221_init_status == INA3221::Status::STATUS_MFG_ID_ERROR)
        LOG("INA3221 MFG ID ERROR\n");
}

void pwr_mon::run(void){
    mgr.ina3221_ch1_value = mgr.ina3221.read_bus_voltage(INA3221::REG_ID_CH1_BUS);
    mgr.ina3221_ch2_value = mgr.ina3221.read_bus_voltage(INA3221::REG_ID_CH2_BUS);
    mgr.ina3221_ch3_value = mgr.ina3221.read_bus_voltage(INA3221::REG_ID_CH3_BUS);
    // mgr.ina226_1_value = mgr.ina226_1.read_bus_voltage();
    // mgr.ina226_2_value = mgr.ina226_2.read_bus_voltage();
    mgr.ina226_3_value = mgr.ina226_3.read_bus_voltage();
}

std::vector<std::string> pwr_mon::export_data(void){
    std::vector<std::string> result;
    std::string s;

    /* Result has to be property-value pair */
    result.push_back("Power cell #1 (Motor#1)");
    result.push_back(format_data(mgr.ina226_1_value)+"V");
    result.push_back("Power cell #2 (Motor#2)");
    result.push_back(format_data(mgr.ina226_2_value)+"V");
    result.push_back("Power cell #3 (ICs)    ");
    result.push_back(format_data(mgr.ina226_3_value)+"V");
    result.push_back("===============");
    result.push_back("===============");
    result.push_back("Power rail 3.3V        ");
    result.push_back(format_data(mgr.ina3221_ch1_value)+"V");
    result.push_back("Power rail 5V          ");
    result.push_back(format_data(mgr.ina3221_ch2_value)+"V");
    result.push_back("Power rail 12V         ");
    result.push_back(format_data(mgr.ina3221_ch3_value)+"V");
    return result;
}

std::string format_data(float val){
    std::stringstream ss;
    ss << std::fixed << std::setprecision(2) << val;
    return ss.str();
}