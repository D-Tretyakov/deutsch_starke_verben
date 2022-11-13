#pragma once
#include <wx/wx.h>
#include "ChoiceButton/ChoiceButton.hpp"
#include <vector>
#include <string>

class ButtonPanel : public wxPanel
{
public:
    ButtonPanel(wxFrame* parent);

    void OnButtonClick(wxCommandEvent& event, int button_num);

    void Refresh(std::vector<std::wstring>& words, int correct);
    void DisableButtons();
private:
    wxFrame* m_Parent;
    wxBoxSizer* m_Sizer;
    ChoiceButton* m_Buttons[4];

    int m_Correct; // index of button with correct answer
};