#include "SanSoftwareRenderer.h"
#include "SanBresenham.h"
#include "SanViewport.h"
#include "SanMesh.h"
#include "SanScene.h"
#include "SanMatrix3.h"
#include "SanMatrix4.h"
#include "SanVector.h"
#include "SanLight.h"

namespace San
{
	CSoftwareRenderer::CSoftwareRenderer()
	{
	}

	/*
	** Arrange les sommets du triangle de tel sorte que 
	** a.x <= b.x <= c.x pour le remplissage
	** nombre de cas à gérer: 3*2*1=6
	*/
	void CSoftwareRenderer::OrderTriangle( CTriangle *t )
	{
		if( t->a._x < t->b._x )
		{
			// a, b, c
			if( t->b._x < t->c._x )
			{
			}
			// a, c, b
			else if( t->a._x < t->c._x )
			{
				Swap<CVector4>( &t->b, &t->c );
				Swap<CVector3>( &t->nb, &t->nc );
				Swap<CVector3>( &t->bview, &t->cview );
				Swap<CVector2>( &t->tb, &t->tc );
			}
			// c, a, b
			else
			{
				Swap<CVector4>( &t->a, &t->b );
				Swap<CVector3>( &t->na, &t->nb );
				Swap<CVector3>( &t->aview, &t->bview );
				Swap<CVector2>( &t->ta, &t->tb );
	
				Swap<CVector4>( &t->a, &t->c );
				Swap<CVector3>( &t->na, &t->nc );
				Swap<CVector3>( &t->aview, &t->cview );
				Swap<CVector2>( &t->ta, &t->tc );
			}
		}
		else // b.x <= a.x
		{
			// b, a, c
			if( t->a._x < t->c._x )
			{
				Swap<CVector4>( &t->a, &t->b );
				Swap<CVector3>( &t->na, &t->nb );
				Swap<CVector3>( &t->aview, &t->bview );
				Swap<CVector2>( &t->ta, &t->tb );
			}
			// b, c, a
			else if( t->b._x < t->c._x )
			{
				Swap<CVector4>( &t->a, &t->c );
				Swap<CVector3>( &t->na, &t->nc );
				Swap<CVector3>( &t->aview, &t->cview );
				Swap<CVector2>( &t->ta, &t->tc );
	
				Swap<CVector4>( &t->b, &t->a );
				Swap<CVector3>( &t->nb, &t->na );
				Swap<CVector3>( &t->bview, &t->aview );
				Swap<CVector2>( &t->tb, &t->ta );
			}
			// c, b, a
			else
			{
				Swap<CVector4>( &t->a, &t->c );
				Swap<CVector3>( &t->na, &t->nc );
				Swap<CVector3>( &t->aview, &t->cview );
				Swap<CVector2>( &t->ta, &t->tc );
			}
		}
	}


	
	
	void CSoftwareRenderer::RenderTriangle(
		CTriangle *tri,
		sanLightningModel lT,
		sanLong triMode,
		CMaterial *material
	)
	{
		CTriangle *t = new CTriangle();
		t = new CTriangle( *tri );

		CCamera *camera = _scene->GetCameraList();

		const CMatrix4 *world = _scene->GetWorldTransform();
		const CMatrix4 *view = camera->GetViewTransform();
		const CMatrix4 *proj = camera->GetProjectionTransform();
	
		// passage en repère caméra
		t->a = (*view) * ( (*world) * t->a );
		t->b = (*view) * ( (*world) * t->b );
		t->c = (*view) * ( (*world) * t->c );
	
		// transformation des normales en repère caméra
		if( triMode & MESH_WITH_NORMALS )
		{
			t->n = (*view) * ( (*world) * t->n );
			t->na = (*view) * ( (*world) * t->na );
			t->nb = (*view) * ( (*world) * t->nb );
			t->nc = (*view) * ( (*world) * t->nc );
		}
	
		// clipping avec le plan proche z=zNear pour empecher la division par
		// 0 lors de la projection
		if( _clipPlans[0].clipTriangle( t ) == 0 )
		{
			delete t;
			return;
		}
	
		CTriangle *temp = t;
		
		// sauvegarde des coordonnées en repère caméra
		while( temp )
		{
			temp->aview = CVector3(temp->a._x, temp->a._y, temp->a._z);
			temp->bview = CVector3(temp->b._x, temp->b._y, temp->b._z);
			temp->cview = CVector3(temp->c._x, temp->c._y, temp->c._z);

			temp = (CTriangle*)(temp->GetNext());
		}
	
		temp = t;

		// projection puis homogénéisation des coordonnées
		while( temp )
		{
			temp->a = (*proj) * temp->a;
			temp->b = (*proj) * temp->b;
			temp->c = (*proj) * temp->c;

			temp->a /= temp->a._w;
			temp->b /= temp->b._w;
			temp->c /= temp->c._w;

			temp = (CTriangle*)(temp->GetNext());
		}

		temp = t;
/*
		// clipping avec les plans restants
		for( sanShort cp=1; cp<6; cp++ )
		{
			// on récupère le premier triangle de la liste
			temp = t;

			while( temp )
			{
				CTriangle *next = (CTriangle*)(temp->GetNext());

				// suppression des triangles hors champ
				if( _clipPlans[cp].clipTriangle( temp ) == 0 )
				{
					// on avance la liste si le premier élément est supprimé
					if( temp == t ) t = next;
					SAFE_DELETE( temp );
				}

				temp = next;
			}
		}
		*/
		while( temp )
			{
				CTriangle *next = (CTriangle*)(temp->GetNext());

				// suppression des triangles hors champ
				if( _clipPlans[1].clipTriangle( temp ) == 0 )
				{
					// on avance la liste si le premier élément est supprimé
					if( temp == t ) t = next;
					SAFE_DELETE( temp );
				}

				temp = next;
			}

		if( t ) temp = t;
		else return; // on retourne si tout les triangles sont hors champ

		// affichage des triangles
		sanFloat NdotP;
		CVector3 middle;
		while( temp )
		{
			/*
			** test trivial de l'appartenance du triangle au champ de vision
			*/
			middle = (temp->aview + temp->bview + temp->cview) / 3.0;

			NdotP = temp->n.dot( middle );

			if( 
				(_cullMode == 1 && NdotP <= 0.0) || 
				(_cullMode == -1 && NdotP >= 0.0) || _cullMode == 0)
			{
				Rasterize( temp, lT, triMode, material );
			}

			temp = (CTriangle*)(temp->GetNext());
		}

		temp = t;

		// on libère tout les triangles créés
		// note: les triangles ne sont pas censés avoir de fils ni d'autre références
		// donc on peut utiliser delete au lieu de Release
		while( temp )
		{
			CTriangle *next = (CTriangle*)(temp->GetNext());
			delete( temp );
			temp = next;
		}
	}


	void CSoftwareRenderer::Rasterize(
		CTriangle *tri,
		sanLightningModel lT,
		sanLong triMode,
		CMaterial *material
	)
	{
		// on veut A.x <= B.x <= C.x
		OrderTriangle( tri );

		CCamera *camera = _scene->GetCameraList();

		const CMatrix4 *viewportTransform = camera->GetViewport()->GetTransform();
	
		sanFloat zCorrected; // z obtenu par interpolation avec correction de perspective
	
		// passage en repère viewport
		tri->a = (*viewportTransform) * tri->a;
		tri->b = (*viewportTransform) * tri->b;
		tri->c = (*viewportTransform) * tri->c;

		// initialisation des 3 métodes Bresenham nécessaires pour obtenir yR et yS
		CBresenham bresenhamAB( (sanLong)tri->a._x, (sanLong)tri->a._y, (sanLong)tri->b._x, (sanLong)tri->b._y );
		CBresenham bresenhamAC( (sanLong)tri->a._x, (sanLong)tri->a._y, (sanLong)tri->c._x, (sanLong)tri->c._y );
		CBresenham bresenhamBC( (sanLong)tri->b._x, (sanLong)tri->b._y, (sanLong)tri->c._x, (sanLong)tri->c._y );
	
		sanLong yR; // coordonnée y du point R interpolé entre AB ou BC
		sanLong yS; // y du point S interpolé entre AC

		sanLong incY; // 1 ou -1 pour incrémenter y de yS à yR
	
		// si modèle de GOURAUD ce sont les intensités de A, B et C
		CVector3 IA, IB, IC;
		if( (lT & LIGHT_GOURAUD) && (triMode & MESH_WITH_NORMALS) )
		{
			ComputeDiffuseComp( &tri->na, material, &IA );
			ComputeDiffuseComp( &tri->nb, material, &IB );
			ComputeDiffuseComp( &tri->nc, material, &IC );
			ComputeSpecularComp( &tri->aview, &tri->na, material, &IA );
			ComputeSpecularComp( &tri->bview, &tri->nb, material, &IB );
			ComputeSpecularComp( &tri->cview, &tri->nc, material, &IC );
		}

		// si modèle de GOURAUD ce sont les intensités interpolés
		CVector3 IQ;

		// coordonnées barycentriques projetées
		sanFloat s, r;

		// coordonnées barycentriques dans le repère caméra
		sanFloat sView, rView;

		// perpendiculaires à AB et AC nécessaires pour le calcul des coordonnées barycentriques
		CVector2 AB( tri->b._x - tri->a._x, tri->b._y - tri->a._y );
		CVector2 AC( tri->c._x - tri->a._x, tri->c._y - tri->a._y );
		CVector2 perpAB( AB._y, -AB._x );
		CVector2 perpAC( AC._y, -AC._x );

		// on stocke AB.perpAC
		sanFloat ABdotperpAC = AB.dot( perpAC );
		if( ABdotperpAC == 0 ) return; // A, B et C sont alignés

		CVector2 AP;

		bool RinAB = true; // drapeau qui indique si R est sur Ab ou BC
	
		for( sanLong x=(sanLong)tri->a._x; x< (sanLong)tri->c._x; x++ )
		{
			if( RinAB && x >= (sanLong)tri->b._x ) RinAB = false;

			// R est sur le segment BC
			if( !RinAB )
			{
				// calcul de l'ordonnée de R
				while( bresenhamBC._xRes < x ) bresenhamBC.Increment();
				yR = bresenhamBC._yRes;
			}
			// R est sur le segment AB
			else
			{
				// calcul de l'ordonnée de R
				while( bresenhamAB._xRes < x ) bresenhamAB.Increment();
				yR = bresenhamAB._yRes;
			}

			// calcul de l'ordonnée de S
			while( bresenhamAC._xRes < x ) bresenhamAC.Increment();
			yS = bresenhamAC._yRes;

			if( yR > yS ) incY = 1;
			else incY = -1;

			for( sanLong y=yS; y!=yR+incY; y+=incY )
			{
				// calcul de AP
				AP._x = (sanFloat)x - tri->a._x;
				AP._y = (sanFloat)y - tri->a._y;

				// calcul des coordonnées barycentriques projetées
				// r = V.perp(AC)/AB.perp(AC)
				r = (AP.dot( perpAC )) / ABdotperpAC;
				s = (AP.dot( perpAB )) / ABdotperpAC;

				s = Abs( s );
				r = Abs( r );

				// calcul des coordonnées barycentriques en repère caméra
				// rView = wa.wb.s / (wb.wc + wc.(wa-wb).s + wb.(wa-wc).r)
				// sView = wa.wc.s / (wb.wc + wc.(wa-wb).s + wb.(wa-wc).r)
				// et w = zView
				sanFloat wa = tri->aview._z;
				sanFloat wb = tri->bview._z;
				sanFloat wc = tri->cview._z;
				sanFloat denominateur = wb*wc + wc*(wa-wb)*s + wb*(wa-wc)*r;

				rView = wa * wb * r / denominateur;
				sView = wa * wc * s / denominateur;

				rView = Abs( rView );
				sView = Abs( sView );

				zCorrected = (1.0 - rView - sView) * tri->a._z + rView * tri->b._z + sView * tri->c._z;

				CVector3 color(1.0,1.0,1.0);
				
				if( triMode & MESH_WITH_NORMALS )
				{
					if( lT & LIGHT_GOURAUD )
					{
						// calcul de l'interpolation de l'intensité
						IQ = IA * (1.0 - r - s) + IC * s + IB * r;
						color *= IQ;
					}
					else if( lT & LIGHT_PHONG )
					{
						// calcul de la position interpolée
						IQ = tri->aview * (1.0 - rView - sView) + tri->bview * rView + tri->cview * sView;
						// calcul de la normale interpolée
						IA = tri->na * (1.0 - rView - sView) + tri->nb * rView + tri->nc * sView;
						ComputeDiffuseComp( &IA, material, &IB );
						ComputeSpecularComp( &IQ, &IA, material, &IB );
						color *= IB;
					}
					if( triMode & MESH_TEXTURED )
					{
						sanFloat u = tri->ta._x * (1.0 - rView - sView) + tri->tb._x * rView + tri->tc._x * sView;
						sanFloat v = tri->ta._y * (1.0 - rView - sView) + tri->tb._y * rView + tri->tc._y * sView;
						if( _texture[0] )
						{
							sanLong width = _texture[0]->_width;
							sanShort format = _texture[0]->_format;
							int ui = (int)(u*width) % (width-1);
							int vi = (int)(v*_texture[0]->_height) % (_texture[0]->_height-1);
							switch( format )
							{
							case 3:
							case 4:
								color *= CVector3(
									_texture[0]->_texels[(ui*width+vi)*format+0] / 255.0,
									_texture[0]->_texels[(ui*width+vi)*format+1] / 255.0,
									_texture[0]->_texels[(ui*width+vi)*format+2] / 255.0 );
								break;
							}
						}
					}
				}
				else if( triMode & MESH_COLORED )
				{
					IQ = tri->ca * (1.0 - r - s) + tri->cc * s + tri->cb * r;
					color *= IQ;
				}

				// seuil de la couleur finale à (1,1,1)
				if( color._x > 1.0 ) color._x = 1.0;
				if( color._y > 1.0 ) color._y = 1.0;
				if( color._z > 1.0 ) color._z = 1.0;

				camera->GetViewport()->GetRenderTarget()->PutPixel( x, y, zCorrected, color._x, color._y, color._z );
			}
		}
	}


	void CSoftwareRenderer::onStartRender()
	{
	}


	/*
	**                              L      N
	**                                o   |   o  R
	**                                 \  |  /
	**                                  \ | /
	**                                   \|/
	**                                    o-------------------> Caméra C
	**                                      P
	** en repère caméra CP = P
	** R = N*(N.dot(L)*2) - L
	** diffuse = max( N.dot(L), 0 )
	** specular = 0 si diffuse == 0
	**          = max( (-P).dot(R), 0 )
	*/

	void CSoftwareRenderer::ComputeDiffuseComp(
		CVector3 *n,
		CMaterial *material,
		CVector3 *res
	)
	{
		CAmbiantLight *lights = _scene->GetLightList();
		const CMatrix4 *view = _scene->GetCameraList()->GetViewTransform();
		(*res) = CVector3();

		// parcours de toutes les lumières et ajout de leurs contribution à l'illumination finale
		while( lights )
		{
			// lumière ambiante
			if( lights->_type == AMBIANT_LIGHT )
			{
				(*res) += lights->_ambiant * material->_ambiant;
			}
			// lumière directionnelle
			else if( lights->_type == DIRECTIONNAL_LIGHT )
			{
				CVector3 ambiant;
				CVector3 diffuse;

				CDirectionnalLight *light = (CDirectionnalLight*)lights;

				ambiant = light->_ambiant * material->_ambiant;

				// transforme la direction de la lumière en repère caméra
				CVector3 L = (*view) * light->_dir;
				L.normalize();
				L *= -1.0;

				CVector3 N( *n );
				N.normalize();

				// N.L
				sanFloat NdotL = N.dot( L );

				diffuse = light->_diffuse * material->_diffuse * Max( NdotL, 0.0 );

				(*res) += ambiant + diffuse;
			}
			else if( lights->_type == POINT_LIGHT )
			{
			}

			lights = (CAmbiantLight*)(lights->GetNext());
		}
	}

	void CSoftwareRenderer::ComputeSpecularComp(
		CVector3 *v,
		CVector3 *n,
		CMaterial *material,
		CVector3 *res
	)
	{
		CAmbiantLight *lights = _scene->GetLightList();

		const CMatrix4 *view = _scene->GetCameraList()->GetViewTransform();
	
		// parcours de toutes les lumières et ajout de leurs contribution à l'illumination finale
		while( lights )
		{
			// lumière directionnelle
			if( lights->_type == DIRECTIONNAL_LIGHT )
			{
				CVector3 specular;

				CDirectionnalLight *light = (CDirectionnalLight*)lights;

				// transforme la direction de la lumière en repère caméra
				CVector3 L = (*view) * light->_dir;
				L.normalize();
				L *= -1.0;

				CVector3 N( *n );
				N.normalize();

				// N.L
				sanFloat NdotL = N.dot( L );

				CVector3 P( *v );
				P.normalize();
				P *= -1.0;

				// composante spéculaire
				if( NdotL > 0.0 )
				{
					CVector3 R = N * ( NdotL * 2 ) - L;

					sanFloat s = Max( R.dot( P ), 0.0 );

					specular = material->_specular * light->_specular * s;

					if( s != 0.0 )
					for( sanLong i=1; i<material->_specularPower; i++ )
						specular *= s;
				}

				(*res) += specular;
			}
			else if( lights->_type == POINT_LIGHT )
			{
			}

			lights = (CAmbiantLight*)(lights->GetNext());
		}
	}
};

