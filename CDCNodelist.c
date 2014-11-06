#include "CDCNodelist.h"

struct _CDCNodelist {
      const int *ips;
      int ips_count;
      int ips_capacity;
};

CDCNodelist *new_CDCNodelist()
{
      CDCNodelist *node_list = malloc(sizeof(CDCNodelist));
      int init_ips_capacity = 16;
      node_list->ips          = malloc(sizeof(const int) * init_ips_capacity);
      node_list->ips_count    = 0;
      node_list->ips_capacity = init_ips_capacity;
      return node_list;
}

void delete_CDCNodelist(CDCNodelist *node_list)
{
      free(node_list->ips);
      free(node_list);
}
