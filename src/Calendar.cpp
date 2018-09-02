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

int Calendar::getCurrentYear() {
	return parts->tm_year;
}

int Calendar::getCurrentMonth() {
	return parts->tm_mon;
}
int Calendar::getCurrentDay() {
	return parts->tm_mday;
}

} /* namespace Page */
