/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
/* Gestionnaire de ressources                                                 */
/* classe abstraite à dériver en redéfinissant la méthode Load                */
/* Charge ou renvoie une ressource si elle est déjà en mémoire                */
/* Libère les ressources les moins utilisés si manque de mémoire              */
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

#ifndef _SANRESSOURCEMANAGER_H_
#define _SANRESSOURCEMANAGER_H_

#include "SanCommonHeaders.h"
#include "SanNode.h"

namespace San
{
	class CRessource : public CNode
	{
	public:
		CRessource( const char *name, CNode *ressource = NULL ) 
		: CNode( name ), _lastUse( ++_lastRessourceUse )
		{
			_nodeType = RESSOURCE_NODE;
			if( ressource ) AddChild( ressource );
		};

		sanLong				_lastUse;
		static sanLong		_lastRessourceUse;
	};

	class CRessourceManager : public CNode
	{
	public:
		CRessourceManager( const char *name );

		virtual const sanLong GetCount()				= 0;
		virtual CNode * Load( const char *filename )	= 0;

		void AddChild( CNode *node );
	};
};

#endif
