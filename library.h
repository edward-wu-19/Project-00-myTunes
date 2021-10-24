#ifndef LIBRARY

#include "linked.h"
#define LIBRARY

struct library {
    struct song *letter[27];
};

// Creates An Empty Library With Enough Memory For 27 Linked Lists
struct library *create_library();

// Prints Out All Non-Empty Linked Lists In The Library
void print_library(struct library *lib);

// Adds A Song In The Correct Order To The Library
struct library *add_library_song(struct library *lib, struct song *song);

// Alternate Version Of Add_Library_Song
struct library *add_new_library_song(struct library *lib, const char *name, const char *artist);

// Helper Function That Gets The Index Of A Node Given Artist Name
int get_index(const char *artist);

// Prints All Songs That Are Made By A Certain Artist
void print_library_artist(struct library *lib, const char *artist);

// Prints All Songs That Are Made By Artists That Start With A Certain Letter
void print_letter(struct library *lib, const char *letter);

// Finds And Returns A Pointer To The Song Node With The Same Artist And Name
struct song *find_library_song(struct library *lib, const char *name, const char *artist);

// Finds And Returns A Pointer To The First Song Node Of A Certain Artist
struct song *find_first_library_song(struct library *lib, const char *artist);

// Prints N Random Songs From The Entire Library
void print_n_random_songs(struct library *lib, int n);

// Removes A Song From A Library
struct library *remove_library_song(struct library *lib, struct song *song);

// Alternate Version Of Remove_Library_Song
struct library *remove_new_library_song(struct library *lib, const char *name, const char *artist);

// Frees The Entire Library 
struct library *free_library(struct library *lib);

#endif
