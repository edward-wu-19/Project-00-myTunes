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

    // printf("Testing print_song");

    // char *acdc = "ac/dc\0";
    // char *thunderstruck = "thunderstruck\0";
    // struct song *thunder = create_node(acdc, thunderstruck);

    // print_song(thunder);
}

void test_library() {

}

int main() {
    test_linked();
}
