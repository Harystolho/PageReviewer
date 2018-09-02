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
		wxFrame(parent, wxID_ANY, "Add Post", wxPoint(0, 0), wxSize(500, 280)) {
	Center();

	pageFrame = static_cast<PageFrame*>(parent);

	createObjects();

	panel = new wxPanel(this, wxID_ANY);

}

AddPostWindow::~AddPostWindow() {
// TODO Auto-generated destructor stub
}

void AddPostWindow::createObjects() {

	wxStaticText *titleLabel = new wxStaticText(panel, wxID_ANY, "Title",
			wxPoint(), wxSize());
	wxStaticText *linkLabel = new wxStaticText(panel, wxID_ANY, "Link",
			wxPoint(), wxSize());
	wxStaticText *textLabel = new wxStaticText(panel, wxID_ANY, "Text",
			wxPoint(), wxSize());

	title = new wxTextCtrl(panel, TITLE_ID, wxT(""),
			wxPoint(0, 0));
	link = new wxTextCtrl(panel, TITLE_ID, wxT(""), wxPoint(0, 0));
	text = new wxTextCtrl(panel, TEXT_ID, wxT(""), wxPoint(0, 0));
	date = new wxDatePickerCtrl(panel, DATE_ID, wxDateTime::Now(),
			wxPoint(0, 0));
	add = new wxButton(panel, ADD_ID, wxT("Add Post"));

}
