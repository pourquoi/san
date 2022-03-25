#include "SanRenderer.h"
#include "SanScene.h"
#include "SanPlan.h"
#include "SanVector.h"

namespace San
{
	CRenderer::CRenderer()
	{
		_scene = NULL;
		_cullMode = 1;
	
		_clipPlans[1] = CPlan( CVector3(0.0,0.0,1.0), CVector3(0.0,0.0,-1.0) );
		_clipPlans[2] = CPlan( CVector3(-1.0,0.0,0.0), CVector3(1.0,0.0,0.0) );
		_clipPlans[3] = CPlan( CVector3(1.0,0.0,0.0), CVector3(-1.0,0.0,1.0) );
		_clipPlans[4] = CPlan( CVector3(0.0,1.0,0.0), CVector3(0.0,-1.0,0.0) );
		_clipPlans[5] = CPlan( CVector3(0.0,-1.0,0.0), CVector3(0.0,1.0,0.0) );

		for( int i=0; i<3; i++ )
		{
			_texture[i] = NULL;
		}
	}

	void CRenderer::SetScene( CScene *scene )
	{
		_scene = scene;

		sanFloat zNear = scene->GetCameraList() ? scene->GetCameraList()->GetZNear()
			: 1.0;
		
		_clipPlans[0] = CPlan(
			CVector3( 0.0, 0.0, zNear ),
			CVector3( 0.0, 0.0, 1.0 ) );
	}
}
