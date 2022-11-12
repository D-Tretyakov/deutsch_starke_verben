#include <wx/wx.h>
#include <vector>

class MainFrame : public wxFrame
{
public:
    MainFrame();

private:
    wxStaticText* m_Translation;
    wxPanel* m_Parent;
};