#include "WXSceneMenu.h"

#include "wx/image.h"

#include "SanTypes.h"
#include "SanLight.h"

AddLightDialog::AddLightDialog( wxWindow* parent, int id, wxString title, wxPoint pos, wxSize size, int style ) : wxDialog( parent, id, title, pos, size, style )
{
	wxBoxSizer* bSizer1;
	bSizer1 = new wxBoxSizer( wxVERTICAL );
	
	wxString _btnTypeChoices[] = { wxT("Ambiant"), wxT("Directionnal"), wxT("Point"), wxT("Spot") };
	int _btnTypeNChoices = sizeof( _btnTypeChoices ) / sizeof( wxString );
	_btnType = new wxRadioBox( this, Dialog_Light_ChangeType, wxT("Light type"), wxDefaultPosition, wxDefaultSize, _btnTypeNChoices, _btnTypeChoices, 4, wxRA_SPECIFY_COLS );
	_btnType->SetSelection( 1 );
	bSizer1->Add( _btnType, 0, wxALL, 5 );

	wxImage image1( 20, 20, true );
	wxImage image2( 20, 20, true );
	wxImage image3( 20, 20, true );
	wxBitmap bitmap1( image1 );
	wxBitmap bitmap2( image2 );
	wxBitmap bitmap3( image3 );
	
	wxStaticBoxSizer* sbSizer2;
	sbSizer2 = new wxStaticBoxSizer( new wxStaticBox( this, -1, wxT("Light composants") ), wxHORIZONTAL );
	
	wxStaticBoxSizer* sbSizer3;
	sbSizer3 = new wxStaticBoxSizer( new wxStaticBox( this, -1, wxT("Ambiant") ), wxHORIZONTAL );
	
	_btnAmbiantCol = new wxBitmapButton( this, Dialog_Light_ChooseAmbiant, bitmap1, wxDefaultPosition, wxDefaultSize );
	sbSizer3->Add( _btnAmbiantCol, 0, wxALL, 5 );
	
	sbSizer2->Add( sbSizer3, 1, wxEXPAND, 5 );
	
	wxStaticBoxSizer* sbSizer4;
	sbSizer4 = new wxStaticBoxSizer( new wxStaticBox( this, -1, wxT("Diffuse") ), wxHORIZONTAL );
	
	_btnDiffuseCol = new wxBitmapButton( this, Dialog_Light_ChooseDiffuse, bitmap2, wxDefaultPosition, wxDefaultSize );
	sbSizer4->Add( _btnDiffuseCol, 0, wxALL, 5 );
	
	sbSizer2->Add( sbSizer4, 1, wxEXPAND, 5 );
	
	wxStaticBoxSizer* sbSizer5;
	sbSizer5 = new wxStaticBoxSizer( new wxStaticBox( this, -1, wxT("Specular") ), wxHORIZONTAL );
	
	_btnSpecularCol = new wxBitmapButton( this, Dialog_Light_ChooseSpecular, bitmap3, wxDefaultPosition, wxDefaultSize );
	sbSizer5->Add( _btnSpecularCol, 0, wxALL, 5 );
	
	sbSizer2->Add( sbSizer5, 1, wxEXPAND, 5 );
	
	bSizer1->Add( sbSizer2, 1, wxEXPAND, 5 );
	
	wxStaticBoxSizer* sbSizer6;
	sbSizer6 = new wxStaticBoxSizer( new wxStaticBox( this, -1, wxT("Coorrdinates") ), wxVERTICAL );
	
	wxBoxSizer* bSizer6;
	bSizer6 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText9 = new wxStaticText( this, ID_DEFAULT, wxT("Position(x, y, z)"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer6->Add( m_staticText9, 0, wxALL, 5 );
	
	_textPosX = new wxTextCtrl( this, ID_DEFAULT, wxT("0.0"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer6->Add( _textPosX, 0, wxALL, 5 );
	
	_textPosY = new wxTextCtrl( this, ID_DEFAULT, wxT("0.0"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer6->Add( _textPosY, 0, wxALL, 5 );
	
	_textPosZ = new wxTextCtrl( this, ID_DEFAULT, wxT("0.0"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer6->Add( _textPosZ, 0, wxALL, 5 );
	
	sbSizer6->Add( bSizer6, 1, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer5;
	bSizer5 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText8 = new wxStaticText( this, ID_DEFAULT, wxT("Direction(x, y, z)"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer5->Add( m_staticText8, 0, wxALL, 5 );
	
	_textDirX = new wxTextCtrl( this, ID_DEFAULT, wxT("0.0"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer5->Add( _textDirX, 0, wxALL, 5 );
	
	_textDirY = new wxTextCtrl( this, ID_DEFAULT, wxT("0.0"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer5->Add( _textDirY, 0, wxALL, 5 );
	
	_textDirZ = new wxTextCtrl( this, ID_DEFAULT, wxT("1.0"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer5->Add( _textDirZ, 0, wxALL, 5 );
	
	sbSizer6->Add( bSizer5, 1, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer7;
	bSizer7 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText10 = new wxStaticText( this, ID_DEFAULT, wxT("Range(attenuation start, end)"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer7->Add( m_staticText10, 0, wxALL, 5 );
	
	_textRange1 = new wxTextCtrl( this, ID_DEFAULT, wxT("100.0"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer7->Add( _textRange1, 0, wxALL, 5 );
	
	_textRange2 = new wxTextCtrl( this, ID_DEFAULT, wxT("120.0"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer7->Add( _textRange2, 0, wxALL, 5 );
	
	sbSizer6->Add( bSizer7, 1, wxEXPAND, 5 );
	
	bSizer1->Add( sbSizer6, 1, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer8;
	bSizer8 = new wxBoxSizer( wxHORIZONTAL );
	
	_btnOK = new wxButton( this, wxID_OK, wxT("OK"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer8->Add( _btnOK, 0, wxALL, 5 );
	
	_btnCancel = new wxButton( this, wxID_CANCEL, wxT("Cancel"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer8->Add( _btnCancel, 0, wxALL, 5 );
	
	bSizer1->Add( bSizer8, 1, wxALIGN_CENTER_HORIZONTAL, 5 );
	
	this->SetSizer( bSizer1 );
	this->Layout();
}



AddObjectDialog::AddObjectDialog( wxWindow *parent )
				: wxDialog( parent, wxID_ANY, wxString(_T("Add object")) )
{
}

void AddObjectDialog::OnButton( wxCommandEvent &event )
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
}


CTreeScene::~CTreeScene()
{
}

void CTreeScene::AddSceneNode( CNode *node )
{
}

void CTreeScene::RefreshList( CScene *scene )
{
	/*
	** on mémorise l'élément actuellement sélectionné
	*/
	CNode *nselected = NULL;
	wxTreeItemId item = GetSelection();
	if( item.IsOk() )
	{
		CTreeItemData *data = (CTreeItemData*)GetItemData( item );
		if( data ) nselected = data->GetNode();
	}

	DeleteAllItems();

	AddRoot( _T("Scene"), -1, -1 );

	wxTreeItemId lightListID = AppendItem(
		GetRootItem(), 
		wxString( _T("Lights") ), -1, -1,
		new CTreeItemData( scene->GetLightList() )
		);

	CAmbiantLight *light = scene->GetLightList();

	while( light )
	{
		wxTreeItemId lightID = AppendItem( 
			lightListID,
			wxString( light->GetName() ), -1, -1,
			new CTreeItemData( light ) 
			);

		if( light == nselected ) item = lightID;

		wxString label;

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
		AppendItem( lightID, label );

		label.Printf( _T("ambiant: (%f, %f, %f)"), 
			light->_ambiant._x,
			light->_ambiant._y,
			light->_ambiant._z );
		AppendItem( lightID, label );

		if( light->_type != AMBIANT_LIGHT )
		{
			CDirectionnalLight *lightD = (CDirectionnalLight*)light;
			label.Printf( _T("diffuse: (%f, %f, %f)"), 
				lightD->_diffuse._x,
				lightD->_diffuse._y,
				lightD->_diffuse._z );
			AppendItem( lightID, label );

			label.Printf( _T("specular: (%f, %f, %f)"), 
				lightD->_specular._x,
				lightD->_specular._y,
				lightD->_specular._z );
			AppendItem( lightID, label );
		}

		if( light->_type == DIRECTIONNAL_LIGHT )
		{
			CDirectionnalLight *lightD = (CDirectionnalLight*)light;
			label.Printf( _T("direction: (%f, %f, %f)"), 
				lightD->_dir._x,
				lightD->_dir._y,
				lightD->_dir._z );
			AppendItem( lightID, label );
		}
		else if( light->_type == POINT_LIGHT )
		{
			CPointLight *lightD = (CPointLight*)light;
			label.Printf( _T("direction: (%f, %f, %f)"), 
				lightD->_pos._x,
				lightD->_pos._y,
				lightD->_pos._z );
			AppendItem( lightID, label );
		}

		light = (CAmbiantLight*)light->GetNext();
	}

	wxTreeItemId EntityListId = AppendItem( 
		GetRootItem(), wxString( _T("Objects") ), -1, -1,
		new CTreeItemData( scene->GetEntityList() ) );

	CEntity *entity = scene->GetEntityList();

	while( entity )
	{
		wxTreeItemId entityID = AppendItem(
			EntityListId,
			wxString( entity->GetName() ), -1, -1,
			new CTreeItemData( entity ) );

		wxString label;

		label.Printf( "position: (%f, %f, %f)", 
			entity->GetPosition()._x,
			entity->GetPosition()._y,
			entity->GetPosition()._z );
		AppendItem( entityID, label );

		label.Printf( "direction: (%f, %f, %f)",
			entity->GetDirection()._x,
			entity->GetDirection()._y,
			entity->GetDirection()._z );
		AppendItem( entityID, label );

		label.Printf( "scale: (%f, %f, %f)",
			entity->GetScale()._x,
			entity->GetScale()._y,
			entity->GetScale()._z );
		AppendItem( entityID, label );

		if( entity->GetMesh() ) 
			label.Printf( _T("mesh: %s"), entity->GetMesh()->GetName() );
		else label.Printf( _T("mesh: none") );
		AppendItem( entityID, label );

		entity = (CEntity*)entity->GetNext();
	}

	wxTreeItemId meshManagerID = AppendItem( GetRootItem(), _T("Mesh manager") );
	CMeshManager *meshManager = scene->GetMeshManager();
	CRessource* meshR = (CRessource*)meshManager->GetFirstChild();
	while( meshR )
	{
		CMesh *mesh = (CMesh*)meshR->_ressource;
		if( mesh )
		{
			wxTreeItemId meshID = AppendItem(
				meshManagerID, mesh->GetName(),
				-1, -1, new CTreeItemData( mesh ) );

			wxString label;

			label.Printf( _T("triangles: %d"), mesh->GetTriangleCount() );
			AppendItem( meshID, label );

			label.Printf( _T("vertices: %d"), mesh->GetVertexCount() );
			AppendItem( meshID, label );
		}

		meshR = (CRessource*)meshR->GetNext();
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

void CTreeScene::OnTreeKeyDown( wxTreeEvent &event )
{
	wxTreeItemId item = GetSelection();
	switch( event.GetKeyEvent().GetKeyCode() )
	{
	case WXK_NUMPAD_DELETE:
	case WXK_DELETE:
		{
			CTreeItemData *data = item.IsOk() ? (CTreeItemData*)GetItemData(item)
				:NULL;
			if( data )
			{
				CNode *node = data->GetNode();
				if( node && (
					node->GetNodeType() == ENTITY_NODE ||
					node->GetNodeType() == LIGHT_NODE ) )
				{
					node->Release();
					Delete( item );
				}
			}
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