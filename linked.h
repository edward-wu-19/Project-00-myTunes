#ifndef LINKED

#define LINKED

struct song {
    char name[100];
    char artist[100];
    struct song *next;
};

struct song *create_node(const char* name, const char *artist);

void print_list(struct song *list);
void print_song(struct song *song);

struct song *insert_node_front(struct song *list, struct song *song);
struct song *insert_new_node_front(struct song *list, const char *name, const char *artist);

int compare_artist(struct song *song1, struct song *song2);
int compare_name(struct song *song1, struct song *song2);
int compare_node(struct song *song1, struct song *song2);

struct song *insert_node_order(struct song *list, struct song *song);
struct song *insert_new_node_order(struct song *list, const char *name, const char *artist);

struct song *find_song(struct song *list, const char *name, const char *artist);
struct song *find_first_song(struct song *list, const char *artist);
struct song *find_random_song(struct song *list);

struct song *remove_node(struct song *list, struct song *song);
struct song *remove_new_node(struct song *list, const char *name, const char *artist);
struct song *free_list(struct song *list);

#endif
