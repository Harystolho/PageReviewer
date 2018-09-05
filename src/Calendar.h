/*
 * Calendar.h
 *
 *  Created on: Sep 1, 2018
 *      Author: Harystolho
 */

#ifndef CALENDAR_H_
#define CALENDAR_H_

#include "PageFrame.h"
#include "page/Year.h"
#include "page/post.h"
#include "chrono"
#include <vector>
#include "nlohmann/json.hpp"
#include "fstream"
#include "ostream"

namespace Page {

class Calendar {
public:
	Calendar();
	virtual ~Calendar();

	void setup();
	void drawCalendar();

	Year* getYear(int year);

	void addPost(Post *post);
	void removePost(Post* post);

	void loadFromJson(std::string file);
	void saveToJson(std::string file);

	static int getCurrentYear();
	static int getCurrentMonth();
	static int getCurrentDay();

private:
	std::vector<Year*> years;
};

} /* namespace Page */

#endif /* CALENDAR_H_ */
