#pragma once
#include <wx/wx.h>
#include "ChoiceButton/ChoiceButton.hpp"

class ButtonPanel : public wxPanel
{
public:
    ButtonPanel(wxFrame* parent);

    void OnButtonClick(wxCommandEvent& event);
private:
    wxFrame* m_Parent;
    ChoiceButton* m_Buttons[4];
};