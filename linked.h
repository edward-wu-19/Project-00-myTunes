#ifndef LINKED

#define LINKED

struct song;

struct song *create_node(char* name, char *artist);

struct song *insert_node_front(struct song *list, struct song *s);
struct song *insert_new_node_front(struct song *list, char *name, char *artist);

int compare_artist(struct song *s1, struct song *s2);
int compare_name(struct song *s1, struct song *s2);
int compare_node(struct song *s1, struct song *s2);

struct song *insert_node_order(struct song *list, struct song *s);
struct song *insert_new_node_order(struct song *list, char *name, char *artist);

void print_list(struct song *front);
void print_song(struct song *song);

struct song *find_song(struct song *front, char *artist, char *song);
struct song *find_first_song(struct song *front, char *artist);
struct song *find_random_song(struct song *list);

struct song *remove_node(struct song *list, struct song *s);
struct song *remove_new_node(struct song *list, char *name, char *artist);
struct song *free_list(struct song *list);

#endif
