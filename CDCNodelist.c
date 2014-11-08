#include "CDCNodelist.h"

struct _CDCNodelist {
      Node **nodes;
      int nodes_count;
      int node_capacity;
};

CDCNodelist *new_CDCNodelist()
{
      CDCNodelist *node_list = malloc(sizeof(CDCNodelist));
      int init_nodes_capacity   = 16;
      node_list->nodes          = malloc(sizeof(Node *) * init_nodes_capacity);
      node_list->nodes_count    = 0;
      node_list->nodes_capacity = init_ips_capacity;
      return node_list;
}

void delete_CDCNodelist(CDCNodelist *node_list)
{
      free(node_list->nodes);
      free(node_list);
}
