#include "MainFrame.hpp"
#include "ButtonPanel/ButtonPanel.hpp"
#include "TranslationPanel/TranslationPanel.hpp"

MainFrame::MainFrame()
    : wxFrame(NULL, wxID_ANY, wxString("Starke Verben lernen"), wxDefaultPosition, wxSize(500, 700))
{
    SetSizeHints( wxDefaultSize, wxDefaultSize );

    wxBoxSizer* vbox = new wxBoxSizer(wxVERTICAL);

    ButtonPanel* button_panel = new ButtonPanel(this);
    TranslationPanel* translation_panel = new TranslationPanel(this);

    vbox->Add(translation_panel, 0, wxEXPAND | wxALL, 5);
    vbox->Add(button_panel, 0, wxEXPAND | wxALL, 5);

    SetSizer(vbox);

    Center();
}

