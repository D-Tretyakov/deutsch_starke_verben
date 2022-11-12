#include <wx/wx.h>
#include "ButtonPanel/ButtonPanel.hpp"
#include "TranslationPanel/TranslationPanel.hpp"

class MainFrame : public wxFrame
{
public:
    MainFrame();

private:
    ButtonPanel* button_panel;
    TranslationPanel* translation_panel;

    wxBoxSizer* vbox;
};