#include <wx/wx.h>

#include "MyFrame.h"

class MyApp: public wxApp {
public:
    virtual bool OnInit();
};

IMPLEMENT_APP(MyApp)

bool MyApp::OnInit() {
    MyFrame* myFrame1 = new MyFrame;
    myFrame1->Show(true);
    myFrame1->Maximize(true);
    SetTopWindow(myFrame1);
    return true;
}