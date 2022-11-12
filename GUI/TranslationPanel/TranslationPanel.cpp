#include "TranslationPanel.hpp"
#include <wx/string.h>

TranslationPanel::TranslationPanel(wxFrame* parent)
    : wxPanel(parent, wxID_ANY)
{
    m_Grid = new wxGridSizer(0, 1, 0, 0);

    m_Translation = new wxStaticText(this, wxID_ANY, wxT("Русский текст"), wxDefaultPosition, wxDefaultSize, 0);
    
	m_Grid->Add(m_Translation, 0, wxALL | wxALIGN_CENTER_VERTICAL | wxALIGN_CENTER_HORIZONTAL, 5);
}