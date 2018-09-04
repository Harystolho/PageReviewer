/*
 * PageVScrollBox.h
 *
 *  Created on: Sep 1, 2018
 *      Author: Harystolho
 */

#ifndef WINDOWS_PAGEVSCROLLBOX_H_
#define WINDOWS_PAGEVSCROLLBOX_H_

#include "wx/vscroll.h"
#include "../page/Day.h"
#include "../page/post.h"
#include "PostAdapter.h"
#include "wx/sizer.h"
#include "wx/gdicmn.h"
#include "wx/event.h"

class PageVScrollBox: public wxVScrolledWindow {
public:
	PageVScrollBox(wxWindow* window, wxWindowID id, wxPoint point, wxSize size);
	virtual ~PageVScrollBox();

	wxCoord OnGetRowHeight(size_t row) const;

	void setDay(Page::Day *day);

	void drawPosts();

private:
	int day;
	Page::Day* PageDay;

	wxBoxSizer* sizer;

	int rowHeight = 0;
};

#endif /* WINDOWS_PAGEVSCROLLBOX_H_ */
