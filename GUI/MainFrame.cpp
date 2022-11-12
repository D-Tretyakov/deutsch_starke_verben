#include "MainFrame.hpp"


MainFrame::MainFrame()
    : wxFrame(NULL, wxID_ANY, wxString("Starke Verben lernen"), wxDefaultPosition, wxSize(500, 700))
{
    m_Sizer = new wxBoxSizer(wxVERTICAL);

    m_ButtonPanel = new ButtonPanel(this);
    m_TranslationPanel = new TranslationPanel(this);

    m_Sizer->Add(m_ButtonPanel, 0, wxEXPAND | wxALL, 5);
    m_Sizer->Add(m_TranslationPanel, 1, wxEXPAND | wxALL, 5);

    SetSizer(m_Sizer);

    Center(wxBOTH);
}

TranslationPanel* MainFrame::GetTranslationPanel()
{
    return m_TranslationPanel;
}