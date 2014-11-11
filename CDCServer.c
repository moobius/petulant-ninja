#include <stdlib.h>
#include "CDCServer.h"

struct _CDCServer {
	Nodechain *nodechain;

};

CDCServer *new_CDCServer()
{
	CDCServer *server = malloc(sizeof(CDCServer));
	server->nodechain = new_CDCNodechain();
	return server;
}

CDCError delete_CDCServer(CDCServer *server)
{
	CDCError return_error = kCDCError_Success;
	delete_CDCNodechain(server->nodechain);
	free(server);
	return return_error;
}

CDCError CDCServer_run(CDCServer *server)
{
	CDCError return_error = kCDCError_Success;
	// Add some things to the nodechain
	return return_error;
}
