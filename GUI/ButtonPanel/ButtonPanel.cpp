#include "ButtonPanel.hpp"

ButtonPanel::ButtonPanel(wxFrame* parent)
    : wxPanel(parent, wxID_ANY)
{
    wxBoxSizer* vbox = new wxBoxSizer(wxVERTICAL);
    for (auto& button : m_Buttons)
    {
        button = new ChoiceButton(this, wxT("русская кнопка"));
        vbox->Add(button, 0, wxALL, 5);
    }

    SetSizer(vbox);
}