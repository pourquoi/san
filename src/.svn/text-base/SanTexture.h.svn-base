#ifndef _SANTEXTURE_H_
#define _SANTEXTURE_H_

#include "SanCommonHeaders.h"
#include "SanRessourceManager.h"
#include "SanNode.h"

#include <png.h>

namespace San
{
	class CTexture : public CNode
	{
	public:
		CTexture( const char *name ) : CNode( name )
		{
		}
		~CTexture()
		{
			SAFE_DELETE_ARRAY( _texels );
		}
		sanUChar *_texels;
		sanLong _width;
		sanLong _height;
		sanShort _format;
	};

	CTexture * LoadTextureFromPNG( const char *filename );

	class CTextureManager : public CRessourceManager
	{
	public:
		CTextureManager( const char *name="Texture Manager" ) : CRessourceManager( name )
		{
		}

		virtual const sanLong GetCount() { return _texCount; }

		virtual CNode * Load( const char *filename )
		{
			CNode * temp = GetChildByName( filename, true );
			if( temp ) return temp;

			if( filename == NULL )
			{
				std::cerr << "[CTextureManager] Load error: no filename\n";
				return NULL;
			}

			std::string filestr( filename );
			std::string::size_type loc = filestr.find(std::string("."), 0);
			if( loc == std::string::npos ) return NULL;

			std::string ext = filestr.substr( loc, filestr.length() - 1 );

			if( (ext == ".png") || (ext == ".PNG") )
			{
				temp = LoadTextureFromPNG( filename );
			}

			if( temp ) AddChild( temp );

			return temp;
		}

		virtual void OnAddChild() { _texCount++; }

	protected:
		static sanLong _texCount;
	};

}

#endif
