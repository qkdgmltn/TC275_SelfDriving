#include <stdio.h>

#define L               3
#define DEFAULT_SPEED   30
#define WALL_DISTANCE   5
#define WALL_MARGIN     1

typedef struct {
    float v_left;
    float v_right;
} velo_wheel;


float radius;
float ang_spd;
float left_velo;
float right_velo;
float dist;

/* sense the distance between car and wall by ToF sonsor */
float get_dist() {
    return dist;
}

/* sense the current velocity of left wheel speed by encoder */
float get_left() {
    return left_velo;
}

/* sense the current velocity of right wheel speed by encoder */
float get_right() {
    return right_velo;
}

/* calculate new wheel speed based on parameters */
velo_wheel calculate_speed(float velo_l, float velo_r, float distance) {

    velo_wheel new_wheel_velo;
    /* decide the trajectory */

    /* turn right */
    if (dist - WALL_DISTANCE < WALL_MARGIN) {
        radius = (velo_r + velo_l) / (2 * (velo_r - velo_l));
        ang_spd = (velo_r - velo_l) / L;

        new_wheel_velo.v_left = ang_spd * (radius + 0.5 * L);
        new_wheel_velo.v_right = ang_spd * (radius - 0.5 * L);
    }

    /* turn left */
    else if (dist - WALL_DISTANCE > WALL_MARGIN) {
        radius = (velo_l + velo_r) / (2 * (velo_l - velo_r));
        ang_spd = (velo_l - velo_r) / L;

        new_wheel_velo.v_left = ang_spd * (radius - 0.5 * L);
        new_wheel_velo.v_right = ang_spd * (radius + 0.5 * L);
    }
    /* go straight */
    else {
        new_wheel_velo.v_left = DEFAULT_SPEED;
        new_wheel_velo.v_right = DEFAULT_SPEED;
    }

    return new_wheel_velo;
}

void motor_turn(float left, float right) {

}

int main() {
    printf("Hello, World!\n");
    velo_wheel n_wheel;

    left_velo = get_left(); right_velo = get_right(); dist = get_dist();
    while(1) {
        /* calculate new speed */
        n_wheel = calculate_speed(left_velo, right_velo, dist);

        /* send the new wheel velocity to motor */
        motor_turn(n_wheel.v_left, n_wheel.v_right);

        /* change the velocity */
        dist = get_dist();
        left_velo = get_left();
        right_velo = get_right();
    }

    return 0;
}
