#ifndef COMPONENT_OPENGLCANVAS_H
#define COMPONENT_OPENGLCANVAS_H

#include <iostream>
#include <string>
#include <vector>
#include <glm/glm.hpp>
#include <glad/glad.h>

#include "camera.h"
#include "shader.h"
#include "model.h"
#include "gameobject.h"

#include <wx/wx.h>
#include <wx/glcanvas.h>

#include "module_gameobjects.h"
#include "module_properties.h"

#include "component_gameobjects_option.h"

#include "project_load.h"
#include "project_save.h"

#define MY_GET_PROC_ADDRESS wglGetProcAddress

#define PI 3.14159265358979323846f

#define OPENGL_WINDOW_WIDTH 1800
#define OPENGL_WINDOW_HEIGHT 900

#define MAP_WIDTH 1000.0f
#define MAP_HEIGHT 1000.0f
#define MAP_DEPTH 1000.0f

#define MAP_DIMMENSIONS glm::vec3(MAP_WIDTH, MAP_HEIGHT, MAP_DEPTH)

class ComponentOpenglCanvas : public wxGLCanvas
{
private:
    ModuleGameobjects* handleModuleGameobjects;
    ModuleProperties* handleModuleProperties;
    wxGLContext* context;
    Camera camera;
    bool initiated = false;

private:
    void OnPaint(wxPaintEvent& event);
    void render();
    void test();
    void initiateGameobjects();
    void createComponentsGameobjectsOptions();
    void generateGameobjects(std::vector<std::vector<std::string>> files);
private:
    std::vector<Shader*> loaded_shaders;
    std::vector<Model*> loaded_models;

public:
    std::vector<GameObject*> gameobjects;

    ComponentOpenglCanvas(wxWindow* parent , ModuleGameobjects* moduleGameobjects, ModuleProperties* moduleProperties);
    ~ComponentOpenglCanvas();
};

#endif