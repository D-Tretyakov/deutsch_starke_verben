#include <wx/wx.h>

class TranslationPanel : public wxPanel
{
public:
    TranslationPanel(wxFrame* parent);

private:
    wxStaticText* m_Translation;
    wxGridSizer* m_Grid;
};