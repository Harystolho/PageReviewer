/*
 * PageFrame.cpp
 *
 *  Created on: Aug 30, 2018
 *      Author: Harystolho
 */

#include "PageFrame.h"
#include "wx/gdicmn.h"
#include "wx/crt.h"

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

}

void PageFrame::createObjects() {
	addPost = new wxButton(panel, PAGE_ID::ADD_POST, wxT("Add Post"),
			wxPoint(15, 15));

	listPosts = new wxButton(panel, PAGE_ID::LIST_POSTS, wxT("List Posts"),
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
	Connect(PAGE_ID::ADD_POST, wxEVT_COMMAND_BUTTON_CLICKED,
			wxCommandEventHandler(PageFrame::OnAddPost));
}

void PageFrame::setCalendar(Page::Calendar *calendar) {
	this->calendar = calendar;
}
