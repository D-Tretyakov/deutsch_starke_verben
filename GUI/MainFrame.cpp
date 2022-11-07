#include "MainFrame.hpp"

MainFrame::MainFrame()
    : wxFrame(NULL, wxID_ANY, wxString("Starke Verben lernen"), wxDefaultPosition, wxSize(500, 700))
{
    m_Parent = new wxPanel(this, wxID_ANY);

    wxBoxSizer* vbox = new wxBoxSizer(wxVertical);
    for (auto& button : m_Buttons)
    {
        button = new ChoiceButton(m_Parent, wxString("hello"));
        vbox->Add(button, 0, wxALL, 5);
    }

    m_Translation = new wxStaticText(
        m_Parent, wxID_ANY, wxString("Привет"), wxPoint(10, 10), wxDefaultSize, wxALIGN_CENTRE
    );

    m_Parent->SetSizer(hbox);

    Center();
}

