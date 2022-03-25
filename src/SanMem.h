#ifndef _SANMEM_H_
#define _SANMEM_H_

#define SAFE_DELETE(x) { if(x) {delete x;x=NULL;} }
#define SAFE_DELETE_ARRAY(x) { if(x) {delete [] x;x=NULL;} }
#define SAFE_RELEASE(x) { if(x) x->Release(); }

namespace San
{
	template <class U> inline void Swap( U *a, U *b )
	{
		U c = *a;
		*a = *b;
		*b = c;
	}
}

#endif
