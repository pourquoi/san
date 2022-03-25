/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
/* Rectangle de clipping défini par ses coordonnées et ses dimensions 2D dans */
/* l'espace caméra projeté. On lui associe une cible de rendu.                */
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

#ifndef _SANVIEWPORT_H_
#define _SANVIEWPORT_H_

#include "SanCommonHeaders.h"
#include "SanRenderTarget.h"
#include "SanNode.h"
#include "SanMatrix4.h"

namespace San
{
	class CViewport : CNode
	{
		public:
		CViewport( sanLong x, sanLong y, sanLong w, sanLong h, CRenderTarget *rt ) :
		CNode( "Viewport" ), _x(x), _y(y), _width(w), _height(h), _renderTarget(rt)
		{
			_maxZ = 1.0;
			_minZ = 0.0;
			ComputeMatrix();
		};

		sanLong GetX() 						{ return _x; }
		void SetX( sanLong x ) 				{ _x = x; ComputeMatrix(); }

		sanLong GetY() 						{ return _y; }
		void SetY( sanLong y ) 				{ _y = y; ComputeMatrix(); }

		sanLong GetWidth() 					{ return _width; }
		void SetWidth( sanLong w ) 			{ _width = w; ComputeMatrix(); }

		sanLong GetHeight() 				{ return _height; }
		void SetHeight( sanLong h ) 		{ _height = h; ComputeMatrix(); }

		CMatrix4 * GetTransform() 			{ return &_transform; }

		CRenderTarget * GetRenderTarget()	{ return _renderTarget; }

		protected:

		virtual void onDelete()
		{
			if( _renderTarget )
				_renderTarget->Release();
		}

		void ComputeMatrix()
		{
			_transform = CMatrix4::IDENTITY;
			_transform._m[0][0] = _width / 2.0;
			_transform._m[0][3] = _x + _width / 2.0;
			_transform._m[1][1] = _height / 2.0;
			_transform._m[1][3] = _y + _height / 2.0;
			_transform._m[2][2] = _maxZ - _minZ;
			_transform._m[2][3] = _minZ;
		}
	
		sanLong				_x;
		sanLong 			_y;
		sanLong 			_width;
		sanLong 			_height;
		sanFloat			_minZ, _maxZ;

		CMatrix4			_transform;

		CRenderTarget		*_renderTarget;
	};
};

#endif
