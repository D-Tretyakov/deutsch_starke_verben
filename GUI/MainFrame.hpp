#include <wx/wx.h>
#include <vector>
#include "ChoiceButton/ChoiceButton.hpp"

class MainFrame : public wxFrame
{
public:
    MainFrame();

private:
    wxStaticText* m_Translation;
    ChoiceButton* m_Buttons[4];
    wxPanel* m_Parent;
};