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
