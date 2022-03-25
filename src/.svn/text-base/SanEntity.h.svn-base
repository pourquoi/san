/******************************************************************************/
/* Class Entité:                                                              */
/* - un lien vers un mesh                                                     */
/* - position, direction, echelle, matériel, modèle d'eclairage               */
/* - lors de l'animation la matrice de transformation globale est calculé en  */
/*   fonction des paramètre de l'entité et de ses parents.                    */
/* - lors du rendu on transforme chaque triangle avec la matrice et on appelle*/
/*   la méthode de rendu d'un triangle du renderer.                           */
/******************************************************************************/

#ifndef _SANENTITY_H_
#define _SANENTITY_H_

#include "SanCommonHeaders.h"
#include "SanMatrix4.h"
#include "SanLight.h"
#include "SanNewtonNode.h"
#include "SanTexture.h"

namespace San
{
	class CEntity : public CNewtonNode
	{
	public:
		CEntity( const char *name=NULL );

		CMesh * GetMesh() { return _mesh; }
		CMaterial * GetMaterial() { return &_material; }
		sanLightningModel GetLightningModel() { return _lightningModel; }

		void SetMaterial( const CMaterial & mat ) { _material = mat; }
		void SetLightModel( const sanLightningModel & lM ) { _lightningModel = lM; }
		void SetMesh( CMesh *mesh ) { _mesh = mesh; }
		void SetTexture( CTexture *tex ) { _texture = tex; }

	protected:
		virtual void onRender( CRenderer *renderer );
		virtual void onDelete();

		CMesh *_mesh;
		CTexture *_texture;
		CMaterial _material;
		sanLightningModel _lightningModel;
	};
};

#endif
