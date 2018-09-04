/*
 * PostAdapter.cpp
 *
 *  Created on: Sep 3, 2018
 *      Author: Harystolho
 */

#include "PostAdapter.h"

PostAdapter::PostAdapter(wxWindow* window, wxWindowID id, wxString text,
		Post* post) :
		wxStaticText(window, id, text), frame(nullptr), post(post) {
}

PostAdapter::~PostAdapter() {
}

void PostAdapter::openWindow() {
	if (frame == nullptr) {
		frame = new wxFrame(NULL, wxID_ANY, post->getTitle(), wxDefaultPosition,
				wxSize(1000, 500), wxSTAY_ON_TOP | wxDEFAULT_FRAME_STYLE);
	}

	wxBoxSizer *verticalSizer = new wxBoxSizer(wxVERTICAL);

	wxStaticText *title = new wxStaticText(frame, wxID_ANY, post->getTitle());
	wxHyperlinkCtrl *link = new wxHyperlinkCtrl(frame, wxID_ANY,
			post->getLink(), post->getLink());

	verticalSizer->Add(title, 1, wxALIGN_CENTER | wxTOP, 5);
	verticalSizer->Add(link, 1, wxALIGN_CENTER | wxBOTTOM, 15);

	wxBoxSizer *timeSizer = new wxBoxSizer(wxHORIZONTAL);

	wxButton *ONEday = new wxButton(frame, 550, "+1 Day");
	wxButton *THREEdays = new wxButton(frame, 551, "+3 Days");
	wxButton *SEVENdays = new wxButton(frame, 552, "+7 Days");
	wxButton *FIFTEENdays = new wxButton(frame, 553, "+15 Days");
	wxButton *THIRTYdays = new wxButton(frame, 554, "+30 Days");
	wxButton *FIFYdays = new wxButton(frame, 555, "+50 Days");

	timeSizer->Add(ONEday, 1);
	timeSizer->Add(THREEdays, 1);
	timeSizer->Add(SEVENdays, 1);
	timeSizer->Add(FIFTEENdays, 1);
	timeSizer->Add(THIRTYdays, 1);
	timeSizer->Add(FIFYdays, 1);

	verticalSizer->Add(timeSizer, 1, wxALIGN_TOP | wxALIGN_CENTER | wxALL, 5);

	wxTextCtrl *text = new wxTextCtrl(frame, wxID_ANY, post->getText(),
			wxDefaultPosition, wxSize(1000, -1), wxTE_MULTILINE);
	text->SetEditable(false);

	verticalSizer->Add(text, 5, wxEXPAND | wxALL, 7);

	wxBoxSizer *editTools = new wxBoxSizer(wxHORIZONTAL);

	wxButton *edit = new wxButton(frame, 556, "EDIT");
	wxButton *save = new wxButton(frame, 557, "SAVE");
	wxButton *remove = new wxButton(frame, 558, "REMOVE");

	editTools->Add(edit, 1, wxALL, 3);
	editTools->Add(save, 1, wxALL, 3);
	editTools->Add(remove, 1, wxALL, 3);

	verticalSizer->Add(editTools, 1, wxALIGN_CENTER);

	verticalSizer->SetSizeHints(frame);

	frame->SetSizer(verticalSizer);

	frame->Center();
	frame->Show();
}
