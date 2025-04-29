// linked_list.h

typedef struct node_s
{
	int value;
	struct node_s* next;

} node_t;

typedef struct list_s
{
	node_t* first;
	node_t* last;

} list_t;
