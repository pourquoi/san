#include "SanMatrix3.h"

using namespace San;

namespace San
{

const CMatrix3 CMatrix3::IDENTITY(
	1,0,0,
	0,1,0,
	0,0,1 );

const CMatrix3 CMatrix3::ZERO(
	0,0,0,
	0,0,0,
	0,0,0 );

/*
** matrice de rotation autour d'un vecteur quelconque
** V(x, y, z)
** R = I + sin(a)*P + (1-cos(a))*P^2
**    +-       -+
**    | 0 -z +y |
** P= |+z  0 -x |
**    |-y +x  0 |
**    +-       -+
** P = [ 0,-z,y ; z,0,-x ; -y,x,0 ]
** (pour les rotations usuelles utiliser les fonctions inline)
*/
CMatrix3 & CMatrix3::fromAxisAngle( const CVector3 &V, const sanRadians a )
{
	sanFloat fcos = Cos( a );
	sanFloat fsin = Sin( a );
	sanFloat fOneMinusCos = 1.0 - fcos;

	sanFloat fX2 = V._x * V._x;
	sanFloat fY2 = V._y * V._y;
	sanFloat fZ2 = V._z * V._z;

	sanFloat fXY = V._x * V._y;
	sanFloat fXZ = V._x * V._z;
	sanFloat fYZ = V._y * V._z;

	sanFloat fXsin = V._x * fsin;
	sanFloat fYsin = V._y * fsin;
	sanFloat fZsin = V._z * fsin;

	_m[0][0] = 1.0 - fOneMinusCos * ( fZ2 + fY2 );
	_m[0][1] = fZsin + fOneMinusCos * fXY;
	_m[0][2] = fYsin - fOneMinusCos * fXZ;
	_m[1][0] = -fZsin + fOneMinusCos * fXY;
	_m[1][1] = 1.0 - fOneMinusCos * ( fZ2 + fX2 );
	_m[1][2] = -fXsin - fOneMinusCos * fYZ;
	_m[2][0] = -fYsin - fOneMinusCos * fXZ;
	_m[2][1] = fXsin - fOneMinusCos * fYZ;
	_m[2][2] = 1.0 - fOneMinusCos * ( fX2 + fY2 );
		
	return *this;
}

}
