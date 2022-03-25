#ifndef _SANMATRIX4_H_
#define _SANMATRIX4_H_

#include "SanMatrix3.h"

namespace San
{
	struct CMatrix4
	{
		CMatrix4() {};

		inline CMatrix4(
			sanFloat a00, sanFloat a01, sanFloat a02, sanFloat a03,
			sanFloat a10, sanFloat a11, sanFloat a12, sanFloat a13,
			sanFloat a20, sanFloat a21, sanFloat a22, sanFloat a23,
			sanFloat a30, sanFloat a31, sanFloat a32, sanFloat a33 )
		{
			_m[0][0] = a00;
			_m[0][1] = a01;
			_m[0][2] = a02;
			_m[0][3] = a03;
			_m[1][0] = a10;
			_m[1][1] = a11;
			_m[1][2] = a12;
			_m[1][3] = a13;
			_m[2][0] = a20;
			_m[2][1] = a21;
			_m[2][2] = a22;
			_m[2][3] = a23;
			_m[3][0] = a30;
			_m[3][1] = a31;
			_m[3][2] = a32;
			_m[3][3] = a33;
		}

		CMatrix4( const CMatrix4 &M )
		{
			for(int i=0;i<4;i++)
				for(int j=0;j<4;j++)
					_m[i][j] = M._m[i][j];
		}

		CMatrix4(
			const CMatrix3 &M,
			const CVector3 &translate=CVector3(),
			const CVector3 &proj=CVector3()
		)
		{
			for( sanLong i=0; i<3; i++ )
				for( sanLong j=0; j<3; j++ )
					_m[i][j] = M._m[i][j];

			_m[0][3] = translate._x;
			_m[1][3] = translate._y;
			_m[2][3] = translate._z;

			_m[3][3] = 1.0;

			_m[3][0] = proj._x;
			_m[3][1] = proj._y;
			_m[3][2] = proj._z;
		}

		inline sanFloat* operator []( const sanLong i )
		{
			return _m[i];
		}

		inline CVector4 operator *( const CVector4 &V ) const
		{
			CVector4 r;
			r._x = _m[0][0] * V._x + _m[0][1] * V._y + _m[0][2] * V._z + _m[0][3] * V._w;
			r._y = _m[1][0] * V._x + _m[1][1] * V._y + _m[1][2] * V._z + _m[1][3] * V._w;
			r._z = _m[2][0] * V._x + _m[2][1] * V._y + _m[2][2] * V._z + _m[2][3] * V._w;
			r._w = _m[3][0] * V._x + _m[3][1] * V._y + _m[3][2] * V._z + _m[3][3] * V._w;
			return r;
		}

		inline CVector3 operator *( const CVector3 &V ) const
		{
			CVector3 r;
			r._x = _m[0][0] * V._x + _m[0][1] * V._y + _m[0][2] * V._z;
			r._y = _m[1][0] * V._x + _m[1][1] * V._y + _m[1][2] * V._z;
			r._z = _m[2][0] * V._x + _m[2][1] * V._y + _m[2][2] * V._z;
			return r;
		}

		inline void operator *=( CMatrix3 &m )
		{
			_m[0][0] = _m[0][0]*m[0][0] + _m[0][1]*m[1][0] + _m[0][2]*m[2][0];
			_m[0][1] = _m[0][0]*m[0][1] + _m[0][1]*m[1][1] + _m[0][2]*m[2][1];
			_m[0][2] = _m[0][0]*m[0][2] + _m[0][1]*m[1][2] + _m[0][2]*m[2][2];
			_m[1][0] = _m[1][0]*m[0][0] + _m[1][1]*m[1][0] + _m[1][2]*m[2][0];
			_m[1][1] = _m[1][0]*m[0][1] + _m[1][1]*m[1][1] + _m[1][2]*m[2][1];
			_m[1][2] = _m[1][0]*m[0][2] + _m[1][1]*m[1][2] + _m[1][2]*m[2][2];
			_m[2][0] = _m[2][0]*m[0][0] + _m[2][1]*m[1][0] + _m[2][2]*m[2][0];
			_m[2][1] = _m[2][0]*m[0][1] + _m[2][1]*m[1][1] + _m[2][2]*m[2][1];
			_m[2][2] = _m[2][0]*m[0][2] + _m[2][1]*m[1][2] + _m[2][2]*m[2][2];
		}

		inline void operator =( const CMatrix4 &M )
		{
			for( int i=0; i<4; i++ )
				for( int j=0; j<4; j++ )
					_m[i][j] = M._m[i][j];
		}

		static const CMatrix4 IDENTITY;
		static const CMatrix4 ZERO;

		sanFloat _m[4][4];
	};
};

#endif
