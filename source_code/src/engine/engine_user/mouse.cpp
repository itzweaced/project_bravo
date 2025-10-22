#include "mouse.h"

bool Mouse::cursor_active = false;
float Mouse::cursor_xPos = 0.0f;
float Mouse::cursor_yPos = 0.0f;

bool Mouse::scroll_active = false;
float Mouse::scroll_yPos = 0.0f;

Mouse::Mouse(Graphics* setGraphics, float WINDOW_WIDTH, float WINDOW_HEIGHT)
{
    graphics = setGraphics;

    cursor_last_xPos = WINDOW_WIDTH / 2.0f;
    cursor_last_yPos = WINDOW_HEIGHT/ 2.0f;
};


void Mouse::mouse_callback(GLFWwindow *window, double xPos, double yPos)
{
    Mouse* mouse = static_cast<Mouse*>(glfwGetWindowUserPointer(window));

    cursor_active = true;
    cursor_xPos = xPos - mouse->cursor_last_xPos;
    cursor_yPos = mouse->cursor_last_yPos - yPos;
    
    mouse->cursor_last_xPos = xPos;
    mouse->cursor_last_yPos = yPos;
};

void Mouse::scroll_callback(GLFWwindow *window, double xoffset, double yoffset)
{
    Mouse* mouse = static_cast<Mouse*>(glfwGetWindowUserPointer(window));
    scroll_active = true;
    scroll_yPos = yoffset;
};