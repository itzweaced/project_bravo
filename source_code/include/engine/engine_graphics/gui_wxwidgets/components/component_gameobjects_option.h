#ifndef COMPONENT_GAMEOBJECTS_OPTION_H
#define COMPONENT_GAMEOBJECTS_OPTION_H

#include <memory>

#include "gameobject.h"

#include <wx/wx.h>
#include <wx/glcanvas.h>

class ComponentGameobjectsOption: public wxPanel
{
private:
    GameObject* handleGameObject;

public:
    int ID;
    
    ComponentGameobjectsOption(wxWindow* parent, int id , GameObject* gameobject);
    ~ComponentGameobjectsOption(){delete this;};
    void click(wxMouseEvent& event);
    void hover(wxMouseEvent& event);
    void unhover(wxMouseEvent& event);
};

#endif