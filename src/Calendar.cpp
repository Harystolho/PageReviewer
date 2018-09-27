/*
 * Calendar.cpp
 *
 *  Created on: Sep 1, 2018
 *      Author: Harystolho
 */

#include "Calendar.h"

using json = nlohmann::json;

extern PageFrame* pageFrame;

auto now = std::chrono::system_clock::now();
std::time_t now_c = std::chrono::system_clock::to_time_t(now);
static tm* parts = std::localtime(&now_c);

namespace Page {

Calendar::Calendar() {
	years.push_back(new Year(getCurrentYear()));
	years.push_back(new Year(getCurrentYear() + 1));
}

Calendar::~Calendar() {
	// TODO Auto-generated destructor stub
}

Year* Calendar::getYear(int year) {
	return years.at(getCurrentYear() - year);
}

void Calendar::addPost(Post* post) {
	Year* postYear = getYear(post->getDate().GetYear());

	Month* postMonth = postYear->getMonth(post->getDate().GetMonth());

	Day* postDay = postMonth->getDay(post->getDate().GetDay());

	postDay->addPost(post);
}

void Calendar::removePost(Post* post) {
	Year* postYear = getYear(post->getDate().GetYear());
	Month* postMonth = postYear->getMonth(post->getDate().GetMonth());
	Day* postDay = postMonth->getDay(post->getDate().GetDay());

	postDay->removePost(post);
}

void Calendar::loadFromJson(std::string file) {
	std::ifstream input;
	input.open(file);

	json j;
	input >> j;

	for (json::iterator it = j.begin(); it != j.end(); ++it) {
		Post *post = new Post();

		post->setTitle(it->at("title").get<std::string>());
		post->setLink(it->at("link").get<std::string>());
		wxDateTime date;
		date.ParseDate(it->at("date").get<std::string>());
		post->setDate(date);
		post->setText(it->at("text").get<std::string>());

		pageFrame->getCalendar()->addPost(post);
	}

	input.close();
}

void Calendar::saveToJson(std::string file) {
	std::ofstream out(file);
	json PostsJSON;

	for (auto itYear = years.begin(); itYear != years.end(); itYear++) {
		Year *year = *itYear;
		for (int m = 0; m < 12; m++) {
			Month* month = year->getMonth(m);
			for (int d = 1; d <= 31; d++) {
				Day* day = month->getDay(d);
				for (Post* p : day->getPosts()) {
					json j = json { { "title", p->getTitle() }, { "link",
							p->getLink() }, { "date",
							p->getDate().FormatISODate() }, { "text",
							p->getText() } };
					PostsJSON.push_back(j);
				}
			}
		}
	}

	try{
		out << PostsJSON << std::endl;
	}catch(...){
		wxLogError("Invalid Text");
	}

	out.close();
}

int Calendar::getCurrentYear() {
	return parts->tm_year + 1900;
}

int Calendar::getCurrentMonth() {
	return parts->tm_mon;
}
int Calendar::getCurrentDay() {
	return parts->tm_mday;
}

} /* namespace Page */
