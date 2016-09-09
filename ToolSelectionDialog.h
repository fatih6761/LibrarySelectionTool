//
// Created by fatih on 9/2/16.
//

#ifndef LIBRARYSELECTIONTOOL_TOOLSELECTIONDIALOG_H
#define LIBRARYSELECTIONTOOL_TOOLSELECTIONDIALOG_H


#include <wx/wx.h>

#include <vector>
#include <tuple>

#include "ListFileHelper.h"
#include "FileSelectionFrame.h"
#include "DuplicateDetectionFrame.h"

class ToolSelectionDialog : public wxFrame {
public:
    ToolSelectionDialog();

    enum ID : int {
        BTN1,
        BTN2
    };

    wxButton* mBtn1;
    wxButton* mBtn2;

    wxFrame* mCurrentFrame;

    void OnToolClose(wxCloseEvent&);

    void OnBtn1Click(wxCommandEvent&);
    void OnBtn2Click(wxCommandEvent&);
};


#endif //LIBRARYSELECTIONTOOL_TOOLSELECTIONDIALOG_H
