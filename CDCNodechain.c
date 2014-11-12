#include <stdlib.h>
#include <string.h>
#include "CDCNodechain.h"
#include "CDCUtil.h"

// TODO: This needs to be the string table
struct _CDCNodechain {
	CDCNodelist *nodelist;
	//CDCStringTable *string_table; // Maps files to nodes
	int i;
};

CDCNodechain *new_CDCNodechain()
{
	CDCNodechain *nodechain = malloc(sizeof(CDCNodechain));

	int init_node_list_capacity = 16;

	nodechain->node_list          = malloc(sizeof(CDCNode*) * init_node_list_capacity);
	nodechain->node_list_count    = 0;
	nodechain->node_list_capacity = init_node_list_capacity;

	return nodechain;
}

void delete_CDCNodechain(CDCNodechain *nodechain)
{
	for (int i = 0; i < nodechain->node_list_count; ++i)
	{
		delete_CDCNode(node_list[i]);
	}
	free(nodechain->node_list);
	free(nodechain);
}

void CDCNodechain_double(CDCNodechain *nodechain)
{
	int old_node_list_capacity = nodechain->node_list_capacity;
	nodechain->node_list_capacity *= 2;
	CDCNode **new_node_list = malloc(sizeof(CDCNode*) * nodechain->node_list_capacity);
	memcpy((void*)new_node_list, (void*)nodechain->node_list, sizeof(CDCNode*) * old_node_list_capacity);
	free(nodechain->node_list);
	nodechain->node_list = new_node_list;
}

CDCError CDCNodechain_insert(CDCNodechain *nodechain, void *data, size_t size, char *key)
{
	CDCError return_error = kCDCError_Success;
	if (nodechain->node_list_count >= nodechain->node_list_capacity)
		CDCNodechain_double(nodechain);
	int node_index = nodechain->node_list_count;
	nodechain->node_list[node_index] = node;
	++nodechain->node_list_count;
	return return_error;
}

CDCError CDCNodechain_lookup(CDCNodechain *nodechain, void **data, size_t *size, char *key)
{
      CDCError return_error = kCDCError_Success;
      Nodelist *node_list = CDCStringTable_lookup(nodechain->string_table, key);
      CDCGatherer *gatherer = new_CDCGatherer(data, size);
      CDCGatherer_gather(gatherer, node_list); // This will block
      delete_CDCGatherer(gatherer);
      return return_error;
}

