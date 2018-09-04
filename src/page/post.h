/*
 * post.h
 *
 *  Created on: Aug 28, 2018
 *      Author: Harystolho
 */

#ifndef POST_H_
#define POST_H_

#include <string>
#include "wx/datetime.h"

class Post {
public:
	Post();
	Post(const std::string& title);
	~Post();

	std::string getTitle() const;
	void setTitle(const std::string& title);
	std::string getLink() const;
	void setLink(const std::string& url);
	wxDateTime getDate();
	void setDate(const wxDateTime date);
	std::string getText();
	void setText(const std::string& text);

	void updateReviewDate(wxDateTime time);
private:
	std::string title;
	std::string link;
	wxDateTime date;
	std::string text;
};

#endif /* POST_H_ */
