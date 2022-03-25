#ifndef _SANGEOMETRYNODE_H_
#define _SANGEOMETRYNODE_H_

#include "SanCommonHeaders.h"

#include "SanNode.h"
#include "SanMatrix4.h"

namespace San
{
	class CGeometryNode : public CNode
	{
		public:
		CGeometryNode( const char *name ) : CNode( name )
		{
			_pos = CVector4();
			_up = CVector3(0.0,1.0,0.0);
			_dir = CVector3(0.0,0.0,1.0);
			_scale= CVector3(1.0,1.0,1.0);
			_nodeType = GEOMETRIC_NODE;

			ComputeTransform();
		}

		virtual void SetPosition( CVector4 & v ) { _pos = v; }
		virtual void SetDirection( CVector3 & v ) { _dir = v.normalize(); }
		inline virtual void SetTarget( CVector3 &v )
		{
			_dir = (v - CVector3(_pos._x,_pos._y,_pos._z)).normalize(); 
		}
		virtual void SetScale( CVector3 & v ) { _scale = v; }
		virtual void SetUp( CVector3 & v ) { _up = v.normalize(); }

		virtual CVector4 & GetPosition() { return _pos; }
		virtual CVector3 & GetDirection() { return _dir; }
		virtual CVector3 & GetScale() { return _scale; }
		virtual CVector3 & GetUp() { return _up; }
		virtual CMatrix4 * GetTransform() { return &_transform; }

		inline void MoveForward( sanFloat m )
		{
			_pos += _dir * m;
		}
		inline void MoveBackward( sanFloat m )
		{
			_pos -= _dir * m;
		}
		inline void StrafeLeft( sanFloat m )
		{
			_pos += _up.crossProduct( _dir ) * m;
		}
		inline void StrafeRight( sanFloat m )
		{
			_pos -= _up.crossProduct( _dir ) * m;
		}

		protected:
		virtual void onAnimate( const sanFloat dt )
		{
			ComputeTransform();
		}

		void ComputeTransform()
		{
			_dir.normalize();
			_up.normalize();

			if( _parent && (_parent->GetNodeType() & GEOMETRIC_NODE) )
			{
				CGeometryNode *parent = (CGeometryNode*)_parent;

				_absolutePos = (*parent->GetTransform()) * _pos;
				_absoluteDir = (*parent->GetTransform()) * _dir;
				_absoluteScale = parent->GetScale() * _scale;
				_absoluteUp = (*parent->GetTransform()) * _up;
			}
			else
			{
				_absolutePos = _pos;
				_absoluteDir = _dir;
				_absoluteScale = _scale;
				_absoluteUp = _up;
			}

			_absoluteDir.normalize();
			_absoluteUp.normalize();
			_absoluteW = _absoluteUp.crossProduct( _absoluteDir ).normalize();
	
			_transform = CMatrix4::IDENTITY;
			_transform[0][0] = _absoluteW._x * _absoluteScale._x;
			_transform[0][1] = _absoluteW._y * _absoluteScale._y;
			_transform[0][2] = _absoluteW._z * _absoluteScale._z;
			_transform[1][0] = _absoluteUp._x * _absoluteScale._x;
			_transform[1][1] = _absoluteUp._y * _absoluteScale._y;
			_transform[1][2] = _absoluteUp._z * _absoluteScale._z;
			_transform[2][0] = _absoluteDir._x * _absoluteScale._x;
			_transform[2][1] = _absoluteDir._y * _absoluteScale._y;
			_transform[2][2] = _absoluteDir._z * _absoluteScale._z;
			_transform[0][3] = _absolutePos._x;
			_transform[1][3] = _absolutePos._y;
			_transform[2][3] = _absolutePos._z;
		}

		CVector3 _up;
		CVector4 _pos;
		CVector3 _dir;
		CVector3 _scale;
		CMatrix4 _transform;

		CVector3 _absoluteUp;
		CVector4 _absolutePos;
		CVector3 _absoluteDir;
		CVector3 _absoluteW;
		CVector3 _absoluteScale;
	};
}

#endif