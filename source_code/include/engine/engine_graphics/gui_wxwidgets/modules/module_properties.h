#ifndef MODULE_PROPERTIES_H
#define MODULE_PROPERTIES_H

#include <vector>
#include <string>

#include "gameobject.h"

#include <wx/wx.h>
#include <wx/glcanvas.h>


class ModuleProperties: public wxPanel
{
public:

    std::vector<GameObject*> handleGameobjects;


    std::string type = "";
    std::string name = "";

    std::string pathVertexShader = "";
    std::string pathFragmentShader = "";
    std::string pathModel = "";

    float xPos = 0.0f;
    float yPos = 0.0f;
    float zPos = 0.0f;

    float xScale = 0.0f;
    float yScale = 0.0f;
    float zScale = 0.0f;

    float xRotation = 0.0f;
    float yRotation = 0.0f;
    float zRotation = 0.0f;

    bool enableRender = false;


    ModuleProperties(wxWindow* parent);
};

#endif