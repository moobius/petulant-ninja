#ifndef __CDCNODECHAIN_H__
#define __CDCNODECHAIN_H__

#include "CDCNode.h"
#include "CDCError.h"

typedef struct _CDCNodechain CDCNodechain;

CDCNodechain *new_CDCNodechain();

void delete_CDCNodechain(CDCNodechain *nodechain);

#endif
