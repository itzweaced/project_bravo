#include "component_gameobjects_option.h"



ComponentGameobjectsOption::ComponentGameobjectsOption(wxWindow* parent, int id, GameObject* gameobject): wxPanel(parent, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxBORDER_SIMPLE)
{
    ID = id;

    //handleGameObject = gameobject;

    wxStaticText* label_1 = new wxStaticText(this, wxID_ANY, gameobject->returnType(), wxDefaultPosition, wxSize(200, -1));
    wxStaticText* label_2 = new wxStaticText(this, wxID_ANY, gameobject->returnName(), wxDefaultPosition, wxSize(200, -1));

    wxBoxSizer* boxSizer = new wxBoxSizer(wxVERTICAL);

    boxSizer->Add(label_1, 0, wxALL, 1);
    boxSizer->Add(label_2, 0, wxALL, 1);

    this->SetBackgroundColour(*wxWHITE);
    this->SetSizer(boxSizer);
    
    this->Bind(wxEVT_MOTION, &hover, this);
    this->Bind(wxEVT_LEAVE_WINDOW, &unhover, this);
    this->Bind(wxEVT_LEFT_DOWN, &click, this);
    
    const wxWindowList& children = this->GetChildren();

    for (auto child : children) {
        child->Bind(wxEVT_MOTION, &hover, this);
        child->Bind(wxEVT_LEAVE_WINDOW, &unhover, this);
        child->Bind(wxEVT_LEFT_DOWN, &click, this);
    }
};

void ComponentGameobjectsOption::click(wxMouseEvent& event)
{
    wxMessageBox( "clicked");
};

void ComponentGameobjectsOption::hover(wxMouseEvent& event)
{
    this->SetBackgroundColour(*wxLIGHT_GREY);
    this->Refresh();
};

void ComponentGameobjectsOption::unhover(wxMouseEvent& event)
{
    this->SetBackgroundColour(*wxWHITE);
    this->Refresh();
};
