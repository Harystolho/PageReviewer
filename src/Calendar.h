/*
 * Calendar.h
 *
 *  Created on: Sep 1, 2018
 *      Author: Harystolho
 */

#ifndef CALENDAR_H_
#define CALENDAR_H_

#include "page/Year.h"
#include "chrono"

namespace Page {

class Calendar {
public:
	Calendar(int year);
	virtual ~Calendar();

	void setup();
	void drawCalendar();

	inline Year& getYear() {
		return year;
	}

	static int getCurrentYear();
	static int getCurrentMonth();
	static int getCurrentDay();
private:
	Year year;
};

} /* namespace Page */

#endif /* CALENDAR_H_ */
