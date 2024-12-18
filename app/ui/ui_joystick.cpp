#include <iostream>
#include <linux/joystick.h>
#include "ui_joystick.hpp"
#include "../../cfg/calib.hpp"
#include "../ui/ui_logging.hpp"

static void axis_event_handler(js_event event);
static void button_event_handler(js_event event);
static inline char bool_to_char(bool b);

static FILE *js_ptr;
static ui_joystick::Js_Input_T js_input;

void ui_joystick::init(void){
    LOG("SWC [ui_joystick] init\n");
    js_ptr = fopen(JS_DEV_PATH,"w+b");
    if(js_ptr == nullptr){
        LOG("Failed to get handle for joystick device");
    }
}

void ui_joystick::deinit(void){
    if(js_ptr != nullptr){
        fclose(js_ptr);
    }
}

void ui_joystick::run(void){
    js_event event;
    int8_t eof = false;
    if(js_ptr != nullptr){
        eof = fread(&event, sizeof(js_event), 1, js_ptr);
        if(eof == 0){
            LOG("EOF\n");
        }
        // LOG_FORMATED_2("%x %x\n", event.number, event.value);
        switch (event.type){
        case JS_EVENT_BUTTON:
            button_event_handler(event);
            break;
        case JS_EVENT_AXIS:
            axis_event_handler(event);
            break;
        default:
            break;
        }
    } else {
        LOG("Failed to get handle for joystick device");
    }
}

ui_joystick::Js_Input_T ui_joystick::get_inputs(void){
    return js_input;
}

std::vector<std::string> ui_joystick::export_data(void){
    using std::vector;
    using std::string;
    vector<string> result;
    string s;

    /* Result has to be property-value pair */
    /* XYAB buttons */
    result.push_back(" X | Y | A | B    ");
    s += bool_to_char(js_input.btn_x);
    s += '|';
    s += bool_to_char(js_input.btn_y);
    s += '|';
    s += bool_to_char(js_input.btn_a);
    s += '|';
    s += bool_to_char(js_input.btn_b);
    result.push_back(s);

    /* LR Sticks */
    result.push_back("L-stick-H/V       ");
    result.push_back(std::to_string(js_input.axis_lstick_h)+"/"+std::to_string(js_input.axis_lstick_v));
    result.push_back("R-stick-H/V       ");
    result.push_back(std::to_string(js_input.axis_rstick_h)+"/"+std::to_string(js_input.axis_rstick_v));
    result.push_back("Stick button L/R  ");
    result.push_back(std::to_string(js_input.btn_lstick)+"/"+std::to_string(js_input.btn_rstick));

    /* DPAD */
    result.push_back("Dpad axis-H/V     ");
    result.push_back(std::to_string(js_input.axis_dpad_h)+"/"+std::to_string(js_input.axis_dpad_v));

    /* Bumpers */
    result.push_back("Top-bumpers L/R   ");
    result.push_back(std::to_string(js_input.btn_l1)+"/"+std::to_string(js_input.btn_r1));
    result.push_back("Btm-bumpers L/R   ");
    result.push_back(std::to_string(js_input.btn_l2)+"/"+std::to_string(js_input.btn_r2));

    /* Misc */
    result.push_back("Select/Start      ");
    result.push_back(std::to_string(js_input.btn_select)+"/"+std::to_string(js_input.btn_start));

    return result;
}

static inline char bool_to_char(bool b){
    return (b?'1':'0');
}

static void button_event_handler(js_event event){
    switch (event.number)
    {
    case JS_BTN_X:
        js_input.btn_x = (bool)event.value;
        break;
    case JS_BTN_Y:
        js_input.btn_y = (bool)event.value;
        break;
    case JS_BTN_A:
        js_input.btn_a = (bool)event.value;
        break;
    case JS_BTN_B:
        js_input.btn_b = (bool)event.value;
        break;
    case JS_BTN_R1:
        js_input.btn_r1 = (bool)event.value;
        break;
    case JS_BTN_R2:
        js_input.btn_r2 = (bool)event.value;
        break;
    case JS_BTN_L1:
        js_input.btn_l1 = (bool)event.value;
        break;
    case JS_BTN_L2:
        js_input.btn_l2 = (bool)event.value;
        break;
    case JS_BTN_LSTICK:
        js_input.btn_lstick = (bool)event.value;
        break;
    case JS_BTN_RSTICK:
        js_input.btn_rstick = (bool)event.value;
        break;
    case JS_BTN_SELECT:
        js_input.btn_select = (bool)event.value;
        break;
    case JS_BTN_START:
        js_input.btn_start = (bool)event.value;
        break;
    default:
        break;
    }
}

static void axis_event_handler(js_event event){
    switch (event.number){
    case JS_AXIS_LSTICK_H:
        js_input.axis_lstick_h = event.value;
        break;
    case JS_AXIS_LSTICK_V:
        js_input.axis_lstick_v = event.value;
        break;
    case JS_AXIS_RSTICK_H:
        js_input.axis_rstick_h = event.value;
        break;
    case JS_AXIS_RSTICK_V:
        js_input.axis_rstick_v = event.value;
        break;
    case JS_AXIS_DPAD_H:
        js_input.axis_dpad_h = event.value;
        break;
    case JS_AXIS_DPAD_V:
        js_input.axis_dpad_v = event.value;
        break;
    default:
        break;
    }
}