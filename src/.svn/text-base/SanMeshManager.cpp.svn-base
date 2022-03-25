#include "SanMeshManager.h"
#include "SanVector.h"
#include "SanTriangle.h"
#include "SanIndexedMesh.h"

using namespace San;

sanLong CMeshManager::_meshCount = 0;

CMeshManager::CMeshManager( const char *name)
			: CRessourceManager( name )
{
}

CNode * CMeshManager::Load( const char *filename )
{
	CNode * temp = GetChildByName( filename, true );
	if( temp ) return temp;

	if( filename == NULL )
	{
		std::cerr << "[CMeshManager] Load error: no filename\n";
		return NULL;
	}

	std::cout << "[CMeshManager] loading " << filename << "file...\n";

	std::string filestr( filename );
	std::string::size_type loc = filestr.find(std::string("."), 0);
	if( loc == std::string::npos ) return NULL;

	std::string ext = filestr.substr( loc, filestr.length() - 1 );

	std::vector< CVector3 > vertice;
	std::vector< CVector3 > normals;
	std::vector< CVector2 > texcoords;
	std::vector< CIndexedTriangle > triangles;

	CVector3 v;
	CIndexedTriangle t;

	bool got_normals = false;
	bool got_texcoords = false;

	if( ext == std::string( ".obj" ) )
	{
		std::ifstream reader;
		reader.open( filename, std::ios_base::in );
		if( !reader )
		{
			std::cerr << "[CMeshManager] ifstream::open " << filename << " failed.\n";
			return NULL;
		}

		std::string id;
		
		while( !reader.eof() )
		{
			reader >> id;
			if( id == std::string("v") )
			{
				reader >> v._x >> v._y >> v._z;
				vertice.push_back( v );
			}
			else if( id == std::string("vn") )
			{
				reader >> v._x >> v._y >> v._z;
				normals.push_back( v );
				got_normals = true;
			}
			else if( id == std::string("vt") )
			{
				reader >> v._x >> v._y;
				texcoords.push_back( CVector2( v._x, v._y ) );
				got_texcoords = true;
			}
			else if( id == std::string("f") )
			{
				for( int i=0; i<3; i++ )
				{
					int pos;
					reader >> pos;

					if( i==0 ) t.a = pos-1;
					else if( i==1 ) t.b = pos-1;
					else t.c = pos-1;

					if( reader.peek() == '/' )
					{
						reader.ignore();
						if( '/' != reader.peek() )
						{
							int tex;
							reader >> tex;
						}

						if( reader.peek() == '/' )
						{
							reader.ignore();
							int ni;
							reader >> ni;
							if(i==0) t.na = normals[ni-1];
							else if(i==1) t.nb = normals[ni-1];
							else t.nc = normals[ni-1];
						}
					}
				}

				triangles.push_back( t );
			}

			reader.ignore( 1000, '\n' );
		}

		reader.close();
	}
	else
	{
		return NULL;
	}

	CIndexedMesh *mesh = new CIndexedMesh(filename);
	mesh->_verticeCount = vertice.size();
	mesh->_interval = 3;
	mesh->_meshType = MESH_INDEXED;
	if( got_normals ) mesh->_meshType |= MESH_WITH_NORMALS;
	if( got_texcoords ) mesh->_meshType |= MESH_TEXTURED;
	mesh->_triangleCount = triangles.size();

	mesh->_vertice = new sanFloat[ vertice.size() * 3 ];
	mesh->_triangles = new CIndexedTriangle[ triangles.size() ];

	for( int i=0; i<vertice.size(); i++ )
	{
		mesh->_vertice[i*3+0] = vertice[i]._x;
		mesh->_vertice[i*3+1] = vertice[i]._y;
		mesh->_vertice[i*3+2] = vertice[i]._z;
	}

	for( int i=0; i<triangles.size(); i++ )
	{
		mesh->_triangles[i] = triangles[i];
	}

	vertice.clear();
	normals.clear();
	triangles.clear();

	if( !got_normals ) mesh->ComputeNormals();

	AddChild( mesh );

	return mesh;
}


