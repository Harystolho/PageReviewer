/*
 * PostAdapter.h
 *
 *  Created on: Sep 3, 2018
 *      Author: Harystolho
 */

#ifndef WINDOWS_POSTADAPTER_H_
#define WINDOWS_POSTADAPTER_H_

#include "../page/post.h"
#include "../PageFrame.h"
#include "wx/stattext.h"
#include "wx/wxcrtvararg.h"
#include "wx/frame.h"
#include "wx/sizer.h"
#include "wx/stattext.h"
#include "wx/textctrl.h"
#include "wx/hyperlink.h"
#include "wx/button.h"
#include "wx/font.h"
#include "wx/colour.h"

class PostAdapter: public wxStaticText {
public:
	PostAdapter(wxWindow* window, wxWindowID id, wxString text, Post* post);
	virtual ~PostAdapter();

	void openWindow();

private:
	wxFrame* frame;
	Post* post;

	void updatePost(Post* post, int days);

};

#endif /* WINDOWS_POSTADAPTER_H_ */
