#include "ButtonPanel.hpp"
#include "MainFrame.hpp"

ButtonPanel::ButtonPanel(wxFrame* parent)
    : wxPanel(parent, wxID_ANY),
      m_Parent(parent),
      m_Correct(-1)
{
    wxBoxSizer* vbox = new wxBoxSizer(wxVERTICAL);
    for (int i = 0; i < 4; i++)
    {
        m_Buttons[i] = new ChoiceButton(this, wxT("Обычный текст"));
        vbox->Add(m_Buttons[i], 0, wxALL | wxALIGN_CENTER_HORIZONTAL, 5);

        auto const handler = [i, this](wxCommandEvent& event){
            OnButtonClick(event, i);
        };
        m_Buttons[i]->Bind(wxEVT_BUTTON, handler);
    }

    SetSizer(vbox);
}

void ButtonPanel::OnButtonClick(wxCommandEvent& event, int button_num)
{

    m_Buttons[m_Correct]->PaintCorrect();

    if (button_num != m_Correct)
        m_Buttons[button_num]->PaintIncorrect();

    DisableButtons();

    MainFrame* main_frame = dynamic_cast<MainFrame*>(m_Parent);
    main_frame->NeedRefresh();
}

void ButtonPanel::Refresh(std::vector<std::wstring>& words, int correct)
{
    for (int i = 0; i < 4; i++)
    {
        m_Buttons[i]->SetLabel(words[i].c_str());
        m_Buttons[i]->Enable(true);
        m_Buttons[i]->PaintDefault();
    }

    m_Correct = correct;
}

void ButtonPanel::DisableButtons()
{
    for (int i = 0; i < 4; i++)
         m_Buttons[i]->Enable(false);
}