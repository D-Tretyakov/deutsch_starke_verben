#include <wx/wx.h>

class ChoiceButton : public wxWindow
{
public:
    ChoiceButton(wxPanel* parent, wxString text);

    void OnPaintEvent(wxPaintEvent& event);
    void paintNow();
    
    void OnMouseDown(wxMouseEvent& event);
    void OnMouseReleased(wxMouseEvent& event);
    void OnMouseLeftWindow(wxMouseEvent& event);
    
    void render(wxDC& dc);

    wxDECLARE_EVENT_TABLE();

private:
    bool m_PressedDown;
    wxString m_Text;
    wxSize m_Size;
};
