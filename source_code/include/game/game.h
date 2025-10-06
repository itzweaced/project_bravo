#ifndef GAME_H
#define GAME_H


#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <Windows.h>
#include <mmsystem.h>

#include "camera.h"
#include "shader.h"
#include "model.h"
#include "graphics.h"
#include "gameobject.h"
#include "rigid_body.h"
#include "collider.h"
#include "collision.h"
#include "geometry.h"
#include "project_save.h"
#include "project_load.h"
#include "network_server.h"
#include "user_input.h"
#include "raycast.h"

#pragma comment(lib, "winmm.lib")

#define WINDOW_WIDTH 1800
#define WINDOW_HEIGHT 900

#define MAP_WIDTH 1000.0f
#define MAP_HEIGHT 1000.0f
#define MAP_DEPTH 1000.0f


class Game
{
private:
    std::vector<Shader*> loaded_shaders;

    std::vector<Model*> loaded_models;
    std::vector<Geometry*> loaded_geometry;
    std::vector<GameObject*> loaded_gameobjects;

    std::vector<GameObject*> loaded_players;
    std::vector<GameObject*> loaded_cameras;

    std::vector<GameObject*> loaded_colliders_floors;
    std::vector<GameObject*> loaded_colliders_walls;
    std::vector<GameObject*> loaded_colliders_portals;

    std::vector<GameObject*> loaded_colliders_targets;

private:
    std::vector<Collider*> colliders_floors;
    std::vector<Collider*> colliders_walls;
    std::vector<Collider*> colliders_portals;

    std::vector<Collider*> colliders_targets;

private:
    bool sceneReset = false;
    glm::vec3 resetCameraPosition;

private:
    glm::vec3 map_dimmensions = glm::vec3(MAP_WIDTH, MAP_HEIGHT, MAP_DEPTH);

    Graphics graphics;
    Camera camera;

    bool mouseLeftClick = true;
    float lastX = WINDOW_WIDTH / 2.0f;
    float lastY = WINDOW_HEIGHT/ 2.0f;

    
    bool shoot = false;


private:
    void initiate();
    void reset();
    void mainloop();

    void processInput(GLFWwindow *window, GameObject *gameobject);
    static void mouse_callback(GLFWwindow *window, double xPos, double yPos);
    static void scroll_callback(GLFWwindow *window, double xoffset, double yoffset);

public:
    Game();
    ~Game();
    void play();

};

#endif