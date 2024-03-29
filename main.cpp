#include <wx/wx.h>
#include "GUI/MainFrame.hpp"
#include "static/icon.xpm" 

class App : public wxApp
{
public:
    virtual bool OnInit();
};

bool App::OnInit()
{
    MainFrame* frame = new MainFrame();
    frame->SetIcon(app_icon);
    frame->Show();

    return true;
}

IMPLEMENT_APP(App)