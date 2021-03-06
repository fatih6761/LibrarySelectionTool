//
// Created by fatih on 9/1/16.
//

#include "FileSelectionFrame.h"

#include <fstream>
#include <boost/algorithm/string.hpp>

#include "ListFileHelper.h"

FileSelectionFrame::FileSelectionFrame()
        : wxFrame(nullptr, -1, wxT("Title"), wxDefaultPosition, wxSize(600, 600)) {
    // control boxes
//  {
//      {

    mTxtSrcDir = new wxStaticText(this, TXT_SRCDIR, wxT("Kaynak: "));
    mBtnSrcDir = new wxButton(this, BTN_SRCDIR, wxT("Aç..."));
    mBtnLoadList = new wxButton(this, BTN_LOADLIST, wxT("Liste yükle"));

    wxBoxSizer *mboxTop = new wxBoxSizer(wxHORIZONTAL);
    mboxTop->Add(mTxtSrcDir, 1, wxEXPAND | wxALL, 5);
    mboxTop->Add(mBtnSrcDir, 0, wxEXPAND | wxALL, 5);
    mboxTop->Add(mBtnLoadList, 0, wxEXPAND | wxALL, 5);

//      }
//  }

    // List boxes
//  {
    auto *mboxMid = new wxBoxSizer(wxHORIZONTAL);

    mLeftPane = new wxListBox(this, LBOX_LEFT);

    // Mid buttons
//      {
    wxBoxSizer *mboxListCtlButtons = new wxBoxSizer(wxVERTICAL);
    mBtnMoveAllRight = new wxButton(this, BTN_MOVEALLRIGHT, wxT("Hepsini\nEkle >>"));
    mBtnMoveRight = new wxButton(this, BTN_MOVERIGHT, wxT("Ekle >"));
    mBtnMoveLeft = new wxButton(this, BTN_MOVELEFT, wxT("< Çıkar"));
    mBtnMoveAllLeft = new wxButton(this, BTN_MOVEALLLEFT, wxT("<< Hepsini\nÇıkar"));
    mboxListCtlButtons->Add(mBtnMoveAllRight, 0, wxEXPAND | wxALL, 5);
    mboxListCtlButtons->Add(mBtnMoveRight, 0, wxEXPAND | wxALL, 5);
    mboxListCtlButtons->Add(mBtnMoveLeft, 0, wxEXPAND | wxALL, 5);
    mboxListCtlButtons->Add(mBtnMoveAllLeft, 0, wxEXPAND | wxALL, 5);
//      }

    mRightPane = new wxListBox(this, LBOX_RIGHT);

    mboxMid->Add(mLeftPane, 1, wxEXPAND | wxALL, 5);
    mboxMid->Add(mboxListCtlButtons, 0, wxALIGN_CENTER_VERTICAL|wxALIGN_CENTER_HORIZONTAL, 5);
    mboxMid->Add(mRightPane, 1, wxEXPAND | wxALL, 5);
//  }


    wxBoxSizer *mboxBottom = new wxBoxSizer(wxHORIZONTAL);
    mTxtTotalSize = new wxStaticText(this, TXT_TOTSIZE, wxT("Toplam boyut: "));
    mBtnFilterExt = new wxButton(this, BTN_FILTER, wxT("Filtre"));
    mBtnSaveList = new wxButton(this, BTN_SAVE, wxT("Listeyi kaydet..."));

    mboxBottom->Add(mTxtTotalSize, 100, wxEXPAND | wxALL, 5);
    mboxBottom->Add(mBtnFilterExt, 1, wxALL, 5);
    mboxBottom->Add(mBtnSaveList, 1, wxALL, 5);

    wxBoxSizer *mboxRoot = new wxBoxSizer(wxVERTICAL);

    mboxRoot->Add(mboxTop, 0, wxEXPAND | wxALL, 5);
    mboxRoot->Add(mboxMid, 1, wxEXPAND | wxALL, 5);
    mboxRoot->Add(mboxBottom, 0, wxEXPAND | wxALL, 5);

    mBtnSrcDir->Bind(wxEVT_BUTTON, &FileSelectionFrame::OnSrcButtonClick, this);
    mBtnLoadList->Bind(wxEVT_BUTTON, &FileSelectionFrame::OnLoadListButtonClick, this);

    mBtnMoveAllRight->Bind(wxEVT_BUTTON, &FileSelectionFrame::OnMoveAllRightButtonClick, this);
    mBtnMoveRight->Bind(wxEVT_BUTTON, &FileSelectionFrame::OnMoveRightButtonClick, this);
    mBtnMoveLeft->Bind(wxEVT_BUTTON, &FileSelectionFrame::OnMoveLeftButtonClick, this);
    mBtnMoveAllLeft->Bind(wxEVT_BUTTON, &FileSelectionFrame::OnMoveAllLeftButtonClick, this);

    mLeftPane->Bind(wxEVT_LISTBOX_DCLICK, &FileSelectionFrame::OnLeftListDoubleClick, this);
    mRightPane->Bind(wxEVT_LISTBOX_DCLICK, &FileSelectionFrame::OnRightListDoubleClick, this);

    mBtnFilterExt->Bind(wxEVT_BUTTON, &FileSelectionFrame::OnFilterExtButtonClick, this);
    mBtnSaveList->Bind(wxEVT_BUTTON, &FileSelectionFrame::OnSaveListButtonClick, this);

    this->SetSizer(mboxRoot);
    this->Layout();

    this->Centre(wxBOTH);
}

void FileSelectionFrame::OnSrcButtonClick(wxCommandEvent &) {
    wxDirDialog dlg(this, wxT("Kaynak klasör"));
    if (dlg.ShowModal() == wxID_OK) {
        setSourceDirectory(dlg.GetPath());
    }
}

void FileSelectionFrame::OnLoadListButtonClick(wxCommandEvent &) {
    wxFileDialog dlg(this, wxT("Liste dosyası"));
    std::vector<file_info> new_list;

    if (dlg.ShowModal() == wxID_OK) {
        new_list =
                ListFileHelper::load_list(std::string(dlg.GetPath().mb_str(wxConvUTF8)));

        wxMessageDialog a(this, wxT("Mevcut liste silinsin mi?"),
                          wxT("Liste Yükleme Seçeneği"), wxYES_NO | wxCANCEL | wxICON_INFORMATION);

        switch (a.ShowModal()) {
            case wxID_YES:
                m_destFiles = new_list;
                break;
            case wxID_NO:
                m_destFiles.insert(m_destFiles.end(), new_list.begin(), new_list.end());
                break;
            default:
                break;
        }

        std::sort(m_destFiles.begin(), m_destFiles.end());

        updateListBoxes();
    }
}

void FileSelectionFrame::OnMoveRightButtonClick(wxCommandEvent &e) {
    int sel = mLeftPane->GetSelection();
    if (sel != -1) {
        moveSourceToDest(sel);
        mLeftPane->SetSelection(std::min(sel, (int) m_sourceFiles.size() - 1));
    }
}

void FileSelectionFrame::OnMoveLeftButtonClick(wxCommandEvent &) {
    int sel = mRightPane->GetSelection();
    if (sel != -1) {
        moveDestToSource(sel);
        mRightPane->SetSelection(std::min(sel, (int) m_destFiles.size() - 1));
    }
}

void FileSelectionFrame::OnMoveAllRightButtonClick(wxCommandEvent &) {
    moveAllSourceToDest();
}

void FileSelectionFrame::OnMoveAllLeftButtonClick(wxCommandEvent &) {
    moveAllDestToSource();
}


void FileSelectionFrame::OnRightListDoubleClick(wxCommandEvent &) {
    int sel = mRightPane->GetSelection();
    if (sel != -1) {
        playDestItem(sel);
    }
}

void FileSelectionFrame::OnLeftListDoubleClick(wxCommandEvent &) {
    int sel = mLeftPane->GetSelection();
    if (sel != -1) {
        playSourceItem(sel);
    }
}

void FileSelectionFrame::OnFilterExtButtonClick(wxCommandEvent &) {
    const std::string ext = ".mp3";

    std::vector<file_info> new_src;

    for (const file_info &x : m_sourceFiles) {
        std::string s = x.get_ext();
        boost::to_lower(s);
        if (ext == s)
            new_src.emplace_back(x);
    }

    m_sourceFiles = std::move(new_src);
    updateListBoxes();
}


void FileSelectionFrame::OnSaveListButtonClick(wxCommandEvent &) {
    wxFileDialog dlg(this, wxT("Kaydedilecek dosya adı"), wxEmptyString, wxEmptyString, wxT("*.txt"), wxFD_SAVE);
    if (dlg.ShowModal() == wxID_OK) {
        ListFileHelper::save_list(m_destFiles, std::string(dlg.GetPath().mb_str(wxConvUTF8)));
    }
}

void FileSelectionFrame::setSourceDirectory(const wxString &path) {
    auto path2 = std::string(path.mb_str(wxConvUTF8).data());

    m_sourceDir = path2;
    m_sourceFiles = file_info::from_directory(path2);

    std::sort(m_sourceFiles.begin(), m_sourceFiles.end(),
              [](const file_info &a, const file_info &b) {
                  return a.get_name() < b.get_name();
              });

    updateDirTexts();
    updateListBoxes();
}

void FileSelectionFrame::moveSourceToDest(int sel) {
    auto item = m_sourceFiles[sel];
    m_sourceFiles.erase(m_sourceFiles.begin() + sel);
    m_destFiles.push_back(item);
    std::sort(m_destFiles.begin(), m_destFiles.end());
    updateListBoxes();
}

void FileSelectionFrame::moveDestToSource(int sel) {
    auto item = m_destFiles[sel];
    m_destFiles.erase(m_destFiles.begin() + sel);
    m_sourceFiles.push_back(item);
    std::sort(m_sourceFiles.begin(), m_sourceFiles.end());
    updateListBoxes();
}

#define IGNORE_UNUSED_RESULT(x) if (x);

void FileSelectionFrame::playSourceItem(int sel) {
    IGNORE_UNUSED_RESULT(
            system(("vlc \"" + m_sourceFiles[sel].get_path() + "\" &").c_str())
    );
}

void FileSelectionFrame::playDestItem(int sel) {
    IGNORE_UNUSED_RESULT(
            system(("vlc \"" + m_destFiles[sel].get_path() + "\" &").c_str())
    );
}

void fill_pane(wxListBox *lb, const std::vector<file_info>& v) {
    std::vector<wxString> fnames;
    std::transform(v.begin(), v.end(), std::back_inserter(fnames),
                   [](const file_info &a) { return wxString(a.get_name().c_str(), wxConvUTF8); });
    lb->Clear();
    lb->Append(fnames);
    lb->SetMinSize({0, 0}); // to fix distorted layout problem.
};

void FileSelectionFrame::updateListBoxes() {
    fill_pane(mLeftPane, m_sourceFiles);
    fill_pane(mRightPane, m_destFiles);
    this->Layout();

    size_t total = std::accumulate(m_destFiles.begin(), m_destFiles.end(), (size_t) 0,
                                   [](size_t a, const file_info &b) {
                                       return a + b.get_size(file_info::size_format::mbytes);
                                   });

    mTxtTotalSize->SetLabelText(wxString("Toplam boyut: " + std::to_string(total) + " MB"));
}

void FileSelectionFrame::updateDirTexts() {
    mTxtSrcDir->SetLabelText(m_sourceDir);
}

void FileSelectionFrame::moveAllSourceToDest() {
    m_destFiles.insert(m_destFiles.end(), m_sourceFiles.begin(), m_sourceFiles.end());
    m_sourceFiles.clear();
    updateListBoxes();
}

void FileSelectionFrame::moveAllDestToSource() {
    m_sourceFiles.insert(m_sourceFiles.end(), m_destFiles.begin(), m_destFiles.end());
    m_destFiles.clear();
    updateListBoxes();
}
