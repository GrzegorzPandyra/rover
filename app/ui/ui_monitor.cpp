#include <iostream>
#include <vector>
#include "calib.hpp"
#include <ncurses.h>
#include "ui_monitor.hpp"
#include "../ui/ui_logging.hpp"
#include "../dummy_app/dummy_app.hpp"
#include "../light_ctrlr/light_ctrlr.hpp"
#include "../pwtr_drv/pwtr_drv.hpp"
#include "../steer_sys_drv/steer_sys_drv.hpp"
#include "../veh/veh.hpp"
#include "../app/fan_ctrl/fan_ctrl.hpp"

/**************************************************************************
 *** Declarations
 *************************************************************************/

enum Monitor_Id{
    LIGHT_CONTROLLER = 0,
    POWERTRAIN,
    STEERING_SYSTEM,
    VEHICLE,
    POWER,
    DIAGNOSTIC
};

struct Monitor_T {
    Monitor_Id id;
    char name[20];
    mutable WINDOW * win;
    std::vector<std::string> (*get_app_data)();
};

static void update_monitor(Monitor_T);

/**************************************************************************
 *** Variables
 *************************************************************************/

static const Monitor_T monitors[] = {
    {LIGHT_CONTROLLER,  "LIGHT_CONTROLLER", NULL,  light_ctrlr::export_data},
    {POWERTRAIN,        "POWERTRAIN",       NULL,  pwtr_drv::export_data},
    {STEERING_SYSTEM,   "STEERING_SYSTEM",  NULL,  steer_sys_drv::export_data},
    {VEHICLE,           "VEHICLE",          NULL,  veh::export_data},
    {POWER,             "POWER",            NULL,  dummy_app::get_mon_data},
    {DIAGNOSTIC,        "DIAGNOSTIC",       NULL,  dummy_app::get_mon_data},

};

const uint8_t NUM_MONITORS = sizeof(monitors)/sizeof(monitors[0]);

/**************************************************************************
 *** Interface functions
 *************************************************************************/

/*
 * Initialize monitors
 */
void ui_monitor::init(void){
    monitors[LIGHT_CONTROLLER].win =    newwin(LIGHT_CONTROLLER_WIN_HEIGHT, LIGHT_CONTROLLER_WIN_WIDTH, LIGHT_CONTROLLER_WIN_Y, LIGHT_CONTROLLER_WIN_X  );
    monitors[POWERTRAIN].win =          newwin(POWERTRAIN_WIN_HEIGHT,       POWERTRAIN_WIN_WIDTH,       POWERTRAIN_WIN_Y,       POWERTRAIN_WIN_X        );
    monitors[STEERING_SYSTEM].win =     newwin(STEERING_SYSTEM_WIN_HEIGHT,  STEERING_SYSTEM_WIN_WIDTH,  STEERING_SYSTEM_WIN_Y,  STEERING_SYSTEM_WIN_X   );
    monitors[VEHICLE].win =             newwin(VEHICLE_WIN_HEIGHT,          VEHICLE_WIN_WIDTH,          VEHICLE_WIN_Y,          VEHICLE_WIN_X           );
    monitors[POWER].win =               newwin(POWER_WIN_HEIGHT,            POWER_WIN_WIDTH,            POWER_WIN_Y,            POWER_WIN_X             );
    monitors[DIAGNOSTIC].win =          newwin(DIAGNOSTIC_WIN_HEIGHT,       DIAGNOSTIC_WIN_WIDTH,       DIAGNOSTIC_WIN_Y,       DIAGNOSTIC_WIN_X        );
    
    LOG("SWC [ui_monitor] init\n");
}

/*
 * Iterate over all monitors
 */
void ui_monitor::run(void){
    for(uint8_t i=0; i<NUM_MONITORS; i++){
        if(NULL != monitors[i].get_app_data){
            update_monitor(monitors[i]);
        }
        box(monitors[i].win,0,0);
        mvwprintw(monitors[i].win, 0, 4, monitors[i].name);
        wrefresh(monitors[i].win);
    }
}

/* 
 * Print specific monitor according to defined format
 */
static void update_monitor(Monitor_T mon){
    std::vector<std::string> app_data = mon.get_app_data();
    for(uint8_t i=0u; i<app_data.size(); i+=2u){
        mvwprintw(mon.win, (i/2u)+1, 1, app_data[i].c_str());
        wprintw(mon.win, " : ");
        wprintw(mon.win, app_data[i+1u].c_str());
        wprintw(mon.win, "   "); /* Clear previously used fields */
    }
}