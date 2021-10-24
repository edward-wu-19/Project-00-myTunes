#ifndef LINKED

#define LINKED

struct song {
    char name[100];
    char artist[100];
    struct song *next;
};

// Creates A New Song Node
struct song *create_node(const char* name, const char *artist);

// Prints Every Song Node In A Linked List Of Song Nodes
void print_list(struct song *list);

// Prints A Singular Song Node
void print_song(struct song *song);

// Inserts A Song Node To The Front Of A Linked List Of Song Nodes
struct song *insert_node_front(struct song *list, struct song *song);

// Alternate Version Of Insert_Node_Front
struct song *insert_new_node_front(struct song *list, const char *name, const char *artist);

// Helper Function To Compare The Artists Of 2 Song Nodes
int compare_artist(struct song *song1, struct song *song2);

// Helper Function To Compare The Names Of 2 Song Nodes
int compare_name(struct song *song1, struct song *song2);

// Compares 2 Song Nodes By Artist First Then Name
int compare_node(struct song *song1, struct song *song2);

// Inserts A Song Node Into The Proper Order Of A Linked List
struct song *insert_node_order(struct song *list, struct song *song);

// Alternate Version To Insert_Node_Order
struct song *insert_new_node_order(struct song *list, const char *name, const char *artist);

// Returns A Pointer To A Song Node With A Certain Artist And Name
struct song *find_song(struct song *list, const char *name, const char *artist);

// Returns A Pointer To The First Song Node With A Certain Artist
struct song *find_first_song(struct song *list, const char *artist);

// Returns A Pointer To A Random Song Node In The Linked List
struct song *find_random_song(struct song *list);

// Removes A Song Node From A Linked List Of Song Nodes
struct song *remove_node(struct song *list, struct song *song);

// Alternate Version Of Remove_Node
struct song *remove_new_node(struct song *list, const char *name, const char *artist);

// Frees The Entirety Of A Linked List Of Songs
struct song *free_list(struct song *list);

#endif
