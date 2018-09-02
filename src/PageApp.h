/*
 * PageApp.h
 *
 *  Created on: Aug 30, 2018
 *      Author: Harystolho
 */

#ifndef PAGEAPP_H_
#define PAGEAPP_H_
#include "wx/app.h"
#include "PageFrame.h"
#include "Calendar.h"

class PageApp: public wxApp{
public:
	virtual bool OnInit();
private:
	PageFrame* frame;

	Page::Calendar* createCalendar();
};

#endif /* PAGEAPP_H_ */
