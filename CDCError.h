#ifndef __CDCERROR_H__
#define __CDCERROR_H__
#include <stdio.h>

#define TRY(_f_) CDCError e; if ((e=_f_) != kCDCError_Success) CATCH(e);
#define CDCERRORS \
	X(kCDCError_Failure, "Failure") \
	X(kCDCError_Success, "Success")

#define X(_e_, _s_) _e_,
typedef enum {
	CDCERRORS
} CDCError;
#undef X

void CATCH(CDCError e)
{
#define X(_e_, _s_) case _e_: fprintf(stderr, "Error: %s\n", _s_); break;
	switch (e)
	{
		CDCERRORS
		default: fprintf(stderr, "Unknown error type %d\n", e); break;
	}
#undef X
}

#endif
