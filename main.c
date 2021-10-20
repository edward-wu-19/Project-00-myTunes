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

}

void test_library() {

}

int main() {
    test_linked();
}
