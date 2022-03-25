#ifndef _SANRENDERER_H_
#define _SANRENDERER_H_

#include "SanCommonHeaders.h"

#include "SanPlan.h"
#include "SanLight.h"
#include "SanTexture.h"

namespace San
{
	class CRenderer
	{
	public:
		CRenderer();

		virtual void onStartRender() = 0;

		virtual void RenderTriangle(
			CTriangle *tri,
			sanLightningModel lT,
			sanLong triMode,
			CMaterial *material
		) = 0;

		virtual ~CRenderer() {}

		void SetCullMode( sanShort c )				{ _cullMode = c; }
		void SetScene( CScene *scene );

		sanShort GetCullMode()						{ return _cullMode; }
		CScene * GetScene()							{ return _scene; }

		void SetTexture( CTexture *texture, int stage )
		{
			_texture[stage] = texture;
		}

	protected:
		virtual void ComputeDiffuseComp(
			CVector3 *n,
			CMaterial *material,
			CVector3 *res
		) = 0;

		virtual void ComputeSpecularComp(
			CVector3 *v,
			CVector3 *n,
			CMaterial *material,
			CVector3 *res
		) = 0;

		CScene			*_scene;
		sanShort		_cullMode;
		CPlan			_clipPlans[6];
		CTexture *_texture[3];

		
	};
};

#endif

