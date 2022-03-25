/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
/* Classe Caméra:                                                             */
/* - matrice de transformation en repère caméra                               */
/* - matrice de projection                                                    */
/* - calcul de la matrice caméra avec la position et direction.               */
/* - calcul de la matrice de projection avec les plan de coupe proche et      */
/*   lointains, l'angle d'ouverture et l'aspect                               */
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/


#ifndef _SANCAMERA_H_
#define _SANCAMERA_H_

#include "SanCommonHeaders.h"

#include "SanVector.h"
#include "SanMatrix4.h"
#include "SanEntity.h"
#include "SanNewtonNode.h"

namespace San
{
	class CCamera : public CNewtonNode
	{
	public:
		CCamera( CViewport *viewport, const char *name=NULL );

		void SetViewport( CViewport *v )						{ _viewport = v; }
		void SetAspect( sanFloat a )							{ _aspect = a; ComputeProjectionMatrix(); }
		void SetZFar( sanFloat z )								{ _zFar = z; ComputeProjectionMatrix(); }
		void SetZNear( sanFloat z )								{ _zNear = z; ComputeProjectionMatrix(); }
		void SetOuverture( sanFloat a )
		{
			_ouverture = a;
			_d = 1.0 / tanf( _ouverture / 2.0 );
			ComputeProjectionMatrix();
		}

		const CMatrix4 * GetViewTransform()						{ return (const CMatrix4*)&_viewMat; }
		const CMatrix4 * GetProjectionTransform()				{ return (const CMatrix4*)&_projectionMat; }
		CViewport * GetViewport()								{ return _viewport; }
		sanFloat GetZNear()										{ return _zNear; }
		sanFloat GetZFar()										{ return _zFar; }
		sanFloat GetOuverture()									{ return _ouverture; }
		sanFloat GetAspect()									{ return _aspect; }

	protected:
		virtual void onAnimate( const sanFloat time_elapsed );
		virtual void onDelete();

		void ComputeViewMatrix();
		void ComputeProjectionMatrix();

		sanFloat		_ouverture;
		sanFloat		_zNear, _zFar;
		sanFloat		_d;
		sanFloat 		_aspect;

		CMatrix4		_viewMat;
		CMatrix4		_projectionMat;

		CViewport		*_viewport;
	};
};

#endif
