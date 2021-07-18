/***************************************************************
 * Name:      hash_login_pageApp.cpp
 * Purpose:   Code for Application Class
 * Author:    ali ()
 * Created:   2019-04-24
 * Copyright: ali ()
 * License:
 **************************************************************/

#include "wx_pch.h"
#include "hash_login_pageApp.h"

//(*AppHeaders
#include "hash_login_pageMain.h"
#include <wx/image.h>
//*)

IMPLEMENT_APP(hash_login_pageApp);

bool hash_login_pageApp::OnInit()
{
    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
    	hash_login_pageFrame* Frame = new hash_login_pageFrame(0);
    	Frame->Show();
    	SetTopWindow(Frame);
    }
    //*)
    return wxsOK;

}
        