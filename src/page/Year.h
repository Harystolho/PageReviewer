/*
 * Year.h
 *
 *  Created on: Sep 1, 2018
 *      Author: Harystolho
 */

#ifndef PAGE_YEAR_H_
#define PAGE_YEAR_H_

#include "Month.h"

namespace Page {

class Year {
public:
	Year(int year);
	virtual ~Year();
	Month* getMonth(int index);

	inline int getYear(){
		return year;
	}
private:
	int year;
	Month* months[12] = {0};
};

}

#endif /* PAGE_YEAR_H_ */
