#include "SanNode.h"
#include "SanRenderer.h"

using namespace San;

namespace San
{

sanLong CNode::_count = 0;

CNode::CNode( const char *name )
{
	_ref = 1;
	_next = _previous = _firstChild = _parent = NULL;
	if( name ) sprintf( _name, "%s", name );
	else sprintf( _name, "%s", "Unknown" );
	++_count;
	_nodeType = GENERIC_NODE;
}

CNode::~CNode()
{
	if( _previous ) _previous->SetNext( _next );
	if( _next ) _next->SetPrevious( _previous );
	if( !_previous && _parent ) _parent->SetFirstChild( _next );
	--_count;
}

void CNode::Release()
{
	--_ref;
	if( _ref == 0 )
	{
		CNode *temp = _firstChild;
		while( temp )
		{
			CNode *next = temp->GetNext();
			temp->Release();
			temp = next;
		}
		onDelete();
		delete this;
	}
}

void CNode::AddChild( CNode *node )
{
	node->SetNext( _firstChild );
	node->SetPrevious( NULL );
	node->SetParent( this );
	if( _firstChild ) _firstChild->SetPrevious( node );
	_firstChild = node;

	onAddChild();
}

void CNode::AddBrother( CNode * node )
{
	CNode *temp = this;
	while( temp->GetNext() )
	{
		temp = temp->GetNext();
	}
	temp->SetNext( node );
	node->SetPrevious( temp );
	node->SetParent( _parent );
}

void CNode::AddBrotherBefore( CNode * node )
{
	if( _previous ) _previous->SetNext( node );
	else if( _parent ) _parent->SetFirstChild( node );
	node->SetPrevious( _previous );
	node->SetNext( this );
	_previous = node;
}

CNode * CNode::GetFirstBrother()
{
	CNode *temp = this;
	while( temp->GetPrevious() )
	{
		temp = temp->GetPrevious();
	}
	return temp;
}

void CNode::RemoveChild( const char *name )
{
	CNode * temp = GetChildByName( name );
	if( temp )
	{
		temp->Release();
	}
}

sanLong CNode::GetChildCount()
{
	sanLong res = 0;
	CNode *temp = _firstChild;
	while( temp )
	{
		temp = temp->GetNext();
		++res;
	}
	return res;
}

CNode * CNode::GetBrotherByName( const char *name )
{
	if( _parent ) return _parent->GetChildByName( name );
	CNode * temp = GetFirstBrother();
	while( temp )
	{
		if( strcmp( name, temp->GetName() ) == 0 )
		{
			return temp;
		}
		temp = temp->GetNext();
	}
	return NULL;
}

CNode * CNode::GetChildByName( const char *name, bool rec )
{
	CNode *temp = _firstChild;
	while( temp )
	{
		if( strcmp( name, temp->GetName() ) == 0 )
		{
			return temp;
		}
		if( rec )
		{
			CNode *grandchild = temp->GetChildByName( name );
			if( grandchild ) return grandchild;
		}

		temp = temp->GetNext();
	}
	return NULL;
}

void CNode::Animate( const sanFloat time_elapsed )
{
	onAnimate( time_elapsed );
	CNode *temp = _firstChild;
	while( temp )
	{
		temp->Animate( time_elapsed );
		temp = temp->GetNext();
	}
}

void CNode::Render( CRenderer *renderer )
{
	CNode *temp = _firstChild;
	while( temp )
	{
		temp->Render( renderer );
		temp = temp->GetNext();
	}
	onRender( renderer );
}

}
