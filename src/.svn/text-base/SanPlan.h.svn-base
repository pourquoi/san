/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
/* Classe CPlan: plan 3D                                                      */
/* - distance d'un point au plan                                              */
/* - intersection d'une droite avec le plan                                   */
/* - clipping d'un triangle par un plan( insertion/suppression dans la liste) */
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

#ifndef _SANPLAN_H_
#define _SANPLAN_H_

#include "SanCommonHeaders.h"

#include "SanVector.h"
#include "SanTriangle.h"

namespace San
{
	class CPlan
	{
		public:
		CVector3 _A; // un point du plan
		CVector3 _N; // la normale du plan

		/*
		** construction du plan de point a et normale n
		*/
		CPlan( const CVector3 &a=CVector3(), const CVector3 &n=CVector3(0.0,1.0,0.0) );

		/*
		** construction du plan à partir de 3 points.
		** normale = ab^ac
		*/
		CPlan( const CVector3 &a, const CVector3 &b, const CVector3 &c );

		/*
		** calcule la distance signée d'un point au plan
		*/
		sanFloat distanceToPoint( const CVector3 &p ) const;

		/*
		** calcule le point d'intersection entre une droite et le plan
		** droite parametrique: V(l) = a + l*(b-a)  l dans [0..1]
		** donc N.(V(l) - A) = 0  <=> N.a + N.(l*(b-a)) - N.A = 0
		** l = N.(A - a) / N.(b-a)
		** V(l) = a + (b-a) * N.(a - A)/N.(a-b)
		** V(l) = a + (b-a) * (dist_a / dist_a - dist_b) ou dist_a est la distance de a au plan
		*/
		bool intersectPlan( const CVector3 &a, const CVector3 &b, CVector3 *res ) const;

		/*
		** clipping du triangle t1 et renvoie du ou des 2 triangles
		** clippés dans t1 et t2
		** retourne le nombre de triangle intérieurs 0, 1 ou 2
		*/
		sanShort clipTriangle( CTriangle *t1 ) const;
	};
};

#endif
