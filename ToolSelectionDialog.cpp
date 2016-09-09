//
// Created by fatih on 9/2/16.
//

#include "ToolSelectionDialog.h"

ToolSelectionDialog::ToolSelectionDialog()
    : wxFrame(nullptr, -1, wxT("Araç Seç"), wxDefaultPosition, wxDefaultSize) {

    wxBoxSizer* vbox = new wxBoxSizer(wxVERTICAL);

    mBtn1 = new wxButton(this, ID::BTN1, wxT("Dosya Seçimi"));
    mBtn2 = new wxButton(this, ID::BTN2, wxT("Benzer Dosyalar"));

    mBtn1->Bind(wxEVT_BUTTON, &ToolSelectionDialog::OnBtn1Click, this);
    mBtn2->Bind(wxEVT_BUTTON, &ToolSelectionDialog::OnBtn2Click, this);

    vbox->Add(mBtn1, 1, wxEXPAND|wxALL);
    vbox->Add(mBtn2, 1, wxEXPAND|wxALL);

    this->SetSizer(vbox);
    this->Layout();
    this->Centre(wxBOTH);
}

void ToolSelectionDialog::OnBtn1Click(wxCommandEvent &) {
    auto myFrame1 = new FileSelectionFrame;
    myFrame1->Bind(wxEVT_CLOSE_WINDOW, &ToolSelectionDialog::OnToolClose, this);
    myFrame1->Show(true);
    mCurrentFrame = myFrame1;
    this->Show(false);
}

void ToolSelectionDialog::OnBtn2Click(wxCommandEvent &) {
    auto myFrame1 = new DuplicateDetectionFrame;
    myFrame1->Bind(wxEVT_CLOSE_WINDOW, &ToolSelectionDialog::OnToolClose, this);
    myFrame1->Show(true);
    mCurrentFrame = myFrame1;
    this->Show(false);
}

void ToolSelectionDialog::OnToolClose(wxCloseEvent & a) {
    mCurrentFrame->Destroy();
    delete mCurrentFrame;
    this->Show(true);
}
