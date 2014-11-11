#ifndef __CDCSERVER_H__
#define __CDCSERVER_H__
#include "CDCError.h"

typedef struct _CDCServer CDCServer;

CDCServer *new_CDCServer();

CDCError delete_CDCServer(CDCServer *server);

CDCError CDCServer_run(CDCServer *server);

#endif
