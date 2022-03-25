/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
/* Classes de lumières ambiantes, directionnelles, ponctuelles avec:          */
/* - couleur ambiante pour tout les types                                     */
/* - couleur diffuses, spéculaires et puissance spéculaire pour les lumières  */
/*   ponctuelles et directionnelles                                           */
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

#ifndef _SANLIGHT_H_
#define _SANLIGHT_H_

#include "SanCommonHeaders.h"
#include "SanVector.h"
#include "SanNode.h"

namespace San
{
	class CMaterial
	{
		public:
		CMaterial()
		{
			_specularPower = 2;
		}
		CMaterial( CMaterial & mat )
		{
			_ambiant = mat._ambiant;
			_diffuse = mat._diffuse;
			_specular = mat._specular;
			_specularPower = mat._specularPower;
		}

		CVector3 	_ambiant;
		CVector3 	_diffuse;
		CVector3 	_specular;
		sanShort	_specularPower;
	};

	class CAmbiantLight : public CNode
	{
		public:
		CAmbiantLight() : CNode( "Light" )
		{
			onCreate();
		}

		CVector3 		_ambiant;
		sanLightType 	_type;

		protected:
		virtual void onCreate()
		{
			_ambiant = CVector3(1.0,1.0,1.0);
			_type = AMBIANT_LIGHT;
			_nodeType = LIGHT_NODE;
		}
		virtual void onDelete()
		{
		}
	};

	class CPointLight : public CAmbiantLight
	{
		public:
		CPointLight()
		{
			onCreate();
		}

		CVector3	 	_pos;
		CVector3 		_diffuse;
		CVector3 		_specular;
		sanFloat		_range;

		protected:
		virtual void onCreate()
		{
			_ambiant = CVector3(1.0,1.0,1.0);
			_type = POINT_LIGHT;
			_diffuse = CVector3(1.0,1.0,1.0);
			_specular = CVector3(1.0,1.0,1.0);
			_range = 1000.0;
			_nodeType = LIGHT_NODE;
		}
		virtual void onDelete()
		{
		}
	};

	class CDirectionnalLight : public CAmbiantLight
	{
		public:
		CDirectionnalLight()
		{
			onCreate();
		}

		CVector3 		_dir;
		CVector3 		_diffuse;
		CVector3 		_specular;

		protected:
		virtual void onCreate()
		{
			_ambiant = CVector3(1.0,1.0,1.0);
			_type = DIRECTIONNAL_LIGHT;
			_dir = CVector3(0.0,0.0,1.0);
			_diffuse = CVector3(1.0,1.0,1.0);
			_specular = CVector3(1.0,1.0,1.0);
			_nodeType = LIGHT_NODE;
		}
		virtual void onDelete()
		{
		}
	};

};

#endif
