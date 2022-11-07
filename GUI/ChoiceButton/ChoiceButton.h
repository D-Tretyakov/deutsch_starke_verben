#include <wx/wx.h>

class ChoiceButton : wxWindow
{
public:
    ChoiceButton(wxFrame* parent, wxString text);

    void OnPaintEvent(wxPaintEvent& event);
    void paintNow();
    
    void OnMouseDown(wxMouseEvent& event);
    void OnMouseReleased(wxMouseEvent& event);
    void OnMouseLeftWindow(wxMouseEvent& event);
    
    void render(wxDC& dc);

    wxDECLARE_EVENT_TABLE()

private:
    bool m_PressedDown;
    wxString m_Text;
    wxSize m_Size;
};

wxBEGIN_EVENT_TABLE(ChoiceButton, wxWindow)

    EVT_LEFT_DOWN(ChoiceButton::OnMouseDown)
    EVT_LEFT_UP(ChoiceButton::OnMouseReleased)
    EVT_LEAVE_WINDOW(ChoiceButton::OnMouseLeftWindow)

    // catch paint events
    EVT_PAINT(ChoiceButton::OnPaintEvent)

wxEND_EVENT_TABLE()