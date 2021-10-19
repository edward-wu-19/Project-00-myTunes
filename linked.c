#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>


// Struct Definition
struct song {
    char name[100];
    char artist[100];
    struct song *next;
};


// Node Creation Functions
struct song *create_node(char* name, char *artist) {
    struct song *s = (struct song *) calloc(1, sizeof(struct song));
    char *np = name, *ap = artist;
    while (np != NULL) {
        *np = tolower(*np); np++;
    }
    while (ap != NULL) {
        *ap = tolower(*ap); ap++;
    }
    strncpy((char *)&(s->name), name, sizeof(s->name)-1);
    strncpy((char *)&(s->artist), artist, sizeof(s->artist)-1);
    s->next = NULL;
    return s;
}


// Insert Front Functions
struct song *insert_node_front(struct song *list, struct song *s) {
    s->next = list;
    return s;
}
struct song *insert_new_node_front(struct song *list, char *name, char* artist) {
    return insert_node_front(list, create_node(name, artist));
}


// Comparison Functions
int compare_artist(struct song *s1, struct song *s2) {
    return strcmp(s1->artist, s2->artist);
}
int compare_name(struct song *s1, struct song *s2) {
    return strcmp(s1->name, s2->name);
}
int compare_node(struct song *s1, struct song *s2) {
    int a = compare_artist(s1, s2);
    int b = compare_name(s1, s2);
    return (a == 0 ? b : a);
}


// Insert Order Functions
struct song *insert_node_order(struct song *list, struct song *s) {
    if (list == NULL || compare_node(s, list) <= 0) return insert_node_front(list, s);
    struct song *temp1 = list, *temp2 = list->next;
    while (temp2 != NULL) {
        if (compare_node(s, temp2) <= 0) {
            temp1->next = s;
            s->next = temp2;
            return list;
        }
    }
    temp1->next = s;
    s->next = temp2;
    return list;
}
struct song *insert_new_node_order(struct song *list, char *name, char* artist) {
    return insert_node_order(list, create_node(name, artist));
}


// Print Song Functions
void print_song(struct song *song) {
    printf("%s: %s", song->name, song->artist);
}
void print_list(struct song *front) {
    while (front != NULL){
        print_song(front);
        printf(" | ");
        front = front->next;
    }
    printf("\n");
}

// Find Song Functions
struct song *find_song(struct song *front, char *artist, char *song) {
    struct song *temp = front, *s = create_node(artist, song);
    while (temp != NULL) {
        if (compare_node(temp, s) == 0) return temp;
        temp = temp->next;
    }
    return temp;
}
struct song *find_first_song(struct song *front, char *artist) {
    struct song *temp = front, *s = create_node(NULL, artist);
    while (temp != NULL) {
        if (compare_artist(s, temp) == 0) return temp;
        temp = temp->next;
    }
    return temp;
}
struct song *find_random_song(struct song *list) {
    srand(time(NULL));
    int mx = -1;
    struct song *temp = list, *ret;
    while (temp != NULL) {
        int val = rand();
        if (val > mx) {
            mx = val;
            ret = temp;
        }
        temp++;
    }
    return ret;
}


// Remove Song Fucntions
struct song *remove_node(struct song *list, struct song *s) {
    struct song *temp1 = list;
    if (temp1 == NULL) return list;
    if (compare_node(temp1, s) == 0) {
        list = list->next;
        free((void *) temp1);
        return list;
    }
    struct song *temp2 = list->next;
    while (temp2 != NULL) {
        if (compare_node(temp2, s) == 0) {
            temp1->next = temp2->next;
            free((void *) temp2);
            return list;
        }
        temp2 = temp2->next;
        temp1 = temp1->next;
    }
    return list;
}
struct song *remove_new_node(struct song *list, char *name, char *artist) {
    return remove_node(list, create_node(name, artist));
}
struct song *free_list(struct song *list) {
    struct song *temp = list;
    while (list != NULL) {
        list = list->next;
        free((void *) temp);
        temp = list;
    }
    return list;
}
