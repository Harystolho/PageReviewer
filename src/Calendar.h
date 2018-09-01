/*
 * Calendar.h
 *
 *  Created on: Sep 1, 2018
 *      Author: Harystolho
 */

#ifndef CALENDAR_H_
#define CALENDAR_H_

#include "page/Year.h"

namespace Page {

class Calendar {
public:
	Calendar(int year);
	virtual ~Calendar();

	void setup();
	void drawCalendar();
private:
};

} /* namespace Page */

#endif /* CALENDAR_H_ */
