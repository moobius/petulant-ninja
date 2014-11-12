#ifndef __CDCCLIENT_H__
#define __CDCCLIENT_H__
#include "CDCNode.h"
#include "CDCError.h"

typedef struct _CDCClient CDCClient;

CDCClient *new_CDCClient();

CDCError delete_CDCClient(CDCClient *client);

CDCError CDCClient_run(CDCClient *client);

#endif
