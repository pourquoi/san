#include "SanPlan.h"

using namespace San;

CPlan::CPlan( const CVector3 &a, const CVector3 &n )
{
	_A = a;
	_N = n;
	_N.normalize();
}

CPlan::CPlan( const CVector3 &a, const CVector3 &b, const CVector3 &c )
{
	CVector3 u = b - a;
	CVector3 v = c - a;
	_N = u.crossProduct( v ).normalize();
	_A = a;
}

sanFloat CPlan::distanceToPoint( const CVector3 &p ) const
{
	return _N.dot( p - _A );
}

bool CPlan::intersectPlan( const CVector3 &a, const CVector3 &b, CVector3 *res ) const
{
	sanFloat dist_a = distanceToPoint( a );
	sanFloat dist_b = distanceToPoint( b );

	sanFloat diff = dist_a - dist_b;
	if( diff == 0.0 ) return false;

	(*res) = a + ((b-a) * (dist_a / diff ));
	return true;
}

sanShort CPlan::clipTriangle( CTriangle *t1 ) const
{
	CVector3 a3 = CVector3( t1->a._x, t1->a._y, t1->a._z );
	CVector3 b3 = CVector3( t1->b._x, t1->b._y, t1->b._z );
	CVector3 c3 = CVector3( t1->c._x, t1->c._y, t1->c._z );

	sanFloat d1 = distanceToPoint( a3 );
	sanFloat d2 = distanceToPoint( b3 );
	sanFloat d3 = distanceToPoint( c3 );

	/*
	** 3 points ayant 2 possibilités: intérieur/extérieur
	** donc 2^3=8 possibilités. 0=>signe(d) négatif, 1=>signe(d) positif
	** d1 d2 d3  d1*d2 d1*d3
	** 0  0  0     1     1        1)
	** 0  0  1     1     0        4)
	** 0  1  0     0     1        2)
	** 0  1  1     0     0        3)
	** 1  0  0     0     0        3)
	** 1  0  1     0     1        2)
	** 1  1  0     1     0        4)
	** 1  1  1     1     1        1)
	** on peut regrouper en 4 cas similaires
	**   1)     |        2)    |  B
	**      C   |              |/ /
	**     / \  |             A| /
	**    A--B  |             C|
	**
	**   3)     |        4)    |  C
	**          | C            |/ /
	**          |/ \          A| /
	**         A|--B           |/
	**          |             B|
	*/

	sanFloat d1xd3 = d1*d3;
	bool d1_0 = ( d1 < 0.0 );
	if( d1*d2 >= 0.0 )
	{
		// cas 1
		if( d1xd3 >= 0.0 )
		{
			// tout les sommets sont externes
			if( d1 < 0.0 )
			{
				//std::cout << "cas tous externes\n";
				return 0;
			}
			// tout les sommets sont internes
			else
			{
				//std::cout << "cas tous internes\n";
				return 1;
			}
		}
		// cas 4
		else
		{
			// seul C est interne
			if( d1_0 )
			{
				// calcule les intersection A'=AC/Plan et B'=BC/Plan
				// et renvoie le triangle A'B'C
				CVector3 Ap;
				if( intersectPlan( a3, c3, &Ap ) )
					t1->a = CVector4( Ap, t1->a._w );
				CVector3 Bp;
				if( intersectPlan( b3, c3, &Bp ) )
					t1->b = CVector4( Bp, t1->b._w );

				//std::cout << "cas C interne\n";
				return 1;
			}
			// seul C est externe
			else
			{
				// calcule les intersections C1=AC/Plan et C2=BC/Plan
				// renvoie les triangles A B C2 et A C2 C1
				CVector3 C2;
				intersectPlan( b3, c3, &C2 );
				CVector3 C1;
				intersectPlan( a3, c3, &C1 );

				CTriangle *t2 = new CTriangle( *t1 );
				t1->AddBrotherBefore( t2 );

				t2->c = CVector4( C1, t2->c._w );
				t2->b = CVector4( C2, t2->b._w );
				t1->c = CVector4( C2, t1->c._x );
				return 2;
			}
		}
	}
	else
	{
		// cas 2
		if( d1xd3 >= 0.0 )
		{
			// seul B est interne
			if( d1_0 )
			{
				// calcule les intersections A'=BA/Plan et C'=BC/Plan
				// renvoie le triangle A' B C'
				CVector3 Ap;
				if( intersectPlan( a3, b3, &Ap ) )
					t1->a = CVector4( Ap, t1->a._w );
				CVector3 Cp;
				if( intersectPlan( b3, c3, &Cp ) )
					t1->c = CVector4( Cp, t1->c._w );
				//std::cout << "cas B interne\n";
				return 1;
			}
			// seul B est externe
			else
			{
				// calcule les intersections B1=AB/Plan et B2=CB/Plan
				// renvoie les triangles A B1 C et B1 B2 C
				CVector3 B1;
				CVector3 B2;

				CTriangle *t2 = new CTriangle( *t1 );
				t1->AddBrotherBefore( t2 );

				intersectPlan( a3, b3, &B1 );
				intersectPlan( b3, c3, &B2 );

				t2->b = CVector4( B2, t2->b._w );
				t1->b = CVector4( B1, t1->b._w );
				t2->a = CVector4( B1, t2->a._w );
				//std::cout << "cas B externe\n";
				return 2;
			}
		}
		// cas 3
		else
		{
			// seul A est externe
			if( d1_0 )
			{
				// calcule les intersections A1=CA/Plan et A2=BA/Plan
				// renvoie les triangles A2 B A1 et A1 B C
				CVector3 A1;
				CVector3 A2;

				CTriangle *t2 = new CTriangle( *t1 );
				t1->AddBrotherBefore( t2 );

				intersectPlan( a3, c3, &A1 );
				intersectPlan( b3, a3, &A2 );

				t2->a = CVector4( A2, t2->a._w );
				t1->a = CVector4( A1, t1->a._w );
				t2->c = CVector4( A1, t2->c._w );

				return 2;
			}
			// seul A est interne
			else
			{
				// calcule les intersection B'=AB/Plan et C'=AC/Plan
				// renvoie le triangle A B' C'
				CVector3 B, C;

				intersectPlan( a3, c3, &C );
				intersectPlan( a3, b3, &B );

				t1->b = CVector4( B, t1->b._w );
				t1->c = CVector4( C, t1->c._w );

				//std::cout << "cas A interne\n";
				return 1;
			}
		}
	}
	return 0;
}

