#include "WXSceneTree.h"
#include "SanScene.h"
#include "SanNode.h"
#include "SanLight.h"
#include "SanEntity.h"
#include "SanMeshManager.h"
#include "SanMesh.h"

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
