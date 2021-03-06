/***************************************************************
 * Name:      hash_home_pageMain.h
 * Purpose:   Defines Application Frame
 * Author:    ali ()
 * Created:   2019-04-24
 * Copyright: ali ()
 * License:
 **************************************************************/

#ifndef HASH_HOME_PAGEMAIN_H
#define HASH_HOME_PAGEMAIN_H

//(*Headers(hash_home_pageFrame)
#include <wx/button.h>
#include <wx/menu.h>
#include <wx/panel.h>
#include <wx/statusbr.h>
#include <wx/frame.h>
#include <wx/stattext.h>
//*)

class hash_home_pageFrame: public wxFrame
{
    public:

        hash_home_pageFrame(wxWindow* parent,wxWindowID id = -1);
        virtual ~hash_home_pageFrame();

    private:

        //(*Handlers(hash_home_pageFrame)
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        void OnPanel1Paint(wxPaintEvent& event);
        //*)

        //(*Identifiers(hash_home_pageFrame)
        static const long ID_STATICTEXT1;
        static const long ID_BUTTON1;
        static const long ID_BUTTON2;
        static const long ID_BUTTON3;
        static const long ID_PANEL1;
        static const long idMenuQuit;
        static const long idMenuAbout;
        static const long ID_STATUSBAR1;
        //*)

        //(*Declarations(hash_home_pageFrame)
        wxPanel* Panel1;
        wxStatusBar* StatusBar1;
        wxButton* Button1;
        wxButton* Button2;
        wxButton* Button3;
        wxStaticText* StaticText1;
        //*)

        DECLARE_EVENT_TABLE()
};

#endif // HASH_HOME_PAGEMAIN_H
                                                                    