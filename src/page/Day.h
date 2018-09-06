/*
 * Day.h
 *
 *  Created on: Sep 1, 2018
 *      Author: Harystolho
 */

#ifndef PAGE_DAY_H_
#define PAGE_DAY_H_

#include <vector>
#include "post.h"

namespace Page {

class Day {
public:
	Day(int day);
	virtual ~Day();
	std::vector<Post*> getPosts();
	void addPost(Post *post);
	void removePost(Post *post);

	int getDay() {
		return day;
	}

private:
	std::vector<Post*> posts;

	int day;

};

} /* namespace Page */

#endif /* PAGE_DAY_H_ */
