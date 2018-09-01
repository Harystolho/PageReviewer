#include "PageApp.h"

bool PageApp::OnInit() {
	frame = new PageFrame("Page Reviewer", wxPoint(0, 0), wxSize(1280, 720));

	frame->Show(true);
	return true;
}

Page::Calendar* PageApp::createCalendar(int year) {
	Page::Calendar* calendar = new Page::Calendar();
}
