#include "WXMainFrame.h"

#include "San.h"
#include "MyRenderTarget.h"

/*
** Fonction appell?e ? interval r?gulier
** affiche et anime la sc?ne
*/
void CTimer::Notify()
{
	if( !_scene ) return;
	if( !_renderWindow ) return;

	sanFloat fps = 1000.0 / GetInterval();
	wxString str;
	str.Printf( "FPS: %f", fps );

	_elapsedTime += GetInterval();
	sanFloat dt = _elapsedTime / 1000.0;


	CCamera *cam = (CCamera*)_scene->GetCameraList();
	if( cam )
	{
		wxClientDC dc( _renderWindow );

		CViewport *vp = cam->GetViewport();
		MyRenderTarget *rt = (MyRenderTarget*)vp->GetRenderTarget();

		wxBufferedDC bdc( &dc, rt->_backbuffer );
		rt->_dc = &bdc;

		// un peu d'animation

		/*
		CEntity *entity = _scene->GetEntityList();
		while( entity )
		{
			CMatrix3 mat;
			mat.fromAxisAngle( CVector3(0.0,1.0,0.0), GetInterval() / 1000.0 );
			entity->SetDirection( mat * entity->GetDirection() );
			entity = (CEntity*)entity->GetNext();
		}
		*/

	//	_scene->GetCameraList()->SetPosition( CVector4( Sin( dt )*300, 0.0, Cos( dt )*300 + 300 ) );
//		_scene->GetCameraList()->SetTarget( CVector3(0,0,300) );

		// normalement animation et rendu se font s?par?ment...
		_scene->AnimateScene( GetInterval()/1000 );

		if( rt->OnBeginRender() )
		{
			bdc.SetPen( wxPen( wxColour(255,255,255) ) );
			bdc.DrawText( str, wxPoint(10,30) );
			rt->Clear();
			_scene->RenderScene();
			rt->OnEndRender();
		}
	}
}



CRenderWindow::CRenderWindow( wxWindow *parent, wxWindowID id )
:wxWindow( parent, id, wxDefaultPosition, wxDefaultSize, wxDOUBLE_BORDER )
{
}

void CRenderWindow::OnKeyDown( wxKeyEvent &event )
{
	if( event.GetKeyCode() == WXK_UP )
	{
		SanDemo* frame = (SanDemo*)GetParent();
		CScene *scene = frame->GetScene();
		if( scene )
		{
			CCamera *camera = scene->GetCameraList();
			if( camera )
			{
				camera->MoveForward( 10.0 );
			}
		}
	}
	event.Skip();
}

CDialogAddLight::CDialogAddLight( wxWindow* parent, int id, wxString title, wxPoint pos, wxSize size, int style ) : wxDialog( parent, id, title, pos, size, style )
{
	wxBoxSizer* bSizer1;
	bSizer1 = new wxBoxSizer( wxVERTICAL );
	
	wxString _radioboxTypeChoices[] = { wxT("Ambiant"), wxT("Directionnal"), wxT("Point"), wxT("Spot") };
	int _radioboxTypeNChoices = sizeof( _radioboxTypeChoices ) / sizeof( wxString );
	_radioboxType = new wxRadioBox( this, DIALOG_ADD_LIGHT_TYPE, wxT("Light type"), wxDefaultPosition, wxDefaultSize, _radioboxTypeNChoices, _radioboxTypeChoices, 4, wxRA_SPECIFY_COLS );
	bSizer1->Add( _radioboxType, 0, wxALL, 5 );

	wxImage image( 20, 20, true );
	wxBitmap bitmap( image );
	
	wxStaticBoxSizer* sbSizer2;
	sbSizer2 = new wxStaticBoxSizer( new wxStaticBox( this, -1, wxT("Light composants") ), wxHORIZONTAL );
	
	m_staticText4 = new wxStaticText( this, ID_DEFAULT, wxT("ambiant"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizer2->Add( m_staticText4, 0, wxALL, 5 );
	
	_buttonAmbiant = new wxBitmapButton( this, DIALOG_ADD_LIGHT_AMBIANT, bitmap, wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	sbSizer2->Add( _buttonAmbiant, 0, wxALL, 5 );
	
	m_staticText5 = new wxStaticText( this, ID_DEFAULT, wxT("diffuse"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizer2->Add( m_staticText5, 0, wxALL, 5 );
	
	_buttonDiffuse = new wxBitmapButton( this, DIALOG_ADD_LIGHT_DIFFUSE, bitmap, wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	_buttonDiffuse->Enable( false );
	
	sbSizer2->Add( _buttonDiffuse, 0, wxALL, 5 );
	
	m_staticText6 = new wxStaticText( this, ID_DEFAULT, wxT("specular"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizer2->Add( m_staticText6, 0, wxALL, 5 );
	
	_buttonSpecular = new wxBitmapButton( this, DIALOG_ADD_LIGHT_SPECULAR, bitmap, wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
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
	
	_textDirX = new wxTextCtrl( this, DIALOG_ADD_LIGHT_DIRX, wxT("0.0"), wxDefaultPosition, wxDefaultSize, 0 );
	_textDirX->Enable( false );
	
	sbSizer8->Add( _textDirX, 0, wxALL, 5 );
	
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

void CDialogAddLight::OnButton( wxCommandEvent &event )
{
	if( event.GetEventObject() == _buttonAmbiant )
	{
		wxColourDialog cd( this );
		cd.SetTitle( wxString( _T("Ambiant Color") ) );
		if( cd.ShowModal() == wxID_OK )
		{
			_ambiant = cd.GetColourData().GetColour();
			wxImage image( 40, 40 );
			unsigned char *data = image.GetData();
			for( int i=0; i<40*40*3; i+=3 )
			{
				data[i] = _ambiant.Red();
				data[i+1] = _ambiant.Green();
				data[i+2] = _ambiant.Blue();
			}
			wxBitmap bitmap( image );
			_buttonAmbiant->SetBitmapSelected( bitmap );
			_buttonAmbiant->SetBitmapFocus( bitmap );
			_buttonAmbiant->SetBitmapDisabled( bitmap );
			_buttonAmbiant->SetBitmapLabel( bitmap );
		}
	}
	else if( event.GetEventObject() == _buttonDiffuse )
	{
		wxColourDialog cd( this );
		cd.SetTitle( wxString( _T("Diffuse Color") ) );
		if( cd.ShowModal() == wxID_OK )
		{
			_diffuse = cd.GetColourData().GetColour();
			wxImage image( 40, 40 );
			unsigned char *data = image.GetData();
			for( int i=0; i<40*40*3; i+=3 )
			{
				data[i] = _diffuse.Red();
				data[i+1] = _diffuse.Green();
				data[i+2] = _diffuse.Blue();
			}
			wxBitmap bitmap( image );
			_buttonDiffuse->SetBitmapSelected( bitmap );
			_buttonDiffuse->SetBitmapFocus( bitmap );
			_buttonDiffuse->SetBitmapDisabled( bitmap );
			_buttonDiffuse->SetBitmapLabel( bitmap );
		}
	}
	else if( event.GetEventObject() == _buttonSpecular )
	{
		wxColourDialog cd( this );
		cd.SetTitle( wxString( _T("Specular Color") ) );
		if( cd.ShowModal() == wxID_OK )
		{
			_specular = cd.GetColourData().GetColour();
			wxImage image( 40, 40 );
			unsigned char *data = image.GetData();
			for( int i=0; i<40*40*3; i+=3 )
			{
				data[i] = _specular.Red();
				data[i+1] = _specular.Green();
				data[i+2] = _specular.Blue();
			}
			wxBitmap bitmap( image );
			_buttonSpecular->SetBitmapSelected( bitmap );
			_buttonSpecular->SetBitmapFocus( bitmap );
			_buttonSpecular->SetBitmapDisabled( bitmap );
			_buttonSpecular->SetBitmapLabel( bitmap );
		}
	}
}

void CDialogAddLight::OnModifyType( wxCommandEvent &event )
{
	switch( _radioboxType->GetSelection() )
	{
	case 0:
		{
			_buttonDiffuse->Enable( false );
			_buttonSpecular->Enable( false );
			_textPosX->Enable( false );
			_textPosY->Enable( false );
			_textPosZ->Enable( false );
			_textDirX->Enable( false );
			_textDirY->Enable( false );
			_textDirZ->Enable( false );
			_textFadingStart->Enable( false );
			_textFadingEnd->Enable( false );
			break;
		}
	case 1:
		{
			_textPosX->Enable( false );
			_textPosY->Enable( false );
			_textPosZ->Enable( false );
			_textDirX->Enable( true );
			_textDirY->Enable( true );
			_textDirZ->Enable( true );
			_buttonDiffuse->Enable( true );
			_buttonSpecular->Enable( true );
			_textFadingStart->Enable( false );
			_textFadingEnd->Enable( false );
			break;
		}
	case 2:
	case 3:
		{
			_textPosX->Enable( true );
			_textPosY->Enable( true );
			_textPosZ->Enable( true );
			_textDirX->Enable( true );
			_textDirY->Enable( true );
			_textDirZ->Enable( true );
			_buttonDiffuse->Enable( true );
			_buttonSpecular->Enable( true );
			break;
		}
	}
}

CDialogAddObject::CDialogAddObject( wxWindow* parent, int id, wxString title, wxPoint pos, wxSize size, int style ) : wxDialog( parent, id, title, pos, size, style )
{
	wxStaticBoxSizer* sbSizer10;
	sbSizer10 = new wxStaticBoxSizer( new wxStaticBox( this, -1, wxT("Add an object") ), wxVERTICAL );

	wxStaticBoxSizer* sbSizerName;
	sbSizerName = new wxStaticBoxSizer( new wxStaticBox( this, -1, wxT("Name") ), wxHORIZONTAL );
	
	_textName = new wxTextCtrl( this, ID_DEFAULT );
	sbSizerName->Add( _textName, 0, wxALL, 5 );

	sbSizer10->Add( sbSizerName, 0, wxEXPAND, 5 );
	
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
	
	_textPosZ = new wxTextCtrl( this, DIALOG_ADD_OBJECT_POSZ, wxT("500.0"), wxDefaultPosition, wxDefaultSize, 0 );
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
	
	wxImage image( 20, 20, true );
	wxBitmap bitmap( image );
	
	wxStaticBoxSizer* sbSizer19;
	sbSizer19 = new wxStaticBoxSizer( new wxStaticBox( this, -1, wxT("Material") ), wxHORIZONTAL );
	
	m_staticText27 = new wxStaticText( this, ID_DEFAULT, wxT("ambiant"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizer19->Add( m_staticText27, 0, wxALL, 5 );
	
	_buttonAmbiant = new wxBitmapButton( this, DIALOG_ADD_OBJECT_AMBIANT, bitmap, wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	sbSizer19->Add( _buttonAmbiant, 0, wxALL, 5 );
	
	m_staticText28 = new wxStaticText( this, ID_DEFAULT, wxT("diffuse"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizer19->Add( m_staticText28, 0, wxALL, 5 );
	
	_buttonDiffuse = new wxBitmapButton( this, DIALOG_ADD_OBJECT_DIFFUSE, bitmap, wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	sbSizer19->Add( _buttonDiffuse, 0, wxALL, 5 );
	
	m_staticText29 = new wxStaticText( this, ID_DEFAULT, wxT("specular"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizer19->Add( m_staticText29, 0, wxALL, 5 );
	
	_buttonSpecular = new wxBitmapButton( this, DIALOG_ADD_OBJECT_SPECULAR, bitmap, wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
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

void CDialogAddObject::OnChangeType( wxCommandEvent& event )
{
	switch( _radioboxMeshType->GetSelection() )
	{
	case 3:
		{
			_textMeshPath->Enable( true );
			_buttonChoosePath->Enable( true );
			break;
		}
	default:
		{
			_textMeshPath->Enable( false );
			_buttonChoosePath->Enable( false );
		}
	}
}

void CDialogAddObject::OnButton( wxCommandEvent& event )
{
	if( event.GetEventObject() == _buttonAmbiant )
	{
		wxColourDialog cd( this );
		cd.SetTitle( wxString( _T("Ambiant Color") ) );
		if( cd.ShowModal() == wxID_OK )
		{
			_ambiant = cd.GetColourData().GetColour();
			wxImage image( 40, 40 );
			unsigned char *data = image.GetData();
			for( int i=0; i<40*40*3; i+=3 )
			{
				data[i] = _ambiant.Red();
				data[i+1] = _ambiant.Green();
				data[i+2] = _ambiant.Blue();
			}
			wxBitmap bitmap( image );
			_buttonAmbiant->SetBitmapSelected( bitmap );
			_buttonAmbiant->SetBitmapFocus( bitmap );
			_buttonAmbiant->SetBitmapDisabled( bitmap );
			_buttonAmbiant->SetBitmapLabel( bitmap );
		}
	}
	else if( event.GetEventObject() == _buttonDiffuse )
	{
		wxColourDialog cd( this );
		cd.SetTitle( wxString( _T("Diffuse Color") ) );
		if( cd.ShowModal() == wxID_OK )
		{
			_diffuse = cd.GetColourData().GetColour();
			wxImage image( 40, 40 );
			unsigned char *data = image.GetData();
			for( int i=0; i<40*40*3; i+=3 )
			{
				data[i] = _diffuse.Red();
				data[i+1] = _diffuse.Green();
				data[i+2] = _diffuse.Blue();
			}
			wxBitmap bitmap( image );
			_buttonDiffuse->SetBitmapSelected( bitmap );
			_buttonDiffuse->SetBitmapFocus( bitmap );
			_buttonDiffuse->SetBitmapDisabled( bitmap );
			_buttonDiffuse->SetBitmapLabel( bitmap );
		}
	}
	else if( event.GetEventObject() == _buttonSpecular )
	{
		wxColourDialog cd( this );
		cd.SetTitle( wxString( _T("Specular Color") ) );
		if( cd.ShowModal() == wxID_OK )
		{
			_specular = cd.GetColourData().GetColour();
			wxImage image( 40, 40 );
			unsigned char *data = image.GetData();
			for( int i=0; i<40*40*3; i+=3 )
			{
				data[i] = _specular.Red();
				data[i+1] = _specular.Green();
				data[i+2] = _specular.Blue();
			}
			wxBitmap bitmap( image );
			_buttonSpecular->SetBitmapSelected( bitmap );
			_buttonSpecular->SetBitmapFocus( bitmap );
			_buttonSpecular->SetBitmapDisabled( bitmap );
			_buttonSpecular->SetBitmapLabel( bitmap );
		}
	}
	else if( event.GetEventObject() == _buttonChoosePath )
	{
		wxFileDialog dialog( this, wxString( _T("Load external mesh") ) );
		if( dialog.ShowModal() == wxID_OK )
		{
			_textMeshPath->SetValue( dialog.GetPath() );
		}
	}
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
	
	_textPosX = new wxTextCtrl( this, DIALOG_CAMERA_POSX, wxT("0.0"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizer21->Add( _textPosX, 0, wxALL, 5 );
	
	m_staticText32 = new wxStaticText( this, ID_DEFAULT, wxT("y"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizer21->Add( m_staticText32, 0, wxALL, 5 );
	
	_textPosY = new wxTextCtrl( this, DIALOG_CAMERA_POSY, wxT("0.0"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizer21->Add( _textPosY, 0, wxALL, 5 );
	
	m_staticText33 = new wxStaticText( this, ID_DEFAULT, wxT("z"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizer21->Add( m_staticText33, 0, wxALL, 5 );
	
	_textPosZ = new wxTextCtrl( this, DIALOG_CAMERA_POSZ, wxT("0.0"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizer21->Add( _textPosZ, 0, wxALL, 5 );
	
	bSizer8->Add( sbSizer21, 0, wxEXPAND, 5 );
	
	wxStaticBoxSizer* sbSizer22;
	sbSizer22 = new wxStaticBoxSizer( new wxStaticBox( this, -1, wxT("Target") ), wxHORIZONTAL );
	
	m_staticText34 = new wxStaticText( this, ID_DEFAULT, wxT("x"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizer22->Add( m_staticText34, 0, wxALL, 5 );
	
	_textTargetX = new wxTextCtrl( this, DIALOG_CAMERA_TARGETX, wxT("0.0"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizer22->Add( _textTargetX, 0, wxALL, 5 );
	
	m_staticText35 = new wxStaticText( this, ID_DEFAULT, wxT("y"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizer22->Add( m_staticText35, 0, wxALL, 5 );
	
	_textTargetY = new wxTextCtrl( this, DIALOG_CAMERA_TARGETY, wxT("0.0"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizer22->Add( _textTargetY, 0, wxALL, 5 );
	
	m_staticText36 = new wxStaticText( this, ID_DEFAULT, wxT("z"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizer22->Add( m_staticText36, 0, wxALL, 5 );
	
	_textTargetZ = new wxTextCtrl( this, DIALOG_CAMERA_TARGETZ, wxT("1.0"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizer22->Add( _textTargetZ, 0, wxALL, 5 );
	
	bSizer8->Add( sbSizer22, 0, wxEXPAND, 5 );
	
	wxStaticBoxSizer* sbSizer23;
	sbSizer23 = new wxStaticBoxSizer( new wxStaticBox( this, -1, wxT("Clipping") ), wxHORIZONTAL );
	
	m_staticText38 = new wxStaticText( this, ID_DEFAULT, wxT("near"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizer23->Add( m_staticText38, 0, wxALL, 5 );
	
	_textNear = new wxTextCtrl( this, DIALOG_CAMERA_NEAR, wxT("1.0"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizer23->Add( _textNear, 0, wxALL, 5 );
	
	m_staticText39 = new wxStaticText( this, ID_DEFAULT, wxT("far"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizer23->Add( m_staticText39, 0, wxALL, 5 );
	
	_textFar = new wxTextCtrl( this, DIALOG_CAMERA_FAR, wxT("900.0"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizer23->Add( _textFar, 0, wxALL, 5 );
	
	m_staticText41 = new wxStaticText( this, ID_DEFAULT, wxT("FOV(deg)"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizer23->Add( m_staticText41, 0, wxALL, 5 );
	
	_textFOV = new wxTextCtrl( this, DIALOG_CAMERA_FOV, wxT("90.0"), wxDefaultPosition, wxDefaultSize, 0 );
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


void CDialogCamera::OnModifyType( wxCommandEvent &event )
{
	switch( _radioboxType->GetSelection() )
	{
	case 0:
		{
			_textPosX->Enable( true );
			_textPosY->Enable( true );
			_textPosZ->Enable( true );
			_textTargetX->Enable( false );
			_textTargetY->Enable( false );
			_textTargetZ->Enable( false );
			break;
		}
	case 1:
		{
			_textPosX->Enable( false );
			_textPosY->Enable( false );
			_textPosZ->Enable( false );
			_textTargetX->Enable( true );
			_textTargetY->Enable( true );
			_textTargetZ->Enable( true );
			break;
		}
	}
}

SanDemo::SanDemo( wxWindow* parent, int id, wxString title, wxPoint pos, wxSize size, int style ) : wxFrame( parent, id, title, pos, size, style )
{
	int resX=640, resY=480;
	MyRenderTarget *renderTarget = new MyRenderTarget( resX, resY, 3 );

	CViewport *viewport = new CViewport(
					0, 0,
					resX, resY,
					renderTarget );

	CCamera *camera = new CCamera( viewport, "Camera" );
	camera->SetAspect( resX / resY );

	CSoftwareRenderer *renderer = new CSoftwareRenderer();
	renderer->SetCullMode( 1 );

	_scene = new CScene();
	_scene->SetRenderer( renderer );
	_scene->AddChild( camera );

	_scene->GetMeshManager()->Load( "IndexedCube" );
	_scene->GetMeshManager()->Load( "IndexedTriangle" );
	_scene->GetMeshManager()->Load( "IndexedSphere" );

	_scene->GetTextureManager()->Load( "tex.png" );

	_sceneTree = NULL;
	_renderWindow = NULL;

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

	wxMenuItem* menuItemRemove = new wxMenuItem( _menuScene, MAIN_MENU_REMOVEITEM, wxString( wxT("Delete seletion") ) , wxT(""), wxITEM_NORMAL );
	_menuScene->Append( menuItemRemove );
	
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

	_sceneTree = new CTreeScene(
		this, TREE_SCENE,
		wxDefaultPosition, wxDefaultSize,
		wxTR_DEFAULT_STYLE | wxTR_HAS_VARIABLE_ROW_HEIGHT | wxBORDER_DOUBLE );

	_sceneTree->AddRoot( _T("Scene"), 0, -1 );
	_sceneTree->SelectItem( _sceneTree->GetRootItem() );
	_sceneTree->RefreshList( _scene );

	Resize();

	_renderWindow = new CRenderWindow( this, MAIN_RENDER_WINDOW );
}

void SanDemo::OnQuit( wxCommandEvent &event )
{
	SAFE_RELEASE( _scene );
	Close( true );
}

void SanDemo::OnSize( wxSizeEvent &event )
{
	Resize();
	event.Skip();
}

void SanDemo::Resize()
{
	wxSize size = GetClientSize();
	if( _scene && _renderWindow )
	{
		sanLong viewx = _scene->GetCameraList()->GetViewport()->GetRenderTarget()->GetWidth();
		sanLong viewy = _scene->GetCameraList()->GetViewport()->GetRenderTarget()->GetHeight();
		 _sceneTree->SetSize( 
			 0,
			 0, 
			 size.x - viewx,
			 size.y );
		_renderWindow->SetSize(
			size.x - viewx,
			0.0,
			viewx,
			viewy );
	}
}

void SanDemo::OnAddLight( wxCommandEvent& event )
{
	CDialogAddLight dialog( this );

	if( dialog.ShowModal() == wxID_OK )
	{
		switch( dialog._radioboxType->GetSelection() )
		{
		case 0:
			{
				CAmbiantLight *light = new CAmbiantLight();
				light->_ambiant = CVector3(
					dialog._ambiant.Red() / 255.0,
					dialog._ambiant.Green() / 255.0,
					dialog._ambiant.Blue() / 255.0
					);
				_scene->AddChild( light );
				break;
			}
		case 1:
			{
				CDirectionnalLight *light = new CDirectionnalLight();
				light->_ambiant = CVector3(
					dialog._ambiant.Red() / 255.0,
					dialog._ambiant.Green() / 255.0,
					dialog._ambiant.Blue() / 255.0
					);
				light->_diffuse = CVector3(
					dialog._diffuse.Red() / 255.0,
					dialog._diffuse.Green() / 255.0,
					dialog._diffuse.Blue() / 255.0
					);
				light->_specular = CVector3(
					dialog._specular.Red() / 255.0,
					dialog._specular.Green() / 255.0,
					dialog._specular.Blue() / 255.0
					);
				sanFloat x=0, y=0, z=0;
				sscanf( dialog._textDirX->GetValue(), "%f", &x );
				sscanf( dialog._textDirY->GetValue(), "%f", &y );
				sscanf( dialog._textDirZ->GetValue(), "%f", &z );
				light->_dir = CVector3(x,y,z);
				_scene->AddChild( light );
				break;
			}
		default:
			break;
		}
		_sceneTree->RefreshList( _scene );
	}
}

void SanDemo::OnAddEntity( wxCommandEvent& event )
{
	CDialogAddObject dialog( this );
	if( dialog.ShowModal() == wxID_OK )
	{
		CEntity *entity = new CEntity( dialog._textName->GetValue() );
		sanFloat x, y, z, dirX, dirY, dirZ, scaleX, scaleY, scaleZ;

		sscanf( dialog._textPosX->GetValue(), "%f", &x );
		sscanf( dialog._textPosY->GetValue(), "%f", &y );
		sscanf( dialog._textPosZ->GetValue(), "%f", &z );
		sscanf( dialog._textDirX->GetValue(), "%f", &dirX );
		sscanf( dialog._textDirY->GetValue(), "%f", &dirY );
		sscanf( dialog._textDirZ->GetValue(), "%f", &dirZ );
		sscanf( dialog._textScaleX->GetValue(), "%f", &scaleX );
		sscanf( dialog._textScaleY->GetValue(), "%f", &scaleY );
		sscanf( dialog._textScaleZ->GetValue(), "%f", &scaleZ );

		CMesh *mesh = NULL;

		switch( dialog._radioboxMeshType->GetSelection() )
		{
		case 0:
			{
				mesh = (CMesh*)_scene->GetMeshManager()->Load( "IndexedTriangle" );
				if( !mesh )
				{
					mesh = CreateIndexedTriangle();
					_scene->GetMeshManager()->AddChild( mesh );
				}
				break;
			}
		case 1:
			{
				mesh = (CMesh*)_scene->GetMeshManager()->Load( "IndexedCube" );
				if( !mesh )
				{
					mesh = CreateIndexedCube( 100.0 );
					_scene->GetMeshManager()->AddChild( mesh );
				}
				break;
			}
		case 2:
			{
				mesh = (CMesh*)_scene->GetMeshManager()->Load( "IndexedSphere" );
				if( !mesh )
				{
					mesh = CreateIndexedSphere( 100, 20, 20 );
					_scene->GetMeshManager()->AddChild( mesh );
				}
				break;
			}
		case 3:
			{
				mesh = (CMesh*)_scene->GetMeshManager()->Load( 
					dialog._textMeshPath->GetValue()
					);
				if( !mesh )
				{
					if( wxMessageBox( 
						wxString(_T("Can not read the file!")),
						wxString(_T("Error reading file")) ) == wxOK )
					{
						entity->Release();
						return;
					}
				}
			}
		}

		entity->SetMesh( mesh );
		entity->GetMaterial()->_ambiant = CVector3(
			dialog._ambiant.Red() / 255.0,
			dialog._ambiant.Green() / 255.0,
			dialog._ambiant.Blue() / 255.0 );
		entity->GetMaterial()->_diffuse = CVector3(
			dialog._diffuse.Red() / 255.0,
			dialog._diffuse.Green() / 255.0,
			dialog._diffuse.Blue() / 255.0 );
		entity->GetMaterial()->_specular = CVector3(
			dialog._specular.Red() / 255.0,
			dialog._specular.Green() / 255.0,
			dialog._specular.Blue() / 255.0 );
		entity->GetMaterial()->_specularPower = dialog._spinPower->GetValue();

		switch( dialog._choiceLightningType->GetSelection() )
		{
		case 0:
			entity->SetLightModel( LIGHT_GOURAUD );
			break;
		case 1:
			entity->SetLightModel( LIGHT_PHONG );
			break;
		default:
			entity->SetLightModel( LIGHT_GOURAUD );
			break;
		}

		sanLong mode = MESH_INDEXED;
		switch( dialog._choiceMeshType->GetSelection() )
		{
		case 0:
			break;
		case 1:
			mode |= MESH_WITH_NORMALS;
			break;
		case 2:
			mode |= MESH_WITH_NORMALS | MESH_TEXTURED;
			// todo...
			entity->SetTexture( (CTexture*)_scene->GetTextureManager()->Load( "tex.png" ) );
			break;
		case 3:
			mode |= MESH_TEXTURED;
			break;
		}
		entity->GetMesh()->SetMeshType( mode );

		entity->SetPosition( CVector4(x,y,z) );
		entity->SetDirection( CVector3(dirX,dirY,dirZ) );
		entity->SetScale( CVector3(scaleX,scaleY,scaleZ) );

		// on ajoute l'objet comme fils du premier objet rencontr?s en remontant
		// l'arbre depuis l'item s?lectionn?

		wxTreeItemId item = _sceneTree->GetSelection();
		CTreeItemData *data = (CTreeItemData*)_sceneTree->GetItemData( item );
		if( data && data->GetNode() )
		{
			CNode *node = data->GetNode();
			while( node->GetParent() && !(node->GetNodeType() & ENTITY_NODE) )
			{
				node = node->GetParent();
			}
			node->AddChild( entity );
		}
		else
		{
			_scene->AddChild( entity );
		}

		_sceneTree->RefreshList( _scene );
	}
}

void SanDemo::OnKeyDown( wxKeyEvent &event )
{
	switch( event.GetKeyCode() )
	{
	case WXK_UP:
		if( _scene )
		{
			CCamera *camera = _scene->GetCameraList();
			if( camera )
			{
				camera->MoveForward( 10.0 );
			}
		}
	}
	event.Skip();
}

void SanDemo::OnRemoveItem( wxCommandEvent& event )
{
	_sceneTree->RemoveSelection();
}

void SanDemo::OnShowTree( wxCommandEvent& event )
{
	_sceneTree->Show( !_sceneTree->IsShown() );
}

void SanDemo::OnRenderProps( wxCommandEvent& event )
{
	CRenderDialog dialog( this, wxID_ANY, wxString( "Renderer properties" ) );
	if( dialog.ShowModal() == wxID_OK )
	{
		CCamera *camera = _scene->GetCameraList();
		if( camera )
		{
			sanLong w, h, nb;
			sscanf( dialog._texteWidth->GetValue(), "%d", &w );
			sscanf( dialog._texteHeight->GetValue(), "%d", &h );
			sscanf( dialog._texteComponents->GetValue(), "%d", &nb );
			CViewport *vp = camera->GetViewport();
			CRenderTarget *rt = vp->GetRenderTarget();
			vp->SetWidth( w );
			vp->SetHeight( h );
			rt->Resize( w, h );
			rt->SetComposantes( nb );
			sanLong op = SAN_LESS;
			switch( dialog._choiceOperation->GetSelection() )
			{
			case 0:
				op = SAN_LESS;
				break;
			case 1:
				op = SAN_LEQUAL;
				break;
			case 2:
				op = SAN_EQUAL;
				break;
			case 3:
				op = SAN_GEQUAL;
				break;
			case 4:
				op = SAN_GREATER;
				break;
			case 5:
				op = SAN_NEVER;
				break;
			case 6:
				op = SAN_ALWAYS;
				break;
			}
			rt->SetZBufferOp( op );
		}
		this->Resize();
	}
}
void SanDemo::OnLoad( wxCommandEvent& event )
{
}
void SanDemo::OnSave( wxCommandEvent& event )
{
}
void SanDemo::OnChangeCamera( wxCommandEvent& event )
{
	CDialogCamera dialog( this, wxID_ANY, "Change camera settings" );
	if( dialog.ShowModal() == wxID_OK )
	{
		sanFloat x,y,z,tx,ty,tz,n,f,fov;
		sscanf( dialog._textPosX->GetValue(), "%f", &x );
		sscanf( dialog._textPosY->GetValue(), "%f", &y );
		sscanf( dialog._textPosZ->GetValue(), "%f", &z );
		sscanf( dialog._textTargetX->GetValue(), "%f", &tx );
		sscanf( dialog._textTargetY->GetValue(), "%f", &ty );
		sscanf( dialog._textTargetZ->GetValue(), "%f", &tz );
		sscanf( dialog._textNear->GetValue(), "%f", &n );
		sscanf( dialog._textFar->GetValue(), "%f", &f );
		sscanf( dialog._textFOV->GetValue(), "%f", &fov );
		CCamera *camera = _scene->GetCameraList();
		if( camera )
		{
			camera->SetPosition( CVector4(x,y,z) );
			camera->SetDirection( CVector3(tx,ty,tz) - CVector3(x,y,z) );
			camera->SetZNear( n );
			camera->SetZFar( f );
			camera->SetOuverture( fov * SAN_PI / 180.0 );
		}
	}
}
void SanDemo::OnAbout( wxCommandEvent& event )
{
}


CTreeScene::CTreeScene()
{
}

CTreeScene::CTreeScene( wxWindow *parent, const wxWindowID &id,
						const wxPoint &pos, const wxSize &size,
						long style )
						: wxTreeCtrl( parent, id, pos, size, style )
{
	//wxImage image_node;
	//image_node.LoadFile( wxString("node.bmp"), wxBITMAP_TYPE_BMP );

	//wxBitmap bitmap_node( image_node.Rescale( 20, 20 ), -1 );

	//wxImageList *img_list = new wxImageList( 20, 20, true);
	//img_list->Add( bitmap_node, wxColour(255,255,255) );

	//AssignImageList( img_list );
}


CTreeScene::~CTreeScene()
{
}

void CTreeScene::AddSceneNode( CNode *node )
{
}


void CTreeScene::AddNodeRec( CNode *node, wxTreeItemId parent, CNode *nsel )
{
	wxTreeItemId id;
	wxString label;

	id = AppendItem(
		parent,
		wxString( node->GetName() ),
		-1, -1,
		new CTreeItemData( node ) );
	
	if( node->GetNodeType() & GEOMETRIC_NODE )
	{
		CGeometryNode *gnode = (CGeometryNode*)node;
		label.Printf( "position: (%f, %f, %f)", 
			gnode->GetPosition()._x,
			gnode->GetPosition()._y,
			gnode->GetPosition()._z );
		AppendItem( id, label );

		label.Printf( "direction: (%f, %f, %f)",
			gnode->GetDirection()._x,
			gnode->GetDirection()._y,
			gnode->GetDirection()._z );
		AppendItem( id, label );

		label.Printf( "scale: (%f, %f, %f)",
			gnode->GetScale()._x,
			gnode->GetScale()._y,
			gnode->GetScale()._z );
		AppendItem( id, label );

		label.Printf( "up: (%f, %f, %f)",
			gnode->GetUp()._x,
			gnode->GetUp()._y,
			gnode->GetUp()._z );
		AppendItem( id, label );

		if( node->GetNodeType() & NEWTON_NODE )
		{
			CNewtonNode *nnode = (CNewtonNode*)node;
			label.Printf( "velocity: (%f, %f, %f)",
				nnode->GetVelocity()._x,
				nnode->GetVelocity()._y,
				nnode->GetVelocity()._z );
			AppendItem( id, label );

			label.Printf( "forces: (%f, %f, %f)",
				nnode->GetSomme()._x,
				nnode->GetSomme()._y,
				nnode->GetSomme()._z );
			AppendItem( id, label );
		}
	}
	
	if( node->GetNodeType() & ENTITY_NODE )
	{
		CEntity *entity = (CEntity*)node;		

		label.Printf( "ambiant: (%f, %f, %f)",
			entity->GetMaterial()->_ambiant._x,
			entity->GetMaterial()->_ambiant._y,
			entity->GetMaterial()->_ambiant._z );
		AppendItem( id, label );

		label.Printf( "diffuse: (%f, %f, %f)",
			entity->GetMaterial()->_diffuse._x,
			entity->GetMaterial()->_diffuse._y,
			entity->GetMaterial()->_diffuse._z );
		AppendItem( id, label );

		label.Printf( "specular: (%f, %f, %f)",
			entity->GetMaterial()->_specular._x,
			entity->GetMaterial()->_specular._y,
			entity->GetMaterial()->_specular._z );
		AppendItem( id, label );

		label.Printf( "specular power: %d", entity->GetMaterial()->_specularPower );
		AppendItem( id, label );

		if( entity->GetLightningModel() == LIGHT_GOURAUD )
			AppendItem( id, "lightning model: GOURAUD" );
		if( entity->GetLightningModel() == LIGHT_PHONG )
			AppendItem( id, "lightning model: PHONG" );
		if( entity->GetLightningModel() == LIGHT_FLAT )
			AppendItem( id, "lightning model: FLAT" );

		if( entity->GetMesh() ) 
			label.Printf( _T("mesh: %s"), entity->GetMesh()->GetName() );
		else label.Printf( _T("mesh: none") );
			AppendItem( id, label );
	}

	if( node->GetNodeType() & LIGHT_NODE )
	{
		CAmbiantLight *light = (CAmbiantLight*)node;

		switch( light->_type )
		{
			case AMBIANT_LIGHT:
				label.Printf( _T("light type: ambiant") );
				break;
			case DIRECTIONNAL_LIGHT:
				label.Printf( _T("light type: directionnal") );
				break;
			case POINT_LIGHT:
				label.Printf( _T("light type: point") );
				break;
		}
		AppendItem( id, label );

		label.Printf( _T("ambiant: (%f, %f, %f)"), 
			light->_ambiant._x,
			light->_ambiant._y,
			light->_ambiant._z );
		AppendItem( id, label );

		if( light->_type != AMBIANT_LIGHT )
		{
			CDirectionnalLight *lightD = (CDirectionnalLight*)light;
			label.Printf( _T("diffuse: (%f, %f, %f)"), 
				lightD->_diffuse._x,
				lightD->_diffuse._y,
				lightD->_diffuse._z );
			AppendItem( id, label );

			label.Printf( _T("specular: (%f, %f, %f)"), 
				lightD->_specular._x,
				lightD->_specular._y,
				lightD->_specular._z );
			AppendItem( id, label );
		}

		if( light->_type == DIRECTIONNAL_LIGHT || light->_type == SPOT_LIGHT )
		{
			CDirectionnalLight *lightD = (CDirectionnalLight*)light;
			label.Printf( _T("direction: (%f, %f, %f)"), 
				lightD->_dir._x,
				lightD->_dir._y,
				lightD->_dir._z );
			AppendItem( id, label );
		}
		else if( light->_type == POINT_LIGHT )
		{
			CPointLight *lightD = (CPointLight*)light;
			label.Printf( _T("position: (%f, %f, %f)"), 
				lightD->_pos._x,
				lightD->_pos._y,
				lightD->_pos._z );
			AppendItem( id, label );
		}
	}

	if( node->GetNodeType() & MESH_NODE )
	{
		CMesh *mesh = (CMesh*)node;
	
		label.Printf( _T("triangles: %d"), mesh->GetTriangleCount() );
		AppendItem( id, label );

		label.Printf( _T("vertices: %d"), mesh->GetVertexCount() );
		AppendItem( id, label );

		if( mesh->GetMeshType() & MESH_INDEXED )
			AppendItem( id, "indexed mesh" );
		if( mesh->GetMeshType() & MESH_NON_INDEXED )
			AppendItem( id, "non indexed mesh" );
		if( mesh->GetMeshType() & MESH_WITH_NORMALS )
			AppendItem( id, "mesh with normals" );
		if( mesh->GetMeshType() & MESH_TEXTURED )
			AppendItem( id, "mesh with texture coordinates" );
		if( mesh->GetMeshType() & MESH_COLORED )
			AppendItem( id, "mesh with color datas" );
	}

	if( node->GetNodeType() & RESSOURCE_NODE )
	{
		CRessource *res = (CRessource*)node;

		label.Printf( _T("last use: %d"), res->_lastUse );
		AppendItem( id, label );

		label.Printf( _T("last used ressource: %d"), res->_lastRessourceUse );
		AppendItem( id, label );
	}
	if( node->GetNodeType() & CAMERA_NODE )
	{
		CCamera *camera = (CCamera*)node;

		label.Printf( _T("near plan: %f"), camera->GetZNear() );
		AppendItem( id, label );

		label.Printf( _T("far plan: %f"), camera->GetZFar() );
		AppendItem( id, label );

		label.Printf( _T("FOV: %f rad"), camera->GetOuverture() );
		AppendItem( id, label );
	}

	CNode *child = node->GetFirstChild();
	while( child )
	{
		AddNodeRec( child, id, nsel );
		child = child->GetNext();
	}

	if( node == nsel )
	{
		SelectItem( id, true );
		Expand( id );
	}
}

void CTreeScene::RefreshList( CScene *scene )
{
	wxTreeItemId idsel = GetSelection();
	CNode *node_selected = NULL;
	if( idsel.IsOk() )
	{
		CTreeItemData *data = (CTreeItemData*)GetItemData( idsel );
		if( data )
		{
			node_selected = data->GetNode();
		}
	}

	DeleteAllItems();

	wxTreeItemId id = AddRoot(
		wxString(scene->GetName()),
		-1,
		-1,
		new CTreeItemData( scene ) );

	CNode *node = scene->GetFirstChild();
	while( node )
	{
		AddNodeRec( node, id, node_selected );
		node = node->GetNext();
	}
}

// avoid repetition
#define TREE_EVENT_HANDLER(name)                                 \
void CTreeScene::name(wxTreeEvent& event)                        \
{                                                                \
    event.Skip();                                                \
}

TREE_EVENT_HANDLER(OnBeginRDrag)
TREE_EVENT_HANDLER(OnBeginDrag)
TREE_EVENT_HANDLER(OnEndDrag)
TREE_EVENT_HANDLER(OnBeginLabelEdit)
TREE_EVENT_HANDLER(OnEndLabelEdit)
TREE_EVENT_HANDLER(OnDeleteItem)
TREE_EVENT_HANDLER(OnGetInfo)
TREE_EVENT_HANDLER(OnSetInfo)
TREE_EVENT_HANDLER(OnItemExpanded)
TREE_EVENT_HANDLER(OnItemExpanding)
TREE_EVENT_HANDLER(OnItemCollapsed)
TREE_EVENT_HANDLER(OnItemCollapsing)
TREE_EVENT_HANDLER(OnSelChanged)
TREE_EVENT_HANDLER(OnSelChanging)
TREE_EVENT_HANDLER(OnItemMenu)
TREE_EVENT_HANDLER(OnItemActivated)
TREE_EVENT_HANDLER(OnItemRClick)

void CTreeScene::RemoveSelection()
{
	wxTreeItemId item = GetSelection();
	CTreeItemData *data = item.IsOk() ? (CTreeItemData*)GetItemData(item)
	:NULL;
	if( data )
	{
		CNode *node = data->GetNode();
		if( node && (
			(node->GetNodeType() & ENTITY_NODE) ||
			(node->GetNodeType() & LIGHT_NODE) ) )
		{
			node->Release();
			Delete( item );
		}
		else
		{
			wxMessageBox(
				wxString(_T("You can only delete Entity and lights")),
				wxString(_T("Could not delete the selection")));
		}
	}
	else
	{
		wxMessageBox(
			wxString(_T("You can only delete Entity and lights")),
			wxString(_T("Could not delete the selection")));
	}
}

void CTreeScene::OnTreeKeyDown( wxTreeEvent &event )
{
	switch( event.GetKeyEvent().GetKeyCode() )
	{
	case WXK_NUMPAD_DELETE:
	case WXK_DELETE:
		{
			RemoveSelection();
			break;
		}
	}
	event.Skip();
}

void CTreeScene::OnRMouseDown(wxMouseEvent& event)
{
	event.Skip();
}
void CTreeScene::OnRMouseUp(wxMouseEvent& event)
{
    event.Skip();
}
void CTreeScene::OnRMouseDClick(wxMouseEvent& event)
{
    event.Skip();
}

void CTreeScene::OnContextMenu(wxContextMenuEvent& event)
{
	event.Skip();
}

CRenderDialog::CRenderDialog( wxWindow* parent, int id, wxString title, wxPoint pos, wxSize size, int style ) : wxDialog( parent, id, title, pos, size, style )
{
	wxBoxSizer* bSizer1;
	bSizer1 = new wxBoxSizer( wxVERTICAL );
	
	wxStaticBoxSizer* sbSizer1;
	sbSizer1 = new wxStaticBoxSizer( new wxStaticBox( this, -1, wxT("Resolution") ), wxHORIZONTAL );
	
	m_staticText1 = new wxStaticText( this, ID_DEFAULT, wxT("width"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizer1->Add( m_staticText1, 0, wxALL, 5 );
	
	_texteWidth = new wxTextCtrl( this, ID_DEFAULT, wxT("600"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizer1->Add( _texteWidth, 0, wxALL, 5 );
	
	m_staticText2 = new wxStaticText( this, ID_DEFAULT, wxT("height"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizer1->Add( m_staticText2, 0, wxALL, 5 );
	
	_texteHeight = new wxTextCtrl( this, ID_DEFAULT, wxT("400"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizer1->Add( _texteHeight, 0, wxALL, 5 );
	
	m_staticText3 = new wxStaticText( this, ID_DEFAULT, wxT("components"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizer1->Add( m_staticText3, 0, wxALL, 5 );
	
	_texteComponents = new wxTextCtrl( this, ID_DEFAULT, wxT("4"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizer1->Add( _texteComponents, 0, wxALL, 5 );
	
	bSizer1->Add( sbSizer1, 1, wxEXPAND, 5 );
	
	wxStaticBoxSizer* sbSizer2;
	sbSizer2 = new wxStaticBoxSizer( new wxStaticBox( this, -1, wxT("Z-Buffer") ), wxHORIZONTAL );
	
	m_staticText4 = new wxStaticText( this, ID_DEFAULT, wxT("z test"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizer2->Add( m_staticText4, 0, wxALL, 5 );
	
	wxString _choiceOperationChoices[] = { wxT("LESS"), wxT("LESS OR EQUAL"), wxT("EQUAL"), wxT("GREATER OR EQUAL"), wxT("GREATER"), wxT("NEVER"), wxT("ALWAYS") };
	int _choiceOperationNChoices = sizeof( _choiceOperationChoices ) / sizeof( wxString );
	_choiceOperation = new wxChoice( this, ID_DEFAULT, wxDefaultPosition, wxDefaultSize, _choiceOperationNChoices, _choiceOperationChoices, 0 );
	sbSizer2->Add( _choiceOperation, 0, wxALL, 5 );
	
	bSizer1->Add( sbSizer2, 1, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer2;
	bSizer2 = new wxBoxSizer( wxHORIZONTAL );
	
	_buttonOK = new wxButton( this, wxID_OK, wxT("OK"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer2->Add( _buttonOK, 0, wxALL, 5 );
	
	_buttonCancel = new wxButton( this, wxID_CANCEL, wxT("Cancel"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer2->Add( _buttonCancel, 0, wxALL, 5 );
	
	bSizer1->Add( bSizer2, 0, wxALIGN_CENTER_HORIZONTAL, 5 );
	
	this->SetSizer( bSizer1 );
	this->Layout();
	bSizer1->Fit( this );
}