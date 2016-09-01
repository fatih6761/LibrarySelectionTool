//
// Created by fatih on 9/1/16.
//

#include "MyFrame.h"

MyFrame::MyFrame()
        : wxFrame(nullptr, -1, wxT("Title"), wxDefaultPosition, wxSize(500, 300)) {
    // Directory control boxes
//  {
//      {
    // Source directory control box
    wxBoxSizer *mboxDirLeft = new wxBoxSizer(wxHORIZONTAL);

    mTxtSrcDir = new wxStaticText(this, TXT_SRCDIR, wxT("Kaynak: "));
    mBtnSrcDir = new wxButton(this, BTN_SRCDIR, wxT("Aç..."));

    mboxDirLeft->Add(mTxtSrcDir, 1, wxEXPAND | wxALL, 5);
    mboxDirLeft->Add(mBtnSrcDir, 0, wxALL, 5);
//      }

//      {
    // Destination directory control box
    wxBoxSizer *mboxDirRight = new wxBoxSizer(wxHORIZONTAL);

    mTxtDstDir = new wxStaticText(this, TXT_DSTDIR, wxT("Hedef: "));
    mBtnDstDir = new wxButton(this, BTN_DSTDIR, wxT("Aç..."));

    mboxDirRight->Add(mTxtDstDir, 1, wxEXPAND | wxALL, 5);
    mboxDirRight->Add(mBtnDstDir, 0, wxALL, 5);
//      }
//  }

    // List boxes
//  {
    wxBoxSizer *mboxList = new wxBoxSizer(wxHORIZONTAL);

    mLeftPane = new wxListBox(this, LBOX_LEFT);

    // Mid buttons
//      {
    wxBoxSizer *mboxListMid = new wxBoxSizer(wxVERTICAL);
    mBtnMoveRight = new wxButton(this, BTN_MOVERIGHT, wxT("Ekle >>"));
    mBtnMoveLeft = new wxButton(this, BTN_MOVELEFT, wxT("<< Çıkar"));
    mboxListMid->Add(mBtnMoveRight, 0, wxEXPAND | wxALL, 5);
    mboxListMid->Add(mBtnMoveLeft, 0, wxEXPAND | wxALL, 5);
//      }

    mRightPane = new wxListBox(this, LBOX_RIGHT);

    mboxList->Add(mLeftPane, 1, wxEXPAND | wxALL, 5);
    mboxList->Add(mboxListMid, 0, wxALIGN_CENTER_VERTICAL, 5);
    mboxList->Add(mRightPane, 1, wxEXPAND | wxALL, 5);
//  }

    wxBoxSizer *mboxTop = new wxBoxSizer(wxHORIZONTAL);
    mboxTop->Add(mboxDirLeft, 1, wxEXPAND | wxALL, 5);
    mboxTop->Add(mboxDirRight, 1, wxEXPAND | wxALL, 5);

    wxBoxSizer *mboxRoot = new wxBoxSizer(wxVERTICAL);
    mboxRoot->Add(mboxTop, 0, wxEXPAND | wxALL, 5);
    mboxRoot->Add(mboxList, 1, wxEXPAND | wxALL, 5);

    this->SetSizer(mboxRoot);
    this->Layout();

    mBtnSrcDir->Bind(wxEVT_BUTTON, &MyFrame::OnSrcButtonClick, this);
    mBtnDstDir->Bind(wxEVT_BUTTON, &MyFrame::OnDstButtonClick, this);
    mBtnMoveRight->Bind(wxEVT_BUTTON, &MyFrame::OnMoveRightButtonClick, this);
    mBtnMoveLeft->Bind(wxEVT_BUTTON, &MyFrame::OnMoveLeftButtonClick, this);

    mLeftPane->Bind(wxEVT_LISTBOX_DCLICK, &MyFrame::OnLeftListDoubleClick, this);
    mRightPane->Bind(wxEVT_LISTBOX_DCLICK, &MyFrame::OnRightListDoubleClick, this);

    this->Centre(wxBOTH);
}

void MyFrame::OnSrcButtonClick(wxCommandEvent &) {
    wxDirDialog dlg(this, wxT("Kaynak klasör"));
    if (dlg.ShowModal() == wxID_OK) {
        setSourceDirectory(dlg.GetPath());
    }
}

void MyFrame::OnDstButtonClick(wxCommandEvent &) {
    wxDirDialog dlg(this, wxT("Hedef klasör"));
    if (dlg.ShowModal() == wxID_OK) {
        setDestDirectory(dlg.GetPath());
    }
}

void MyFrame::OnMoveRightButtonClick(wxCommandEvent &e) {
    int sel = mLeftPane->GetSelection();
    if (sel != -1) {
        moveSourceToDest(sel);
    }
}

void MyFrame::OnMoveLeftButtonClick(wxCommandEvent &) {
    int sel = mRightPane->GetSelection();
    if (sel != -1) {
        moveDestToSource(sel);
    }
}

void MyFrame::OnRightListDoubleClick(wxCommandEvent &) {
    int sel = mRightPane->GetSelection();
    if (sel != -1) {
        playDestItem(sel);
    }
}

void MyFrame::OnLeftListDoubleClick(wxCommandEvent &) {
    int sel = mLeftPane->GetSelection();
    if (sel != -1) {
        playSourceItem(sel);
    }
}

void MyFrame::setSourceDirectory(const wxString& path) {

}

void MyFrame::setDestDirectory(const wxString& path) {

}

void MyFrame::moveSourceToDest(int sel) {

}

void MyFrame::moveDestToSource(int sel) {

}

void MyFrame::playSourceItem(int sel) {

}

void MyFrame::playDestItem(int sel) {

}

