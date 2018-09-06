/*
 * PageVScrollBox.h
 *
 *  Created on: Sep 1, 2018
 *      Author: Harystolho
 */

#ifndef WINDOWS_PAGESCROLLBOX_H_
#define WINDOWS_PAGESCROLLBOX_H_

#include "wx/scrolwin.h"
#include "../page/Day.h"
#include "../page/post.h"
#include "PostAdapter.h"
#include "wx/sizer.h"
#include "wx/gdicmn.h"
#include "wx/event.h"
#include "wx/stattext.h"

class PageScrollBox: public wxScrolledWindow {
public:
	PageScrollBox(wxWindow* window, wxWindowID id, wxPoint point, wxSize size);
	virtual ~PageScrollBox();

	void setDay(Page::Day *day);

	void drawPosts();

private:
	Page::Day* PageDay;

	wxStaticText* dayText;

	wxBoxSizer* sizer;
	wxBoxSizer* postSizer;
};

#endif /* WINDOWS_PAGESCROLLBOX_H_ */
