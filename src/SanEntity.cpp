#include "SanEntity.h"
#include "SanTriangle.h"
#include "SanRenderer.h"
#include "SanIndexedMesh.h"

namespace San
{
	CEntity::CEntity( const char *name ) : CNewtonNode( name )
	{
		_mesh = NULL;
		_nodeType = ENTITY_NODE | NEWTON_NODE | GEOMETRIC_NODE;
		_material._ambiant = CVector3(0.1,0.1,0.1);
		_material._diffuse = CVector3(1.0,1.0,1.0);
		_material._specular = CVector3(1.0,1.0,1.0);
		_material._specularPower = 2;
		_lightningModel = LIGHT_GOURAUD;
		_texture = NULL;
	}

	void CEntity::onDelete()
	{
	}

	void CEntity::onRender( CRenderer *renderer )
	{
		for( sanLong i=0; i<_mesh->GetTriangleCount(); i++ )
		{
			CTriangle tri;

			if( _mesh->GetMeshType() & MESH_INDEXED )
			{
				CIndexedMesh *mesh = (CIndexedMesh*)_mesh;

				tri.a = CVector4(
					mesh->_vertice[ mesh->_triangles[i].a * mesh->_interval + 0 ],
					mesh->_vertice[ mesh->_triangles[i].a * mesh->_interval + 1 ],
					mesh->_vertice[ mesh->_triangles[i].a * mesh->_interval + 2 ] );

				tri.b = CVector4(
					mesh->_vertice[ mesh->_triangles[i].b * mesh->_interval + 0 ],
					mesh->_vertice[ mesh->_triangles[i].b * mesh->_interval + 1 ],
					mesh->_vertice[ mesh->_triangles[i].b * mesh->_interval + 2 ] );

				tri.c = CVector4(
					mesh->_vertice[ mesh->_triangles[i].c * mesh->_interval + 0 ],
					mesh->_vertice[ mesh->_triangles[i].c * mesh->_interval + 1 ],
					mesh->_vertice[ mesh->_triangles[i].c * mesh->_interval + 2 ] );

				if( mesh->GetMeshType() & MESH_WITH_NORMALS )
				{
					tri.n = mesh->_triangles[i].n;
					tri.na = mesh->_triangles[i].na;
					tri.nb = mesh->_triangles[i].nb;
					tri.nc = mesh->_triangles[i].nc;
				}
				if( mesh->GetMeshType() & MESH_TEXTURED )
				{
					tri.ta = CVector2(
						mesh->_vertice[mesh->_triangles[i].a * mesh->_interval + 3],
						mesh->_vertice[mesh->_triangles[i].a * mesh->_interval + 4]);
					tri.tb = CVector2(
						mesh->_vertice[mesh->_triangles[i].b * mesh->_interval + 3],
						mesh->_vertice[mesh->_triangles[i].b * mesh->_interval + 4]);
					tri.tc = CVector2(
						mesh->_vertice[mesh->_triangles[i].c * mesh->_interval + 3],
						mesh->_vertice[mesh->_triangles[i].c * mesh->_interval + 4]);
				}
			}
			else if( _mesh->GetMeshType() & MESH_NON_INDEXED )
			{
			}

			tri.a = _transform * tri.a;
			tri.b = _transform * tri.b;
			tri.c = _transform * tri.c;

			if( _mesh->GetMeshType() & MESH_WITH_NORMALS )
			{
				tri.n = _transform * tri.n;
				tri.na = _transform * tri.na;
				tri.nb = _transform * tri.nb;
				tri.nc = _transform * tri.nc;
			}

			if( _mesh->GetMeshType() & MESH_TEXTURED && _texture )
			{
				renderer->SetTexture( _texture, 0 );
			}

			renderer->RenderTriangle(
				&tri,
				_lightningModel,
				_mesh->GetMeshType(),
				&_material );
		}
	}
};
