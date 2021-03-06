#ifndef SCENE_H
#define SCENE_H

/*
* Handles scene drawing and animations
*/

#include <GL/glut.h>
#include "../includes/SOIL/SOIL.h"
#include "shapes.h"
#include "transforms.h"
#include "motion.h"
#include "settings.h"

/* -------------------------------- INPUT ----------------------------------- */
void on_mouseClick(int button, int click_state,
    int x_mouse_position, int y_mouse_position);
void mouseHold();
void keyPress(unsigned char key, int x, int y);
/* -------------------------------- INPUT ----------------------------------- */

/* -------------------------------- TEXTURES ---------------------------------- */
GLuint background_texture, cloud_texture, goku_texture;
GLuint loadTexture(const char *filename);
/* -------------------------------- TEXTURES ---------------------------------- */

/* -------------------------------- WINDOW ---------------------------------- */
void reshape(int width, int height);
/* -------------------------------- WINDOW ---------------------------------- */

/* ----------------------------- SCENE DRAWING ------------------------------ */
void drawLoop();
/* ----------------------------- SCENE DRAWING ------------------------------ */

#endif
