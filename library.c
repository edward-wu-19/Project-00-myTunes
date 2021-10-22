#include <stdio.h>
#include <stdlib.h>
#include "linked.h"
#include "library.h"

struct library *create_library();
int get_index(const char *artist) {
    if (artist == NULL) return 26;
    if ((*artist-'a' >= 0) && (*artist-'z' <= 0)) return (*artist-'a');
    return 26;
}

void print_library_artist(struct library *lib, const char *artist);
void print_letter(struct library *lib, const char *letter);
void print_library(struct library *lib);

struct library *add_library_song(struct library *lib, struct song *song);
struct library *add_new_library_song(struct library *lib, const char *name, const char *artist);

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
    int i;
    for (i = 0; i < 27; i++) {
        (lib->letter)[i] = free_list((lib->letter)[i]);
    }
    free((void *) lib);
    return NULL;
}

struct song *find_library_song(struct library *lib, const char *name, const char *artist) {
    return find_song((lib->letter)[(get_index(artist))], name, artist);
}
struct song *find_first_library_song(struct library *lib, const char *artist) {
    return find_first_song((lib->letter)[get_index(artist)], artist);
}
struct song *find_random_library_song(struct library *lib);
