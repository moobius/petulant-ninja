#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "CDCClient.h"

struct _CDCClient {
	int i;
};

typedef struct _CDCRequest CDCRequest;

typedef enum {
	kCDCRequestType_File,
	kCDCRequestType_Nodes,
} CDCRequestType;

struct _CDCRequest {
	CDCRequestType request_type;
	union {
		CDCNode **nodes;
		FILE *file;
	} data;
};

CDCClient *new_CDCClient()
{
	CDCClient *client = malloc(sizeof(CDCClient));
	return client;
}

CDCError delete_CDCClient(CDCClient *client)
{
	CDCError return_error = kCDCError_Success;
	free(client);
	return return_error;
}

CDCError CDCClient_request(CDCClient *c, CDCRequest *r)
{
	c = (CDCClient*)r;
	printf("%p\n", c);
	return kCDCError_Success;
}

CDCError CDCClient_run(CDCClient *client)
{
	CDCError return_error = kCDCError_Success;
	// Make a server request for some node chain vals
	// Distribute a file
	//  - Request some nodes from the nodechain
	CDCRequest node_request = { .request_type = kCDCRequestType_Nodes };
	if ((return_error = CDCClient_request(client, &node_request)) != kCDCError_Success)
		goto bail;

bail:
	return return_error;
}
