#include "ButtonPanel.hpp"
#include "MainFrame.hpp"
#include <string>

ButtonPanel::ButtonPanel(wxFrame* parent)
    : wxPanel(parent, wxID_ANY),
      m_Parent(parent),
      m_Correct(-1)
{
    wxBoxSizer* vbox = new wxBoxSizer(wxVERTICAL);
    for (int i = 0; i < m_Buttons.size(); i++)
    {
        m_Buttons[i] = new ChoiceButton(this, wxT("Обычный текст"));
        vbox->Add(m_Buttons[i], 0, wxALL | wxALIGN_CENTER_HORIZONTAL, 5);

        auto const handler = [i, this](wxCommandEvent& event){
            OnButtonClick(event, i);
        };
        m_Buttons[i]->Bind(wxEVT_BUTTON, handler);
    }

    m_Buttons[0]->SetLabel(wxT("текст 0"));
    m_Buttons[1]->SetLabel(wxT("текст 1"));
    m_Buttons[2]->SetLabel(wxT("текст 2"));
    m_Buttons[3]->SetLabel(wxT("текст 3"));

    SetSizer(vbox);
}

void ButtonPanel::OnButtonClick(wxCommandEvent& event, int button_num)
{
    MainFrame* main_frame = dynamic_cast<MainFrame*>(m_Parent);
    std::wstring text = std::wstring(L"кнопка #") + std::to_wstring(button_num);
    main_frame->GetTranslationPanel()->SetText(text);
}