#pragma once
#include <wx/wx.h>
#include <string>

class TranslationPanel : public wxPanel
{
public:
    TranslationPanel(wxFrame* parent);

    void SetText(std::wstring& text);

private:
    wxStaticText* m_Translation;
    wxGridSizer* m_Grid;
};