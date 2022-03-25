#ifndef _SANSCENE_H_
#define _SANSCENE_H_

#include "SanCommonHeaders.h"
#include "SanNode.h"
#include "SanMeshManager.h"
#include "SanRenderer.h"
#include "SanMatrix4.h"
#include "SanCamera.h"
#include "SanEntity.h"
#include "SanLight.h"
#include "SanTexture.h"

namespace San
{
	class CScene : public CNode
	{
		public:
		CScene();

		void RenderScene();
		void AnimateScene( const sanFloat timeElapsed );

		virtual void AddChild( CNode *node );

		void SetRenderer( CRenderer *renderer );

		void SetActiveCamera( sanLong i );		

		CMeshManager * GetMeshManager()				{ return _meshManager; }
		CTextureManager * GetTextureManager()		{ return _texManager; }
		CEntity * GetEntityList()					{ return (CEntity*)_entityList->GetFirstChild(); }
		CCamera * GetCameraList()					{ return (CCamera*)_cameraList->GetFirstChild(); }
		CAmbiantLight * GetLightList()				{ return (CAmbiantLight*)(_lightList->GetFirstChild()); }
		CMatrix4 * GetWorldTransform()				{ return &_worldTransform; }

		void SetAmbiantLight( const CVector3 &v )	{ ((CAmbiantLight*)_lightList->GetFirstChild())->_ambiant = v; }

		protected:
		virtual void onRender( CRenderer *renderer );
		virtual void onAnimate( const sanFloat time_elapsed );
		virtual void onDelete();
		virtual void onCreate();

		CMeshManager	*_meshManager;
		CTextureManager *_texManager;
		CRenderer		*_renderer;
		CNode			*_lightList;
		CNode			*_entityList;
		CNode			*_cameraList;
		CMatrix4		_worldTransform;
	};
};

#endif
