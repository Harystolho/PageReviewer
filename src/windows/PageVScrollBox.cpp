/*
 * PageVScrollBox.cpp
 *
 *  Created on: Sep 1, 2018
 *      Author: Harystolho
 */

#include "PageVScrollBox.h"
#include "iostream"

PageVScrollBox::PageVScrollBox(wxWindow* window, wxWindowID id, wxPoint point,
		wxSize size) :
		wxVScrolledWindow(window, wxID_ANY, point, size), day(0), PageDay(
				nullptr) {

	sizer = new wxBoxSizer(wxVERTICAL);
	SetSizer(sizer);

	SetMaxSize(size);
}

PageVScrollBox::~PageVScrollBox() {
}

wxCoord PageVScrollBox::OnGetRowHeight(size_t row) const {
	return rowHeight;
}

void PageVScrollBox::setDay(Page::Day* day) {
	PageDay = day;
}

void PageVScrollBox::drawPosts() {
	for (Post* p : PageDay->getPosts()) {
		wxWindowID id = wxWindow::NewControlId();
		PostAdapter* text = new PostAdapter(this, id, p->getTitle(), p);

		text->Bind(wxEVT_LEFT_DOWN, [text](wxMouseEvent&){
			text->openWindow();
		}, id);

		rowHeight = text->GetSize().GetHeight();

		GetSizer()->Add(text, 1, wxALL, 2);
	}
	// TODO fix this shit
	SetSizerAndFit(sizer, true);
	//SetRowCount(GetSizer()->GetItemCount());
}

