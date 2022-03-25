#ifndef _SANNEWTONNODE_H_
#define _SANNEWTONNODE_H_

#include "SanCommonHeaders.h"

#include "SanGeometryNode.h"

namespace San
{
	struct s_force_list_node
	{
		CVector3 _value;
		sanLong _id;
		s_force_list_node *_next;
	};

	typedef s_force_list_node * s_force_list;

	class CNewtonNode : public CGeometryNode
	{
		public:
		CNewtonNode( const char * name ) :
		_forces(NULL), _somme( CVector3() ), _vel( CVector3() ), CGeometryNode( name )
		{
			_nodeType = GEOMETRIC_NODE | NEWTON_NODE;
		}

		inline sanLong AddForce( CVector3 & v )
		{
			s_force_list_node *node = new s_force_list_node();
			node->_value = v;
			node->_next = _forces;
			node->_id = _forces ?  _forces->_id+1 : 0;
			_forces = node;
			_somme += v;
			return node->_id;
		}

		inline void RemoveForce( sanLong id )
		{
			s_force_list_node *node = _forces;
			s_force_list_node *parent = _forces;
			while( node && node->_id != id )
			{
				parent = node;
				node = node->_next;
			}
			if( node )
			{
				_somme -= node->_value;
				if( parent ) parent->_next = node->_next;
				delete node;
			}			
		}

		inline CVector3 & GetForce( sanLong id )
		{
			s_force_list_node *node = _forces;
			while( node && node->_id != id )
			{
				node = node->_next;
			}
			return node->_value;
		}

		inline void ResetForces()
		{
			s_force_list_node *node = _forces;
			s_force_list_node *next = _forces;
			while( node )
			{
				next = node->_next;
				delete node;
				node = next;
			}
			_somme = CVector3();
		}

		void AddImpulsion( const CVector3 & v ) { _vel += v; }

		CVector3 & GetSomme() { return _somme; }
		CVector3 & GetVelocity() { return _vel; }

		void SetVelocity( const CVector3 & v ) { _vel = v; }

		protected:
		virtual void onAnimate( sanFloat dt )
		{
			_vel += _somme * dt;
			_pos += CVector4(_vel) * dt;
			ComputeTransform();
		}

		s_force_list _forces;
		CVector3 _somme;
		CVector3 _vel;
	};
};

#endif