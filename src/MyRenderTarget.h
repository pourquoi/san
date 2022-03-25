#ifndef _MYRENDERTARGET_H_
#define _MYRENDERTARGET_H_

#include "wx/wx.h"
#include "SanRenderTarget.h"

using namespace San;

class MyRenderTarget : public CRenderTarget
{
public:
	MyRenderTarget(
		sanLong w,
		sanLong h,
		sanLong nc 
	) : CRenderTarget( w, h, nc )
	{
		_backbuffer = wxBitmap( w, h, -1 );
		_dc = NULL;
	};

	~MyRenderTarget()
	{
	}

	void Clear(
		const sanFloat &r=0.0,
		const sanFloat &g=0.0,
		const sanFloat &b=0.0,
		const sanFloat &a=1.0,
		const sanFloat &z=1.0 
	)
	{
		wxBrush brush( wxColour( r*255, g*255, b*255 ) );
		_dc->SetBackground( brush );
		_dc->Clear();
		ClearZBuffer( z );
	};

	void PutPixel(
		sanLong x,
		sanLong y,
		const sanFloat &z,
		const sanFloat &r=0.0,
		const sanFloat &g=0.0,
		const sanFloat &b=0.0,
		const sanFloat &a=1.0 
	)
	{
		wxPen pen;

		/*
		** le syst�me de coordonn�es de wxWidgets est diff�rent du rep�re projet� 
		** du moteur. wxWidgets d�finit l'origine en haut � gauche de la fen�tre
		** le rep�re projet� � son origine en bas � gauche
		*/
		y = _height - y;

		// index du point dans le z-buffer
		sanLong index = y * _width + x;

		// test de profondeur en fonction de la comparaison choisie
		if( !ZTest( y *_width + x, z ) ) return;

		// mise � jour de la couleur de tra�age en fonction du nombre de 
		// composantes choisies
		switch( _composantes )
		{
		// une composante: mod�le luminance
		case 1:
			{
				pen.SetColour( r*255, r*255, r*255 );
				break;
			}
		// 3 composantes: mod�le RGB
		case 3:
			{
				pen.SetColour( r*255, g*255, b*255);
				break;
			}
		// 4 composantes: mod�le RGBA
		case 4:
			{
				pen.SetColour( r*255, g*255, b*255);
				break;
			}
		default:
			{
				pen.SetColour( r*255, g*255, b*255);
				break;
			}
		}
		_dc->SetPen( pen );

		_dc->DrawPoint( x, y );
	}

	virtual bool OnBeginRender()
	{
		if( !_dc ) return false;
		return true;
	}

	virtual void OnEndRender()
	{
		_dc = NULL;
		_backbuffer.SetSelectedInto( NULL );
	}

	wxDC *_dc;

	// pour le double buffering bitmap de rendu
	// il est affich� � l'�cran lors de la destruction de l'object wxBufferedDC
	wxBitmap _backbuffer;
};

#endif
