/*
 * post.cpp
 *
 *  Created on: Aug 28, 2018
 *      Author: Harystolho
 */

#include "post.h"
#include <iostream>

Post::Post() {

}

Post::Post(const std::string& title_) :
		title(title_) {

}

Post::~Post() {

}

void Post::setTitle(const std::string& title) {
	this->title = title;
}

std::string Post::getTitle() const {
	return title;
}

void Post::setLink(const std::string& url) {
	link = url;
}

std::string Post::getLink() const {
	return link;
}

void Post::setDate(const wxDateTime date) {
	this->date = date;
}

wxDateTime Post::getDate() {
	return date;
}

void Post::setText(const std::string& text) {
	this->text = text;
}

std::string Post::getText() {
	return text;
}

void Post::updateReviewDate(wxDateTime time) {
	date = time;



}
