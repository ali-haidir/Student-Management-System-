/***************************************************************
 * Name:      hash_home_pageApp.cpp
 * Purpose:   Code for Application Class
 * Author:    ali ()
 * Created:   2019-04-24
 * Copyright: ali ()
 * License:
 **************************************************************/

#include "wx_pch.h"
#include "hash_home_pageApp.h"

//(*AppHeaders
#include "hash_home_pageMain.h"
#include <wx/image.h>
//*)

IMPLEMENT_APP(hash_home_pageApp);

bool hash_home_pageApp::OnInit()
{
    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
    	hash_home_pageFrame* Frame = new hash_home_pageFrame(0);
    	Frame->Show();
    	SetTopWindow(Frame);
    }
    //*)
    return wxsOK;

}
        