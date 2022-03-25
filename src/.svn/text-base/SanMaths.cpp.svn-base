#include "SanMaths.h"

namespace San
{

sanFloat Max( sanFloat a, sanFloat b )
{
	if(a > b)
		return a;
	else
		return b;
}

sanFloat Min( sanFloat a, sanFloat b )
{
	if(a < b)
		return a;
	else 
		return b;
}

sanFloat Ceil( sanFloat a )
{
	return ceilf( a );
}

sanFloat Floor( sanFloat a )
{
	return floorf( a );
}

sanFloat Abs( sanFloat a )
{
	return (a > 0 ? a : -a);
}

sanFloat Sqrt( sanFloat a )
{
	return sqrtf( a );
}

sanRadians Sin( sanRadians a, const bool use_table )
{
	return sinf( a );
}

sanRadians Cos( sanRadians a, const bool use_table )
{
	return Sin( SAN_PI_2 - a, use_table );
}

};
