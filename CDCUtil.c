#include <stdio.h>
#include <string.h>
#include "CDCUtil.h"
#include "CDCDebug.h"


void CDCUtil_grow_mem(void **mem, size_t size, int scale_factor)
{
	CDCAssert(scale_factor > 0);
	size_t new_size = size * scale_factor;
}
