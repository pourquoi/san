#include "SanIndexedMesh.h"
#include "SanTriangle.h"
#include "SanVector.h"
#include "SanMaths.h"

namespace San
{
	CIndexedMesh::CIndexedMesh( const char *name ) : CMesh( name )
	{
		_vertice = NULL;
		_verticeCount = 0;
		_triangleCount = 0;
		_interval = 0;
		_triangles = NULL;
		_sharpEdgeAngle = SAN_PI / 2 + 0.01;
		_meshType = MESH_INDEXED | MESH_WITH_NORMALS;
	}
	
	void CIndexedMesh::onDelete()
	{
		SAFE_DELETE_ARRAY( _vertice );
		SAFE_DELETE_ARRAY( _triangles );
	}
	
	void CIndexedMesh::Load( const char *filename )
	{
	}
	
	void CIndexedMesh::ComputeNormals( bool got_adjacency )
	{
		// calcul des triangles adjacents pour chaque triangle
		if( !got_adjacency )
			ComputeAdjacency();
	
		// calcul de la normale en chaque face
		for( sanLong t=0; t<_triangleCount; t++ )
		{
			sanLong ia = _triangles[t].a * _interval;
			sanLong ib = _triangles[t].b * _interval;
			sanLong ic = _triangles[t].c * _interval;
	
			CVector3 ab =
			CVector3(_vertice[ib],_vertice[ib+1],_vertice[ib+2]) -
			CVector3(_vertice[ia],_vertice[ia+1],_vertice[ia+2]);
	
			CVector3 ac =
			CVector3(_vertice[ic],_vertice[ic+1],_vertice[ic+2]) -
			CVector3(_vertice[ia],_vertice[ia+1],_vertice[ia+2]);
	
			_triangles[t].n = ab.crossProduct( ac );
			_triangles[t].n.normalize();
		}
	
		// calcul de la normale aux sommets
		for( sanLong t=0; t<_triangleCount; t++ )
		{
			_triangles[t].na = _triangles[t].n;
	
			// somme les normales des triangles contenant ce point
			for( sanLong  i=0; i<_triangles[t].s_ta; i++ )
			{
				// test si l'angle entre la normale du triangle et la normale
				// du triangle adjacent est inferieur à l'angle de detection des arrêtes vives
				if( _triangles[t].n.dot( _triangles[_triangles[t].ta[i]].n ) < _sharpEdgeAngle )
				{
					_triangles[t].na += _triangles[_triangles[t].ta[i]].n;
				}
			}
			_triangles[t].na.normalize();
			

			_triangles[t].nb = _triangles[t].n;

			for( sanLong  i=0; i<_triangles[t].s_tb; i++ )
			{
				// test si l'angle entre la normale du triangle et la normale
				// du triangle adjacent est inferieur à l'angle de detection des arrêtes vives
				if( _triangles[t].n.dot( _triangles[_triangles[t].tb[i]].n) < _sharpEdgeAngle )
				{
					_triangles[t].nb += _triangles[_triangles[t].tb[i]].n;
				}				
			}
			_triangles[t].nb.normalize();
	
			_triangles[t].nc = _triangles[t].n;

			for( sanLong  i=0; i<_triangles[t].s_tc; i++ )
			{
				// test si l'angle entre la normale du triangle et la normale
				// du triangle adjacent est inferieur à l'angle de detection des arrêtes vives
				if( _triangles[t].n.dot( _triangles[_triangles[t].tc[i]].n) < _sharpEdgeAngle )
				{
					_triangles[t].nc += _triangles[_triangles[t].tc[i]].n;
				}				
			}
			_triangles[t].nc.normalize();
		}
	}
	
	void CIndexedMesh::ComputeAdjacency()
	{
		for( sanLong t1=0; t1<_triangleCount; t1++ )
		{
			std::stack<int> aa, ab, ac;
	
			for( sanLong t2=0; t2<_triangleCount; t2++ )
			{
				if( t2 == t1 ) continue;
	
				// t1 partage son sommet A avec un des sommets de t2
				if(
				_triangles[t1].a == _triangles[t2].a ||
				_triangles[t1].a == _triangles[t2].b ||
				_triangles[t1].a == _triangles[t2].c )
				{
					aa.push( t2 );
				}
	
				// t1 partage son sommet B avec un des sommets de t2
				if(
				_triangles[t1].b == _triangles[t2].a ||
				_triangles[t1].b == _triangles[t2].b ||
				_triangles[t1].b == _triangles[t2].c )
				{
					ab.push( t2 );
				}
	
				// t1 partage son sommet C avec un des sommets de t2
				if(
				_triangles[t1].c == _triangles[t2].a ||
				_triangles[t1].c == _triangles[t2].b ||
				_triangles[t1].c == _triangles[t2].c )
				{
					ac.push( t2 );
				}
			}
	
			// au cas ou on avait déjà calculer les faces adjacentes
			SAFE_DELETE_ARRAY( _triangles[t1].ta );
			SAFE_DELETE_ARRAY( _triangles[t1].tb );
			SAFE_DELETE_ARRAY( _triangles[t1].tc );
	
			/*
			** copie des piles dans les tableaux de faces adjacentes
			*/
			if( !aa.empty() )
				_triangles[t1].ta = new sanLong[ aa.size() ];
			if( !ab.empty() )
				_triangles[t1].tb = new sanLong[ ab.size() ];
			if( !ac.empty() )
				_triangles[t1].tc = new sanLong[ ac.size() ];
	
			_triangles[t1].s_ta = aa.size();
			_triangles[t1].s_tb = ab.size();
			_triangles[t1].s_tc = ac.size();
	
			while( !aa.empty() )
			{
				_triangles[t1].ta[aa.size()-1] = aa.top();
				aa.pop();
			}
	
			while( !ab.empty() )
			{
				_triangles[t1].tb[ab.size()-1] = ab.top();
				ab.pop();
			}
	
			while( !ac.empty() )
			{
				_triangles[t1].tc[ac.size()-1] = ac.top();
				ac.pop();
			}
		}
	}
};
