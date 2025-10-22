#ifndef MOUSE_H
#define MOUSE_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "graphics.h"

class Mouse
{
private:
    Graphics* graphics;

public:
    Mouse(Graphics* setGraphics, float WINDOW_WIDTH, float WINDOW_HEIGHT);

public:
    float cursor_last_xPos;
    float cursor_last_yPos;
    
    static bool cursor_active;
    static float cursor_xPos;
    static float cursor_yPos;

    static bool scroll_active;
    static float scroll_yPos;

public:

    static void mouse_callback(GLFWwindow *window, double xPos, double yPos);
    static void scroll_callback(GLFWwindow *window, double xoffset, double yoffset);
};

#endif