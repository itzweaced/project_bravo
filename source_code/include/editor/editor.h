#include <iostream>
#include <glm/glm.hpp>
#include <glad/glad.h> 

#include "module_properties.h"
#include "module_opengl.h"
#include "module_gameobjects.h"

#include <wx/wx.h>
#include <wx/glcanvas.h>

#define WINDOW_WIDTH 1800
#define WINDOW_HEIGHT 900

class guiMainFrame : public wxFrame
{
public:
    wxBoxSizer* mainSizer = new wxBoxSizer(wxHORIZONTAL);

    guiMainFrame() : wxFrame(nullptr, wxID_ANY, "Project Bravo", wxDefaultPosition, wxSize(WINDOW_WIDTH, WINDOW_HEIGHT))
    {

        ModuleGameobjects* moduleGameobjects =  new ModuleGameobjects(this);
        ModuleProperties* moduleProperties =  new ModuleProperties(this);

        ModuleOpengl* moduleOpengl = new ModuleOpengl(this , moduleGameobjects, moduleProperties);

        mainSizer->Add(moduleGameobjects, 0, wxEXPAND | wxALL, 5);
        mainSizer->Add(moduleProperties, 0, wxEXPAND | wxALL, 5);
        mainSizer->Add(moduleOpengl, 1, wxEXPAND | wxALL, 5);
        this->SetSizer(mainSizer);
    };
};

class App : public wxApp
{
public:
    bool OnInit() override
    {
        guiMainFrame* frame = new guiMainFrame();
        frame->Move(100,100);
        frame->Show();

        return true;
    };
};

wxIMPLEMENT_APP(App);