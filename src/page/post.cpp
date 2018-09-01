/*
 * post.cpp
 *
 *  Created on: Aug 28, 2018
 *      Author: Harystolho
 */

#include "post.h"
#include <iostream>

Post::Post(const std::string& title_) : title(title_){

}

Post::~Post(){

}

void Post::setTitle(const std::string& title) {
	this->title = title;
}

std::string Post::getTitle() const {
	return title;
}

void Post::setUrl(const std::string& url) {
	this->url = url;
}

std::string Post::getUrl() const {
	return url;
}
