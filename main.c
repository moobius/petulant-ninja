#include "CDCError.h"
#include "CDCServer.h"
#include "CDCClient.h"

typedef enum {
	kCDCInstance_Client,
	kCDCInstance_Server,
	kCDCInstance_Size,
} CDCInstance;

typedef struct {
	CDCInstance instance;
} CDCOptions;

CDCError launch_CDCClient()
{
	CDCError return_error = kCDCError_Success;
	CDCClient *client = new_CDCClient();
	CDCClient_run(client);
	delete_CDCClient(client);
	return return_error;
}

CDCError launch_CDCServer()
{
	CDCError return_error = kCDCError_Success;
	CDCServer *server = new_CDCServer();
	TRY(CDCServer_run(server));
	delete_CDCServer(server);
	return return_error;
}

int main(void)
{
	CDCError return_error = kCDCError_Success;

	CDCOptions options = {
                           .instance = kCDCInstance_Client,
	                     };

	switch (options.instance)
	{
		case kCDCInstance_Client: return_error = launch_CDCClient(); break;
		case kCDCInstance_Server: return_error = launch_CDCServer(); break;
		default: break;
	}

	return return_error;
}
