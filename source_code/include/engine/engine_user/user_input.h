#ifndef USER_INPUT_H
#define USER_INPUT_H

#include <GLFW/glfw3.h>


class UserInput
{
private:
    GLFWwindow* window;

public:
    UserInput(GLFWwindow* setWindow);

public:
    int inputKeyboard();
};


#endif