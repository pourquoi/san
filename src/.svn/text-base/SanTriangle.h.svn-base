/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

#ifndef _SANTRIANGLE_H_
#define _SANTRIANGLE_H_

#include "SanCommonHeaders.h"
#include "SanVector.h"
#include "SanNode.h"

namespace San
{
	class CTriangle : public CNode
	{
		public:
		CTriangle() : CNode( "Triangle" )
		{
		}

		CVector4 	a, b, c; // sommets
		CVector3	aview, bview, cview;
		CVector3 	n, na, nb, nc; // normale moyenne + normales en chaque sommets
		CVector3 	ca, cb, cc; // couleurs
		sanFloat	aa, ab, ac; // alphas
		CVector2 	ta, tb, tc; // coordonnées de textures

		protected:
		virtual void onCreate()
		{
		}
		virtual void onDelete()
		{
		}
		virtual void onRender( CRenderer *renderer )
		{
		}
		virtual void onAnimate( const sanFloat time_elapsed )
		{
		}
	};

	class CIndexedTriangle
	{
		public:
		CIndexedTriangle()
		{
			ta = tb = tc = NULL;
			s_ta = s_tb = s_tc = 0;
		};

		~CIndexedTriangle()
		{
			SAFE_DELETE_ARRAY( ta );
			SAFE_DELETE_ARRAY( tb );
			SAFE_DELETE_ARRAY( tc );
		}

		sanLong 		a, b, c; // sommets
		CVector2		tex[3];
		CVector3	 	n, na, nb, nc; // normale moyenne + normales en chaque sommets
		sanLong 		*ta, *tb, *tc; // triangles adjacents pour le calcul des normales
		sanLong 		s_ta, s_tb, s_tc; // nb triangles adjacents pour chaque points
	};
};

#endif
