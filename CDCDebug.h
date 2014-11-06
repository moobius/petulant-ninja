#ifndef __CDCDEBUG_H__
#define __CDCDEBUG_H__

#include <assert.h>
#define DEBUG

#if defined(DEBUG)

#define CDCAssert(_x_) assert(_x_);

#else

#define CDCAssert(_x_) ;

#endif

#endif
