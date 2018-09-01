/*
 * Calendar.cpp
 *
 *  Created on: Sep 1, 2018
 *      Author: Harystolho
 */

#include "Calendar.h"

namespace Page {

Calendar::Calendar(int year) :
		year(year) {

}

Calendar::~Calendar() {
	// TODO Auto-generated destructor stub
}

int Calendar::getCurrentYear() {
	auto now = std::chrono::system_clock::now();
	std::time_t now_c = std::chrono::system_clock::to_time_t(now);
	tm* parts = std::localtime(&now_c);

	return parts->tm_year;
}

int Calendar::getCurrentMonth() {
	auto now = std::chrono::system_clock::now();
	std::time_t now_c = std::chrono::system_clock::to_time_t(now);
	tm* parts = std::localtime(&now_c);

	return parts->tm_mon;
}
int Calendar::getCurrentDay() {
	auto now = std::chrono::system_clock::now();
	std::time_t now_c = std::chrono::system_clock::to_time_t(now);
	tm* parts = std::localtime(&now_c);

	return parts->tm_mday;
}

} /* namespace Page */
