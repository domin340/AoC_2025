#include "lib.h"
#include <stdio.h>

extern int solution();
extern int solution_part_two();

int main() {
    int which_part;
    printf("which part would you like to execute?\n");
    printf("1 -> solution for part 1\n");
    printf("2 -> solution for part 2\n");
    scanf_s("%d", &which_part);

    if (which_part == 1) {
        if (solution() == FAILED) {
            printf("something went wrong, couldn't solve the problem!\n");
        }
    } else if (which_part == 2) {
        if (solution_part_two() == FAILED) {
            printf("solution for part two resulted in failure!\n");
        }
    } else {
        printf("there is no solution for part %d\n", which_part);
    }
}
