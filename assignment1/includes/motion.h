#ifndef PHYSICS_H
#define PHYSICS_H

/*
* Handles rotation and velocity calculations
* for animations
*/

#include <stdio.h>
#include "scene.h"
#include "settings.h"

extern GLfloat positionX;
extern GLfloat positionY; 
extern char stopped;

/* -------------------------------- VARIABLES ------------------------------- */
float getCurAngle();
/* -------------------------------- VARIABLES ------------------------------- */

/* --------------------------------- MOTIONS -------------------------------- */
void animator();
void increaseSpeed();
void decreaseSpeed();
void stop();
void resume();
/* --------------------------------- MOTIONS -------------------------------- */

#endif
