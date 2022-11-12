#include <wx/wx.h>
#include "ChoiceButton/ChoiceButton.hpp"

class ButtonPanel : public wxPanel
{
public:
    ButtonPanel(wxFrame* parent);

private:
    ChoiceButton* m_Buttons[4];
};