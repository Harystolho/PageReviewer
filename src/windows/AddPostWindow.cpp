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
		wxFrame(NULL, wxID_ANY, "Add Post", wxPoint(0, 0), wxSize(850, 350)) {
	Center();

	pageFrame = dynamic_cast<PageFrame*>(parent);

	sizer = new wxBoxSizer(wxVERTICAL);

	SetSizer(sizer);

	createObjects();
}

AddPostWindow::~AddPostWindow() {
// TODO Auto-generated destructor stub
}

void AddPostWindow::createObjects() {

	wxBoxSizer *topSizer = new wxBoxSizer(wxHORIZONTAL);

	wxBoxSizer *titleSizer = new wxBoxSizer(wxVERTICAL);

	wxBoxSizer *linkSizer = new wxBoxSizer(wxVERTICAL);

	wxBoxSizer *textSizer = new wxBoxSizer(wxVERTICAL);

	wxStaticText *titleLabel = new wxStaticText(this, wxID_ANY, "Title",
			wxPoint(5, 5));
	wxStaticText *linkLabel = new wxStaticText(this, wxID_ANY, "Link",
			wxPoint(5,
					titleLabel->GetPosition().y
							+ titleLabel->GetSize().GetHeight() + 10));
	wxStaticText *textLabel = new wxStaticText(this, wxID_ANY, "Text",
			wxPoint(5,
					linkLabel->GetPosition().y
							+ linkLabel->GetSize().GetHeight() + 10));

	title = new wxTextCtrl(this, TITLE_ID, wxT(""),
			wxPoint(
					titleLabel->GetPosition().x
							+ titleLabel->GetSize().GetWidth() + 15,
					titleLabel->GetPosition().y));
	link = new wxTextCtrl(this, TITLE_ID, wxT(""),
			wxPoint(
					linkLabel->GetPosition().x + linkLabel->GetSize().GetWidth()
							+ 15, linkLabel->GetPosition().y));

	text = new wxTextCtrl(this, TEXT_ID, wxT(""),
			wxPoint(
					textLabel->GetPosition().x + textLabel->GetSize().GetWidth()
							+ 15, textLabel->GetPosition().y),
			wxSize(850, 350));
	date = new wxDatePickerCtrl(this, DATE_ID, wxDateTime::Now(),
			wxPoint(title->GetPosition().x + title->GetSize().GetWidth() + 15,
					title->GetPosition().y), title->GetSize());
	add = new wxButton(this, ADD_ID, wxT("Add Post"),
			wxPoint(link->GetPosition().x + link->GetSize().GetWidth() + 15,
					link->GetPosition().y));

	titleSizer->Add(titleLabel);
	titleSizer->Add(title);

	topSizer->Add(titleSizer,1);
	topSizer->Add(date, 1, wxLEFT, 35);

	linkSizer->Add(linkLabel);
	linkSizer->Add(link);

	textSizer->Add(textLabel);
	textSizer->Add(text, 1, wxEXPAND);

	sizer->Add(topSizer, 0, wxALL, 5);
	sizer->Add(linkSizer, 0, wxALL, 5);
	sizer->Add(textSizer, 5, wxALL, 5);
	sizer->Add(add, 0, wxCENTER | wxALL, 5);

	sizer->SetSizeHints(this);

	Connect(ADD_ID, wxEVT_COMMAND_BUTTON_CLICKED,
			wxCommandEventHandler(AddPostWindow::OnAddPost));

}

void AddPostWindow::OnAddPost(wxCommandEvent& event) {
	if(title->GetValue().IsEmpty() || !date->GetValue().IsValid() || text->GetValue().IsEmpty()){
		return;
	}

	Post *post = new Post();
	post->setTitle(title->GetValue().ToStdString());
	post->setLink(link->GetValue().ToStdString());
	post->setDate(date->GetValue());
	post->setText(text->GetValue().ToStdString());

	pageFrame->getCalendar()->addPost(post);

	Close(true);
	pageFrame->redrawCalendar();
}
