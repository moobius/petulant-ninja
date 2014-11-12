#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "CDCClient.h"

struct _CDCClient {
	//CDCStringTable *string_table;

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

CDCError CDCClient_run(CDCClient *client)
{
	CDCError return_error = kCDCError_Success;
	// Make a server request for some node chain vals
	// Distribute a file
	//  - Request some nodes from the nodechain
	CDCRequest node_request = { .request_type = kCDCRequestType_Nodes };
	TRY(return_error, CDCClient_request(client, &node_request));
	CDCNode **nodes = node_request.data.nodes;
	FILE *my_file = NULL;
	TRY(return_error, CDCClient_distribute(my_file, nodes));
	CDCRequest file_request = { .request_type = kCDCRequestType_File };
	TRY(return_error, CDCClient_gather(my_file, nodes));
	// Request that same file

	return return_error;
	CATCH
	// Handle catch
	return return_error;
}
