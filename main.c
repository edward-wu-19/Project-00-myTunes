#include <stdio.h>
#include <string.h>
#include "linked.h"
#include "library.h"

void test_linked() {
    printf("LINKED LIST TESTS\n");
    printf("==================================================\n");
    printf("\n");

    printf("TESTING CREATE_NODE\n");
    printf("s1: NULL\ns1: ");
    struct song *s1 = NULL;
    s1 = create_node("Believer","Imagine Dragons");
    print_song(s1);
    printf("\n");
    printf("==================================================\n");
    printf("\n");

    printf("TESTING INSERT_NODE_FRONT AND INSERT_NEW_NODE_FRONT\n");
    printf("s1: NULL\ns1: ");
    remove_node(s1, s1);
    s1 = create_node("Believer","Imagine Dragons");
    print_song(s1);
    printf("\ns1: ");
    s1 = insert_new_node_front(s1, "Capsized", "Andrew Bird");
    print_list(s1);
    printf("==================================================\n");
    printf("\n");

    printf("TESTING COMPARE_NODE, COMPARE_NAME, AND COMPARE_ARTIST\n");

}

void test_library() {

}

int main() {
    test_linked();
}
