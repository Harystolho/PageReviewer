/*
 * Month.h
 *
 *  Created on: Sep 1, 2018
 *      Author: Harystolho
 */

#ifndef PAGE_MONTH_H_
#define PAGE_MONTH_H_

#include "Day.h"

namespace Page {

class Month {
public:
	Month();
	virtual ~Month();

	Day* getDay(int day);

private:
	std::string name;
	Day* days[31] = { 0 };
};

} /* namespace Page */

#endif /* PAGE_MONTH_H_ */
