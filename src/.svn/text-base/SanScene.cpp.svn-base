#include "SanScene.h"

using namespace San;

CScene::CScene() : CNode( "Scene" )
{
	onCreate();
}

void CScene::onRender( CRenderer *renderer )
{
}

void CScene::onAnimate( const sanFloat time_elapsed )
{
}

void CScene::AddChild( CNode *node )
{
	if( node->GetNodeType() & CAMERA_NODE )
	{
		_cameraList->AddChild( node );
		if( _renderer ) _renderer->SetScene( this );
	}
	else if( node->GetNodeType() & LIGHT_NODE )
	{
		_lightList->AddChild( node );
	}
	else if( node->GetNodeType() & ENTITY_NODE )
	{
		_entityList->AddChild( node );
	}
	else
	{
		node->SetNext( _firstChild );
		node->SetPrevious( NULL );
		node->SetParent( this );
		if( _firstChild )
			_firstChild->SetPrevious( node );
		_firstChild = node;
	}
}

void CScene::SetActiveCamera( sanLong i )
{
}

void CScene::SetRenderer( CRenderer *renderer )
{
	_renderer = renderer;
	_renderer->SetScene( this );
}

void CScene::onDelete()
{
	SAFE_DELETE( _renderer );
}

void CScene::onCreate()
{
	CNode *node = new CNode( "LightList" );
	AddChild( node );
	_lightList = node;
	CAmbiantLight *light = new CAmbiantLight();
	light->_ambiant = CVector3(0.1,0.1,0.1);
	_lightList->AddChild( (CNode*)light );

	node = new CNode( "EntityList" );
	AddChild( node );
	_entityList = node;

	node = new CNode( "CameraList" );
	AddChild( node );
	_cameraList = node;

	_meshManager = new CMeshManager();
	AddChild( _meshManager );

	_texManager = new CTextureManager();
	AddChild( _texManager );

	_worldTransform = CMatrix4::IDENTITY;
}

void CScene::RenderScene()
{
	Render( _renderer );
}

void CScene::AnimateScene( const sanFloat timeElapsed )
{
	Animate( timeElapsed );
}
