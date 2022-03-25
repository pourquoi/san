#ifndef _SANNODE_H_
#define _SANNODE_H_

#include "SanCommonHeaders.h"


namespace San
{
	class CNode
	{
		public:
		CNode( const char *name );

		virtual ~CNode();

		virtual void Release();

		virtual void AddChild( CNode *node );
		virtual void AddBrother( CNode * node );
		virtual void AddBrotherBefore( CNode * node );
		virtual void RemoveChild( const char *name );
		virtual CNode * GetChildByName( const char *name, bool rec=false );
		virtual CNode * GetBrotherByName( const char *name );

		virtual void Animate( const sanFloat time_elapsed );
		virtual void Render( CRenderer *renderer );

		virtual sanLong GetChildCount();

		virtual void SetType( sanLong t )			{ _nodeType = t; }
		virtual void SetName( const char *name )	{ sprintf( _name, "%s", name ); }
		virtual void SetNext( CNode *node )			{ _next = node; }
		virtual void SetParent( CNode *node )		{ _parent = node; }
		virtual void SetFirstChild( CNode *node )	{ _firstChild = node; }
		virtual void SetPrevious( CNode *node )		{ _previous = node; }

		virtual CNode * GetNext()					{ return _next; }
		virtual CNode * GetPrevious()				{ return _previous; }
		virtual CNode * GetParent()					{ return _parent; }
		virtual CNode * GetFirstChild()				{ return _firstChild; }
		virtual CNode * GetFirstBrother();
		virtual const char * GetName() 				{ return _name; }
		virtual sanLong GetNodeType()	 			{ return _nodeType; }
		virtual sanLong GetReferenceCount()			{ return _ref; }
		virtual sanLong GetInstanceCount()			{ return _count; }

		virtual sanLong Reference()					{ return ++_ref; }

		protected:
		virtual void onRender( CRenderer *renderer ) {}
		virtual void onAnimate( const sanFloat time_elapsed ) {}
		virtual void onDelete() {}
		virtual void onCreate() {}
		virtual void onAddChild() {}

		sanLong				_nodeType;
		sanLong 			_ref;
		CNode				*_next;
		CNode				*_previous;
		CNode				*_firstChild;
		CNode				*_parent;
		sanChar				_name[SAN_STRING_LENGHT];
		static sanLong		_count;
	};
};

#endif
