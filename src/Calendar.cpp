/*
 * Calendar.cpp
 *
 *  Created on: Sep 1, 2018
 *      Author: Harystolho
 */

#include "Calendar.h"

auto now = std::chrono::system_clock::now();
std::time_t now_c = std::chrono::system_clock::to_time_t(now);
static tm* parts = std::localtime(&now_c);

namespace Page {

Calendar::Calendar() {
	years.push_back(new Year(getCurrentYear()));
	years.push_back(new Year(getCurrentYear() + 1));
}

Calendar::~Calendar() {
	// TODO Auto-generated destructor stub
}

Year* Calendar::getYear(int year) {
	return years.at(getCurrentYear() - year);
}

void Calendar::addPost(Post* post){
	Year* postYear = getYear(post->getDate().GetYear());

	Month* postMonth = postYear->getMonth(post->getDate().GetMonth());

	Day* postDay = postMonth->getDay(post->getDate().GetDay());

	postDay->addPost(post);
}

int Calendar::getCurrentYear() {
	return parts->tm_year + 1900;
}

int Calendar::getCurrentMonth() {
	return parts->tm_mon;
}
int Calendar::getCurrentDay() {
	return parts->tm_mday;
}

} /* namespace Page */
