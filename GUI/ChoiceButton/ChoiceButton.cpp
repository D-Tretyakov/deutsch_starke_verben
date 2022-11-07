#include "ChoiceButton.hpp"

ChoiceButton::ChoiceButton(wxFrame* parent, wxString text)
    : wxWindow(parent, wxID_ANY),
      m_Text(text),
      m_PressedDown(false),
      m_Size(wxSize(200, 50))
{
    SetMinSize(m_Size);
}

void ChoiceButton::paintNow()
{
    wxClientDC dc(this);
    render(dc);
}

void ChoiceButton::render(wxDC&  dc)
{
    if (m_PressedDown)
        dc.SetBrush(*wxRED_BRUSH);
    else
        dc.SetBrush(*wxGREY_BRUSH);
    
    dc.DrawRectangle(0, 0, m_Size.GetWidth(), m_Size.GetHeight());
    dc.DrawText(m_Text, 20, 15);
}

void ChoiceButton::paintEvent(wxPaintEvent & evt)
{
    paintNow();
}

void ChoiceButton::OnMouseDown(wxMouseEvent& event)
{
    pressedDown = true;
    paintNow();
}
void ChoiceButton::OnMouseReleased(wxMouseEvent& event)
{
    pressedDown = false;
    paintNow();
}
void ChoiceButton::OnMouseLeftWindow(wxMouseEvent& event)
{
    if (pressedDown)
    {
        pressedDown = false;
        paintNow();
    }
}