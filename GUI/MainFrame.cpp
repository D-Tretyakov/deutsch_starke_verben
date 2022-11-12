#include "MainFrame.hpp"


MainFrame::MainFrame()
    : wxFrame(NULL, wxID_ANY, wxString("Starke Verben lernen"), wxDefaultPosition, wxSize(500, 700))
{
    vbox = new wxBoxSizer(wxVERTICAL);

    button_panel = new ButtonPanel(this);
    translation_panel = new TranslationPanel(this);

    vbox->Add(translation_panel, 1, wxEXPAND | wxALL, 5);
    vbox->Add(button_panel, 0, wxEXPAND | wxALL, 5);

    SetSizer(vbox);

    Center(wxBOTH);
}

