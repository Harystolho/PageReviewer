/*
 * PostAdapter.h
 *
 *  Created on: Sep 3, 2018
 *      Author: Harystolho
 */

#ifndef WINDOWS_POSTADAPTER_H_
#define WINDOWS_POSTADAPTER_H_

#include "../page/post.h"
#include "wx/stattext.h"
#include "wx/wxcrtvararg.h"

class PostAdapter: public wxStaticText {
public:
	PostAdapter(wxWindow* window, wxWindowID id, wxString text, Post* post);
	virtual ~PostAdapter();

	void openWindow();

private:
	Post* post;
};

#endif /* WINDOWS_POSTADAPTER_H_ */