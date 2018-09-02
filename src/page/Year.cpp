/*
 * Year.cpp
 *
 *  Created on: Sep 1, 2018
 *      Author: Harystolho
 */

#include "Year.h"

namespace Page {

Year::Year(int year) :
		year(year) {

	for(int i=0; i <= 11; i++){
		months[i] = new Month();
	}
}

Year::~Year() {
	// TODO Auto-generated destructor stub
}

Month* Year::getMonth(int index) {
	return months[index];
}

}

