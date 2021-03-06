/***************************************************************
 * Name:      hash_home_pageMain.cpp
 * Purpose:   Code for Application Frame
 * Author:    ali ()
 * Created:   2019-04-24
 * Copyright: ali ()
 * License:
 **************************************************************/

#include "wx_pch.h"
#include "hash_home_pageMain.h"
#include <wx/msgdlg.h>

//(*InternalHeaders(hash_home_pageFrame)
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

//(*IdInit(hash_home_pageFrame)
const long hash_home_pageFrame::ID_STATICTEXT1 = wxNewId();
const long hash_home_pageFrame::ID_BUTTON1 = wxNewId();
const long hash_home_pageFrame::ID_BUTTON2 = wxNewId();
const long hash_home_pageFrame::ID_BUTTON3 = wxNewId();
const long hash_home_pageFrame::ID_PANEL1 = wxNewId();
const long hash_home_pageFrame::idMenuQuit = wxNewId();
const long hash_home_pageFrame::idMenuAbout = wxNewId();
const long hash_home_pageFrame::ID_STATUSBAR1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(hash_home_pageFrame,wxFrame)
    //(*EventTable(hash_home_pageFrame)
    //*)
END_EVENT_TABLE()

hash_home_pageFrame::hash_home_pageFrame(wxWindow* parent,wxWindowID id)
{
    //(*Initialize(hash_home_pageFrame)
    wxMenuItem* MenuItem2;
    wxMenuItem* MenuItem1;
    wxMenu* Menu1;
    wxMenuBar* MenuBar1;
    wxMenu* Menu2;

    Create(parent, id, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("id"));
    SetClientSize(wxSize(484,450));
    Panel1 = new wxPanel(this, ID_PANEL1, wxPoint(264,312), wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL1"));
    wxFont Panel1Font(24,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_T("Sans"),wxFONTENCODING_DEFAULT);
    Panel1->SetFont(Panel1Font);
    StaticText1 = new wxStaticText(Panel1, ID_STATICTEXT1, _("Fast National University"), wxPoint(56,64), wxSize(376,40), 0, _T("ID_STATICTEXT1"));
    wxFont StaticText1Font(22,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_T("Sans"),wxFONTENCODING_DEFAULT);
    StaticText1->SetFont(StaticText1Font);
    Button1 = new wxButton(Panel1, ID_BUTTON1, _("Attendence"), wxPoint(160,168), wxSize(120,32), 0, wxDefaultValidator, _T("ID_BUTTON1"));
    wxFont Button1Font(10,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_T("Sans"),wxFONTENCODING_DEFAULT);
    Button1->SetFont(Button1Font);
    Button2 = new wxButton(Panel1, ID_BUTTON2, _("Marks"), wxPoint(160,216), wxSize(120,32), 0, wxDefaultValidator, _T("ID_BUTTON2"));
    wxFont Button2Font(10,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_T("Sans"),wxFONTENCODING_DEFAULT);
    Button2->SetFont(Button2Font);
    Button3 = new wxButton(Panel1, ID_BUTTON3, _("Course Registration"), wxPoint(160,264), wxSize(120,32), 0, wxDefaultValidator, _T("ID_BUTTON3"));
    wxFont Button3Font(10,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_T("Sans"),wxFONTENCODING_DEFAULT);
    Button3->SetFont(Button3Font);
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

    Connect(idMenuQuit,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&hash_home_pageFrame::OnQuit);
    Connect(idMenuAbout,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&hash_home_pageFrame::OnAbout);
    //*)
}

hash_home_pageFrame::~hash_home_pageFrame()
{
    //(*Destroy(hash_home_pageFrame)
    //*)
}

void hash_home_pageFrame::OnQuit(wxCommandEvent& event)
{
    Close();
}

void hash_home_pageFrame::OnAbout(wxCommandEvent& event)
{
    wxString msg = wxbuildinfo(long_f);
    wxMessageBox(msg, _("Welcome to..."));
}
                                                                                                                                                                                                                                                                    