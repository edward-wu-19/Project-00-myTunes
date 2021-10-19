struct song {
    char name[100];
    char artist[100];
    struct song *next;
};

struct song *create_node(char* name, char *artist) {}

struct song *insert_front(struct song *list, char *name, char* artist) {}

int compare_nodes(struct song *s1, struct song *s2) {}

struct song *insert_order(struct song *list, char *name, char* artist) {}

void print_list(struct song *front){}

void print_song(struct song *song){}

struct song *find_song(struct song *front, char artist[], char song[]){}

struct song *find_first_song(struct song *front, char artist[]){}