#include <wx/wx.h>
#include <vector>
#include "ChoiceButton/ChoiceButton.hpp"

class MainFrame : wxFrame
{
public:
    MainFrame();

private:
    wxStaticText* m_Translation;
    std::vector<ChoiceButton*> m_Buttons(4);
    wxPanel* m_Parent;
}