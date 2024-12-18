#ifndef UI_JOYSTICK_H
#define UI_JOYSTICK_H

#include <vector>

namespace ui_joystick{
    struct Js_Input_T{
        bool btn_x;
        bool btn_y;
        bool btn_a;
        bool btn_b;
        bool btn_r1;
        bool btn_r2;
        bool btn_l1;
        bool btn_l2;
        bool btn_lstick;
        bool btn_rstick;
        bool btn_select;
        bool btn_start;
        int16_t axis_lstick_h;
        int16_t axis_lstick_v;
        int16_t axis_rstick_h;
        int16_t axis_rstick_v;
        int16_t axis_dpad_h;
        int16_t axis_dpad_v;
    };
    void init(void);
    void deinit(void);
    void run(void);
    Js_Input_T get_inputs(void);
    std::vector<std::string> export_data(void);
}

#endif