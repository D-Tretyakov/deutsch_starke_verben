#include "ChoiceButton.hpp"

ChoiceButton::ChoiceButton(wxPanel* parent, wxString text)
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

void ChoiceButton::OnPaintEvent(wxPaintEvent & evt)
{
    paintNow();
}

void ChoiceButton::OnMouseDown(wxMouseEvent& event)
{
    m_PressedDown = true;
    paintNow();
}
void ChoiceButton::OnMouseReleased(wxMouseEvent& event)
{
    m_PressedDown = false;
    paintNow();
}
void ChoiceButton::OnMouseLeftWindow(wxMouseEvent& event)
{
    if (m_PressedDown)
    {
        m_PressedDown = false;
        paintNow();
    }
}


wxBEGIN_EVENT_TABLE(ChoiceButton, wxWindow)

    EVT_LEFT_DOWN(ChoiceButton::OnMouseDown)
    EVT_LEFT_UP(ChoiceButton::OnMouseReleased)
    EVT_LEAVE_WINDOW(ChoiceButton::OnMouseLeftWindow)

    EVT_PAINT(ChoiceButton::OnPaintEvent)

wxEND_EVENT_TABLE()