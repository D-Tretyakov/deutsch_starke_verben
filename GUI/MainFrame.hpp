#pragma once
#include <wx/wx.h>
#include "ButtonPanel/ButtonPanel.hpp"
#include "TranslationPanel/TranslationPanel.hpp"
#include "DataProvider.hpp"

class MainFrame : public wxFrame
{
public:
    MainFrame();

    void MakeQuestion();
    void NeedRefresh();

private:
    ButtonPanel* m_ButtonPanel;
    TranslationPanel* m_TranslationPanel;

    wxBoxSizer* m_Sizer;

    DataProvider m_DataProvider;
};