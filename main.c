#include "CDCServer.h"
#include "CDCClient.h"

typedef enum {
	kCDCInstance_Client,
	kCDCInstance_Server,
} CDCInstance;

typedef struct {
	CDCInstance instance;
} CDCOptions;

CDCError launch_CDCClient()
{
	CDCError return_error;
	CDCClient *client = new_CDCClient();
	delete_CDCClient(client);
	return return_error;
}

CDCError launch_CDCServer()
{
	CDCError return_error;
	CDCServer *server = new_CDCServer();
	delete_CDCServer(server);
	return return_error;
}

int main(void)
{
	CDCError return_error = kCDCError_Success;

	CDCOptions options = {
                           .instance = kCDCInstance_Server,
	                     };

	switch (options.instance)
	{
		case kCDCInstance_Client: return_error = launch_CDCClient(); break;
		case kCDCInstance_Server: return_error = launch_CDCServer(); break;
		case default: break;
	}

	return return_error;
}
