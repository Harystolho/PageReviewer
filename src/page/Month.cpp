/*
 * Month.cpp
 *
 *  Created on: Sep 1, 2018
 *      Author: Harystolho
 */

#include "Month.h"

namespace Page {

Month::Month() {
	for (int i = 0; i <= 30; i++) {
		days[i] = new Day();
	}
}

Month::~Month() {
	// TODO Auto-generated destructor stub
}

Day* Month::getDay(int day) {
	return days[day - 1];
}

} /* namespace Page */
