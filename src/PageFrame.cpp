/*
 * PageFrame.cpp
 *
 *  Created on: Aug 30, 2018
 *      Author: Harystolho
 */

#include "PageFrame.h"

enum PAGE_ID {
	ADD_POST, LIST_POSTS
};

PageFrame::PageFrame(const wxString& title, const wxPoint& pos,
		const wxSize& size) :
		wxFrame(NULL, wxID_ANY, title, pos, size), calendar(nullptr) {
	Center();

	panel = new wxPanel(this, wxID_ANY);

	createObjects();
	connectEventHandlers();

}

void PageFrame::OnAddPost(wxCommandEvent& event) {
	AddPostWindow* window = new AddPostWindow(this);
	window->Show(true);
}

void PageFrame::createObjects() {
	addPost = new wxButton(panel, ADD_POST, wxT("Add Post"), wxPoint(15, 15));

	listPosts = new wxButton(panel, LIST_POSTS, wxT("List Posts"),
			wxPoint(
					addPost->GetPosition().x + addPost->GetSize().GetWidth()
							+ PageFrame::BUTTON_SPACING, 15));

	calendarPanel = new wxPanel(panel, wxID_ANY,
			wxPoint(15, addPost->GetPosition().y + 45),
			wxSize(this->GetSize().GetWidth() - 45,
					this->GetSize().GetHeight() - 15 - 30
							- addPost->GetSize().GetHeight() - 45));

	calendarPanel->SetBackgroundColour(wxColour(204, 204, 204));
}

void PageFrame::connectEventHandlers() {
	Connect(ADD_POST, wxEVT_COMMAND_BUTTON_CLICKED,
			wxCommandEventHandler(PageFrame::OnAddPost));
	Connect(LIST_POSTS, wxEVT_COMMAND_BUTTON_CLICKED,
			wxCommandEventHandler(PageFrame::onListPosts));
}

void PageFrame::setCalendar(Page::Calendar *calendar) {
	this->calendar = calendar;
}

void PageFrame::showCalendar() {
	if (calendar != nullptr) {
		drawCalendar();
	}
}

void PageFrame::drawCalendar() {

	int rows = 5;
	int colums = 7;

	int width = calendarPanel->GetSize().GetWidth() / colums;
	int height = calendarPanel->GetSize().GetHeight() / rows;

	int day = 1;

	bool exit = false;

	for (int j = 0; j < rows && !exit; j++) {
		for (int i = 0; i < colums; i++) {
			PageVScrollBox *window = new PageVScrollBox(calendarPanel, wxID_ANY,
					wxPoint(width * i, height * j), wxSize(width, height));

			window->setDay(
					calendar->getYear(Page::Calendar::getCurrentYear())->getMonth(
							Page::Calendar::getCurrentMonth() + monthIndex)->getDay(
							day));

			window->drawPosts();

			if (day == 31) {
				exit = true;
				break;
			} else {
				day++;
			}
		}
	}

	calendarPanel->Refresh(true);
}

void PageFrame::onListPosts(wxCommandEvent& event) {
	calendarPanel->DestroyChildren();
	drawCalendar();
}

Page::Calendar* PageFrame::getCalendar() {
	return calendar;
}
