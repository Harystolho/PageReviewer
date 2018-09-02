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

}

PageVScrollBox::~PageVScrollBox() {
}

wxCoord PageVScrollBox::OnGetRowHeight(size_t row) const {
	return 35;
}

void PageVScrollBox::setDay(Page::Day* day){
	PageDay = day;
}

void PageVScrollBox::drawPosts(){
	for(Post* p : PageDay->getPosts()){
		SetBackgroundColour(*wxYELLOW);
	}
}
