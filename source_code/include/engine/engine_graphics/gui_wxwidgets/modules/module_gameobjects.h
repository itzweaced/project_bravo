#ifndef MODULE_GAMEOBJECTS_H
#define MODULE_GAMEOBJECTS_H

#include <wx/wx.h>
#include <wx/glcanvas.h>

class ModuleGameobjects: public wxScrolledWindow
{
public:

    wxBoxSizer* boxSizer = new wxBoxSizer(wxVERTICAL);

    ModuleGameobjects(wxWindow* parent);
};

#endif