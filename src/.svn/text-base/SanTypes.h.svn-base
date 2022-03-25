#ifndef _SANTYPES_H_
#define _SANTYPES_H_

#define SAN_STRING_LENGHT 255

namespace San
{
	typedef unsigned char 			sanUChar;
	typedef char					sanChar;
	typedef short					sanShort;
	typedef long					sanLong;
	typedef float					sanFloat;
	typedef double					sanDouble;
	typedef char					*sanString;
	typedef float					sanRadians;

	class CNode;
	class CAmbiantLight;
	class CCamera;
	class CDirectionnalLight;
	class CEntity;
	class CIndexedMesh;
	class CInedxedTriangle;
	class CMaterial;
	class CMatrix3;
	class CMatrix4;
	class CMesh;
	class CMeshManager;
	class CNode;
	class CPointLight;
	class CRenderTarget;
	class CRenderer;
	class CRessourceManager;
	class CScene;
	class CSoftwareRenderer;
	class CTriangle;
	class CVector2;
	class CVector3;
	class CVector4;
	class CViewport;
	class CWorld;
	class CPlan;
	class CIndexedTriangle;

	// modèle d'eclairage
	enum sanLightningModel
	{
		LIGHT_FLAT,
		LIGHT_GOURAUD,
		LIGHT_PHONG
	};

	// type de test de profondeur
	#define SAN_LESS 0
	#define SAN_LEQUAL 1
	#define SAN_GREATER 2
	#define SAN_GEQUAL 3
	#define SAN_EQUAL 4
	#define SAN_NOT_EQUAL 5
	#define SAN_ALWAYS 6
	#define SAN_NEVER 7

	enum sanMixOp
	{
		MODULATE,
		ADD,
		SUBSTRACT,
		ONE_MINUS_COLOR,
		ONE_MINUS_ALPHA
	};

	enum sanRendererType
	{
		SOFTWARE_RENDERER
	};

	#define	GENERIC_NODE			0<<0
	#define	GEOMETRIC_NODE			1<<0
	#define NEWTON_NODE				1<<1
	#define	ENTITY_NODE				1<<2
	#define	RESSOURCE_NODE			1<<3
	#define	MESH_NODE				1<<4
	#define	LIGHT_NODE				1<<5
	#define	CAMERA_NODE				1<<6

	#define MESH_INDEXED			1<<0
	#define MESH_NON_INDEXED		1<<1
	#define MESH_WITH_NORMALS		1<<2
	#define MESH_COLORED			1<<3
	#define MESH_TEXTURED			1<<4
	#define MESH_USE_ALPHA			1<<5

	enum sanLightType
	{
		AMBIANT_LIGHT,
		POINT_LIGHT,
		DIRECTIONNAL_LIGHT,
		SPOT_LIGHT
	};

};

#endif
