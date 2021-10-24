#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "linked.h"
#include "library.h"

void test_linked() {
    printf("LINKED LIST TESTS");
    struct song *s1 = NULL, *s2 = NULL, *s3 = NULL;
    printf("\n============================================================\n\n");

    printf("TESTING CREATE_NODE, PRINT_SONG, AND PRINT_LIST\n");
    printf("s1: "); print_song(s1); printf("\n");
    printf("s1 = create_node(\"Believer\", \"Imagine Dragons\")\n");
    s1 = create_node("Believer", "Imagine Dragons");
    printf("s1: "); print_song(s1); printf("\n");
    s2 = create_node("Capsized", "Andrew Bird");
    printf("s2 = create_node(\"Capsized\", \"Andrew Bird\")\n");
    printf("s2: "); print_song(s2); printf("\n");
    printf("s1->next = s2\n");
    s1->next = s2;
    printf("s1: "); print_list(s1);
    s1 = free_list(s1);
    printf("============================================================\n\n");

    printf("TESTING INSERT_NODE_FRONT AND INSERT_NEW_NODE_FRONT\n");
    printf("s1: "); print_list(s1);
    printf("s1 = insert_node_front(s1, create_node(\"Believer\",\"Imagine Dragons\"))\n");
    s1 = insert_node_front(s1, create_node("Believer","Imagine Dragons"));
    printf("s1: "); print_list(s1);
    printf("s1 = insert_new_node_front(s1, \"Capsized\", \"Andrew Bird\")\n");
    s1 = insert_new_node_front(s1, "Capsized", "Andrew Bird");
    printf("s1: "); print_list(s1);
    s1 = free_list(s1);
    printf("==============================================================\n\n");

    printf("TESTING COMPARE_NODE, COMPARE_NAME, AND COMPARE_ARTIST\n");
    s1 = create_node("Believer","Imagine Dragons");
    s2 = create_node("Capsized","Andrew Bird");
    s3 = create_node("Capsized","Andrew Bird");
    printf("s1: "); print_song(s1); printf("\n");
    printf("s2: "); print_song(s2); printf("\n");
    printf("s3: "); print_song(s3); printf("\n");
    printf("compare_name(s1, s2) = %2d\n", compare_name(s1, s2));
    printf("compare_name(s2, s1) = %2d\n", compare_name(s2, s1));
    printf("compare_name(s2, s3) = %2d\n", compare_name(s2, s3));
    printf("compare_artist(s1, s2) = %2d\n", compare_artist(s1, s2));
    printf("compare_artist(s2, s1) = %2d\n", compare_artist(s2, s1));
    printf("compare_artist(s2, s3) = %2d\n", compare_artist(s2, s3));
    printf("compare_node(s1, s2) = %2d\n", compare_node(s1, s2));
    printf("compare_node(s2, s1) = %2d\n", compare_node(s2, s1));
    printf("compare_node(s2, s3) = %2d\n", compare_node(s2, s3));
    free((void *) s1);
    free((void *) s2);
    free((void *) s3);
    printf("==============================================================\n\n");

    printf("TESTING INSERT_NODE_ORDER AND INSERT_NEW_NODE_ORDER\n");
    s1 = create_node("Believer", "Imagine Dragons");
    s2 = create_node("Good Morning World!", "BURNOUT SYNDROMES");
    s3 = create_node("Thunder", "Imagine Dragons");
    printf("s1: "); print_song(s1); printf("\n");
    printf("s2: "); print_song(s2); printf("\n");
    printf("s3: "); print_song(s3); printf("\n");
    printf("s1 = insert_new_node_order(s1,\"Love Dramatic\",\"Miura Jam\")\n");
    s1 = insert_new_node_order(s1,"Love Dramatic","Miura Jam");
    printf("s1: "); print_list(s1);
    printf("s1 = insert_node_order(s1, s2)\n");
    s1 = insert_node_order(s1, s2);
    printf("s1: "); print_list(s1);
    printf("s1 = insert_node_order(s1, s3)\n");
    s1 = insert_node_order(s1, s3);
    printf("s1: "); print_list(s1);
    printf("s1 = insert_new_node_order(s1,\"Love Dramatic\",\"Miura Jam\")\n");
    s1 = insert_new_node_order(s1,"Love Dramatic","Miura Jam");
    printf("s1: "); print_list(s1);
    printf("==============================================================\n\n");

    printf("TESTING FIND_SONG, FIND_FIRST_SONG, AND FIND_RANDOM_SONG\n");
    s1 = insert_new_node_order(s1, "Capsized", "Andrew Bird");
    printf("s1: "); print_list(s1);
    printf("find_song(s1, \"Capsized\", \"Andrew Bird\"): ");
    print_song(find_song(s1, "Capsized", "Andrew Bird")); printf("\n");
    printf("find_song(s1, \"Are You Serious\", \"Andrew Bird\"): ");
    print_song(find_song(s1, "Are You Serious", "Andrew Bird")); printf("\n");
    printf("find_first_song(s1, \"Imagine Dragons\"): ");
    print_song(find_first_song(s1, "Imagine Dragons")); printf("\n");
    printf("find_first_song(s1, \"Backstreet Boys\"): ");
    print_song(find_first_song(s1, "Backstreet Boys")); printf("\n");
    printf("find_random_song(s1): "); print_song(find_random_song(s1)); printf("\n");
    printf("find_random_song(s1): "); print_song(find_random_song(s1)); printf("\n");
    printf("find_random_song(s1): "); print_song(find_random_song(s1)); printf("\n");
    printf("find_random_song(s1): "); print_song(find_random_song(s1)); printf("\n");
    printf("find_random_song(s1): "); print_song(find_random_song(s1)); printf("\n");
    printf("==============================================================\n\n");

    printf("TESTING REMOVE_NODE, REMOVE_NEW_NODE, AND FREE_LIST\n");
    s2 = create_node("Love Dramatic", "Miura Jam");
    s3 = create_node("I Want It That Way", "Backstreet Boys");
    printf("s1: "); print_list(s1);
    printf("s2: "); print_song(s2); printf("\n");
    printf("s3: "); print_song(s3); printf("\n");
    printf("s1 = remove_node(s1, s2)\n");
    s1 = remove_node(s1, s2);
    printf("s1: "); print_list(s1);
    printf("s1 = remove_node(s1, s3)\n");
    s1 = remove_node(s1, s3);
    printf("s1: "); print_list(s1);
    printf("s1 = remove_new_node(s1, \"Thunder\", \"Imagine Dragons\")\n");
    s1 = remove_new_node(s1, "Thunder", "Imagine Dragons");
    printf("s1: "); print_list(s1);
    printf("s1 = remove_new_node(s1, \"Demons\", \"Imagine Dragons\")\n");
    s1 = remove_new_node(s1, "Demons", "Imagine Dragons");
    printf("s1: "); print_list(s1);
    printf("s1 = free_list(s1)\n");
    s1 = free_list(s1);
    printf("s1: "); print_list(s1);
    free((void *) s2);
    free((void *) s3);
    printf("==============================================================\n\n");
}

void test_library() {
    printf("LIBRARY TESTS");
    struct song *s1 = NULL, *s2 = NULL, *s3 = NULL;
    printf("\n============================================================\n\n");

    printf("TESTING CREATE_LIBRARY, PRINT_LIBRARY, ADD_LIBRARY_SONG, AND ADD_NEW_LIBRARY_SONG\n");
    printf("lib = create_library()\n");
    struct library *lib = create_library();
    printf("s1 = create_node(\"Demons\",\"Imagine Dragons\")\n");
    s1 = create_node("Demons","Imagine Dragons");
    printf("lib:\n"); print_library(lib);
    printf("lib = add_library_song(lib, s1)\n");
    lib = add_library_song(lib, s1);
    printf("lib:\n"); print_library(lib);
    printf("lib = add_new_library_song(lib, \"Believer\", \"Imagine Dragons\")\n");
    lib = add_new_library_song(lib, "Believer", "Imagine Dragons");
    printf("lib:\n"); print_library(lib);
    printf("lib = add_new_library_song(lib, \"Thunder\", \"Imagine Dragons\")\n");
    lib = add_new_library_song(lib, "Thunder", "Imagine Dragons");
    printf("lib:\n"); print_library(lib);
    printf("lib = add_new_library_song(lib, \"Capsized\", \"Andrew Bird\")\n");
    lib = add_new_library_song(lib, "Capsized", "Andrew Bird");
    printf("lib:\n"); print_library(lib);
    printf("lib = add_new_library_song(lib, \"TestName\", \"__TESTARTIST__\")\n");
    lib = add_new_library_song(lib, "TESTNAME", "__TESTARTIST__");
    printf("lib:\n"); print_library(lib);
    printf("==============================================================\n\n");

    printf("TESTING GET_INDEX\n");
    printf("get_index(\"a\"): %d\n", get_index("a"));
    printf("get_index(\"A\"): %d\n", get_index("A"));
    printf("get_index(\"hi\"): %d\n", get_index("hi"));
    printf("get_index(\"HI\"): %d\n", get_index("HI"));
    printf("get_index(\"%c\"): %d\n", '%', get_index("%"));
    printf("get_index(\"*\"): %d\n", get_index("*"));
    printf("==============================================================\n\n");

    printf("TESTING PRINT_LIBRARY_ARTIST AND PRINT_LETTER\n");
    lib = add_new_library_song(lib, "Check Yo Self", "Ice Cube");
    printf("lib:\n"); print_library(lib);
    printf("print_library_artist(lib, \"Imagine Dragons\"): ");
    print_library_artist(lib, "Imagine Dragons");
    printf("print_library_artist(lib, \"Backstreet Boys\"): ");
    print_library_artist(lib, "Backstreet Boys");
    printf("print_library_artist(lib, \"Andrew Bird\"): ");
    print_library_artist(lib, "Andrew Bird");
    printf("print_letter(lib, \"i\"): \n");
    print_letter(lib, "i");
    printf("print_letter(lib, \"^\"): \n");
    print_letter(lib, "^");
    printf("print_letter(lib, \"Imagine\"): \n");
    print_letter(lib, "Imagine");
    printf("print_letter(lib, \"O\"): \n");
    print_letter(lib, "O");
    printf("==============================================================\n\n");

    printf("TESTING FIND_LIBRARY_SONG, FIND_FIRST_LIBRARY_SONG\n");
    lib = add_new_library_song(lib, "Love Dramatic", "Miura Jam");
    printf("lib:\n"); print_library(lib);
    printf("find_library_song(lib, \"Demons\", \"Imagine Dragons\"): ");
    print_song(find_library_song(lib, "Demons", "Imagine Dragons")); printf("\n");
    printf("find_library_song(lib, \"Love Dramatic Extended Version\", \"Miura Jam\"): ");
    print_song(find_library_song(lib, "Love Dramatic Extended Version", "Miura Jam")); printf("\n");
    printf("find_library_song(lib, \"Corrupt\", \"_Corrupt\"): ");
    print_song(find_library_song(lib, "Corrupt", "_Corrupt")); printf("\n");
    printf("find_first_library_song(lib, \"Imagine Dragons\"): ");
    print_song(find_first_library_song(lib, "Imagine Dragons")); printf("\n");
    printf("find_first_library_song(lib, \"Adele\"): ");
    print_song(find_first_library_song(lib, "Adele")); printf("\n");
    printf("==============================================================\n\n");

    printf("TESTING FIND_N_RANDOM_SONGS\n");
    printf("lib:\n"); print_library(lib);
    printf("find_n_random_songs(lib, 1):\n");
    print_n_random_songs(lib, 1);
    printf("find_n_random_songs(lib, 4):\n");
    print_n_random_songs(lib, 4);
    printf("find_n_random_songs(lib, 5):\n");
    print_n_random_songs(lib, 5);
    printf("==============================================================\n\n");

    printf("TESTING REMOVE_LIBRARY_SONG, REMOVE_NEW_LIBRARY_SONG, FREE_LIBRARY\n");
    printf("lib:\n"); print_library(lib);
    s1 = create_node("Love Dramatic", "Miura Jam");
    s2 = create_node("Good Morning World", "BURNOUT SYNDROMES");
    printf("s1: "); print_song(s1); printf("\n");
    printf("s2: "); print_song(s2); printf("\n");
    printf("lib = remove_library_song(lib, s1)\n");
    lib = remove_library_song(lib, s1);
    printf("lib:\n"); print_library(lib);
    printf("lib = remove_library_song(lib, s2)\n");
    lib = remove_library_song(lib, s2);
    printf("lib:\n"); print_library(lib);
    printf("lib = remove_new_library_song(lib, \"Capsized\", \"Andrew Bird\")");
    lib = remove_new_library_song(lib, "Capsized", "Andrew Bird");
    printf("lib:\n"); print_library(lib);
    printf("lib = remove_new_library_song(lib, \"Are You Seriou\", \"Andrew Bird\")");
    lib = remove_new_library_song(lib, "Are You Serious", "Andrew Bird");
    printf("lib:\n"); print_library(lib);
    printf("lib = free_library(lib)\n");
    lib = free_library(lib);
    printf("lib:\n"); print_library(lib);
    printf("==============================================================\n\n");
}

int main() {
    test_linked();
    test_library();
    return 0;
}
