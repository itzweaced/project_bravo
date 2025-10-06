#include "module_properties.h"

ModuleProperties::ModuleProperties(wxWindow* parent): wxPanel(parent)
{
    wxStaticText* choice_label_1 = new wxStaticText(this, wxID_ANY, "Shader", wxDefaultPosition, wxSize(200, -1));

    wxArrayString choice_options_1;
    choice_options_1.Add("Shader 1");
    choice_options_1.Add("Shader 2");
    choice_options_1.Add("Shader 3");
    wxChoice* choice_1 = new wxChoice(this, wxID_ANY, wxPoint(150, 375), wxSize(100, -1), choice_options_1);
    choice_1->Select(0);
    wxStaticText* choice_label_2 = new wxStaticText(this, wxID_ANY, "Model", wxDefaultPosition, wxSize(200, -1));

    wxArrayString choice_options_2;
    choice_options_2.Add("Model 1");
    choice_options_2.Add("Model 2");
    choice_options_2.Add("Model 3");
    wxChoice* choice_2 = new wxChoice(this, wxID_ANY, wxPoint(150, 375), wxSize(100, -1), choice_options_2);
    choice_2->Select(0);

    wxStaticText* label_1 = new wxStaticText(this, wxID_ANY, "X Position", wxDefaultPosition, wxSize(200, -1));
    wxTextCtrl* entry_1 = new wxTextCtrl(this, wxID_ANY, std::to_string(xPos), wxDefaultPosition, wxSize(200, -1));
    wxStaticText* label_2 = new wxStaticText(this, wxID_ANY, "Y Position", wxDefaultPosition, wxSize(200, -1));
    wxTextCtrl* entry_2 = new wxTextCtrl(this, wxID_ANY, std::to_string(yPos), wxDefaultPosition, wxSize(200, -1));
    wxStaticText* label_3 = new wxStaticText(this, wxID_ANY, "Z Position", wxDefaultPosition, wxSize(200, -1));
    wxTextCtrl* entry_3 = new wxTextCtrl(this, wxID_ANY, std::to_string(zPos), wxDefaultPosition, wxSize(200, -1));

    wxStaticText* label_4 = new wxStaticText(this, wxID_ANY, "X Scale", wxDefaultPosition, wxSize(200, -1));
    wxTextCtrl* entry_4 = new wxTextCtrl(this, wxID_ANY, std::to_string(xScale), wxDefaultPosition, wxSize(200, -1));
    wxStaticText* label_5 = new wxStaticText(this, wxID_ANY, "Y Scale", wxDefaultPosition, wxSize(200, -1));
    wxTextCtrl* entry_5 = new wxTextCtrl(this, wxID_ANY, std::to_string(yScale), wxDefaultPosition, wxSize(200, -1));
    wxStaticText* label_6 = new wxStaticText(this, wxID_ANY, "Z Scale", wxDefaultPosition, wxSize(200, -1));
    wxTextCtrl* entry_6 = new wxTextCtrl(this, wxID_ANY, std::to_string(zScale), wxDefaultPosition, wxSize(200, -1));

    wxStaticText* label_7 = new wxStaticText(this, wxID_ANY, "X Rotation", wxDefaultPosition, wxSize(200, -1));
    wxTextCtrl* entry_7 = new wxTextCtrl(this, wxID_ANY, std::to_string(xRotation), wxDefaultPosition, wxSize(200, -1));
    wxStaticText* label_8 = new wxStaticText(this, wxID_ANY, "Y Rotation", wxDefaultPosition, wxSize(200, -1));
    wxTextCtrl* entry_8 = new wxTextCtrl(this, wxID_ANY, std::to_string(yRotation), wxDefaultPosition, wxSize(200, -1));
    wxStaticText* label_9 = new wxStaticText(this, wxID_ANY, "Z Rotation", wxDefaultPosition, wxSize(200, -1));
    wxTextCtrl* entry_9 = new wxTextCtrl(this, wxID_ANY, std::to_string(zRotation), wxDefaultPosition, wxSize(200, -1));

    wxCheckBox* checkbox_1 = new wxCheckBox(this, wxID_ANY, "Enable Render", wxPoint(550, 50), wxDefaultSize, wxCHK_3STATE | wxCHK_ALLOW_3RD_STATE_FOR_USER);
    wxCheckBox* checkbox_2 = new wxCheckBox(this, wxID_ANY, "Enable Bounding Box", wxPoint(550, 50), wxDefaultSize, wxCHK_3STATE | wxCHK_ALLOW_3RD_STATE_FOR_USER);
    wxBoxSizer* boxSizer = new wxBoxSizer(wxVERTICAL);

    boxSizer->Add(choice_label_1, 0, wxALL, 5);
    boxSizer->Add(choice_1, 0, wxALL, 5);
    boxSizer->Add(choice_label_2, 0, wxALL, 5);
    boxSizer->Add(choice_2, 0, wxALL, 5);

    boxSizer->Add(label_1, 0, wxALL, 5);
    boxSizer->Add(entry_1, 0, wxALL, 5);
    boxSizer->Add(label_2, 0, wxALL, 5);
    boxSizer->Add(entry_2, 0, wxALL, 5);
    boxSizer->Add(label_3, 0, wxALL, 5);
    boxSizer->Add(entry_3, 0, wxALL, 5);

    boxSizer->Add(label_4, 0, wxALL, 5);
    boxSizer->Add(entry_4, 0, wxALL, 5);
    boxSizer->Add(label_5, 0, wxALL, 5);
    boxSizer->Add(entry_5, 0, wxALL, 5);
    boxSizer->Add(label_6, 0, wxALL, 5);
    boxSizer->Add(entry_6, 0, wxALL, 5);

    boxSizer->Add(label_7, 0, wxALL, 5);
    boxSizer->Add(entry_7, 0, wxALL, 5);
    boxSizer->Add(label_8, 0, wxALL, 5);
    boxSizer->Add(entry_8, 0, wxALL, 5);
    boxSizer->Add(label_9, 0, wxALL, 5);
    boxSizer->Add(entry_9, 0, wxALL, 5);

    boxSizer->Add(checkbox_1, 0, wxALL, 5);
    boxSizer->Add(checkbox_2, 0, wxALL, 5);
    this->SetSizer(boxSizer);
    
};