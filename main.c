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
    printf("compare_name(s1, s2) = %2d\n", compare_name(s1, s2));
    printf("compare_name(s2, s1) = %2d\n", compare_name(s2, s1));
    printf("compare_name(s2, s3) = %2d\n", compare_name(s2, s3));
    printf("compare_artist(s1, s2) = %2d\n", compare_artist(s1, s2));
    printf("compare_artist(s2, s1) = %2d\n", compare_artist(s2, s1));
    printf("compare_artist(s2, s3) = %2d\n", compare_artist(s2, s3));
    printf("compare_node(s1, s2) = %2d\n", compare_node(s1, s2));
    printf("compare_node(s2, s1) = %2d\n", compare_node(s1, s2));
    printf("compare_node(s2, s3) = %2d\n", compare_node(s1, s2));
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
    printf("==============================================================\n\n");

    printf("TESTING GET_INDEX\n");
    printf("%d\n", get_index(s1->artist));
    printf("==============================================================\n\n");

    printf("TESTING REMOVE_NODE, REMOVE_NEW_NODE, AND FREE_LIST\n");
    printf("s1: "); print_list(s1);
    printf("s1 = remove_node(s1, create_node(\"Love Dramatic\",\"Miura Jam\"))\n");
    s1 = remove_node(s1, create_node("Love Dramatic","Miura Jam"));
    printf("s1: "); print_list(s1);
    printf("s1 = remove_node(s1, create_node(\"I Want It That Way\",\"Backstreet Boys\"))\n");
    s1 = remove_node(s1, create_node("I Want It That Way","Backstreet Boys"));
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
}

void test_library() {

}

int main() {
    test_linked();
}
