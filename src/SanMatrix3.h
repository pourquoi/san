/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
/* Classe de matrice 3 dimension avec surcharge des opérateurs:               */
/* + -: addition/soustraction de matrices                                     */
/* * M  : multiplication de matrices                                          */
/* * V  : multiplication par un vecteur                                       */
/* aussi transposé, création d'une matrice de rotation à partir d'un angle et */
/* du vecteur autour duquel on souhaite effectuer la rotation                 */
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

#ifndef _SANMATRIX3_H_
#define _SANMATRIX3_H_

#include "SanCommonHeaders.h"
#include "SanVector.h"

namespace San
{
	class CMatrix3
	{
		public:
		inline CMatrix3()
		{
		}

		inline CMatrix3( const sanFloat tab[3][3] )
		{
			memcpy( _m, tab, sizeof(sanFloat)*9 );
		}

		inline CMatrix3(
			sanFloat a00, sanFloat a01, sanFloat a02,
			sanFloat a10, sanFloat a11, sanFloat a12,
			sanFloat a20, sanFloat a21, sanFloat a22 )
		{
			_m[0][0] = a00;
			_m[0][1] = a01;
			_m[0][2] = a02;
			_m[1][0] = a10;
			_m[1][1] = a11;
			_m[1][2] = a12;
			_m[2][0] = a20;
			_m[2][1] = a21;
			_m[2][2] = a22;
		}

		/*
		** accesseur de la rangé i
		*/
		inline sanFloat* operator []( const sanLong i )
		{
			assert( i < 3 );
			return _m[i];
		}

		inline void SetColumn( const sanLong i, const CVector3 &V )
		{
			assert( i < 3 );
			_m[0][i] = V._x;
			_m[1][i] = V._y;
			_m[2][i] = V._z;
		}

		inline void fromAxes( const CVector3 &X, const CVector3 &Y, const CVector3 &Z )
		{
			SetColumn( 0, X );
			SetColumn( 1, Y );
			SetColumn( 2, Z );
		}

		inline CMatrix3 operator *( const CMatrix3 &M ) const
		{
			CMatrix3 r;
			r._m[0][0] = _m[0][0] * M._m[0][0] + _m[0][1] * M._m[1][0] + _m[0][2] * M._m[2][0];
			r._m[0][1] = _m[0][0] * M._m[0][1] + _m[0][1] * M._m[1][1] + _m[0][2] * M._m[2][1];
			r._m[0][2] = _m[0][0] * M._m[0][2] + _m[0][1] * M._m[1][2] + _m[0][2] * M._m[2][2];
			r._m[1][0] = _m[1][0] * M._m[0][0] + _m[1][1] * M._m[1][0] + _m[1][2] * M._m[2][0];
			r._m[1][1] = _m[1][0] * M._m[0][1] + _m[1][1] * M._m[1][1] + _m[1][2] * M._m[2][1];
			r._m[1][2] = _m[1][0] * M._m[0][2] + _m[1][1] * M._m[1][2] + _m[1][2] * M._m[2][2];
			r._m[2][0] = _m[2][0] * M._m[0][0] + _m[2][1] * M._m[1][0] + _m[2][2] * M._m[2][0];
			r._m[2][1] = _m[2][0] * M._m[0][1] + _m[2][1] * M._m[1][1] + _m[2][2] * M._m[2][1];
			r._m[2][2] = _m[2][0] * M._m[0][2] + _m[2][1] * M._m[1][2] + _m[2][2] * M._m[2][2];
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

		CMatrix3 operator *( const sanFloat s ) const
		{
			CMatrix3 M;
			for( sanLong i=0; i<3; i++ )
				for( sanLong j=0; j<3; j++ )
					M[i][j] = _m[i][j] * s;
			return M;
		}

		CMatrix3 operator +( const CMatrix3 &M ) const
		{
			CMatrix3 r;
			for( sanLong i=0; i<3; i++ )
				for( sanLong j=0; j<3; j++ )
					r._m[i][j] = _m[i][j] + M._m[i][j];
			return r;
		}

		CMatrix3 operator -( const CMatrix3 &M ) const
		{
			CMatrix3 r;
			for( sanLong i=0; i<3; i++ )
				for( sanLong j=0; j<3; j++ )
					r._m[i][j] = _m[i][j] - M._m[i][j];
			return r;
		}

		inline CMatrix3& transpose()
		{
			Swap( &_m[1][0], &_m[0][1] );
			Swap( &_m[2][0], &_m[0][2] );
			Swap( &_m[2][1], &_m[1][2] );
			return *this;
		}

		CMatrix3& fromAxisAngle( const CVector3 &V, const sanRadians a );

		public:
		sanFloat _m[3][3];

		static const CMatrix3 IDENTITY;
		static const CMatrix3 ZERO;
	};
}
#endif
