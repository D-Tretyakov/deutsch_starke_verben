#pragma once
#include <wx/wx.h>
#include <wx/string.h>

class ChoiceButton : public wxButton
{
public:
    ChoiceButton(wxPanel* parent, const wxString& text);

    void PaintCorrect();
    void PaintIncorrect();
    void PaintDefault();
};
