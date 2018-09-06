/*
 * PageVScrollBox.cpp
 *
 *  Created on: Sep 1, 2018
 *      Author: Harystolho
 */

#include "PageScrollBox.h"

#include "iostream"

extern PageFrame* pageFrame;

PageScrollBox::PageScrollBox(wxWindow* window, wxWindowID id, wxPoint point,
		wxSize size) :
		wxScrolledWindow(window, wxID_ANY, point, size), PageDay(nullptr) {

	sizer = new wxBoxSizer(wxVERTICAL);

	dayText = new wxStaticText(this, wxID_ANY, "0");
	postSizer = new wxBoxSizer(wxVERTICAL);

	sizer->Add(dayText, 0, wxLEFT, 3);
	sizer->Add(postSizer);

	SetSizer(sizer);

	SetBackgroundColour(wxColour("#e5c100"));

	//SetMaxSize(size);
}

PageScrollBox::~PageScrollBox() {
}

void PageScrollBox::setDay(Page::Day* day) {
	PageDay = day;

	this->dayText->SetLabel(std::to_string(day->getDay()));

	if (day->getDay() == Page::Calendar::getCurrentDay() && pageFrame->isDisplayingCurrentMonth()) {
		SetBackgroundColour(wxColour("#b79a00"));
	}

}

void PageScrollBox::drawPosts() {
	for (Post* p : PageDay->getPosts()) {
		wxWindowID id = wxWindow::NewControlId();
		PostAdapter* text = new PostAdapter(this, id, p->getTitle(), p);

		text->Bind(wxEVT_LEFT_DOWN, [text](wxMouseEvent&) {
			text->openWindow();
		}, id);

		postSizer->Add(text, 0, wxALL, 2);
	}

	SetSizer(sizer, true);
	FitInside();
	SetScrollRate(0, 5);
}

