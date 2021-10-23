#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include "linked.h"
#include "library.h"

struct library *create_library() {
    struct library *lib = (struct library *) calloc(1, sizeof(struct library));
    return lib;
}

void print_library(struct library *lib) {
    int index;
    for (index = 0; index < 26; index++) {
        if ((lib->letter)[index] != NULL) {
            const char c = char(97+index);
            print_letter(lib, &c);
        }
    }
    if ((lib->letter)[index] != NULL) print_letter(lib, "%");
}

struct library *add_library_song(struct library *lib, struct song *song) {
    int index = get_index(song->artist);
    (lib->letter)[index] = insert_node_order((lib->letter)[index], song);
    return lib;
}

struct library *add_new_library_song(struct library *lib, const char *name, const char *artist) {
    return add_library_song(lib, create_node(name, artist));
}

int get_index(const char *artist) {
    if ((tolower(*artist)-'a' >= 0) && (tolower(*artist)-'z' <= 0)) return (tolower(*artist)-'a');
    return 26;
}

void print_library_artist(struct library *lib, const char *artist) {
    struct song *list = (lib->letter)[get_index(artist)];
    printf("[ ");
    while (list != NULL) {
        list = find_first_song(list, artist);
        print_song(list); printf(" | ");
        list = (list->next);
    }
    printf("]\n");
}

void print_letter(struct library *lib, const char *letter) {
    int index = get_index(letter);
    if (index < 26) {
        printf("%c: ", char(index+97)); print_list((lib->letter)[index]);
    } else {
        printf("%c: ", '%'); print_list((lib->letter)[index]);
    }
}

struct song *find_library_song(struct library *lib, const char *name, const char *artist) {
    return find_song((lib->letter)[(get_index(artist))], name, artist);
}

struct song *find_first_library_song(struct library *lib, const char *artist) {
    return find_first_song((lib->letter)[get_index(artist)], artist);
}

long RANDOM_LIB_COUNT = 0;

void print_n_random_songs(struct library *lib, int n) {
    if (RANDOM_LIB_COUNT == 0) srand(time(NULL));
    printf("[ ");
    int i, index;
    for (i = 0; i < n; i++) {
        index = rand()%27;
        while ((lib->letter)[index] == NULL) index = rand()%27;
        print_song(find_random_song((lib->letter)[index]));
        printf(" | ");
        RANDOM_LIB_COUNT++;
    }
    printf("]\n");
}

struct library *remove_library_song(struct library *lib, struct song *song) {
    int index = get_index(song->artist);
    (lib->letter)[index] = remove_node((lib->letter)[index], song);
    return lib;
}

struct library *remove_new_library_song(struct library *lib, const char *name, const char *artist) {
    struct song *song = create_node(name, artist);
    struct library *ret = remove_library_song(lib, song);
    free((void *) song);
    return ret;
}

struct library *free_library(struct library *lib) {
    int index;
    for (index = 0; index < 27; index++) {
        (lib->letter)[index] = free_list((lib->letter)[index]);
    }
    free((void *) lib);
    return lib;
}
