#include "SanCamera.h"
#include "SanViewport.h"
#include "SanRenderer.h"

namespace San
{
	CCamera::CCamera( CViewport *viewport, const char *name ) : CNewtonNode( name )
	{
		_viewport = viewport;
		_nodeType =	CAMERA_NODE | GEOMETRIC_NODE | NEWTON_NODE;
		_ouverture = SAN_PI_4;
		_d = 1.0 / tanf( _ouverture / 2.0 );
		_zNear = 1.0;
		_zFar = 1000.0;
		_aspect = 4.0/3.0;
		ComputeProjectionMatrix();
		ComputeViewMatrix();
	}

	void CCamera::ComputeProjectionMatrix()
	{
		_projectionMat = CMatrix4::IDENTITY;
		_projectionMat._m[0][0] = 2.0 * _zNear / _d;
		_projectionMat._m[1][1] = 2.0 * _zNear / (_d*_aspect);
		_projectionMat._m[2][2] = _zFar / (_zFar - _zNear);
		_projectionMat._m[2][3] = _zNear * _zFar / (_zNear - _zFar);
		_projectionMat._m[3][2] = 1.0;
		_projectionMat._m[3][3] = 0.0;
	}

	void CCamera::ComputeViewMatrix()
	{
		_viewMat = _transform;
		CVector3 abspos( _absolutePos._x, _absolutePos._y, _absolutePos._z );
		_viewMat[0][3] = _absoluteW.dot( abspos ) * -1;
		_viewMat[1][3] = _absoluteUp.dot( abspos ) * -1;
		_viewMat[2][3] = _absoluteDir.dot( abspos ) * -1;
	}

	void CCamera::onAnimate( const sanFloat dt )
	{
		_vel += _somme * dt;
		_pos += CVector4(_vel) * dt;
		ComputeTransform();
		ComputeViewMatrix();
	}

	void CCamera::onDelete()
	{
		if( _viewport )
			((CNode*)_viewport)->Release();
	}
};
