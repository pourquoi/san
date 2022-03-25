/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
/* Gestionnaire de meshes. Voir SanRessourceManager.h                         */
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

#ifndef _SANMESHMANAGER_H_
#define _SANMESHMANAGER_H_

#include "SanRessourceManager.h"
#include "SanMesh.h"

namespace San
{
	class CMeshManager : public CRessourceManager
	{
	public:
		CMeshManager( const char *name="Mesh manager" );

		virtual CNode * Load( const char *filename );

		virtual const sanLong GetCount()		{ return _meshCount; }

	protected:
		virtual void onAddChild() { _meshCount++; }

		static sanLong _meshCount;
	};
};

#endif
