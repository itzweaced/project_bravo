#ifndef MODULE_OPENGL_H
#define MODULE_OPENGL_H

#include "component_opengl_canvas.h"
#include "module_gameobjects.h"
#include "module_properties.h"

#include <wx/wx.h>
#include <wx/glcanvas.h>

class ModuleOpengl: public wxPanel
{
public:
    ComponentOpenglCanvas* canvas;
    wxBoxSizer* boxSizer = new wxBoxSizer(wxVERTICAL);

    ModuleOpengl(wxWindow* parent , ModuleGameobjects* moduleGameobjects , ModuleProperties* moduleProperties);
};

#endif