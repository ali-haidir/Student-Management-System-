/***************************************************************
 * Name:      hash_login_pageMain.cpp
 * Purpose:   Code for Application Frame
 * Author:    ali ()
 * Created:   2019-04-24
 * Copyright: ali ()
 * License:
 **************************************************************/

#include "wx_pch.h"
#include "hash_login_pageMain.h"
#include <wx/msgdlg.h>

//(*InternalHeaders(hash_login_pageFrame)
#include <wx/string.h>
#include <wx/intl.h>
#include <wx/font.h>
//*)

//helper functions
enum wxbuildinfoformat {
    short_f, long_f };

wxString wxbuildinfo(wxbuildinfoformat format)
{
    wxString wxbuild(wxVERSION_STRING);

    if (format == long_f )
    {
#if defined(__WXMSW__)
        wxbuild << _T("-Windows");
#elif defined(__UNIX__)
        wxbuild << _T("-Linux");
#endif

#if wxUSE_UNICODE
        wxbuild << _T("-Unicode build");
#else
        wxbuild << _T("-ANSI build");
#endif // wxUSE_UNICODE
    }

    return wxbuild;
}

//(*IdInit(hash_login_pageFrame)
const long hash_login_pageFrame::ID_STATICTEXT1 = wxNewId();
const long hash_login_pageFrame::ID_TEXTCTRL1 = wxNewId();
const long hash_login_pageFrame::ID_STATICTEXT2 = wxNewId();
const long hash_login_pageFrame::ID_TEXTCTRL2 = wxNewId();
const long hash_login_pageFrame::ID_STATICTEXT3 = wxNewId();
const long hash_login_pageFrame::ID_BUTTON1 = wxNewId();
const long hash_login_pageFrame::ID_PANEL1 = wxNewId();
const long hash_login_pageFrame::idMenuQuit = wxNewId();
const long hash_login_pageFrame::idMenuAbout = wxNewId();
const long hash_login_pageFrame::ID_STATUSBAR1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(hash_login_pageFrame,wxFrame)
    //(*EventTable(hash_login_pageFrame)
    //*)
END_EVENT_TABLE()

hash_login_pageFrame::hash_login_pageFrame(wxWindow* parent,wxWindowID id)
{
    //(*Initialize(hash_login_pageFrame)
    wxMenuItem* MenuItem2;
    wxMenuItem* MenuItem1;
    wxMenu* Menu1;
    wxMenuBar* MenuBar1;
    wxMenu* Menu2;

    Create(parent, id, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("id"));
    SetClientSize(wxSize(649,450));
    Panel1 = new wxPanel(this, ID_PANEL1, wxPoint(208,288), wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL1"));
    StaticText1 = new wxStaticText(Panel1, ID_STATICTEXT1, _("Enter username and password"), wxPoint(184,152), wxDefaultSize, 0, _T("ID_STATICTEXT1"));
    TextCtrl1 = new wxTextCtrl(Panel1, ID_TEXTCTRL1, _("Text"), wxPoint(280,208), wxSize(144,27), 0, wxDefaultValidator, _T("ID_TEXTCTRL1"));
    StaticText2 = new wxStaticText(Panel1, ID_STATICTEXT2, _("username:"), wxPoint(160,208), wxSize(87,24), 0, _T("ID_STATICTEXT2"));
    wxFont StaticText2Font(14,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_T("Sans"),wxFONTENCODING_DEFAULT);
    StaticText2->SetFont(StaticText2Font);
    TextCtrl2 = new wxTextCtrl(Panel1, ID_TEXTCTRL2, _("Text"), wxPoint(280,264), wxSize(144,27), 0, wxDefaultValidator, _T("ID_TEXTCTRL2"));
    StaticText3 = new wxStaticText(Panel1, ID_STATICTEXT3, _("Password:"), wxPoint(160,264), wxSize(91,17), 0, _T("ID_STATICTEXT3"));
    wxFont StaticText3Font(14,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_T("Sans"),wxFONTENCODING_DEFAULT);
    StaticText3->SetFont(StaticText3Font);
    Button1 = new wxButton(Panel1, ID_BUTTON1, _("login"), wxPoint(256,320), wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
    MenuBar1 = new wxMenuBar();
    Menu1 = new wxMenu();
    MenuItem1 = new wxMenuItem(Menu1, idMenuQuit, _("Quit\tAlt-F4"), _("Quit the application"), wxITEM_NORMAL);
    Menu1->Append(MenuItem1);
    MenuBar1->Append(Menu1, _("&File"));
    Menu2 = new wxMenu();
    MenuItem2 = new wxMenuItem(Menu2, idMenuAbout, _("About\tF1"), _("Show info about this application"), wxITEM_NORMAL);
    Menu2->Append(MenuItem2);
    MenuBar1->Append(Menu2, _("Help"));
    SetMenuBar(MenuBar1);
    StatusBar1 = new wxStatusBar(this, ID_STATUSBAR1, 0, _T("ID_STATUSBAR1"));
    int __wxStatusBarWidths_1[1] = { -1 };
    int __wxStatusBarStyles_1[1] = { wxSB_NORMAL };
    StatusBar1->SetFieldsCount(1,__wxStatusBarWidths_1);
    StatusBar1->SetStatusStyles(1,__wxStatusBarStyles_1);
    SetStatusBar(StatusBar1);

    Connect(idMenuQuit,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&hash_login_pageFrame::OnQuit);
    Connect(idMenuAbout,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&hash_login_pageFrame::OnAbout);
    //*)
}

hash_login_pageFrame::~hash_login_pageFrame()
{
    //(*Destroy(hash_login_pageFrame)
    //*)
}

void hash_login_pageFrame::OnQuit(wxCommandEvent& event)
{
    Close();
}

void hash_login_pageFrame::OnAbout(wxCommandEvent& event)
{
    wxString msg = wxbuildinfo(long_f);
    wxMessageBox(msg, _("Welcome to..."));
}
                                                                                                                                                                                                                                                        