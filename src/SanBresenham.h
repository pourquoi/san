/******************************************************************************/
/* Classe Bresenham pour le calcul incrémental de y=ax+b                      */
/* -on passe les x,y de départ et d'arrivé                                    */
/* -chaque incrémentation doit être appellé par la méthode Increment()        */
/* -on récupère les valeurs courantes en x et y par _xRes et _yRes            */
/******************************************************************************/

#ifndef _SANBRESENHAM_H_
#define _SANBRESENHAM_H_

#include "SanCommonHeaders.h"

namespace San
{
	class CBresenham
	{
		public:
		CBresenham(
			sanLong xStart,
			sanLong yStart,
			sanLong xEnd,
			sanLong yEnd
			);

		inline void Increment()
		{
			if( _switchXY )
			{
				_xRes = _y;
				_yRes = _x;
    		}
			else
			{
				_xRes = _x;
				_yRes = _y;
    		}
		    if( _incCUR <= 0 )
			{
				_incCUR += _incE;
    		}
    		else
			{
				_incCUR += _incNE;
				_y += _incY;
    		}
			_x += _incX;
		}

		sanLong _xRes;
		sanLong _yRes;

		protected:
		sanLong 		_incNE;
		sanLong 		_incE;
		sanLong 		_incCUR;
		bool 			_switchXY;
		sanShort 		_incY;
		sanLong 		_incX;
		sanLong 		_x;
		sanLong			_y;
	};
};

#endif
