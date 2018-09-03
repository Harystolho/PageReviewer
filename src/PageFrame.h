/*
 * PageFrame.h
 *
 *  Created on: Aug 30, 2018
 *      Author: Harystolho
 */

#ifndef PAGEFRAME_H_
#define PAGEFRAME_H_

#include "wx/frame.h"
#include "wx/event.h"
#include "wx/menu.h"
#include "wx/panel.h"
#include "Wx/button.h"
#include "Calendar.h"
#include "wx/gdicmn.h"
#include "windows/PageVScrollBox.h"
#include "windows/AddPostWindow.h"
#include "wx/wxcrtvararg.h"
#include <list>

class PageFrame: public wxFrame {
public:
	PageFrame(const wxString& title, const wxPoint& pos, const wxSize& size);

	void setCalendar(Page::Calendar *calendar);
	void showCalendar();

	Page::Calendar* getCalendar();

	const int BUTTON_SPACING = 15;
private:

	uint8_t monthIndex = 0;

	Page::Calendar* calendar;

	wxButton* addPost;
	wxButton* listPosts;

	wxPanel *panel;
	wxPanel *calendarPanel;

	void OnAddPost(wxCommandEvent& event);
	void onListPosts(wxCommandEvent& event);

	void createObjects();
	void connectEventHandlers();

	void drawCalendar();

wxDECLARE_EVENT_TABLE();
};

#endif /* PAGEFRAME_H_ */

