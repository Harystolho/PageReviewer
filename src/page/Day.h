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
	Day();
	virtual ~Day();
	std::vector<Post*> getPosts();
	void addPost(Post *post);
	bool removePost(Post *post);
private:
	std::vector<Post*> posts;
};

} /* namespace Page */

#endif /* PAGE_DAY_H_ */
