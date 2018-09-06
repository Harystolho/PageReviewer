/*
 * PageFrame.h
 *
 *  Created on: Aug 30, 2018
 *      Author: Harystolho
 */

#ifndef PAGEFRAME_H_
#define PAGEFRAME_H_

namespace Page {
	class Calendar;
}

#include "wx/frame.h"
#include "wx/event.h"
#include "wx/menu.h"
#include "wx/panel.h"
#include "Wx/button.h"
#include "Calendar.h"
#include "wx/colour.h"
#include "windows/AddPostWindow.h"
#include "wx/wxcrtvararg.h"
#include <list>
#include "windows/PageScrollBox.h"

class PageFrame: public wxFrame {
public:
	PageFrame(const wxString& title, const wxPoint& pos, const wxSize& size);

	void setCalendar(Page::Calendar *calendar);
	void showCalendar();

	Page::Calendar* getCalendar();

	void redrawCalendar();

	bool isDisplayingCurrentMonth();

	const int BUTTON_SPACING = 15;
private:

	int8_t monthIndex = 0;

	Page::Calendar* calendar;

	wxButton* addPost;
	wxButton* listPosts;

	wxButton* nextMonth;
	wxButton* previousMonth;

	wxPanel *panel;
	wxPanel *calendarPanel;

	void OnAddPost(wxCommandEvent& event);
	void onListPosts(wxCommandEvent& event);

	void onPreviousMonth(wxCommandEvent& event);
	void onNextMonth(wxCommandEvent& event);

	void createObjects();
	void connectEventHandlers();

	void drawCalendar();

wxDECLARE_EVENT_TABLE();
};

#endif /* PAGEFRAME_H_ */

