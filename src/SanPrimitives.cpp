#include "SanPrimitives.h"
#include "SanIndexedMesh.h"
#include "SanMaths.h"
#include "SanTriangle.h"
#include "SanVector.h"

namespace San
{
	CIndexedMesh * CreateIndexedTriangle( CVector3 a,CVector3 b, CVector3 c )
	{
		CIndexedMesh *mesh = new CIndexedMesh( "IndexedTriangle" );

		mesh->_interval = 5;
		mesh->_triangleCount = 1;
		mesh->_verticeCount = 3;
		mesh->_vertice = new sanFloat[mesh->_verticeCount * mesh->_interval];
		mesh->_triangles = new CIndexedTriangle[1];
		mesh->SetMeshType( MESH_INDEXED | MESH_WITH_NORMALS | MESH_TEXTURED );

		mesh->_vertice[0] = a._x;
		mesh->_vertice[1] = a._y;
		mesh->_vertice[2] = a._z;
		mesh->_vertice[3] = 0;
		mesh->_vertice[4] = 1;

		mesh->_vertice[5] = b._x;
		mesh->_vertice[6] = b._y;
		mesh->_vertice[7] = b._z;
		mesh->_vertice[8] = 0.5;
		mesh->_vertice[9] = 0;

		mesh->_vertice[10] = c._x;
		mesh->_vertice[11] = c._y;
		mesh->_vertice[12] = c._z;
		mesh->_vertice[13] = 1;
		mesh->_vertice[14] = 1;

		mesh->_triangles[0].a = 0;
		mesh->_triangles[0].b = 1;
		mesh->_triangles[0].c = 2;

		mesh->ComputeNormals();

		return mesh;
	}

	CIndexedMesh * CreateIndexedSphere( sanFloat R, sanLong nlat, sanLong nlong )
	{
		CIndexedMesh *mesh = new CIndexedMesh( "IndexedSphere" );

		mesh->_interval = 3;
		mesh->_triangleCount = (nlat-3) * nlong * 2 + nlong * 2;
		mesh->_verticeCount = (nlat-2) * nlong + 2;
		mesh->_vertice = new sanFloat[ mesh->_interval * mesh->_verticeCount ];
		mesh->_triangles = new CIndexedTriangle[ mesh->_triangleCount ];
		mesh->SetMeshType( MESH_INDEXED | MESH_WITH_NORMALS );

		// point du haut
		mesh->_vertice[((nlat-2)*nlong)*3 + 0] = 0.0;
		mesh->_vertice[((nlat-2)*nlong)*3 + 1] = R;
		mesh->_vertice[((nlat-2)*nlong)*3 + 2] = 0.0;
		
		// point du bas
		mesh->_vertice[((nlat-2)*nlong+1)*3 + 0] = 0.0;
		mesh->_vertice[((nlat-2)*nlong+1)*3 + 1] = -R;
		mesh->_vertice[((nlat-2)*nlong+1)*3 + 2] = 0.0;

		sanLong t=0;

		for( sanLong y=0; y<nlat-2; y++ )
		{
			sanFloat omega = (sanFloat)(y+1) * SAN_PI / (sanFloat)nlat;
			for( sanLong x=0; x<nlong; x++ )
			{
				sanFloat theta = (sanFloat)x * SAN_PI * 2.0 / (sanFloat)nlong;
				sanLong index = y*nlong + x;
				mesh->_vertice[index*3+0] = Cos(theta)*Sin(omega)*R;
				mesh->_vertice[index*3+1] = Cos(omega)*R;
				mesh->_vertice[index*3+2] = Sin(theta)*Sin(omega)*R;

				if( y != 0 )
				{
				mesh->_triangles[t].a = index;
				mesh->_triangles[t].b = y*nlong + ((x+1)%nlong);
				mesh->_triangles[t].c = (y-1)*nlong + x;

				mesh->_triangles[t].na = CVector3(
					mesh->_vertice[mesh->_triangles[t].a*3+0],
					mesh->_vertice[mesh->_triangles[t].a*3+1],
					mesh->_vertice[mesh->_triangles[t].a*3+2] ).normalize();
				mesh->_triangles[t].nb = CVector3(
					mesh->_vertice[mesh->_triangles[t].b*3+0],
					mesh->_vertice[mesh->_triangles[t].b*3+1],
					mesh->_vertice[mesh->_triangles[t].b*3+2] ).normalize();
				mesh->_triangles[t].nc = CVector3(
					mesh->_vertice[mesh->_triangles[t].c*3+0],
					mesh->_vertice[mesh->_triangles[t].c*3+1],
					mesh->_vertice[mesh->_triangles[t].c*3+2] ).normalize();

				mesh->_triangles[t].n = ((mesh->_triangles[t].na + mesh->_triangles[t].nb + mesh->_triangles[t].nc)/3).normalize();
				t++;

				mesh->_triangles[t].a = (y-1)*nlong + x;
				mesh->_triangles[t].b = y*nlong + ((x+1)%nlong);
				mesh->_triangles[t].c = (y-1)*nlong + ((x+1)%nlong);

				mesh->_triangles[t].na = CVector3(
					mesh->_vertice[mesh->_triangles[t].a*3+0],
					mesh->_vertice[mesh->_triangles[t].a*3+1],
					mesh->_vertice[mesh->_triangles[t].a*3+2] ).normalize();
				mesh->_triangles[t].nb = CVector3(
					mesh->_vertice[mesh->_triangles[t].b*3+0],
					mesh->_vertice[mesh->_triangles[t].b*3+1],
					mesh->_vertice[mesh->_triangles[t].b*3+2] ).normalize();
				mesh->_triangles[t].nc = CVector3(
					mesh->_vertice[mesh->_triangles[t].c*3+0],
					mesh->_vertice[mesh->_triangles[t].c*3+1],
					mesh->_vertice[mesh->_triangles[t].c*3+2] ).normalize();

				mesh->_triangles[t].n = ((mesh->_triangles[t].na + mesh->_triangles[t].nb + mesh->_triangles[t].nc)/3).normalize();
				t++;
				}
			}
		}

		// chapeau du haut
		for( sanLong x=0; x<nlong; x++ )
		{
			mesh->_triangles[t].a = (nlat-2)*nlong;
			mesh->_triangles[t].b = x;
			mesh->_triangles[t].c = (x+1)%nlong;
			mesh->_triangles[t].na = CVector3(
				mesh->_vertice[mesh->_triangles[t].a*3+0],
				mesh->_vertice[mesh->_triangles[t].a*3+1],
				mesh->_vertice[mesh->_triangles[t].a*3+2] ).normalize();
			mesh->_triangles[t].nb = CVector3(
				mesh->_vertice[mesh->_triangles[t].b*3+0],
				mesh->_vertice[mesh->_triangles[t].b*3+1],
				mesh->_vertice[mesh->_triangles[t].b*3+2] ).normalize();
			mesh->_triangles[t].nc = CVector3(
				mesh->_vertice[mesh->_triangles[t].c*3+0],
				mesh->_vertice[mesh->_triangles[t].c*3+1],
				mesh->_vertice[mesh->_triangles[t].c*3+2] ).normalize();

			mesh->_triangles[t].n = ((mesh->_triangles[t].na + mesh->_triangles[t].nb + mesh->_triangles[t].nc)/3).normalize();
			t++;
		}

		// chapeau du bas
		for( sanLong x=0; x<nlong; x++ )
		{
			mesh->_triangles[t].a = (nlat-2)*nlong+1;
			mesh->_triangles[t].b = (nlat-3)*nlong + ((x+1)%nlong);
			mesh->_triangles[t].c = (nlat-3)*nlong + x;
			mesh->_triangles[t].na = CVector3(
				mesh->_vertice[mesh->_triangles[t].a*3+0],
				mesh->_vertice[mesh->_triangles[t].a*3+1],
				mesh->_vertice[mesh->_triangles[t].a*3+2] ).normalize();
			mesh->_triangles[t].nb = CVector3(
				mesh->_vertice[mesh->_triangles[t].b*3+0],
				mesh->_vertice[mesh->_triangles[t].b*3+1],
				mesh->_vertice[mesh->_triangles[t].b*3+2] ).normalize();
			mesh->_triangles[t].nc = CVector3(
				mesh->_vertice[mesh->_triangles[t].c*3+0],
				mesh->_vertice[mesh->_triangles[t].c*3+1],
				mesh->_vertice[mesh->_triangles[t].c*3+2] ).normalize();

			mesh->_triangles[t].n = ((mesh->_triangles[t].na + mesh->_triangles[t].nb + mesh->_triangles[t].nc)/3).normalize();
			t++;
		}

		mesh->ComputeNormals();

		return mesh;
	}

	CIndexedMesh * CreateIndexedCube( sanFloat size )
	{
		CIndexedMesh *mesh = new CIndexedMesh( "IndexedCube" );

		mesh->_interval = 3;
		mesh->_triangleCount = 12;
		mesh->_verticeCount = 8;
		mesh->_vertice = new sanFloat[3*8];
		mesh->_triangles = new CIndexedTriangle[12];
		mesh->SetMeshType( MESH_INDEXED | MESH_WITH_NORMALS );

		mesh->_vertice[0] = 0.0;
		mesh->_vertice[1] = 0.0;
		mesh->_vertice[2] = 0.0;

		mesh->_vertice[3] = size;
		mesh->_vertice[4] = 0.0;
		mesh->_vertice[5] = 0.0;

		mesh->_vertice[6] = size;
		mesh->_vertice[7] = size;
		mesh->_vertice[8] = 0.0;

		mesh->_vertice[9] = 0.0;
		mesh->_vertice[10] = size;
		mesh->_vertice[11] = 0.0;

		mesh->_vertice[12] = 0.0;
		mesh->_vertice[13] = 0.0;
		mesh->_vertice[14] = size;

		mesh->_vertice[15] = size;
		mesh->_vertice[16] = 0.0;
		mesh->_vertice[17] = size;

		mesh->_vertice[18] = size;
		mesh->_vertice[19] = size;
		mesh->_vertice[20] = size;

		mesh->_vertice[21] = 0.0;
		mesh->_vertice[22] = size;
		mesh->_vertice[23] = size;

		mesh->_triangles[0].a = 3;
		mesh->_triangles[0].b = 0;
		mesh->_triangles[0].c = 2;
		mesh->_triangles[1].a = 0;
		mesh->_triangles[1].b = 1;
		mesh->_triangles[1].c = 2;
		mesh->_triangles[0].na = CVector3(0,0,-1);
		mesh->_triangles[0].nb = CVector3(0,0,-1);
		mesh->_triangles[0].nc = CVector3(0,0,-1);
		mesh->_triangles[0].n = CVector3(0,0,-1);
		mesh->_triangles[1].na = CVector3(0,0,-1);
		mesh->_triangles[1].nb = CVector3(0,0,-1);
		mesh->_triangles[1].nc = CVector3(0,0,-1);
		mesh->_triangles[1].n = CVector3(0,0,-1);

		mesh->_triangles[2].a = 1;
		mesh->_triangles[2].b = 6;
		mesh->_triangles[2].c = 2;
		mesh->_triangles[3].a = 1;
		mesh->_triangles[3].b = 5;
		mesh->_triangles[3].c = 6;
		mesh->_triangles[2].na = CVector3(1,0,0);
		mesh->_triangles[2].nb = CVector3(1,0,0);
		mesh->_triangles[2].nc = CVector3(1,0,0);
		mesh->_triangles[2].n = CVector3(1,0,0);
		mesh->_triangles[3].na = CVector3(1,0,0);
		mesh->_triangles[3].nb = CVector3(1,0,0);
		mesh->_triangles[3].nc = CVector3(1,0,0);
		mesh->_triangles[3].n = CVector3(1,0,0);

		mesh->_triangles[4].a = 5;
		mesh->_triangles[4].b = 4;
		mesh->_triangles[4].c = 7;
		mesh->_triangles[5].a = 5;
		mesh->_triangles[5].b = 7;
		mesh->_triangles[5].c = 6;
		mesh->_triangles[4].na = CVector3(0,0,1);
		mesh->_triangles[4].nb = CVector3(0,0,1);
		mesh->_triangles[4].nc = CVector3(0,0,1);
		mesh->_triangles[4].n = CVector3(0,0,1);
		mesh->_triangles[5].na = CVector3(0,0,1);
		mesh->_triangles[5].nb = CVector3(0,0,1);
		mesh->_triangles[5].nc = CVector3(0,0,1);
		mesh->_triangles[5].n = CVector3(0,0,1);

		mesh->_triangles[6].a = 0;
		mesh->_triangles[6].b = 3;
		mesh->_triangles[6].c = 7;
		mesh->_triangles[7].a = 0;
		mesh->_triangles[7].b = 7;
		mesh->_triangles[7].c = 4;
		mesh->_triangles[6].na = CVector3(-1,0,0);
		mesh->_triangles[6].nb = CVector3(-1,0,0);
		mesh->_triangles[6].nc = CVector3(-1,0,0);
		mesh->_triangles[6].n = CVector3(-1,0,0);
		mesh->_triangles[7].na = CVector3(-1,0,0);
		mesh->_triangles[7].nb = CVector3(-1,0,0);
		mesh->_triangles[7].nc = CVector3(-1,0,0);
		mesh->_triangles[7].n = CVector3(-1,0,0);

		mesh->_triangles[8].a = 3;
		mesh->_triangles[8].b = 2;
		mesh->_triangles[8].c = 7;
		mesh->_triangles[9].a = 2;
		mesh->_triangles[9].b = 6;
		mesh->_triangles[9].c = 7;
		mesh->_triangles[8].na = CVector3(0,1,0);
		mesh->_triangles[8].nb = CVector3(0,1,0);
		mesh->_triangles[8].nc = CVector3(0,1,0);
		mesh->_triangles[8].n = CVector3(0,1,0);
		mesh->_triangles[9].na = CVector3(0,1,0);
		mesh->_triangles[9].nb = CVector3(0,1,0);
		mesh->_triangles[9].nc = CVector3(0,1,0);
		mesh->_triangles[9].n = CVector3(0,1,0);

		mesh->_triangles[10].a = 1;
		mesh->_triangles[10].b = 4;
		mesh->_triangles[10].c = 5;
		mesh->_triangles[11].a = 1;
		mesh->_triangles[11].b = 0;
		mesh->_triangles[11].c = 4;
		mesh->_triangles[10].na = CVector3(0,-1,0);
		mesh->_triangles[10].nb = CVector3(0,-1,0);
		mesh->_triangles[10].nc = CVector3(0,-1,0);
		mesh->_triangles[10].n = CVector3(0,-1,0);
		mesh->_triangles[11].na = CVector3(0,-1,0);
		mesh->_triangles[11].nb = CVector3(0,-1,0);
		mesh->_triangles[11].nc = CVector3(0,-1,0);
		mesh->_triangles[11].n = CVector3(0,-1,0);

		//mesh->ComputeNormals();

		return mesh;
	}
}
