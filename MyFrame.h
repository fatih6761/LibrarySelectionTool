//
// Created by fatih on 9/1/16.
//

#ifndef LIBRARYSELECTIONTOOL_MYFRAME_H
#define LIBRARYSELECTIONTOOL_MYFRAME_H


#include <wx/wx.h>

#include <string>
#include <vector>
#include <tuple>

#include "file_info.h"

class MyFrame : public wxFrame {
public:
    MyFrame();

    void OnSrcButtonClick(wxCommandEvent&);
    void OnDstButtonClick(wxCommandEvent&);
    void OnMoveRightButtonClick(wxCommandEvent&);
    void OnMoveLeftButtonClick(wxCommandEvent&);

    void OnRightListDoubleClick(wxCommandEvent&);
    void OnLeftListDoubleClick(wxCommandEvent&);

    enum ID : int {
        BTN_SRCDIR = 0,
        BTN_DSTDIR,
        BTN_MOVELEFT,
        BTN_MOVERIGHT,

        TXT_SRCDIR,
        TXT_DSTDIR,

        LBOX_LEFT,
        LBOX_RIGHT
    };

    // UI elements
    wxStaticText*   mTxtSrcDir;
    wxButton*       mBtnSrcDir;

    wxStaticText*   mTxtDstDir;
    wxButton*       mBtnDstDir;

    wxListBox*      mLeftPane;
    wxButton*       mBtnMoveRight;
    wxButton*       mBtnMoveLeft;
    wxListBox*      mRightPane;


    // Members
    std::string m_sourceDir;
    std::string m_destDir;

    std::vector<file_info> m_sourceFiles;
    std::vector<file_info> m_destFiles;

    void setSourceDirectory(const wxString& path);

    void setDestDirectory(const wxString& path);

    void moveSourceToDest(int sel);

    void moveDestToSource(int sel);

    void playSourceItem(int sel);

    void playDestItem(int sel);
};


#endif //LIBRARYSELECTIONTOOL_MYFRAME_H
