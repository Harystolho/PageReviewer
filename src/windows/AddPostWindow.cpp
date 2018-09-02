/*
 * AddPostWindow.cpp
 *
 *  Created on: Sep 1, 2018
 *      Author: Harystolho
 */

#include "AddPostWindow.h"

enum ADD_POST_ID {
	TITLE_ID, LINK_ID, DATE_ID, TEXT_ID, ADD_ID
};

AddPostWindow::AddPostWindow(wxWindow* parent) :
		wxFrame(NULL, wxID_ANY, "Add Post", wxPoint(0, 0), wxSize(500, 280)) {
	Center();

	pageFrame = static_cast<PageFrame*>(parent);

	panel = new wxPanel(this, wxID_ANY);

	createObjects();
}

AddPostWindow::~AddPostWindow() {
// TODO Auto-generated destructor stub
}

void AddPostWindow::createObjects() {

	wxStaticText *titleLabel = new wxStaticText(panel, wxID_ANY, "Title",
			wxPoint(5, 5));
	wxStaticText *linkLabel = new wxStaticText(panel, wxID_ANY, "Link",
			wxPoint(5,
					titleLabel->GetPosition().y
							+ titleLabel->GetSize().GetHeight() + 10));
	wxStaticText *textLabel = new wxStaticText(panel, wxID_ANY, "Text",
			wxPoint(5,
					linkLabel->GetPosition().y
							+ linkLabel->GetSize().GetHeight() + 10));

	title = new wxTextCtrl(panel, TITLE_ID, wxT(""),
			wxPoint(
					titleLabel->GetPosition().x
							+ titleLabel->GetSize().GetWidth() + 15,
					titleLabel->GetPosition().y));
	link = new wxTextCtrl(panel, TITLE_ID, wxT(""),
			wxPoint(
					linkLabel->GetPosition().x + linkLabel->GetSize().GetWidth()
							+ 15, linkLabel->GetPosition().y));
	text = new wxTextCtrl(panel, TEXT_ID, wxT(""),
			wxPoint(
					textLabel->GetPosition().x + textLabel->GetSize().GetWidth()
							+ 15, textLabel->GetPosition().y));
	date = new wxDatePickerCtrl(panel, DATE_ID, wxDateTime::Now(),
			wxPoint(5,
					textLabel->GetPosition().y
							+ textLabel->GetSize().GetHeight() + 10));
	add = new wxButton(panel, ADD_ID, wxT("Add Post"),
			wxPoint(5,
					date->GetPosition().y + date->GetSize().GetHeight() + 10));



}
