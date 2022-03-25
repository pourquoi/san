/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
/* Classe mesh indexé:                                                        */
/* - liste de vertice                                                         */
/* - liste de triangles indexé(voir SanTriangle.h)                            */
/* - Calcule les normales en chaque sommets et la normale de chaque triangle. */
/* - La normale d'un sommet est la moyenne des normales des triangles         */
/*   adjacents sauf si la normale du triangle adjacent fait un angle de plus  */
/*   de 90°(peut être redéfini) avec la normale du triangle. Ainsi on conserve*/
/*   un éclairage réaliste pour les arrêtes "vives"(ex du cube)               */
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

#ifndef _SANINDEXEDMESH_H_
#define _SANINDEXEDMESH_H_

#include "SanMesh.h"

namespace San
{
	class CIndexedMesh : public CMesh
	{
		public:
		CIndexedMesh( const char* name=NULL );

		virtual void Load( const char *filename );
		virtual void ComputeNormals( bool got_adjacency=false );

		protected:
		virtual void onDelete();
		virtual void ComputeAdjacency();

		public:
		CIndexedTriangle	*_triangles;
		sanFloat			_sharpEdgeAngle;
	};
};

#endif
