///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Sep 14 2006)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#ifndef __noname__
#define __noname__

// Define WX_GCH in order to support precompiled headers with GCC compiler.
// You have to create the header "wx_pch.h" and include all files needed
// for compile your gui inside it.
// Then, compile it and place the file "wx_pch.h.gch" into the same
// directory that "wx_pch.h".
#ifdef WX_GCH
#include <wx_pch.h>
#else
#include <wx/wx.h>
#endif

#include <wx/bmpbuttn.h>
#include <wx/button.h>
#include <wx/choice.h>
#include <wx/menu.h>
#include <wx/spinctrl.h>

///////////////////////////////////////////////////////////////////////////

#define ID_DEFAULT wxID_ANY // Default
#define DIALOG_ADD_LIGHT 1000
#define DIALOG_ADD_LIGHT_AMBIANT 1001
#define DIALOG_ADD_LIGHT_DIFFUSE 1002
#define DIALOG_ADD_LIGHT_DIRX 1003
#define DIALOG_ADD_LIGHT_DIRY 1004
#define DIALOG_ADD_LIGHT_DIRZ 1005
#define DIALOG_ADD_LIGHT_FADDINGEND 1006
#define DIALOG_ADD_LIGHT_FADINGSTART 1007
#define DIALOG_ADD_LIGHT_POSX 1008
#define DIALOG_ADD_LIGHT_POSY 1009
#define DIALOG_ADD_LIGHT_POSZ 1010
#define DIALOG_ADD_LIGHT_SPECULAR 1011
#define DIALOG_ADD_LIGHT_TYPE 1012
#define DIALOG_ADD_OBJECT 1013
#define DIALOG_ADD_OBJECT_AMBIANT 1014
#define DIALOG_ADD_OBJECT_CHOOSE_PATH 1015
#define DIALOG_ADD_OBJECT_DIFFUSE 1016
#define DIALOG_ADD_OBJECT_DIRX 1017
#define DIALOG_ADD_OBJECT_DIRY 1018
#define DIALOG_ADD_OBJECT_DIRZ 1019
#define DIALOG_ADD_OBJECT_MESH_PATH 1020
#define DIALOG_ADD_OBJECT_MESH_TYPE 1021
#define DIALOG_ADD_OBJECT_POSX 1022
#define DIALOG_ADD_OBJECT_POSY 1023
#define DIALOG_ADD_OBJECT_POSZ 1024
#define DIALOG_ADD_OBJECT_SCALEX 1025
#define DIALOG_ADD_OBJECT_SCALEY 1026
#define DIALOG_ADD_OBJECT_SCALEZ 1027
#define DIALOG_ADD_OBJECT_SPECULAR 1028
#define DIALOG_CAMERA 1029
#define DIALOG_CAMERA_FAR 1030
#define DIALOG_CAMERA_FOV 1031
#define DIALOG_CAMERA_NEAR 1032
#define DIALOG_CAMERA_POSX 1033
#define DIALOG_CAMERA_POSY 1034
#define DIALOG_CAMERA_POSZ 1035
#define DIALOG_CAMERA_TARGETX 1036
#define DIALOG_CAMERA_TARGETY 1037
#define DIALOG_CAMERA_TARGETZ 1038
#define DIALOG_CAMERA_TYPE 1039
#define MAIN_MENU_ABOUT 1040
#define MAIN_MENU_ADDLIGHT 1041
#define MAIN_MENU_ADDOBJECT 1042
#define MAIN_MENU_CHANGECAMERA 1043
#define MAIN_MENU_LOAD 1044
#define MAIN_MENU_QUIT 1045
#define MAIN_MENU_RENDERPROPS 1046
#define MAIN_MENU_SAVE 1047
#define MAIN_MENU_SHOWTREE 1048
#define MENU 1049

/**
 * Class CDialogAddLight
 */
class CDialogAddLight : public wxDialog
{
	private:
	
	protected:
		wxStaticText* m_staticText4;
		wxBitmapButton* _buttonAmbiant;
		wxStaticText* m_staticText5;
		wxBitmapButton* _buttonDiffuse;
		wxStaticText* m_staticText6;
		wxBitmapButton* _buttonSpecular;
		wxStaticText* m_staticText7;
		wxStaticText* m_staticText8;
		wxStaticText* m_staticText9;
		wxStaticText* m_staticText10;
		wxStaticText* m_staticText11;
		wxStaticText* m_staticText12;
		wxStaticText* m_staticText13;
		wxStaticText* m_staticText14;
		wxButton* _buttonOK;
		wxButton* _buttonCancel;
	
	public:
		wxRadioBox* _radioboxType;
		wxTextCtrl* _textPosX;
		wxTextCtrl* _textPosY;
		wxTextCtrl* _textPosZ;
		wxTextCtrl* _textDir;
		wxTextCtrl* _textDirY;
		wxTextCtrl* _textDirZ;
		wxTextCtrl* _textFadingStart;
		wxTextCtrl* _textFadingEnd;
		CDialogAddLight( wxWindow* parent, int id = -1, wxString title = wxT("Add a light"), wxPoint pos = wxDefaultPosition, wxSize size = wxSize( 403,334 ), int style = wxDEFAULT_DIALOG_STYLE|wxSUNKEN_BORDER );
	
};

/**
 * Class CDialogAddObject
 */
class CDialogAddObject : public wxDialog
{
	private:
	
	protected:
		wxButton* _buttonChoosePath;
		wxStaticText* m_staticText15;
		wxStaticText* m_staticText16;
		wxStaticText* m_staticText17;
		wxStaticText* m_staticText18;
		wxStaticText* m_staticText19;
		wxStaticText* m_staticText20;
		wxStaticText* m_staticText22;
		wxStaticText* m_staticText23;
		wxStaticText* m_staticText24;
		wxStaticText* m_staticText27;
		wxBitmapButton* _buttonAmbiant;
		wxStaticText* m_staticText28;
		wxBitmapButton* _buttonDiffuse;
		wxStaticText* m_staticText29;
		wxBitmapButton* _buttonSpecular;
		wxStaticText* m_staticText30;
		wxStaticText* m_staticText25;
		wxStaticText* m_staticText26;
		wxButton* _buttonOK;
		wxButton* _buttonCancel;
	
	public:
		wxRadioBox* _radioboxMeshType;
		wxTextCtrl* _textMeshPath;
		wxTextCtrl* _textPosX;
		wxTextCtrl* _textPosY;
		wxTextCtrl* _textPosZ;
		wxTextCtrl* _textDirX;
		wxTextCtrl* _textDirY;
		wxTextCtrl* _textDirZ;
		wxTextCtrl* _textScaleX;
		wxTextCtrl* _textScaleY;
		wxTextCtrl* _textScaleZ;
		wxSpinCtrl* _spinPower;
		wxChoice* _choiceLightningType;
		wxChoice* _choiceMeshType;
		CDialogAddObject( wxWindow* parent, int id = -1, wxString title = wxT("Add an object"), wxPoint pos = wxDefaultPosition, wxSize size = wxSize( 499,415 ), int style = wxDEFAULT_DIALOG_STYLE );
	
};

/**
 * Class CDialogCamera
 */
class CDialogCamera : public wxDialog
{
	private:
	
	protected:
		wxStaticText* m_staticText31;
		wxStaticText* m_staticText32;
		wxStaticText* m_staticText33;
		wxStaticText* m_staticText34;
		wxStaticText* m_staticText35;
		wxStaticText* m_staticText36;
		wxStaticText* m_staticText38;
		wxStaticText* m_staticText39;
		wxStaticText* m_staticText41;
		wxButton* m_button8;
		wxButton* m_button9;
	
	public:
		wxRadioBox* _radioboxType;
		wxTextCtrl* _textPosX;
		wxTextCtrl* _textPosY;
		wxTextCtrl* _textPosZ;
		wxTextCtrl* _textTargetX;
		wxTextCtrl* _textTargetY;
		wxTextCtrl* _textTargetZ;
		wxTextCtrl* _textNear;
		wxTextCtrl* _textFar;
		wxTextCtrl* _textFOV;
		CDialogCamera( wxWindow* parent, int id = -1, wxString title = wxT(""), wxPoint pos = wxDefaultPosition, wxSize size = wxDefaultSize, int style = wxDEFAULT_DIALOG_STYLE );
	
};

/**
 * Class SanDemo
 */
class SanDemo : public wxFrame
{
	private:
	
	protected:
		wxMenuBar* _menuBar;
	
	public:
		SanDemo( wxWindow* parent, int id = -1, wxString title = wxT(""), wxPoint pos = wxDefaultPosition, wxSize size = wxSize( 640,480 ), int style = wxDEFAULT_FRAME_STYLE|wxMAXIMIZE|wxTAB_TRAVERSAL );
	
};

#endif //__noname__
