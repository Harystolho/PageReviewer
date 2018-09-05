/*
 * PageVScrollBox.cpp
 *
 *  Created on: Sep 1, 2018
 *      Author: Harystolho
 */

#include "PageScrollBox.h"

#include "iostream"

PageScrollBox::PageScrollBox(wxWindow* window, wxWindowID id, wxPoint point,
		wxSize size) :
		wxScrolledWindow(window, wxID_ANY, point, size), day(0), PageDay(
				nullptr) {

	sizer = new wxBoxSizer(wxVERTICAL);
	SetSizer(sizer);

	SetMaxSize(size);
}

PageScrollBox::~PageScrollBox() {
}

void PageScrollBox::setDay(Page::Day* day) {
	PageDay = day;
}

void PageScrollBox::drawPosts() {
	for (Post* p : PageDay->getPosts()) {
		wxWindowID id = wxWindow::NewControlId();
		PostAdapter* text = new PostAdapter(this, id, p->getTitle(), p);

		text->Bind(wxEVT_LEFT_DOWN, [text](wxMouseEvent&) {
			text->openWindow();
		}, id);

		GetSizer()->Add(text, 0, wxALL, 2);
	}
	SetSizer(sizer, true);
	FitInside();
	SetScrollRate(0,5);
}

