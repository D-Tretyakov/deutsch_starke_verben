#pragma once
#include <wx/wx.h>
#include "ButtonPanel/ButtonPanel.hpp"
#include "TranslationPanel/TranslationPanel.hpp"

class MainFrame : public wxFrame
{
public:
    MainFrame();

    void NeedRefresh();

private:
    ButtonPanel* m_ButtonPanel;
    TranslationPanel* m_TranslationPanel;

    wxBoxSizer* m_Sizer;
};