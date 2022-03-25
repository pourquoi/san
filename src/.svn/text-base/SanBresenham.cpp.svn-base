#include "SanBresenham.h"

namespace San
{

CBresenham::CBresenham(
	sanLong xStart,
	sanLong yStart,
	sanLong xEnd,
	sanLong yEnd )
{
	sanLong dx, dy;

	if( (dx = xEnd - xStart) < 0 )
	{
		sanLong temp = xStart;
		xStart = xEnd;
		xEnd = temp;
		dx = xEnd - xStart;
	}

	if( (dy = yEnd - yStart) < 0 )
	{
		_incY = -1;
		dy = -dy;
	}
	else
	{
		_incY = 1;
	}

	if( dy > dx )
	{
		_switchXY = true;
		sanLong temp = dy;
		dy = dx;
		dx = temp;
	}
	else
	{
		_switchXY = false;
	}

	_incE = 2 * dy;
	_incNE = 2 * (dy - dx);
	_incCUR = 2 * dy - dx;

	_incX = 1;

	if( _switchXY )
	{
		_y = xStart;
		_x = yStart;
		if( _incY == -1 )
		{
			_incX = -1;
			_incY = 1;
		}
	}
	else
	{
		_y = yStart;
		_x = xStart;
	}

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
}

};
