#include "module_gameobjects.h"

ModuleGameobjects::ModuleGameobjects(wxWindow* parent): wxScrolledWindow(parent, wxID_ANY, wxDefaultPosition, wxSize(200, 300), wxVSCROLL)
{
    wxStaticText* header = new wxStaticText(this, wxID_ANY, "", wxDefaultPosition, wxSize(200, -1));

    boxSizer->Add(header, 0, wxALIGN_CENTER_HORIZONTAL, 0);

    this->SetScrollRate(5, 5);
    this->SetSizer(boxSizer);
    boxSizer->FitInside(this);
    Layout();
};