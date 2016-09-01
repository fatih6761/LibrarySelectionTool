//
// Created by fatih on 9/1/16.
//

#ifndef LIBRARYSELECTIONTOOL_MYFRAME_H
#define LIBRARYSELECTIONTOOL_MYFRAME_H


#include <wx/wx.h>

#include <string>
#include <vector>
#include <algorithm>

#include "file_info.h"

class MyFrame : public wxFrame {
public:
    MyFrame();

    void OnSrcButtonClick(wxCommandEvent&);
    void OnDstButtonClick(wxCommandEvent&);

    void OnMoveAllRightButtonClick(wxCommandEvent&);
    void OnMoveRightButtonClick(wxCommandEvent&);
    void OnMoveLeftButtonClick(wxCommandEvent&);
    void OnMoveAllLeftButtonClick(wxCommandEvent&);

    void OnRightListDoubleClick(wxCommandEvent&);
    void OnLeftListDoubleClick(wxCommandEvent&);

    void OnFilterExtButtonClick(wxCommandEvent&);
    void OnSaveListButtonClick(wxCommandEvent&);

    enum ID : int {
        BTN_SRCDIR = 0,
        BTN_DSTDIR,
        BTN_MOVELEFT,
        BTN_MOVERIGHT,
        BTN_MOVEALLRIGHT,
        BTN_MOVEALLLEFT,
        BTN_SAVE,
        BTN_FILTER,

        TXT_SRCDIR,
        TXT_DSTDIR,
        TXT_TOTSIZE,

        LBOX_LEFT,
        LBOX_RIGHT
    };

    // UI elements
    wxStaticText*   mTxtSrcDir;
    wxButton*       mBtnSrcDir;

    wxListBox*      mLeftPane;
    wxButton*       mBtnMoveAllRight;
    wxButton*       mBtnMoveRight;
    wxButton*       mBtnMoveLeft;
    wxButton*       mBtnMoveAllLeft;
    wxListBox*      mRightPane;

    wxStaticText*   mTxtTotalSize;
    wxButton*       mBtnFilterExt;
    wxButton*       mBtnSaveList;


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

    void updateListBoxes();

    void updateDirTexts();

    void moveAllSourceToDest();

    void moveAllDestToSource();
};


#endif //LIBRARYSELECTIONTOOL_MYFRAME_H
