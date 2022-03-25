#include "SanRessourceManager.h"

using namespace San;

namespace San
{
	sanLong CRessource::_lastRessourceUse = 0;

	CRessourceManager::CRessourceManager( const char *name ) : CNode( name )
	{
	}

	void CRessourceManager::AddChild( CNode *node )
	{
		CRessource *child = new CRessource( "Ressource" );
		child->AddChild( node );
		child->SetNext( _firstChild );
		child->SetPrevious( NULL );
		child->SetParent( this );
		if( _firstChild ) _firstChild->SetPrevious( child );
		_firstChild = child;

		onAddChild();
	}
}
