#include "module_opengl.h"


ModuleOpengl::ModuleOpengl(wxWindow* parent , ModuleGameobjects* moduleGameobjects, ModuleProperties* moduleProperties): wxPanel(parent)
{
    canvas = new ComponentOpenglCanvas(this , moduleGameobjects, moduleProperties );

    boxSizer->Add(canvas, 1, wxEXPAND | wxALL, 5);

    this->SetSizer(boxSizer);
};