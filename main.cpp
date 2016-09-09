#include <wx/wx.h>

#include "ToolSelectionDialog.h"

class MyApp: public wxApp {
public:
    virtual bool OnInit() {
        ToolSelectionDialog *mainDialog1 = new ToolSelectionDialog;
        mainDialog1->Show(true);
        SetTopWindow(mainDialog1);
        return true;
    }
};

IMPLEMENT_APP(MyApp)
