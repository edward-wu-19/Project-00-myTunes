#include <stdio.h>
#include "linked.h"
#include "library.h"

void test_linked() {
    printf("LINKED LIST TESTS\n");
    printf("==================================================\n");

    printf("Testing print_song");

    char *acdc = "ac/dc\0";
    char *thunderstruck = "thunderstruck\0";
    struct song *thunder = create_node(acdc, thunderstruck);

    print_song(thunder);
}

void test_library() {

}

int main() {
    test_linked();
}
