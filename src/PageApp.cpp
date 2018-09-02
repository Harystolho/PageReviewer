#include "PageApp.h"

bool PageApp::OnInit() {
	frame = new PageFrame("Page Reviewer", wxPoint(0, 0), wxSize(1280, 720));

	frame->setCalendar(createCalendar());

	frame->showCalendar();

	frame->Show(true);
	return true;
}

Page::Calendar* PageApp::createCalendar() {
	Page::Calendar* calendar = new Page::Calendar();
	return calendar;
}
