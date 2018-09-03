/*
 * PostAdapter.cpp
 *
 *  Created on: Sep 3, 2018
 *      Author: Harystolho
 */

#include "PostAdapter.h"

PostAdapter::PostAdapter(wxWindow* window, wxWindowID id, wxString text, Post* post) :
		wxStaticText(window, id, text), post(post) {

}

PostAdapter::~PostAdapter() {
	// TODO Auto-generated destructor stub
}

void PostAdapter::openWindow(){

}
