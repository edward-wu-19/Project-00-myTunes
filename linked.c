#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct song {
    char name[100];
    char artist[100];
    struct song *next;
};

struct song *create_node(char* name, char *artist) {
    struct song *s = (struct student *) calloc(1, sizeof(struct song));
    strncpy((char *)&(s->name), name, sizeof(s->name)-1);
    strncpy((char *)&(s->artist), name, sizeof(s->artist)-1);
    return s;
}

struct song *insert_front(struct song *list, char *name, char* artist) {
    struct song *s = create_node(name, artist);
    s->next = list;
    return s;
}

int compare_nodes(struct song *s1, struct song *s2) {
    int a = strcmp(s1->artist, s2->artist);
    int b = strcmp(s1->name, s2->name);
    return (a == 0 ? b : a);
}

struct song *insert_order(struct song *list, char *name, char* artist) {
    struct song *s = create_node(name, artist);
    
}
