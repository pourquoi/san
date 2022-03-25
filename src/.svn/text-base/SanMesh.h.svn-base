#ifndef _SANMESH_H_
#define _SANMESH_H_

#include "SanCommonHeaders.h"
#include "SanNode.h"

namespace San
{
	class CMesh : public CNode
	{
		public:
		CMesh( const char* name=NULL ) : CNode( name )
		{
			_nodeType = MESH_NODE;
		}
		
		virtual void Load( const char *filename ) = 0;
		virtual void ComputeNormals( bool got_adjacency=false ) = 0;

		sanLong	GetMeshType()					{ return _meshType; }
		sanLong GetTriangleCount()				{ return _triangleCount; }
		sanLong GetVertexCount()				{ return _verticeCount; }

		void SetMeshType( const sanLong t )		{ _meshType = t; }

		protected:
		virtual void ComputeAdjacency() = 0;

		public:
		sanFloat 			*_vertice;
		sanLong				_verticeCount;
		sanLong				_triangleCount;
		sanLong				_meshType;
		sanShort			_interval;
	};
};

#endif

