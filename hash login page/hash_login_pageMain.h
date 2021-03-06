/***************************************************************
 * Name:      hash_login_pageMain.h
 * Purpose:   Defines Application Frame
 * Author:    ali ()
 * Created:   2019-04-24
 * Copyright: ali ()
 * License:
 **************************************************************/

#ifndef HASH_LOGIN_PAGEMAIN_H
#define HASH_LOGIN_PAGEMAIN_H

//(*Headers(hash_login_pageFrame)
#include <wx/button.h>
#include <wx/menu.h>
#include <wx/panel.h>
#include <wx/statusbr.h>
#include <wx/frame.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
//*)

class hash_login_pageFrame: public wxFrame
{
    public:

        hash_login_pageFrame(wxWindow* parent,wxWindowID id = -1);
        virtual ~hash_login_pageFrame();

    private:

        //(*Handlers(hash_login_pageFrame)
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        //*)

        //(*Identifiers(hash_login_pageFrame)
        static const long ID_STATICTEXT1;
        static const long ID_TEXTCTRL1;
        static const long ID_STATICTEXT2;
        static const long ID_TEXTCTRL2;
        static const long ID_STATICTEXT3;
        static const long ID_BUTTON1;
        static const long ID_PANEL1;
        static const long idMenuQuit;
        static const long idMenuAbout;
        static const long ID_STATUSBAR1;
        //*)

        //(*Declarations(hash_login_pageFrame)
        wxPanel* Panel1;
        wxStatusBar* StatusBar1;
        wxButton* Button1;
        wxStaticText* StaticText1;
        wxStaticText* StaticText3;
        wxTextCtrl* TextCtrl1;
        wxStaticText* StaticText2;
        wxTextCtrl* TextCtrl2;
        //*)

        DECLARE_EVENT_TABLE()
};

#endif // HASH_LOGIN_PAGEMAIN_H
                                                                                    