#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include "linked.h"

// Creates A New Song Node
struct song *create_node(const char* name, const char *artist) {
    struct song *song = (struct song *) calloc(1, sizeof(struct song));
    strncpy((song->name), name, sizeof(song->name)-1);
    strncpy((song->artist), artist, sizeof(song->artist)-1);
    char *namep = (song->name), *artistp = (song->artist);
    while (*namep != '\0') {
        *namep = tolower(*namep); namep++;
    }
    while (*artistp != '\0') {
        *artistp = tolower(*artistp); artistp++;
    }
    (song->next) = NULL;
    return song;
}

// Prints Every Node In A Linked List Of Song Nodes
void print_song(struct song *song) {
    if (song != NULL) printf("{%s, %s}", (song->artist), (song->name));
}

// Prints A Singular Song Node
void print_list(struct song *list) {
    printf("[ ");
    while (list != NULL) {
        print_song(list);
        printf(" | ");
        list = (list->next);
    }
    printf("]\n");
}

// Inserts A Song Node To The Front Of A Linked List Of Song Nodes
struct song *insert_node_front(struct song *list, struct song *song) {
    (song->next) = list;
    return song;
}

// Alternate Version Of Insert_Node_Front
struct song *insert_new_node_front(struct song *list, const char *name, const char* artist) {
    return insert_node_front(list, create_node(name, artist));
}

// Helper Function To Compare The Artists Of 2 Song Nodes
int compare_artist(struct song *song1, struct song *song2) {
    return strcmp((song1->artist), (song2->artist));
}

// Helper Function To Compare The Names Of 2 Song Nodes
int compare_name(struct song *song1, struct song *song2) {
    return strcmp((song1->name), (song2->name));
}

// Compares 2 Song Nodes By Artist First Then Name
int compare_node(struct song *song1, struct song *song2) {
    int a = compare_artist(song1, song2);
    int b = compare_name(song1, song2);
    return (a == 0 ? b : a);
}

// Inserts A Song Node Into The Proper Order Of A Linked List
struct song *insert_node_order(struct song *list, struct song *song) {
    if (list == NULL || compare_node(song, list) <= 0) return insert_node_front(list, song);
    struct song *temp1 = list, *temp2 = (list->next);
    while (temp2 != NULL) {
        if (compare_node(song, temp2) <= 0) {
            (temp1->next) = song;
            (song->next) = temp2;
            return list;
        }
        temp1 = (temp1->next);
        temp2 = (temp2->next);
    }
    (temp1->next) = song;
    (song->next) = temp2;
    return list;
}

// Alternate Version To Insert_Node_Order
struct song *insert_new_node_order(struct song *list, const char *name, const char* artist) {
    return insert_node_order(list, create_node(name, artist));
}

// Returns A Pointer To A Song Node With A Certain Artist And Name
struct song *find_song(struct song *list, const char *name, const char *artist) {
    struct song *temp = list, *song = create_node(name, artist);
    while (temp != NULL) {
        if (compare_node(temp, song) == 0) {
            free((void *) song);
            return temp;
        }
        temp = (temp->next);
    }
    free((void *) song);
    return temp;
}

// Returns A Pointer To The First Song Node With A Certain Artist
struct song *find_first_song(struct song *list, const char *artist) {
    struct song *temp = list, *song = create_node("\0", artist);
    while (temp != NULL) {
        if (compare_artist(song, temp) == 0) {
            free((void *) song);
            return temp;
        }
        temp = temp->next;
    }
    free((void *) song);
    return temp;
}

// Variable To Help Randomize Stuff
long RANDOM_LINKED_COUNT = 0;

// Returns A Pointer To A Random Song Node In The Linked List
struct song *find_random_song(struct song *list) {
    if (RANDOM_LINKED_COUNT == 0) srand(time(NULL)); RANDOM_LINKED_COUNT++;
    int mx = -1, val;
    struct song *temp = list, *ret;
    while (temp != NULL) {
        val = rand();
        if (val > mx) {
            mx = val;
            ret = temp;
        }
        temp = (temp->next);
    }
    return ret;
}

// Removes A Song Node From A Linked List Of Song Nodes
struct song *remove_node(struct song *list, struct song *song) {
    struct song *temp1 = list;
    if (temp1 == NULL) return list;
    if (compare_node(temp1, song) == 0) {
        list = (list->next);
        free((void *) temp1);
        return list;
    }
    struct song *temp2 = list->next;
    while (temp2 != NULL) {
        if (compare_node(temp2, song) == 0) {
            (temp1->next) = temp2->next;
            free((void *) temp2);
            return list;
        }
        temp2 = (temp2->next);
        temp1 = (temp1->next);
    }
    return list;
}

// Alternate Version Of Remove_Node
struct song *remove_new_node(struct song *list, const char *name, const char *artist) {
    struct song *song = create_node(name, artist);
    struct song *ret = remove_node(list, song);
    free((void *) song);
    return ret;
}

// Frees The Entirety Of A Linked List Of Songs
struct song *free_list(struct song *list) {
    struct song *temp = list;
    while (list != NULL) {
        list = list->next;
        free((void *) temp);
        temp = list;
    }
    return list;
}
