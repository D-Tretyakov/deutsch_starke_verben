#include <wx/wx.h>
#include "GUI/MainFrame.hpp"

class App : public wxApp
{
  public:
    virtual bool OnInit();
};

bool App::OnInit()
{
    MainFrame* frame = new MainFrame();
    frame->Show();

    return true;
}

IMPLEMENT_APP(App)