#include "SanTexture.h"

namespace San
{
	sanLong CTextureManager::_texCount = 0;

	struct file_buffer_t
	{
		unsigned char *data;
		long offset;
	};

	void
	png_read_from_mem (png_structp png_ptr, png_bytep data, png_size_t length)
	{
		file_buffer_t *src = (file_buffer_t*)png_get_io_ptr( png_ptr );

		/* copy data from image buffer */
		memcpy( data, src->data + src->offset, length );

		/* advance in the file */
		src->offset += length;
	}

	CTexture * LoadTextureFromPNG( const char *filename )
	{
		if( !filename )
		{
			std::cerr << "LoadTextureFromPNG: NULL argument\n";
			return NULL;
		}
		FILE *f = fopen( filename, "rb" );
		if( !f )
		{
			std::cerr << "LoadTextureFromPNG(" << filename << ") failed\n";
			return NULL;
		}

		fseek (f, 0, SEEK_END);
		int length = ftell (f);
		fseek (f, 0, SEEK_SET);

		file_buffer_t file;
		file.offset = 0;

		file.data = (png_byte*)malloc(length* sizeof(png_byte) );
		fread( file.data, 1, length, f );

		// test de validité du format png
		if( !png_check_sig( file.data, 8 ) )
		{
			std::cerr << "LoadTextureFromPNG(" << filename << "): invalid PNG signature\n";
			return NULL;
		}

		png_structp pngstruct;
		png_infop infos;

		pngstruct = png_create_read_struct(
			PNG_LIBPNG_VER_STRING,
			(png_voidp *)NULL,
			NULL,
			NULL );

		if( !pngstruct )
		{
			std::cerr << "LoadTextureFromPNG(" << filename << ") could not create the png structure\n";
			fclose( f );
			return NULL;
		}

		infos = png_create_info_struct( pngstruct );
		if( !infos )
		{
			std::cerr << "LoadTextureFromPNG(" << filename << ") could not create the png structure\n";
			fclose( f );
			return NULL;
		}

		if( setjmp( png_jmpbuf( pngstruct ) ) )
		{
			png_destroy_read_struct(&pngstruct, &infos,	NULL);
			fclose( f );
			return NULL;
		}

		png_set_read_fn( pngstruct, (png_voidp *)&file, png_read_from_mem );

		png_read_info( pngstruct, infos );

		CTexture *tex = new CTexture( filename );

		switch( infos->color_type )
		{
		case PNG_COLOR_TYPE_GRAY:
			tex->_format = 1;
			break;
		case PNG_COLOR_TYPE_GRAY_ALPHA:
			tex->_format = 2;
			break;
		case PNG_COLOR_TYPE_RGB:
			tex->_format = 3;
			break;
		case PNG_COLOR_TYPE_RGB_ALPHA:
			tex->_format = 4;
			break;
		default:
			tex->_format = 3;
		}
		tex->_width = infos->width;
		tex->_height = infos->height;
		std::cout << "LoadTextureFromPNG: width:" << infos->width << " height:" << infos->height << "format: " << tex->_format << "\n";
		tex->_texels = new sanUChar[ tex->_width * tex->_height * tex->_format ];

		png_bytep *row_pointers = (png_bytep*)malloc( infos->height * sizeof(png_bytep) );

		for( int i=0; i<infos->height; ++i )
		{
			row_pointers[i] = (png_bytep)
				tex->_texels +
				((tex->_height - (i + 1)) * tex->_width * tex->_format);
		}

		png_read_image( pngstruct, row_pointers );

		png_read_end( pngstruct, NULL );

		png_destroy_read_struct( &pngstruct, &infos, NULL );

		fclose( f );

		free( row_pointers );

		return tex;
	}
}