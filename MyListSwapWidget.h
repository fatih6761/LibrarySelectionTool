//
// Created by fatih on 9/1/16.
//

#ifndef LIBRARYSELECTIONTOOL_MYLISTSWAPWIDGET_H
#define LIBRARYSELECTIONTOOL_MYLISTSWAPWIDGET_H

#include <wx/wx.h>

class ListSwapWidget : public wxPanel {
public:
    ListSwapWidget(wxWindow *parent,
                   wxWindowID winid = wxID_ANY,
                   const wxPoint& pos = wxDefaultPosition,
                   const wxSize& size = wxDefaultSize,
                   long style = wxTAB_TRAVERSAL | wxNO_BORDER,
                   const wxString& name = wxPanelNameStr);

    wxListBox*  mLeftPane;
    wxButton*   mBtnMoveRight;
    wxButton*   mBtnMoveLeft;
    wxListBox*  mRightPane;

};


#endif //LIBRARYSELECTIONTOOL_MYLISTSWAPWIDGET_H
