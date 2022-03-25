/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
/* Classes CVector2, CVector3, CVector4 pour des vecteurs de 2,3,4 dimensions.*/
/* - Surcharge des opérateurs + - * / += -= *= /= pour des opérations entre   */
/* vecteurs(V + V) ou entre vecteur et valeur réelle( V *= 2.0).              */
/* - Fonctions de produit en croix, produit vectoriel, normalisation, calcul  */
/*   de longeur et longeur au carré.                                          */
/* - Surcharge des opérateurs de comparaisons == !=                           */
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

#ifndef _SANVECTOR_H_
#define _SANVECTOR_H_

#include "SanCommonHeaders.h"
#include "SanMaths.h"

namespace San
{
	class CVector2
	{
		public:
		inline CVector2() : _x( 0.0 ), _y( 0.0 )
		{
		}

		inline CVector2( const sanFloat x, const sanFloat y ) : _x( x ), _y( y )
		{
		}

		inline CVector2( const CVector2 &V ) : _x( V._x ), _y( V._y )
		{
		}

		inline CVector2( const sanFloat *V ) : _x( V[0] ), _y( V[1] )
		{
		}

		inline CVector2( const sanFloat s ) : _x( s ), _y( s )
		{
		}

		inline sanFloat& operator[]( const sanLong i )
		{
			assert( i < 2 );
			switch( i )
			{
				case 0:
					return _x;
					break;
				case 1:
					return _y;
					break;
			}
		}

		inline CVector2& operator =( const CVector2 &V )
		{
			_x = V._x;
			_y = V._y;
			return *this;
		}

		inline CVector2& operator =( const sanFloat &s )
		{
			_x = s;
			_y = s;
			return *this;
		}

		inline bool operator ==( const CVector2 &V ) const
		{
			return (_x == V._x && _y == V._y );
		}

		inline bool operator !=( const CVector2 &V ) const
		{
			return (_x != V._x || _y != V._y );
		}

		inline CVector2 operator +( const CVector2 &V ) const
		{
			return CVector2(
			V._x + _x,
			V._y + _y );
		}

		inline CVector2 operator -( const CVector2 &V ) const
		{
			return CVector2(
			_x - V._x,
			_y - V._y );
		}

		inline CVector2 operator *( const sanFloat s ) const
		{
			return CVector2(
			_x * s,
			_y * s );
		}

		inline CVector2 operator *( const CVector2 &V ) const
		{
			return CVector2(
				_x * V._x,
				_y * V._y );
		}

		inline CVector2 operator /( const sanFloat r ) const
		{
			assert( r != (sanFloat)0 );
			return CVector2(
				_x / r,
				_y / r );
		}

		inline CVector2 operator /( const CVector2 &R ) const
		{
			assert( R._x != (sanFloat)0 && R._y != (sanFloat)0 );
			return CVector2(
				_x / R._x,
				_y / R._y );
		}

		inline CVector2 operator -() const
		{
			return CVector2( -_x, -_y );
		}

		inline CVector2& operator +=( const CVector2 &V )
		{
			_x += V._x;
			_y += V._y;
			return *this;
		}

		inline CVector2& operator -=( const CVector2 &V )
		{
			_x -= V._x;
			_y -= V._y;
			return *this;
		}

		inline CVector2& operator *=( const sanFloat s )
		{
			_x *= s;
			_y *= s;
			return *this;
		}

		inline CVector2& operator *=( const CVector2 &V )
		{
			_x *= V._x;
			_y *= V._y;
			return *this;
		}

		inline CVector2& operator /=( const sanFloat r )
		{
			assert( r != (sanFloat)0 );
			_x /= r;
			_y /= r;
			return *this;
		}

		inline CVector2& operator /=( const CVector2 &R )
		{
			assert( R._x != (sanFloat)0 && R._y != (sanFloat)0 );
			_x /= R._x;
			_y /= R._y;
			return *this;
		}

		inline sanFloat lenght() const
		{
			return San::Sqrt( _x*_x + _y*_y );
		}

		inline sanFloat squaredLenght() const
		{
			return _x*_x + _y*_y;
		}

		inline sanFloat dot( const CVector2 &V ) const
		{
			return
			_x * V._x + _y * V._y;
		}

		inline sanFloat normalize()
		{
			sanFloat lenght = this->lenght();
			if( lenght > (sanFloat)0 )
			{
				_x /= lenght;
				_y /= lenght;
			}
			return lenght;
		}

		public:
			sanFloat _x, _y;

		
	};

	class CVector3
	{
		public:
		inline CVector3() : _x( 0.0 ), _y( 0.0 ), _z( 0.0 )
		{
		}

		inline CVector3( const sanFloat x, const sanFloat y, const sanFloat z ) : _x( x ), _y( y ), _z( z )
		{
		}

		inline CVector3( const CVector3 &V ) : _x( V._x ), _y( V._y ), _z( V._z )
		{
		}

		inline CVector3( const CVector2 &V ) : _x( V._x ), _y( V._y ), _z( (sanFloat)0 )
		{
		}

		inline CVector3( const sanFloat *V ) : _x( V[0] ), _y( V[1] ), _z( V[2] )
		{
		}

		inline CVector3( const sanFloat scaler ) : _x( scaler ), _y( scaler ), _z( scaler )
		{
		}

		inline sanFloat& operator[]( const sanLong i )
		{
			assert( i < 3 );
			switch( i )
			{
				case 0:
					return _x;
					break;
				case 1:
					return _y;
					break;
				case 2:
					return _z;
					break;
			}
		}

		inline CVector3& operator =( const CVector3 &V )
		{
			_x = V._x;
			_y = V._y;
			_z = V._z;
			return *this;
		}

		inline CVector3& operator =( const sanFloat &s )
		{
			_x = s;
			_y = s;
			_z = s;
			return *this;
		}

		inline bool operator ==( const CVector3 &V ) const
		{
			return (_x == V._x && _y == V._y && _z == V._z );
		}

		inline bool operator !=( const CVector3 &V ) const
		{
			return (_x != V._x || _y != V._y || _z != V._z );
		}

		inline CVector3 operator +( const CVector3 &V ) const
		{
			return CVector3(
			V._x + _x,
			V._y + _y,
			V._z + _z );
		}

		inline CVector3 operator -( const CVector3 &V ) const
		{
			return CVector3(
			_x - V._x,
			_y - V._y,
			_z - V._z );
		}

		inline CVector3 operator *( const sanFloat s ) const
		{
			return CVector3(
			_x * s,
			_y * s,
			_z * s );
		}

		inline CVector3 operator *( const CVector3 &V ) const
		{
			return CVector3(
				_x * V._x,
				_y * V._y,
				_z * V._z );
		}

		inline CVector3 operator /( const sanFloat r ) const
		{
			assert( r != (sanFloat)0 );
			return CVector3(
				_x / r, 
				_y / r,
				_z / r );
		}

		inline CVector3 operator /( const CVector3 &R ) const
		{
			assert( R._x != (sanFloat)0 && R._y != (sanFloat)0 && R._z != (sanFloat)0 );
			return CVector3(
				_x / R._x,
				_y / R._y,
				_z / R._z );
		}

		inline CVector3 operator -() const
		{
			return CVector3( -_x, -_y, -_z );
		}

		inline CVector3& operator +=( const CVector3 &V )
		{
			_x += V._x;
			_y += V._y;
			_z += V._z;
			return *this;
		}

		inline CVector3& operator -=( const CVector3 &V )
		{
			_x -= V._x;
			_y -= V._y;
			_z -= V._z;
			return *this;
		}

		inline CVector3& operator *=( const sanFloat s )
		{
			_x *= s;
			_y *= s;
			_z *= s;
			return *this;
		}

		inline CVector3& operator *=( const CVector3 &V )
		{
			_x *= V._x;
			_y *= V._y;
			_z *= V._z;
			return *this;
		}

		inline CVector3& operator /=( const sanFloat r )
		{
			assert( r != (sanFloat)0 );
			_x /= r;
			_y /= r;
			_z /= r;
			return *this;
		}

		inline CVector3& operator /=( const CVector3 &R )
		{
			assert( R._x != (sanFloat)0 && R._y != (sanFloat)0 && R._z != (sanFloat)0 );
			_x /= R._x;
			_y /= R._y;
			_z /= R._z;
			return *this;
		}

		inline sanFloat lenght() const
		{
			return San::Sqrt( _x*_x + _y*_y + _z*_z );
		}

		inline sanFloat squaredLenght() const
		{
			return _x*_x + _y*_y + _z*_z;
		}

		inline sanFloat dot( const CVector3 &V ) const
		{
			return
			_x * V._x + _y * V._y + _z * V._z;
		}

		inline CVector3 normalize()
		{
			sanFloat lenght = this->lenght();
			if( lenght > (sanFloat)0 )
			{
				_x /= lenght;
				_y /= lenght;
				_z /= lenght;
			}
			return (*this);
		}

		/*
		** produit en croix: X^Y=Z, Y^Z=X, Z^X=Y
		** A^B = (
		** A.y*B.z - A.z*B.y,
		** A.z*B.x - A.x*B.z,
		** A.x*B.y - A.y*B.y )
		*/
		inline CVector3 crossProduct( const CVector3 &V ) const
		{
			return CVector3(
				_y * V._z - _z * V._y,
				_z * V._x - _x * V._z,
				_x * V._y - _y * V._x );
		}

		void print() const 
		{
			std::cout << "(" << _x << "," << _y << "," << _z << ")" << std::endl;
		}
	
		public:
			sanFloat _x, _y, _z;
	};

	class CVector4
	{
		public:
		inline CVector4() : _x( 0.0 ), _y( 0.0 ), _z( 0.0 ), _w( 1.0 )
		{
		}

		inline CVector4( const sanFloat x, const sanFloat y, const sanFloat z, const sanFloat w=1.0 ) : _x( x ), _y( y ), _z( z ), _w( w )
		{
		}

		inline CVector4( const CVector4 &V ) : _x( V._x ), _y( V._y ), _z( V._z ), _w( V._w )
		{
		}

		inline CVector4( const CVector3 &V, const sanFloat &w=1.0 ) : _x( V._x ), _y( V._y ), _z( V._z ), _w( w )
		{
		}

		inline CVector4( const sanFloat *V ) : _x( V[0] ), _y( V[1] ), _z( V[2] ), _w( V[3] )
		{
		}

		inline CVector4( const sanFloat scaler ) : _x( scaler ), _y( scaler ), _z( scaler ), _w( scaler )
		{
		}

		inline sanFloat& operator[]( const sanLong i )
		{
			assert( i < 4 );
			switch( i )
			{
				case 0:
					return _x;
					break;
				case 1:
					return _y;
					break;
				case 2:
					return _z;
					break;
				case 3:
					return _w;
					break;
			}
		}

		inline CVector4& operator =( const CVector4 &V )
		{
			_x = V._x;
			_y = V._y;
			_z = V._z;
			_w = V._w;
			return *this;
		}

		inline CVector4& operator =( const sanFloat &s )
		{
			_x = s;
			_y = s;
			_z = s;
			_w = s;
			return *this;
		}

		inline bool operator ==( const CVector4 &V ) const
		{
			return (_x == V._x && _y == V._y && _z == V._z && _w == V._w);
		}

		inline bool operator !=( const CVector4 &V ) const
		{
			return (_x != V._x || _y != V._y || _z != V._z || _w != V._w);
		}

		inline CVector4 operator +( const CVector4 &V ) const
		{
			return CVector4(
			V._x + _x,
			V._y + _y,
			V._z + _z,
			V._w + _w );
		}

		inline CVector4 operator -( const CVector4 &V ) const
		{
			return CVector4(
			_x - V._x,
			_y - V._y,
			_z - V._z,
			_w - V._w );
		}

		inline CVector4 operator *( const sanFloat s ) const
		{
			return CVector4(
			_x * s,
			_y * s,
			_z * s,
			_w * s );
		}

		inline CVector4 operator *( const CVector4 &V ) const
		{
			return CVector4(
				_x * V._x,
				_y * V._y,
				_z * V._z,
				_w * V._w );
		}

		inline CVector4 operator /( const sanFloat r ) const
		{
			assert( r != (sanFloat)0 );
			return CVector4(
				_x / r,
				_y / r,
				_z / r,
				_w / r );
		}

		inline CVector4 operator /( const CVector4 &R ) const
		{
			assert( R._x != (sanFloat)0 && R._y != (sanFloat)0 && R._z != (sanFloat)0 && R._w != (sanFloat)0 );
			return CVector4(
				_x / R._x,
				_y / R._y,
				_z / R._z,
				_w / R._w );
		}

		inline CVector4 operator -() const
		{
			return CVector4( -_x, -_y, -_z, -_w );
		}

		inline CVector4& operator +=( const CVector4 &V )
		{
			_x += V._x;
			_y += V._y;
			_z += V._z;
			_w += V._w;
			return *this;
		}

		inline CVector4& operator -=( const CVector4 &V )
		{
			_x -= V._x;
			_y -= V._y;
			_z -= V._z;
			_w -= V._w;
			return *this;
		}

		inline CVector4& operator *=( const sanFloat s )
		{
			_x *= s;
			_y *= s;
			_z *= s;
			_w *= s;
			return *this;
		}

		inline CVector4& operator *=( const CVector4 &V )
		{
			_x *= V._x;
			_y *= V._y;
			_z *= V._z;
			_w *= V._w;
			return *this;
		}

		inline CVector4& operator /=( const sanFloat r )
		{
			assert( r != (sanFloat)0 );
			_x /= r;
			_y /= r;
			_z /= r;
			_w /= r;
			return *this;
		}

		inline CVector4& operator /=( const CVector4 &R )
		{
			assert( R._x != (sanFloat)0 && R._y != (sanFloat)0 && R._z != (sanFloat)0 && R._w != (sanFloat)0 );
			_x /= R._x;
			_y /= R._y;
			_z /= R._z;
			_w /= R._w;
			return *this;
		}

		inline sanFloat dot( const CVector4 &V ) const
		{
			return
			_x * V._x + _y * V._y + _z * V._z + _w * V._w;
		}

		void print()
		{
			std::cout << "(" << _x << "," << _y << "," << _z << "," << _w << ")\n";
		}

		public:
			sanFloat _x, _y, _z, _w;
	};
}

#endif
