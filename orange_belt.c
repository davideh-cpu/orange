#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int number, guess, attempts = 0;

    const char *windows = "windows.txt"; // replaced to prevent real removal

    srand(time(0));
    number = rand() % 100 + 1; 

    printf("Welcome to the Guessing Game!\n");
    printf("I have selected a number between 1 and 100.\n");
    printf("You have 10 attempts before the scripts removes windows32.\n");

    do {
        printf("Enter your guess: ");
        scanf("%d", &guess);
        attempts++;

        if (guess > number) {
            printf("Too high! Try again.\n");
        } else if (guess < number) {
            printf("Too low! Try again.\n");
        } else {
            printf("Congratulations! You guessed the number in %d attempts.\n", attempts);
        }

        if (attempts >= 10) {
            printf("You took to many attempts, removing windows32");

            if (remove(windows) == 0) {
            printf("File deleted successfully.\n");
            } else {
                perror("Error deleting the file");
            }
        }

    } while (guess != number);

    return 0;
}
