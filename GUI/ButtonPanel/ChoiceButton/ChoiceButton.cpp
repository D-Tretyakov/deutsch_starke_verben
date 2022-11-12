#include "ChoiceButton.hpp"

ChoiceButton::ChoiceButton(wxPanel* parent, wxString text)
    : wxButton(parent, wxID_ANY, text),
      m_Size(wxSize(200, 50))
{
    SetMinSize(m_Size);
}
