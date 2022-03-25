///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Sep 14 2006)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "wx/wxprec.h"

#ifdef __BORLANDC__
#pragma hdrstop
#endif //__BORLANDC__

#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif //WX_PRECOMP

#include "noname.h"

///////////////////////////////////////////////////////////////////////////

CDialogAddLight::CDialogAddLight( wxWindow* parent, int id, wxString title, wxPoint pos, wxSize size, int style ) : wxDialog( parent, id, title, pos, size, style )
{
	wxBoxSizer* bSizer1;
	bSizer1 = new wxBoxSizer( wxVERTICAL );
	
	wxString _radioboxTypeChoices[] = { wxT("Ambiant"), wxT("Directionnal"), wxT("Point"), wxT("Spot") };
	int _radioboxTypeNChoices = sizeof( _radioboxTypeChoices ) / sizeof( wxString );
	_radioboxType = new wxRadioBox( this, DIALOG_ADD_LIGHT_TYPE, wxT("Light type"), wxDefaultPosition, wxDefaultSize, _radioboxTypeNChoices, _radioboxTypeChoices, 4, wxRA_SPECIFY_COLS );
	bSizer1->Add( _radioboxType, 0, wxALL, 5 );
	
	wxStaticBoxSizer* sbSizer2;
	sbSizer2 = new wxStaticBoxSizer( new wxStaticBox( this, -1, wxT("Light composants") ), wxHORIZONTAL );
	
	m_staticText4 = new wxStaticText( this, ID_DEFAULT, wxT("ambiant"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizer2->Add( m_staticText4, 0, wxALL, 5 );
	
	_buttonAmbiant = new wxBitmapButton( this, DIALOG_ADD_LIGHT_AMBIANT, wxNullBitmap, wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	sbSizer2->Add( _buttonAmbiant, 0, wxALL, 5 );
	
	m_staticText5 = new wxStaticText( this, ID_DEFAULT, wxT("diffuse"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizer2->Add( m_staticText5, 0, wxALL, 5 );
	
	_buttonDiffuse = new wxBitmapButton( this, DIALOG_ADD_LIGHT_DIFFUSE, wxNullBitmap, wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	_buttonDiffuse->Enable( false );
	
	sbSizer2->Add( _buttonDiffuse, 0, wxALL, 5 );
	
	m_staticText6 = new wxStaticText( this, ID_DEFAULT, wxT("specular"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizer2->Add( m_staticText6, 0, wxALL, 5 );
	
	_buttonSpecular = new wxBitmapButton( this, DIALOG_ADD_LIGHT_SPECULAR, wxNullBitmap, wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	_buttonSpecular->Enable( false );
	
	sbSizer2->Add( _buttonSpecular, 0, wxALL, 5 );
	
	bSizer1->Add( sbSizer2, 0, wxEXPAND, 5 );
	
	wxStaticBoxSizer* sbSizer7;
	sbSizer7 = new wxStaticBoxSizer( new wxStaticBox( this, -1, wxT("position") ), wxHORIZONTAL );
	
	m_staticText7 = new wxStaticText( this, ID_DEFAULT, wxT("x"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizer7->Add( m_staticText7, 0, wxALL, 5 );
	
	_textPosX = new wxTextCtrl( this, DIALOG_ADD_LIGHT_POSX, wxT("0.0"), wxDefaultPosition, wxDefaultSize, 0 );
	_textPosX->Enable( false );
	
	sbSizer7->Add( _textPosX, 0, wxALL, 5 );
	
	m_staticText8 = new wxStaticText( this, ID_DEFAULT, wxT("y"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizer7->Add( m_staticText8, 0, wxALL, 5 );
	
	_textPosY = new wxTextCtrl( this, DIALOG_ADD_LIGHT_POSY, wxT("0.0"), wxDefaultPosition, wxDefaultSize, 0 );
	_textPosY->Enable( false );
	
	sbSizer7->Add( _textPosY, 0, wxALL, 5 );
	
	m_staticText9 = new wxStaticText( this, ID_DEFAULT, wxT("z"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizer7->Add( m_staticText9, 0, wxALL, 5 );
	
	_textPosZ = new wxTextCtrl( this, DIALOG_ADD_LIGHT_POSZ, wxT("0.0"), wxDefaultPosition, wxDefaultSize, 0 );
	_textPosZ->Enable( false );
	
	sbSizer7->Add( _textPosZ, 0, wxALL, 5 );
	
	bSizer1->Add( sbSizer7, 0, wxEXPAND, 5 );
	
	wxStaticBoxSizer* sbSizer8;
	sbSizer8 = new wxStaticBoxSizer( new wxStaticBox( this, -1, wxT("direction") ), wxHORIZONTAL );
	
	m_staticText10 = new wxStaticText( this, ID_DEFAULT, wxT("x"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizer8->Add( m_staticText10, 0, wxALL, 5 );
	
	_textDir = new wxTextCtrl( this, DIALOG_ADD_LIGHT_DIRX, wxT("0.0"), wxDefaultPosition, wxDefaultSize, 0 );
	_textDir->Enable( false );
	
	sbSizer8->Add( _textDir, 0, wxALL, 5 );
	
	m_staticText11 = new wxStaticText( this, ID_DEFAULT, wxT("y"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizer8->Add( m_staticText11, 0, wxALL, 5 );
	
	_textDirY = new wxTextCtrl( this, DIALOG_ADD_LIGHT_DIRY, wxT("0.0"), wxDefaultPosition, wxDefaultSize, 0 );
	_textDirY->Enable( false );
	
	sbSizer8->Add( _textDirY, 0, wxALL, 5 );
	
	m_staticText12 = new wxStaticText( this, ID_DEFAULT, wxT("z"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizer8->Add( m_staticText12, 0, wxALL, 5 );
	
	_textDirZ = new wxTextCtrl( this, DIALOG_ADD_LIGHT_DIRZ, wxT("1.0"), wxDefaultPosition, wxDefaultSize, 0 );
	_textDirZ->Enable( false );
	
	sbSizer8->Add( _textDirZ, 0, wxALL, 5 );
	
	bSizer1->Add( sbSizer8, 0, wxEXPAND, 5 );
	
	wxStaticBoxSizer* sbSizer9;
	sbSizer9 = new wxStaticBoxSizer( new wxStaticBox( this, -1, wxT("fading") ), wxHORIZONTAL );
	
	m_staticText13 = new wxStaticText( this, ID_DEFAULT, wxT("start"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizer9->Add( m_staticText13, 0, wxALL, 5 );
	
	_textFadingStart = new wxTextCtrl( this, DIALOG_ADD_LIGHT_FADINGSTART, wxT("100.0"), wxDefaultPosition, wxDefaultSize, 0 );
	_textFadingStart->Enable( false );
	
	sbSizer9->Add( _textFadingStart, 0, wxALL, 5 );
	
	m_staticText14 = new wxStaticText( this, ID_DEFAULT, wxT("end"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizer9->Add( m_staticText14, 0, wxALL, 5 );
	
	_textFadingEnd = new wxTextCtrl( this, DIALOG_ADD_LIGHT_FADDINGEND, wxT("120.0"), wxDefaultPosition, wxDefaultSize, 0 );
	_textFadingEnd->Enable( false );
	
	sbSizer9->Add( _textFadingEnd, 0, wxALL, 5 );
	
	bSizer1->Add( sbSizer9, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer8;
	bSizer8 = new wxBoxSizer( wxHORIZONTAL );
	
	_buttonOK = new wxButton( this, wxID_OK, wxT("OK"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer8->Add( _buttonOK, 0, wxALL, 5 );
	
	_buttonCancel = new wxButton( this, wxID_CANCEL, wxT("Cancel"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer8->Add( _buttonCancel, 0, wxALL, 5 );
	
	bSizer1->Add( bSizer8, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5 );
	
	this->SetSizer( bSizer1 );
	this->Layout();
}

CDialogAddObject::CDialogAddObject( wxWindow* parent, int id, wxString title, wxPoint pos, wxSize size, int style ) : wxDialog( parent, id, title, pos, size, style )
{
	wxStaticBoxSizer* sbSizer10;
	sbSizer10 = new wxStaticBoxSizer( new wxStaticBox( this, -1, wxT("Add an object") ), wxVERTICAL );
	
	wxStaticBoxSizer* sbSizer12;
	sbSizer12 = new wxStaticBoxSizer( new wxStaticBox( this, -1, wxT("Mesh") ), wxHORIZONTAL );
	
	wxString _radioboxMeshTypeChoices[] = { wxT("Triangle"), wxT("Cube"), wxT("Sphere"), wxT("Custom") };
	int _radioboxMeshTypeNChoices = sizeof( _radioboxMeshTypeChoices ) / sizeof( wxString );
	_radioboxMeshType = new wxRadioBox( this, DIALOG_ADD_OBJECT_MESH_TYPE, wxT("type"), wxDefaultPosition, wxDefaultSize, _radioboxMeshTypeNChoices, _radioboxMeshTypeChoices, 4, wxRA_SPECIFY_COLS );
	sbSizer12->Add( _radioboxMeshType, 0, wxALL, 5 );
	
	wxStaticBoxSizer* sbSizer16;
	sbSizer16 = new wxStaticBoxSizer( new wxStaticBox( this, -1, wxT("path(*.obj)") ), wxHORIZONTAL );
	
	_textMeshPath = new wxTextCtrl( this, DIALOG_ADD_OBJECT_MESH_PATH, wxT(""), wxDefaultPosition, wxDefaultSize, 0 );
	_textMeshPath->Enable( false );
	
	sbSizer16->Add( _textMeshPath, 0, wxALL, 5 );
	
	_buttonChoosePath = new wxButton( this, DIALOG_ADD_OBJECT_CHOOSE_PATH, wxT("Browse"), wxDefaultPosition, wxDefaultSize, 0 );
	_buttonChoosePath->Enable( false );
	
	sbSizer16->Add( _buttonChoosePath, 0, wxALL, 5 );
	
	sbSizer12->Add( sbSizer16, 1, wxEXPAND, 5 );
	
	sbSizer10->Add( sbSizer12, 0, wxEXPAND, 5 );
	
	wxStaticBoxSizer* sbSizer14;
	sbSizer14 = new wxStaticBoxSizer( new wxStaticBox( this, -1, wxT("Position") ), wxHORIZONTAL );
	
	m_staticText15 = new wxStaticText( this, ID_DEFAULT, wxT("x"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizer14->Add( m_staticText15, 0, wxALL, 5 );
	
	_textPosX = new wxTextCtrl( this, DIALOG_ADD_OBJECT_POSX, wxT("0.0"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizer14->Add( _textPosX, 0, wxALL, 5 );
	
	m_staticText16 = new wxStaticText( this, ID_DEFAULT, wxT("y"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizer14->Add( m_staticText16, 0, wxALL, 5 );
	
	_textPosY = new wxTextCtrl( this, DIALOG_ADD_OBJECT_POSY, wxT("0.0"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizer14->Add( _textPosY, 0, wxALL, 5 );
	
	m_staticText17 = new wxStaticText( this, ID_DEFAULT, wxT("z"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizer14->Add( m_staticText17, 0, wxALL, 5 );
	
	_textPosZ = new wxTextCtrl( this, DIALOG_ADD_OBJECT_POSZ, wxT("0.0"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizer14->Add( _textPosZ, 0, wxALL, 5 );
	
	sbSizer10->Add( sbSizer14, 0, wxEXPAND, 5 );
	
	wxStaticBoxSizer* sbSizer15;
	sbSizer15 = new wxStaticBoxSizer( new wxStaticBox( this, -1, wxT("Direction") ), wxHORIZONTAL );
	
	m_staticText18 = new wxStaticText( this, ID_DEFAULT, wxT("x"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizer15->Add( m_staticText18, 0, wxALL, 5 );
	
	_textDirX = new wxTextCtrl( this, DIALOG_ADD_OBJECT_DIRX, wxT("0.0"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizer15->Add( _textDirX, 0, wxALL, 5 );
	
	m_staticText19 = new wxStaticText( this, ID_DEFAULT, wxT("y"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizer15->Add( m_staticText19, 0, wxALL, 5 );
	
	_textDirY = new wxTextCtrl( this, DIALOG_ADD_OBJECT_DIRY, wxT("0.0"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizer15->Add( _textDirY, 0, wxALL, 5 );
	
	m_staticText20 = new wxStaticText( this, ID_DEFAULT, wxT("z"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizer15->Add( m_staticText20, 0, wxALL, 5 );
	
	_textDirZ = new wxTextCtrl( this, DIALOG_ADD_OBJECT_DIRZ, wxT("-1.0"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizer15->Add( _textDirZ, 0, wxALL, 5 );
	
	sbSizer10->Add( sbSizer15, 0, wxEXPAND, 5 );
	
	wxStaticBoxSizer* sbSizer17;
	sbSizer17 = new wxStaticBoxSizer( new wxStaticBox( this, -1, wxT("Scale") ), wxHORIZONTAL );
	
	m_staticText22 = new wxStaticText( this, ID_DEFAULT, wxT("x"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizer17->Add( m_staticText22, 0, wxALL, 5 );
	
	_textScaleX = new wxTextCtrl( this, DIALOG_ADD_OBJECT_SCALEX, wxT("1.0"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizer17->Add( _textScaleX, 0, wxALL, 5 );
	
	m_staticText23 = new wxStaticText( this, ID_DEFAULT, wxT("y"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizer17->Add( m_staticText23, 0, wxALL, 5 );
	
	_textScaleY = new wxTextCtrl( this, DIALOG_ADD_OBJECT_SCALEY, wxT("1.0"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizer17->Add( _textScaleY, 0, wxALL, 5 );
	
	m_staticText24 = new wxStaticText( this, ID_DEFAULT, wxT("z"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizer17->Add( m_staticText24, 0, wxALL, 5 );
	
	_textScaleZ = new wxTextCtrl( this, DIALOG_ADD_OBJECT_SCALEZ, wxT("1.0"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizer17->Add( _textScaleZ, 0, wxALL, 5 );
	
	sbSizer10->Add( sbSizer17, 0, wxEXPAND, 5 );
	
	wxStaticBoxSizer* sbSizer19;
	sbSizer19 = new wxStaticBoxSizer( new wxStaticBox( this, -1, wxT("Material") ), wxHORIZONTAL );
	
	m_staticText27 = new wxStaticText( this, ID_DEFAULT, wxT("ambiant"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizer19->Add( m_staticText27, 0, wxALL, 5 );
	
	_buttonAmbiant = new wxBitmapButton( this, DIALOG_ADD_OBJECT_AMBIANT, wxNullBitmap, wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	sbSizer19->Add( _buttonAmbiant, 0, wxALL, 5 );
	
	m_staticText28 = new wxStaticText( this, ID_DEFAULT, wxT("diffuse"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizer19->Add( m_staticText28, 0, wxALL, 5 );
	
	_buttonDiffuse = new wxBitmapButton( this, DIALOG_ADD_OBJECT_DIFFUSE, wxNullBitmap, wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	sbSizer19->Add( _buttonDiffuse, 0, wxALL, 5 );
	
	m_staticText29 = new wxStaticText( this, ID_DEFAULT, wxT("specular"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizer19->Add( m_staticText29, 0, wxALL, 5 );
	
	_buttonSpecular = new wxBitmapButton( this, DIALOG_ADD_OBJECT_SPECULAR, wxNullBitmap, wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	sbSizer19->Add( _buttonSpecular, 0, wxALL, 5 );
	
	m_staticText30 = new wxStaticText( this, ID_DEFAULT, wxT("specular power"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizer19->Add( m_staticText30, 0, wxALL, 5 );
	
	_spinPower = new wxSpinCtrl( this, ID_DEFAULT, wxT(""), wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 1, 100, 2);
	sbSizer19->Add( _spinPower, 0, wxALL, 5 );
	
	sbSizer10->Add( sbSizer19, 0, wxEXPAND, 5 );
	
	wxStaticBoxSizer* sbSizer18;
	sbSizer18 = new wxStaticBoxSizer( new wxStaticBox( this, -1, wxT("Flags") ), wxHORIZONTAL );
	
	m_staticText25 = new wxStaticText( this, ID_DEFAULT, wxT("lightning type"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizer18->Add( m_staticText25, 0, wxALL, 5 );
	
	wxString _choiceLightningTypeChoices[] = { wxT("LIGHT_GOURAUD"), wxT("LIGHT_PHONG"), wxT("LIGHT_AMBIANT") };
	int _choiceLightningTypeNChoices = sizeof( _choiceLightningTypeChoices ) / sizeof( wxString );
	_choiceLightningType = new wxChoice( this, ID_DEFAULT, wxDefaultPosition, wxDefaultSize, _choiceLightningTypeNChoices, _choiceLightningTypeChoices, 0 );
	sbSizer18->Add( _choiceLightningType, 0, wxALL, 5 );
	
	m_staticText26 = new wxStaticText( this, ID_DEFAULT, wxT("drawing type"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizer18->Add( m_staticText26, 0, wxALL, 5 );
	
	wxString _choiceMeshTypeChoices[] = { wxT("none"), wxT("normals"), wxT("nomals & textured"), wxT("textured") };
	int _choiceMeshTypeNChoices = sizeof( _choiceMeshTypeChoices ) / sizeof( wxString );
	_choiceMeshType = new wxChoice( this, ID_DEFAULT, wxDefaultPosition, wxDefaultSize, _choiceMeshTypeNChoices, _choiceMeshTypeChoices, 0 );
	sbSizer18->Add( _choiceMeshType, 0, wxALL, 5 );
	
	sbSizer10->Add( sbSizer18, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer7;
	bSizer7 = new wxBoxSizer( wxHORIZONTAL );
	
	_buttonOK = new wxButton( this, wxID_OK, wxT("OK"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer7->Add( _buttonOK, 0, wxALL, 5 );
	
	_buttonCancel = new wxButton( this, wxID_CANCEL, wxT("Cancel"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer7->Add( _buttonCancel, 0, wxALL, 5 );
	
	sbSizer10->Add( bSizer7, 0, wxALIGN_CENTER_HORIZONTAL|wxEXPAND, 5 );
	
	this->SetSizer( sbSizer10 );
	this->Layout();
}

CDialogCamera::CDialogCamera( wxWindow* parent, int id, wxString title, wxPoint pos, wxSize size, int style ) : wxDialog( parent, id, title, pos, size, style )
{
	wxBoxSizer* bSizer8;
	bSizer8 = new wxBoxSizer( wxVERTICAL );
	
	wxString _radioboxTypeChoices[] = { wxT("first person style"), wxT("target position") };
	int _radioboxTypeNChoices = sizeof( _radioboxTypeChoices ) / sizeof( wxString );
	_radioboxType = new wxRadioBox( this, DIALOG_CAMERA_TYPE, wxT("Camera type"), wxDefaultPosition, wxDefaultSize, _radioboxTypeNChoices, _radioboxTypeChoices, 2, wxRA_SPECIFY_COLS );
	bSizer8->Add( _radioboxType, 0, wxALL, 5 );
	
	wxStaticBoxSizer* sbSizer21;
	sbSizer21 = new wxStaticBoxSizer( new wxStaticBox( this, -1, wxT("Position") ), wxHORIZONTAL );
	
	m_staticText31 = new wxStaticText( this, ID_DEFAULT, wxT("x"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizer21->Add( m_staticText31, 0, wxALL, 5 );
	
	_textPosX = new wxTextCtrl( this, DIALOG_CAMERA_POSX, wxT(""), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizer21->Add( _textPosX, 0, wxALL, 5 );
	
	m_staticText32 = new wxStaticText( this, ID_DEFAULT, wxT("y"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizer21->Add( m_staticText32, 0, wxALL, 5 );
	
	_textPosY = new wxTextCtrl( this, DIALOG_CAMERA_POSY, wxT(""), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizer21->Add( _textPosY, 0, wxALL, 5 );
	
	m_staticText33 = new wxStaticText( this, ID_DEFAULT, wxT("z"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizer21->Add( m_staticText33, 0, wxALL, 5 );
	
	_textPosZ = new wxTextCtrl( this, DIALOG_CAMERA_POSZ, wxT(""), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizer21->Add( _textPosZ, 0, wxALL, 5 );
	
	bSizer8->Add( sbSizer21, 0, wxEXPAND, 5 );
	
	wxStaticBoxSizer* sbSizer22;
	sbSizer22 = new wxStaticBoxSizer( new wxStaticBox( this, -1, wxT("Target") ), wxHORIZONTAL );
	
	m_staticText34 = new wxStaticText( this, ID_DEFAULT, wxT("x"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizer22->Add( m_staticText34, 0, wxALL, 5 );
	
	_textTargetX = new wxTextCtrl( this, DIALOG_CAMERA_TARGETX, wxT(""), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizer22->Add( _textTargetX, 0, wxALL, 5 );
	
	m_staticText35 = new wxStaticText( this, ID_DEFAULT, wxT("y"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizer22->Add( m_staticText35, 0, wxALL, 5 );
	
	_textTargetY = new wxTextCtrl( this, DIALOG_CAMERA_TARGETY, wxT(""), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizer22->Add( _textTargetY, 0, wxALL, 5 );
	
	m_staticText36 = new wxStaticText( this, ID_DEFAULT, wxT("z"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizer22->Add( m_staticText36, 0, wxALL, 5 );
	
	_textTargetZ = new wxTextCtrl( this, DIALOG_CAMERA_TARGETZ, wxT(""), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizer22->Add( _textTargetZ, 0, wxALL, 5 );
	
	bSizer8->Add( sbSizer22, 0, wxEXPAND, 5 );
	
	wxStaticBoxSizer* sbSizer23;
	sbSizer23 = new wxStaticBoxSizer( new wxStaticBox( this, -1, wxT("Clipping") ), wxHORIZONTAL );
	
	m_staticText38 = new wxStaticText( this, ID_DEFAULT, wxT("near"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizer23->Add( m_staticText38, 0, wxALL, 5 );
	
	_textNear = new wxTextCtrl( this, DIALOG_CAMERA_NEAR, wxT(""), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizer23->Add( _textNear, 0, wxALL, 5 );
	
	m_staticText39 = new wxStaticText( this, ID_DEFAULT, wxT("far"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizer23->Add( m_staticText39, 0, wxALL, 5 );
	
	_textFar = new wxTextCtrl( this, DIALOG_CAMERA_FAR, wxT(""), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizer23->Add( _textFar, 0, wxALL, 5 );
	
	m_staticText41 = new wxStaticText( this, ID_DEFAULT, wxT("FOV"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizer23->Add( m_staticText41, 0, wxALL, 5 );
	
	_textFOV = new wxTextCtrl( this, DIALOG_CAMERA_FOV, wxT(""), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizer23->Add( _textFOV, 0, wxALL, 5 );
	
	bSizer8->Add( sbSizer23, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer9;
	bSizer9 = new wxBoxSizer( wxHORIZONTAL );
	
	m_button8 = new wxButton( this, wxID_OK, wxT("OK"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer9->Add( m_button8, 0, wxALL, 5 );
	
	m_button9 = new wxButton( this, wxID_CANCEL, wxT("Cancel"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer9->Add( m_button9, 0, wxALL, 5 );
	
	bSizer8->Add( bSizer9, 0, wxALIGN_CENTER_HORIZONTAL|wxEXPAND, 5 );
	
	this->SetSizer( bSizer8 );
	this->Layout();
	bSizer8->Fit( this );
}

SanDemo::SanDemo( wxWindow* parent, int id, wxString title, wxPoint pos, wxSize size, int style ) : wxFrame( parent, id, title, pos, size, style )
{
	_menuBar = new wxMenuBar( 0 );
	wxMenu* _menuFile;
	_menuFile = new wxMenu();
	wxMenuItem* menuItem3 = new wxMenuItem( _menuFile, MAIN_MENU_LOAD, wxString( wxT("Load scene") ) + wxT('\t') + wxT("F2"), wxT(""), wxITEM_NORMAL );
	_menuFile->Append( menuItem3 );
	wxMenuItem* menuItem2 = new wxMenuItem( _menuFile, MAIN_MENU_SAVE, wxString( wxT("Save scene") ) + wxT('\t') + wxT("Ctrl+s"), wxT(""), wxITEM_NORMAL );
	_menuFile->Append( menuItem2 );
	
	_menuFile->AppendSeparator();
	wxMenuItem* menuItem1 = new wxMenuItem( _menuFile, MAIN_MENU_QUIT, wxString( wxT("Quit") ) + wxT('\t') + wxT("Ctrl+q"), wxT(""), wxITEM_NORMAL );
	_menuFile->Append( menuItem1 );
	_menuBar->Append( _menuFile, wxT("File") );
	wxMenu* _menuScene;
	_menuScene = new wxMenu();
	wxMenuItem* menuItem4 = new wxMenuItem( _menuScene, MAIN_MENU_ADDOBJECT, wxString( wxT("Add object") ) + wxT('\t') + wxT("Ctrl+o"), wxT(""), wxITEM_NORMAL );
	_menuScene->Append( menuItem4 );
	wxMenuItem* menuItem5 = new wxMenuItem( _menuScene, MAIN_MENU_ADDLIGHT, wxString( wxT("Add light") ) + wxT('\t') + wxT("Ctrl+l"), wxT(""), wxITEM_NORMAL );
	_menuScene->Append( menuItem5 );
	wxMenuItem* menuItem7 = new wxMenuItem( _menuScene, MAIN_MENU_CHANGECAMERA, wxString( wxT("Modify camera") ) , wxT(""), wxITEM_NORMAL );
	_menuScene->Append( menuItem7 );
	
	_menuScene->AppendSeparator();
	wxMenuItem* menuItem6 = new wxMenuItem( _menuScene, MAIN_MENU_SHOWTREE, wxString( wxT("Show scene tree") ) , wxT(""), wxITEM_CHECK );
	_menuScene->Append( menuItem6 );
	menuItem6->Check( true );
	
	_menuBar->Append( _menuScene, wxT("Scene") );
	wxMenu* _menuRender;
	_menuRender = new wxMenu();
	wxMenuItem* menuItem8 = new wxMenuItem( _menuRender, MAIN_MENU_RENDERPROPS, wxString( wxT("Set properties") ) , wxT(""), wxITEM_NORMAL );
	_menuRender->Append( menuItem8 );
	_menuBar->Append( _menuRender, wxT("Render") );
	wxMenu* _menuAbout;
	_menuAbout = new wxMenu();
	wxMenuItem* menuItem9 = new wxMenuItem( _menuAbout, MAIN_MENU_ABOUT, wxString( wxT("About") ) , wxT(""), wxITEM_NORMAL );
	_menuAbout->Append( menuItem9 );
	_menuBar->Append( _menuAbout, wxT("Help") );
	this->SetMenuBar( _menuBar );
	
}
