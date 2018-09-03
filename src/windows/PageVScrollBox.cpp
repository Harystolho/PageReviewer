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
		PostAdapter* text = new PostAdapter(this, wxID_ANY, p->getTitle(), p);
		rowHeight = text->GetSize().GetHeight();

		text->SetForegroundColour(*wxWHITE);
		GetSizer()->Add(text);
	}
	// TODO fix this shit
	SetSizerAndFit(sizer, true);
	SetRowCount(GetSizer()->GetItemCount());
}

void PageVScrollBox::onTitle(wxCommandEvent& event) {

}
