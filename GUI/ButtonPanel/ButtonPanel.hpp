#pragma once
#include <wx/wx.h>
#include "ChoiceButton/ChoiceButton.hpp"
#include <vector>


class ButtonPanel : public wxPanel
{
public:
    ButtonPanel(wxFrame* parent);

    void OnButtonClick(wxCommandEvent& event, int button_num);

    void Refresh(std::vector<std::wstring> words, int correct);
private:
    wxFrame* m_Parent;
    std::vector<ChoiceButton*> m_Buttons;

    int m_Correct; // index of button with correct answer
};