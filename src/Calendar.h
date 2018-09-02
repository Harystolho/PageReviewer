/*
 * Calendar.h
 *
 *  Created on: Sep 1, 2018
 *      Author: Harystolho
 */

#ifndef CALENDAR_H_
#define CALENDAR_H_

#include "page/Year.h"
#include "page/post.h"
#include "chrono"
#include <vector>

namespace Page {

class Calendar {
public:
	Calendar();
	virtual ~Calendar();

	void setup();
	void drawCalendar();

	Year* getYear(int year);

	void addPost(Post *post);

	static int getCurrentYear();
	static int getCurrentMonth();
	static int getCurrentDay();

private:
	std::vector<Year*> years;
};

} /* namespace Page */

#endif /* CALENDAR_H_ */
