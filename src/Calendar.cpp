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

	Post *post = new Post();
	post->setTitle("My New Post");
	post->setLink("http://neume.sourceforge.net/sizerdemo/");
	post->setDate(wxDateTime::Now());
	post->setText(
			"This will most often mean that the programmer does not set the original size of a dialog in the beginning, rather \nthe dialog will be assigned a sizer and this sizer will be queried about the recommended size. The sizer in turn will query its children, which can be normal windows, empty space or other sizers, so that a hierarchy of sizers can be\n constructed. Note that wxSizer does not derive from wxWindow and thus does not interfere with tab ordering and requires very little resources compared to a real window on screen.What makes sizers so well fitted for use in wxWidgets is the fact that every control reports its own minimal size and the algorithm can handle differences \nin font sizes or different window (dialog item) sizes on different platforms without problems. If e.g. the standard font as well as the overall design of Motif widgets requires more space than on Windows, the initial dialog size will automatically be bigger on Motif than on \nWindows.");

	addPost(post);
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
	std::string jsonString = "";

	std::ifstream input;
	input.open(file);

	std::string temp;
	while (getline(input, temp)) {
		jsonString += temp;
	}

	json j = json::parse(jsonString);

	input.close();
}

void Calendar::saveToJson(std::string file) {
	std::ofstream out(file);
	json j;

	for (auto itYear = years.begin(); itYear != years.end();) {
		Year *year = *itYear;
		for(int m = 0; m < 12; m++){
			Month* month = year->getMonth(0);
			for(int d=1; d <=31; d++){
				Day* day = month->getDay(d);

			}
		}
	}

	out << j << std::endl;

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
