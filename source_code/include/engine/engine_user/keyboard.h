#ifndef KEYBOARD_H
#define KEYBOARD_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "graphics.h"

class Keyboard
{
private:
    Graphics* graphics;

public:
    Keyboard(Graphics* setGraphics)
    {
        graphics = setGraphics;
    };

    int inputKeyboard()
    {
        if(glfwGetKey(graphics->window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
            return 101;
        if(glfwGetKey(graphics->window, GLFW_KEY_F1) == GLFW_PRESS)
            return 102;
        if(glfwGetKey(graphics->window, GLFW_KEY_F2) == GLFW_PRESS)
            return 103;
        if(glfwGetKey(graphics->window, GLFW_KEY_F3) == GLFW_PRESS)
            return 104;
        if(glfwGetKey(graphics->window, GLFW_KEY_F4) == GLFW_PRESS)
            return 105;
        if(glfwGetKey(graphics->window, GLFW_KEY_F5) == GLFW_PRESS)
            return 106;
        if(glfwGetKey(graphics->window, GLFW_KEY_F6) == GLFW_PRESS)
            return 107;
        if(glfwGetKey(graphics->window, GLFW_KEY_F7) == GLFW_PRESS)
            return 108;
        if(glfwGetKey(graphics->window, GLFW_KEY_F8) == GLFW_PRESS)
            return 109;
        if(glfwGetKey(graphics->window, GLFW_KEY_F9) == GLFW_PRESS)
            return 110;
        if(glfwGetKey(graphics->window, GLFW_KEY_F10) == GLFW_PRESS)
            return 111;
        if(glfwGetKey(graphics->window, GLFW_KEY_F11) == GLFW_PRESS)
            return 112;
        if(glfwGetKey(graphics->window, GLFW_KEY_F12) == GLFW_PRESS)
            return 113;

        if(glfwGetKey(graphics->window, GLFW_KEY_GRAVE_ACCENT) == GLFW_PRESS)
            return 114;
        if(glfwGetKey(graphics->window, GLFW_KEY_1) == GLFW_PRESS)
            return 115;
        if(glfwGetKey(graphics->window, GLFW_KEY_2) == GLFW_PRESS)
            return 116;
        if(glfwGetKey(graphics->window, GLFW_KEY_3) == GLFW_PRESS)
            return 117;
        if(glfwGetKey(graphics->window, GLFW_KEY_4) == GLFW_PRESS)
            return 118;
        if(glfwGetKey(graphics->window, GLFW_KEY_5) == GLFW_PRESS)
            return 119;
        if(glfwGetKey(graphics->window, GLFW_KEY_6) == GLFW_PRESS)
            return 120;
        if(glfwGetKey(graphics->window, GLFW_KEY_7) == GLFW_PRESS)
            return 121;
        if(glfwGetKey(graphics->window, GLFW_KEY_8) == GLFW_PRESS)
            return 122;
        if(glfwGetKey(graphics->window, GLFW_KEY_9) == GLFW_PRESS)
            return 123;
        if(glfwGetKey(graphics->window, GLFW_KEY_0) == GLFW_PRESS)
            return 124;
        if(glfwGetKey(graphics->window, GLFW_KEY_MINUS) == GLFW_PRESS)
            return 125;
        if(glfwGetKey(graphics->window, GLFW_KEY_EQUAL) == GLFW_PRESS)
            return 126;
        if(glfwGetKey(graphics->window, GLFW_KEY_BACKSPACE) == GLFW_PRESS)
            return 127;

        if(glfwGetKey(graphics->window, GLFW_KEY_TAB) == GLFW_PRESS)
            return 128;
        if(glfwGetKey(graphics->window, GLFW_KEY_Q) == GLFW_PRESS)
            return 129;
        if(glfwGetKey(graphics->window, GLFW_KEY_W) == GLFW_PRESS)
            return 130;
        if(glfwGetKey(graphics->window, GLFW_KEY_E) == GLFW_PRESS)
            return 131;
        if(glfwGetKey(graphics->window, GLFW_KEY_R) == GLFW_PRESS)
            return 132;
        if(glfwGetKey(graphics->window, GLFW_KEY_T) == GLFW_PRESS)
            return 133;
        if(glfwGetKey(graphics->window, GLFW_KEY_Y) == GLFW_PRESS)
            return 134;
        if(glfwGetKey(graphics->window, GLFW_KEY_U) == GLFW_PRESS)
            return 135;
        if(glfwGetKey(graphics->window, GLFW_KEY_I) == GLFW_PRESS)
            return 136;
        if(glfwGetKey(graphics->window, GLFW_KEY_O) == GLFW_PRESS)
            return 137;
        if(glfwGetKey(graphics->window, GLFW_KEY_P) == GLFW_PRESS)
            return 138;
        if(glfwGetKey(graphics->window, GLFW_KEY_LEFT_BRACKET) == GLFW_PRESS)
            return 139;
        if(glfwGetKey(graphics->window, GLFW_KEY_RIGHT_BRACKET) == GLFW_PRESS)
            return 140;
        if(glfwGetKey(graphics->window, GLFW_KEY_BACKSLASH) == GLFW_PRESS)
            return 141;

        if(glfwGetKey(graphics->window, GLFW_KEY_CAPS_LOCK) == GLFW_PRESS)
            return 142;
        if(glfwGetKey(graphics->window, GLFW_KEY_A) == GLFW_PRESS)
            return 143;
        if(glfwGetKey(graphics->window, GLFW_KEY_S) == GLFW_PRESS)
            return 144;
        if(glfwGetKey(graphics->window, GLFW_KEY_D) == GLFW_PRESS)
            return 145;
        if(glfwGetKey(graphics->window, GLFW_KEY_F) == GLFW_PRESS)
            return 146;
        if(glfwGetKey(graphics->window, GLFW_KEY_G) == GLFW_PRESS)
            return 147;
        if(glfwGetKey(graphics->window, GLFW_KEY_H) == GLFW_PRESS)
            return 148;
        if(glfwGetKey(graphics->window, GLFW_KEY_J) == GLFW_PRESS)
            return 149;
        if(glfwGetKey(graphics->window, GLFW_KEY_K) == GLFW_PRESS)
            return 150;
        if(glfwGetKey(graphics->window, GLFW_KEY_L) == GLFW_PRESS)
            return 151;
        if(glfwGetKey(graphics->window, GLFW_KEY_SEMICOLON) == GLFW_PRESS)
            return 152;
        if(glfwGetKey(graphics->window, GLFW_KEY_APOSTROPHE) == GLFW_PRESS)
            return 153;
        if(glfwGetKey(graphics->window, GLFW_KEY_ENTER) == GLFW_PRESS)
            return 154;

        if(glfwGetKey(graphics->window, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS)
            return 155;
        if(glfwGetKey(graphics->window, GLFW_KEY_Z) == GLFW_PRESS)
            return 156;
        if(glfwGetKey(graphics->window, GLFW_KEY_X) == GLFW_PRESS)
            return 157;
        if(glfwGetKey(graphics->window, GLFW_KEY_C) == GLFW_PRESS)
            return 158;
        if(glfwGetKey(graphics->window, GLFW_KEY_V) == GLFW_PRESS)
            return 159;
        if(glfwGetKey(graphics->window, GLFW_KEY_B) == GLFW_PRESS)
            return 160;
        if(glfwGetKey(graphics->window, GLFW_KEY_N) == GLFW_PRESS)
            return 161;
        if(glfwGetKey(graphics->window, GLFW_KEY_M) == GLFW_PRESS)
            return 162;
        if(glfwGetKey(graphics->window, GLFW_KEY_COMMA) == GLFW_PRESS)
            return 163;
        if(glfwGetKey(graphics->window, GLFW_KEY_PERIOD) == GLFW_PRESS)
            return 164;
        if(glfwGetKey(graphics->window, GLFW_KEY_SLASH) == GLFW_PRESS)
            return 165;
        if(glfwGetKey(graphics->window, GLFW_KEY_RIGHT_SHIFT) == GLFW_PRESS)
            return 166;

        if(glfwGetKey(graphics->window, GLFW_KEY_LEFT_ALT) == GLFW_PRESS)
            return 167;
        if(glfwGetKey(graphics->window, GLFW_KEY_LEFT_CONTROL) == GLFW_PRESS)
            return 168;
        if(glfwGetKey(graphics->window, GLFW_KEY_SPACE) == GLFW_PRESS)
            return 169;
        if(glfwGetKey(graphics->window, GLFW_KEY_RIGHT_ALT) == GLFW_PRESS)
            return 170;
        if(glfwGetKey(graphics->window, GLFW_KEY_RIGHT_CONTROL) == GLFW_PRESS)
            return 171;

        if(glfwGetKey(graphics->window, GLFW_KEY_LEFT) == GLFW_PRESS)
            return 172;
        if(glfwGetKey(graphics->window, GLFW_KEY_RIGHT) == GLFW_PRESS)
            return 173;
        if(glfwGetKey(graphics->window, GLFW_KEY_DOWN) == GLFW_PRESS)
            return 174;
        if(glfwGetKey(graphics->window, GLFW_KEY_UP) == GLFW_PRESS)
            return 175;

        return 100;
    };

};

#endif