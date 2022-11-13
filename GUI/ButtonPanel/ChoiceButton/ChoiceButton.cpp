#include "ChoiceButton.hpp"

ChoiceButton::ChoiceButton(wxPanel* parent, const wxString& text)
    : wxButton(parent, wxID_ANY, text)
{
    SetMinSize(wxSize(200, 50));
}

void ChoiceButton::PaintCorrect() 
{
    SetBackgroundColour(*wxGREEN);
}

void ChoiceButton::PaintIncorrect() 
{
    SetBackgroundColour(*wxRED);
}

void ChoiceButton::PaintDefault() 
{
    const wxColor default_color(240, 240, 240);
    SetBackgroundColour(*default_color);
}