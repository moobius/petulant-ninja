#include <stdlib.h>
#include "CDCServer.h"

struct _CDCServer {
	int i;
};

CDCServer *new_CDCServer()
{
	CDCServer *server = malloc(sizeof(CDCServer));
	server->i = 0;
	return server;
}

CDCError delete_CDCServer(CDCServer *server)
{
	CDCAssert(server != NULL);
	CDCError return_error = kCDCError_Success;
	free(server);
	return return_error;
}

CDCError CDCServer_run(CDCServer *server)
{
	CDCError return_error = kCDCError_Success;
	printf("%p\n", server);
	// Add some things to the nodechain
	return return_error;
}
