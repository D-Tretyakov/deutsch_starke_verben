#include "ChoiceButton.hpp"

ChoiceButton::ChoiceButton(wxPanel* parent, const wxString& text)
    : wxButton(parent, wxID_ANY, text)
{
    SetMinSize(wxSize(200, 50));
}