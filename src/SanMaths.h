/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
/* Quelques fonctions, strutures et constantes pour l'arithmétique            */
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

#ifndef _SANMATHS_H_
#define _SANMATHS_H_

#include "SanCommonHeaders.h"


#define SAN_PI 3.141592653
#define SAN_PI_2 1.570796327
#define SAN_PI_4 0.7853981634

namespace San
{
	sanFloat Max( sanFloat a, sanFloat b );

	sanFloat Min( sanFloat a, sanFloat b );

	sanFloat Ceil( sanFloat a );

	sanFloat Floor( sanFloat a );

	sanFloat Abs( sanFloat a );

	sanFloat Sqrt( sanFloat a );

	sanRadians Sin( sanRadians a, const bool use_table=false );

	sanRadians Cos( sanRadians a, const bool use_table=false );
}

#endif
