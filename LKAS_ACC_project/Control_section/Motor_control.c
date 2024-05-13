#include "Motor_control.h"
#include <Sensor_input/Tof.h>

float radius;
float ang_spd;
float left_velo;
float right_velo;


velo_wheel cur_velo_wheel;

void calculate_speed(float velo_l, float velo_r) {

    velo_wheel new_wheel_velo;
    /* decide the trajectory */

    /* turn right */
    if (distance - DEFAULT_WALL_DISTANCE < WALL_MARGIN*(-1)) {
        if(velo_l != velo_r){
            radius = (velo_r + velo_l)*TIRE_L / (2 * (velo_r - velo_l));
            ang_spd = (velo_r + velo_l) / 2* radius;

            new_wheel_velo.v_left = ang_spd * (radius + 0.5 * TIRE_L);
            new_wheel_velo.v_right = ang_spd * (radius - 0.5 * TIRE_L);
        }
        else{
            radius = 10;
            ang_spd = (velo_r + velo_l) / 2* radius;

            new_wheel_velo.v_left = ang_spd * (radius + 0.5 * TIRE_L);
            new_wheel_velo.v_right = ang_spd * (radius - 0.5 * TIRE_L);
        }
    }

    /* turn left */
    else if (distance - DEFAULT_WALL_DISTANCE > WALL_MARGIN) {
        if(velo_l != velo_r){
            radius = (velo_r + velo_l)*TIRE_L / (2 * (velo_r - velo_l));
            ang_spd = (velo_r + velo_l) / 2* radius;

            new_wheel_velo.v_left = ang_spd * (radius - 0.5 * TIRE_L);
            new_wheel_velo.v_right = ang_spd * (radius + 0.5 * TIRE_L);
        }
        else{
            radius = 10;
            ang_spd = (velo_r + velo_l) / 2* radius;

            new_wheel_velo.v_left = ang_spd * (radius - 0.5 * TIRE_L);
            new_wheel_velo.v_right = ang_spd * (radius + 0.5 * TIRE_L);
        }
    }
    /* go straight */
    else {
        new_wheel_velo.v_left = DEFAULT_SPEED;
        new_wheel_velo.v_right = DEFAULT_SPEED;
    }

    cur_velo_wheel = new_wheel_velo;
}
