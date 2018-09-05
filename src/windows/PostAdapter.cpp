/*
 * PostAdapter.cpp
 *
 *  Created on: Sep 3, 2018
 *      Author: Harystolho
 */

#include "PostAdapter.h"

extern PageFrame* pageFrame;

PostAdapter::PostAdapter(wxWindow* window, wxWindowID id, wxString text,
		Post* post) :
		wxStaticText(window, id, text), frame(nullptr), post(post) {
}

PostAdapter::~PostAdapter() {
}

void PostAdapter::openWindow() {
	frame = new wxFrame(NULL, wxID_ANY, post->getTitle(), wxDefaultPosition,
			wxSize(1000, 500), wxDEFAULT_FRAME_STYLE);

	wxBoxSizer *verticalSizer = new wxBoxSizer(wxVERTICAL);

	wxStaticText *title = new wxStaticText(frame, wxID_ANY, post->getTitle());
	verticalSizer->Add(title, 0, wxALIGN_CENTER | wxTOP, 5);

	title->SetFont(wxFontInfo(20).FaceName("Inconsolata"));

	if(!post->getLink().empty()){
		wxHyperlinkCtrl *link = new wxHyperlinkCtrl(frame, wxID_ANY,
				post->getLink(), post->getLink());
		verticalSizer->Add(link, 0, wxALIGN_CENTER | wxBOTTOM, 15);
	}

	wxBoxSizer *timeSizer = new wxBoxSizer(wxHORIZONTAL);

	wxButton *ONEday = new wxButton(frame, 550, "+1 Day");
	wxButton *THREEdays = new wxButton(frame, 551, "+3 Days");
	wxButton *SEVENdays = new wxButton(frame, 552, "+7 Days");
	wxButton *FIFTEENdays = new wxButton(frame, 553, "+15 Days");
	wxButton *THIRTYdays = new wxButton(frame, 554, "+30 Days");
	wxButton *FIFYdays = new wxButton(frame, 555, "+50 Days");

	ONEday->Bind(wxEVT_LEFT_DOWN, [&](wxMouseEvent&) {
		updatePost(post, 1);
	}, 550);
	THREEdays->Bind(wxEVT_LEFT_DOWN, [&](wxMouseEvent&) {
		updatePost(post, 3);
	}, 551);
	SEVENdays->Bind(wxEVT_LEFT_DOWN, [&](wxMouseEvent&) {
		updatePost(post, 7);
	}, 552);
	FIFTEENdays->Bind(wxEVT_LEFT_DOWN, [&](wxMouseEvent&) {
		updatePost(post, 15);
	}, 553);
	THIRTYdays->Bind(wxEVT_LEFT_DOWN, [&](wxMouseEvent&) {
		updatePost(post, 30);
	}, 554);
	FIFYdays->Bind(wxEVT_LEFT_DOWN, [&](wxMouseEvent&) {
		updatePost(post, 50);
	}, 555);

	timeSizer->Add(ONEday, 1);
	timeSizer->Add(THREEdays, 1);
	timeSizer->Add(SEVENdays, 1);
	timeSizer->Add(FIFTEENdays, 1);
	timeSizer->Add(THIRTYdays, 1);
	timeSizer->Add(FIFYdays, 1);

	verticalSizer->Add(timeSizer, 0, wxALIGN_TOP | wxALIGN_CENTER | wxALL, 10);

	wxTextCtrl *text = new wxTextCtrl(frame, wxID_ANY, post->getText(),
			wxDefaultPosition, wxSize(1000, -1), wxTE_MULTILINE);
	text->SetEditable(false);

	text->SetFont(wxFontInfo(15).FaceName("Inconsolata"));

	verticalSizer->Add(text, 5, wxEXPAND | wxALL, 7);

	wxBoxSizer *editTools = new wxBoxSizer(wxHORIZONTAL);

	wxButton *edit = new wxButton(frame, 556, "EDIT");
	wxButton *save = new wxButton(frame, 557, "SAVE");
	wxButton *remove = new wxButton(frame, 558, "REMOVE");

	edit->Bind(wxEVT_LEFT_DOWN, [text](wxMouseEvent&) {
		text->SetEditable(true);
	}, 556);
	save->Bind(wxEVT_LEFT_DOWN, [&, text](wxMouseEvent&) {
		text->SetEditable(false);
		post->setText(text->GetValue().ToStdString());
	}, 557);
	remove->Bind(wxEVT_LEFT_DOWN, [&](wxMouseEvent&) {
		pageFrame->getCalendar()->removePost(post);
		delete post;
		frame->Close();
		pageFrame->redrawCalendar();
	}, 558);

	editTools->Add(edit, 1, wxALL, 3);
	editTools->Add(save, 1, wxALL, 3);
	editTools->Add(remove, 1, wxALL, 3);

	verticalSizer->Add(editTools, 1, wxALIGN_CENTER);

	verticalSizer->SetSizeHints(frame);

	frame->SetSizer(verticalSizer);

	frame->Center();
	frame->Show();
}

void PostAdapter::updatePost(Post* post, int days) {
	pageFrame->getCalendar()->removePost(post);
	post->updateReviewDate(post->getDate().Add(wxDateSpan::Days(days)));
	pageFrame->getCalendar()->addPost(post);
	frame->Close();
	pageFrame->redrawCalendar();
}
