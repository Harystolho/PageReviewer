/*
 * post.h
 *
 *  Created on: Aug 28, 2018
 *      Author: Harystolho
 */

#ifndef POST_H_
#define POST_H_

#include <string>

class Post {
public:
	Post();
	Post(const std::string& tt);
	~Post();

	std::string getTitle() const;
	void setTitle(const std::string& title);
	std::string getUrl() const;
	void setUrl(const std::string& url);
private:
	std::string title;
	std::string url;
};

#endif /* POST_H_ */
