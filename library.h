#ifndef LIBRARY

#include "linked.h"
#define LIBRARY

struct library {
    struct song *letter[27];
};

struct library *create_library();
int get_index(const char *artist);

void print_library_artist(struct library *lib, const char *artist);
void print_letter(struct library *lib, const char *letter);
void print_library(struct library *lib);

struct library *add_library_song(struct library *lib, struct song *song);
struct library *add_new_library_song(struct library *lib, const char *name, const char *artist);

struct library *remove_library_song(struct library *lib, struct song *song);
struct library *remove_new_library_song(struct library *lib, const char *name, const char *artist);
struct library *free_library(struct library *lib);

struct song *find_library_song(struct library *lib, const char *name, const char *artist);
struct song *find_first_library_song(struct library *lib, const char *name, const char *artist);
struct song *find_random_library_song(struct library *lib);

#endif
