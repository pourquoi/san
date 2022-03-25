#ifndef _SANSOFTWARERENDERER_H_
#define _SANSOFTWARERENDERER_H_

#include "SanRenderer.h"
#include "SanCommonHeaders.h"

#include "SanLight.h"

namespace San
{
	class CSoftwareRenderer : public CRenderer
	{
	public:
		CSoftwareRenderer();

		virtual ~CSoftwareRenderer() {}

		virtual void onStartRender();

		virtual void RenderTriangle(
			CTriangle *tri,
			sanLightningModel lT,
			sanLong triMode,
			CMaterial *material
		);

	protected:
		void Rasterize(
			CTriangle *tri,
			sanLightningModel lT,
			sanLong triMode,
			CMaterial *material
		);

		void OrderTriangle( CTriangle *t );

		virtual void ComputeDiffuseComp(
			CVector3 *n,
			CMaterial *material,
			CVector3 *res
		);
		virtual void ComputeSpecularComp(
			CVector3 *v,
			CVector3 *n,
			CMaterial *material,
			CVector3 *res
		);
	};
};

#endif
