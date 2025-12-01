#include "../lib.h"
#include <stdio.h>

// when cur_state is greater than elements, cur_state is reset to 0.
// on the other hand if cur_state is less than 0, it's set to elements
typedef struct {
    int cur_state;
    int max;
} dial_t;

// action enum for dial_t turn method
typedef enum {
    DIAL_LEFT,
    DIAL_RIGHT,
} dial_turn_t;

// returns amount of times dial clicked
int dial_turn(dial_t *dial, dial_turn_t turn, int amount) {
    int dial_elements_count = dial->max + 1;
    int clicks = amount / dial_elements_count;

    amount -= dial_elements_count * clicks;

    int prev_state = dial->cur_state;
    dial->cur_state += (turn == DIAL_LEFT) ? (amount * -1) : amount;

    if ((dial->cur_state < 0) || (dial->cur_state > dial->max)) {
        if (dial->cur_state < 0) {
            dial->cur_state += dial_elements_count;
        } else if (dial->cur_state > dial->max) {
            dial->cur_state %= dial_elements_count;
        }

        if ((prev_state != 0) && (dial->cur_state != 0))
            clicks++;
    }

    return clicks;
}

int solution() {
    FILE *file_ptr;
    fopen_s(&file_ptr, "resources/day_1.txt", "r");
    if (file_ptr == NULL) {
        printf("could not open file: resources/day_1.txt\n");
        return FAILED;
    }

    // incremented every time dial hits exactly 0
    int password = 0;
    dial_t this_dial = {.cur_state = 50, .max = 99};

    // prepare variables to scan the file
    char turn;
    int amount;

    // read file line by line.
    while (fscanf_s(file_ptr, "%c%d\n", &turn, 1, &amount) == 2) {
        if ((turn != 'R' && turn != 'L') || (amount < 0)) {
            printf("invalid line format, turn: %c, amount: %d\n", turn, amount);
            fclose(file_ptr);
            return FAILED;
        }

        dial_turn_t _turn = (turn == 'R') ? DIAL_RIGHT : DIAL_LEFT;
        dial_turn(&this_dial, _turn, amount);

        if (this_dial.cur_state == 0) {
            password++;
        }
    }

    printf("day 1 solution is: %d\n", password);

    // close everything before returning solved state
    fclose(file_ptr);
    return SOLVED;
}

int solution_part_two() {
    FILE *file_ptr;
    fopen_s(&file_ptr, "resources/day_1.txt", "r");
    if (file_ptr == NULL) {
        printf("could not open file: resources/day_1.txt\n");
        return FAILED;
    }

    // incremented every time dial hits exactly 0
    int password = 0;
    dial_t this_dial = {.cur_state = 50, .max = 99};

    // prepare variables to scan the file
    char turn;
    int amount;

    // read file line by line.
    while (fscanf_s(file_ptr, "%c%d\n", &turn, 1, &amount) == 2) {
        if ((turn != 'R' && turn != 'L') || (amount < 0)) {
            printf("invalid line format, turn: %c, amount: %d\n", turn, amount);
            fclose(file_ptr);
            return FAILED;
        }

        dial_turn_t _turn = (turn == 'R') ? DIAL_RIGHT : DIAL_LEFT;
        int clicks = dial_turn(&this_dial, _turn, amount);
        password += clicks;

        if (this_dial.cur_state == 0) {
            password++;
        }
    }

    printf("day 1 solution is: %d\n", password);

    // close everything before returning solved state
    fclose(file_ptr);
    return SOLVED;
}
