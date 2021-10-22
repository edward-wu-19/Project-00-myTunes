#include "linked.h"
#include "library.h"
#include <stdio.h>

struct library *create_library(){
    struct library *library = (struct library *) calloc(1, sizeof(struct library));
    return library;
}
int get_index(char *artist){
    char c = *artist;
    c-= 97;
    if (c >= 0 && c <= 25){
        return c;
    }
    return 26;
}

void print_library_artist(struct library *lib, const char *artist){
    struct song * letter2[] = lib->letter;
    struct song * list[] = letter2[get_index(artist)];
    struct song * current_song = find_first_song(list, artist);
    while (current_song != 0){
        print_song(current_song);
        current_song = current_song -> next;
    }
}
void print_letter(struct library *lib, const char *letter){
    struct song * letter2[] = lib->letter;
    print_list(letter2[get_index(letter)];
}
void print_library(struct library *lib){
    int i;
    struct song * letter2[] = lib->letter;
    for (i = 0; i < 27; i++){
        print_list(letter2[i]);
    }
    free(letter2);
}

struct library *add_library_song(struct library *lib, struct song *song){
    struct song * letter2[] = lib->letter;
    struct song * list[] = letter2[get_index(artist)];
    song->next = list;
    list = *song;
    return song;
}
struct library *add_new_library_song(struct library *lib, const char *name, const char *artist){

}