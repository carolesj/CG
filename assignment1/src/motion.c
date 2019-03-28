#include "../includes/motion.h"

/* -------------------------------- VARIABLES ------------------------------- */
float curAngle      = 0.0f; // Current Angle
float curVeloc      = 1.0f; // Current Velocity
float rotAccel      = 0.2f; // Rotation Acceleration
float velLimit      = 3.0f; // Velocity Limit
float prevVeloc     = 1.0f; // Previous velocity (store state when paused)

GLfloat positionX = 0;
GLfloat positionY = 0;

char stopped = '0';

float getCurAngle() {
    return curAngle;
}

/* -------------------------------- VARIABLES ------------------------------- */

/* -------------------------------- ANIMATIONS ------------------------------ */
void checkMaxVelocity() {
    // Keep velocity within treshold
    if (curVeloc > velLimit)
        curVeloc = velLimit;
    else if (curVeloc < -velLimit)
        curVeloc = -velLimit;
}
void animator() {
        // Keep velocity within treshold
        checkMaxVelocity();

        // Increase rotation
        if (stopped == '0') curAngle = curAngle + curVeloc;

        // Avoid overflow
        if (curAngle > 360) {
            curAngle = 0;
        } else if (curAngle < 0) {
            curAngle = 360;
        }
}
/* -------------------------------- ANIMATIONS ------------------------------ */

/* --------------------------------- MOTIONS -------------------------------- */
void increaseSpeed() {
        if (stopped == '0') {
                curVeloc = curVeloc + rotAccel;
                checkMaxVelocity();
                curAngle = curAngle + curVeloc;
        }

        if (curAngle > 360) {
            curAngle = 0;
        } else if (curAngle < 0) {
            curAngle = 360;
        }

        IF_DEBUG printf(">[ANIM]: Angle: %.2f, Velocity: %.2f\n", curAngle, curVeloc);
}

void decreaseSpeed() {
        if (stopped == '0') {
                curVeloc = curVeloc - rotAccel;
                checkMaxVelocity();
                curAngle = curAngle + curVeloc;
        }

        if (curAngle > 360) {
            curAngle = 0;
        } else if (curAngle < 0) {
            curAngle = 360;
        }

        IF_DEBUG printf(">[ANIM]: Angle: %.2f, Velocity: %.2f\n", curAngle, curVeloc);
}

void stop() {
        stopped = '1';
        prevVeloc = curVeloc;
}

void resume() {
        stopped = '0';
        curVeloc = prevVeloc;
}

/* --------------------------------- MOTIONS -------------------------------- */
