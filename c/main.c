#include "lib.h"
#include <stdio.h>

extern int solution();

int main() {
    printf("running solution!\n");
    if (solution() == FAILED) {
        printf("something went and couldn't solve the problem!\n");
    }
}
