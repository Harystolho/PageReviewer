/*
 * Day.cpp
 *
 *  Created on: Sep 1, 2018
 *      Author: Harystolho
 */

#include "Day.h"

namespace Page {

Day::Day() {

}

Day::~Day() {
	// TODO Auto-generated destructor stub
}

void Day::addPost(Post* post){
	posts.push_back(post);
}

std::vector<Post*> Day::getPosts(){
	return posts;
}

void Day::removePost(Post* post){
	for(auto it = posts.begin(); it != posts.end();){
		if(*it == post){
			posts.erase(it);
			break;
		} else{
			++it;
		}
	}
}

} /* namespace Page */
