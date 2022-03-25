#ifndef _SANRENDERTARGET_H_
#define _SANRENDERTARGET_H_

#include "SanCommonHeaders.h"
#include "SanNode.h"

namespace San
{
	class CRenderTarget : public CNode
	{
	public:
		CRenderTarget( sanLong w, sanLong h, sanShort nc ) :
			CNode( "RenderTarget" ),
			_composantes( nc ),
			_width( w ),
			_height( h ),
			_zBufferOp( SAN_LEQUAL )
		{
			onCreate();
		};

		// <summary>Efface le Buffer de rendu avec la couleur spécifiée</summary>
		// <param name="r">composante rouge</param>
		// <param name="g">composante verte</param>
		// <param name="b">composante bleu</param>
		// <returns>rien</returns>
		virtual void Clear(
				const sanFloat &r=0.0,
				const sanFloat &g=0.0,
				const sanFloat &b=0.0,
				const sanFloat &a=1.0,
				const sanFloat &z=1.0 
		) = 0;

		virtual void PutPixel(
			sanLong x,
			sanLong y,
			const sanFloat &z,
			const sanFloat &r=0.0,
			const sanFloat &g=0.0,
			const sanFloat &b=0.0,
			const sanFloat &a=1.0 
		) = 0;

		virtual void SwapBuffers()
		{
		}

		virtual void Resize( sanLong width, sanLong height )
		{
			SAFE_DELETE_ARRAY( _zBuffer );
			_width = width;
			_height = height;
			onCreate();
		}

		inline bool ZTest( int index, sanFloat z )
		{
			if( index >= _width*_height && index < 0 ) return false;
			
			switch( _zBufferOp )
			{
			case SAN_LEQUAL:
				{
					if( z > _zBuffer[index] ) return false;
					else _zBuffer[index] = z;
					return true;
				}
			case SAN_LESS:
				{
					if( z >= _zBuffer[index] ) return false;
					else _zBuffer[index] = z;
					return true;
				}
			case SAN_EQUAL:
				{
					if( z != _zBuffer[index] ) return false;
					else _zBuffer[index] = z;
					return true;
				}
			case SAN_ALWAYS:
				{
					_zBuffer[index] = z;
					return true;					
				}
			case SAN_NEVER:
				{
					return false;
				}
			case SAN_GREATER:
				{
					if( z <= _zBuffer[index] ) return false;
					else _zBuffer[index] = z;
					return true;
				}
			case SAN_GEQUAL:
				{
					if( z < _zBuffer[index] ) return false;
					else _zBuffer[index] = z;
					return true;
				}
			}
			return false;
		}

		virtual bool OnBeginRender()
		{
			return true;
		}

		virtual void OnEndRender()
		{
		}

		sanLong GetWidth() { return _width; }
		sanLong GetHeight() { return _height; }
		sanLong GetComposantes() { return _composantes; }

		void SetZBufferOp( const sanLong op ) { _zBufferOp = op; }
		void SetComposantes( sanShort c ) { _composantes = c; }		
		void SetWidth( sanLong w ) { _width = w; Resize( _width, _height ); }
		void SetHeight( sanLong h ) { _height = h; Resize( _width, _height ); }

	protected:
		virtual void onCreate()
		{
			_zBuffer = new sanFloat[ _width * _height ];
			assert( _zBuffer );
			ClearZBuffer();
		}

		virtual void onDelete()
		{
			SAFE_DELETE_ARRAY( _zBuffer );
		}

		virtual void ClearZBuffer( const sanFloat &z=1.0 )
		{
			for( sanLong h=0; h<_height*_width; h++ )
				_zBuffer[h] = z;			
		}

		sanShort _composantes; // nombre de composantes 1, 3, 4 pour LUMINANCE, RGB, RGBA
		sanLong	_width;
		sanLong	_height;
		sanFloat *_zBuffer; // Z-buffer. La profondeur du point (x,y) correspond à _zBuffer[_width*x+y]
		sanLong _zBufferOp; // type de comparaison pour le test de profondeur
	};
};

#endif
