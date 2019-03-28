#include "../includes/scene.h"

/* -------------------------------- INPUT ----------------------------------- */

// KEYBOARD EVENT HANDLING
void keyPress(unsigned char key, int x, int y) 
{
        if (key == 'Q' || key == 'q') {
                // Decreases rotation speed
                decreaseSpeed();
        } else if (key == 'E' || key == 'e') {
                // Increases rotation speed
                increaseSpeed();
        } else if (key == 'W' || key == 'w') {
                // Move up
                positionY += 5.0f;
                IF_DEBUG printf(">[ANIM]: UP DeltaX: %.1f DeltaY: %.1f\n", positionX, positionY);
        } else if (key == 'S' || key == 's') {
                // Move down
                positionY -= 5.0f;
                IF_DEBUG printf(">[ANIM]: DOWN DeltaX: %.1f DeltaY: %.1f\n", positionX, positionY);                
        } else if (key == 'A' || key == 'a') {
                // Move left
                positionX -= 5.0f;
                IF_DEBUG printf(">[ANIM]: LEFT DeltaX: %.1f DeltaY: %.1f\n", positionX, positionY);                
        } else if (key == 'D' || key == 'd') {
                // Move right
                positionX += 5.0f;
                IF_DEBUG printf(">[ANIM]: RIGHT DeltaX: %.1f DeltaY: %.1f\n", positionX, positionY);                
        } else if (key == ' ') {
                if (stopped == '0') {
                        printf(">[ANIM] Stopping rotation...");
                        stop();
                } else {
                        printf(">[ANIM] Resuming rotation...");
                        resume();
                }
        }
}

/* -------------------------------- INPUT ----------------------------------- */

/* -------------------------------- WINDOW ---------------------------------- */
void reshape(int width, int height)
{
    // Screen can't be smaller than 0
    if (height == 0)
        height = 1;

    float ratio = width * 1.0/height;

    // Changes matrix mode to projection
    glMatrixMode(GL_PROJECTION);

    // Reset Matrix
    glLoadIdentity();

    // Viewport correction
    glViewport(0, 0, width, height);

    // Perspective and projection correction
    gluOrtho2D(-ORTHO_X * ratio, ORTHO_X * ratio, -ORTHO_Y, ORTHO_Y);

    // Switches matrix mode back to modelview
    glMatrixMode(GL_MODELVIEW);
}
/* -------------------------------- WINDOW ---------------------------------- */

/* ----------------------------- TEXTURES ------------------------------ */
GLuint loadTexture(const char *filename)
{
        GLuint tex = SOIL_load_OGL_texture(filename,
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y);
        if (!tex) {
                return -1;
        }
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	return tex;
}
/* ----------------------------- TEXTURES ------------------------------ */

/* ----------------------------- SCENE DRAWING ------------------------------ */
void drawScene()
{
        // Load matrix mode
        glMatrixMode(GL_MODELVIEW);

        /*--------------------BACKGROUND--------------------*/
        glLoadIdentity();

        // Bind texture to quad
        glBindTexture(GL_TEXTURE_2D, background_texture);
        int bgX = VIEWPORT_X;
        int bgY = VIEWPORT_Y;
        // Start texturing
        glEnable(GL_TEXTURE_2D);
        glBegin(GL_QUADS);
            glTexCoord2f(0, 0);
                glVertex2f(-bgX, -bgY);
            glTexCoord2f(0, 1);
                glVertex2f(-bgX, bgY);
            glTexCoord2f(1, 1);
                glVertex2f(bgX, bgY);
            glTexCoord2f(1, 0);
                glVertex2f(bgX, -bgY);
    	glEnd();
        glDisable(GL_TEXTURE_2D);

        /*--------------------END--------------------*/

        /*--------------------PINWHEEL-------------------*/

        glLoadIdentity();
        Quadrilateral *pole = createQuad();
                // setQuadCoordinates(pole, -50.0f, 50.0f, 50.0f, 50.0f, 100.0f, -250.0f, -100.0f, -250.0f);
                setQuadCoordinates(pole, -10.0f, 10.0f, 10.0f, 10.0f, 10.0f, -300.f, -10.0f, -300.0f);
                setQuadColor(pole, 0.57f, 0.36f, 0.29f); // rgb(145,91,74)
                glTranslatef(positionX, positionY, 0.0f);
                drawQuadFilled(pole);
        freeQuad(pole);
        /*--------------------END--------------------*/

        /*--------------------PADS--------------------*/

        glLoadIdentity();
        Triangle *pad1 = createTriangle();
                setTriangleCoordinates(pad1, 0.0f, 0.0f, 100.0f, 200.0f, 0.0f, 100.0f);
                glTranslatef(positionX, positionY, 0.0f);
                setTriangleColor(pad1, 1.0f, 0.87f, 0.51f);
                setTriangleThickness(pad1, 5.0f);
                rotateTriangleVertex(pad1, getCurAngle(), 1);
                drawTriangleFilled(pad1);
        freeTriangle(pad1);

        glLoadIdentity();
        Triangle *pad2 = createTriangle();
                setTriangleCoordinates(pad2, 0.0f, 0.0f, 200.0f, -100.0f, 100.0f, 0.0f);
                glTranslatef(positionX, positionY, 0.0f);
                setTriangleColor(pad2, 1.0f, 0.83f, 0.31f);
                setTriangleThickness(pad2, 5.0f);
                rotateTriangleVertex(pad2, getCurAngle(), 1);
                drawTriangleFilled(pad2);
        freeTriangle(pad2);

        glLoadIdentity();
        Triangle *pad3 = createTriangle();
                setTriangleCoordinates(pad3, 0.0f, 0.0f, -100.0f, -200.0f, 0.0f, -100.0f);
                glTranslatef(positionX, positionY, 0.0f);                
                setTriangleColor(pad3, 1.0f, 0.79f, 0.15f);
                setTriangleThickness(pad3, 5.0f);
                rotateTriangleVertex(pad3, getCurAngle(), 1);
                drawTriangleFilled(pad3);
        freeTriangle(pad3);

        glLoadIdentity();
        Triangle *pad4 = createTriangle();
                setTriangleCoordinates(pad4, 0.0f, 0.0f, -200.0f, 100.0f, -100.0f, 0.0f);
                glTranslatef(positionX, positionY, 0.0f);
                setTriangleColor(pad4, 1.0f, 0.70f, 0.0f);
                setTriangleThickness(pad4, 5.0f);
                rotateTriangleVertex(pad4, getCurAngle(), 1);
                drawTriangleFilled(pad4);
        freeTriangle(pad4);

        glLoadIdentity();
        // Joint of windmill pole
        Quadrilateral *joint = createQuad();
                setQuadCoordinates(joint, -10.0f, 10.0f, 10.0f, 10.0f, 10.0f, -10.0f, -10.0f, -10.0f);
                glTranslatef(positionX, positionY, 0.0f);
                setQuadColor(joint, 0.98f, 0.55f, 0.0f);
                rotateQuadCenter(joint, getCurAngle());
                drawQuadFilled(joint);
        freeQuad(joint);

        /*--------------------END--------------------*/

}

void drawLoop()
{
        // Background color
        glClearColor(0.0f, 0.0f, 0.0f, 1);
        glColor3f(1.0f, 1.0f, 1.0f);

        // Repaint screen
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        // Draw scene
        drawScene();

        // Animator
        animator();

        // Clear buffer
        glutSwapBuffers();
}
/* ----------------------------- SCENE DRAWING ------------------------------ */
