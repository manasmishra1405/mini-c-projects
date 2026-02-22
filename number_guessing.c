#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int secretNumber;
    int guess;
    int attempts = 0;

    // Seed random number generator
    srand(time(0));

    // Generate random number between 1 and 100
    secretNumber = (rand() % 100) + 1;

    printf("=== Number Guessing Game ===\n");
    printf("I have chosen a number between 1 and 100.\n");

    while (1) {
        printf("Enter your guess: ");
        scanf("%d", &guess);
        attempts++;

        if (guess > secretNumber) {
            printf("Too high! Try again.\n");
        } else if (guess < secretNumber) {
            printf("Too low! Try again.\n");
        } else {
            printf(" Correct! You guessed it in %d attempts.\n", attempts);
            break;
        }
    }

    return 0;
}

