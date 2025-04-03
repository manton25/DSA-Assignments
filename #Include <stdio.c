#include <stdio.h>

#define SUBJECTS 3
#define TESTS 4

const char *subjectNames[SUBJECTS] = {"Physics", "Chemistry", "Math"};
const char *testNames[TESTS] = {"Assignment", "Course work", "Mid-term", "End-term"};

int main() {
    float marks[SUBJECTS][TESTS];
    float total[SUBJECTS] = {0};
    float overallTotal = 0;

    // Get marks for each subject and test
    for (int i = 0; i < SUBJECTS; i++) {
        printf("Enter marks for %s (0-100):\n", subjectNames[i]);
        for (int j = 0; j < TESTS; j++) {
            int validInput = 0;
            while (!validInput) {
                printf("%s: ", testNames[j]);
                
                if (scanf("%f", &marks[i][j]) != 1) {  // Check if input is a number
                    printf("Invalid input! Please enter a number.\n");
                    while (getchar() != '\n');  // Clear input buffer
                    continue;
                }

                if (marks[i][j] < 0 || marks[i][j] > 100) {
                    printf("Invalid input! Marks must be between 0 and 100.\n");
                } else {
                    validInput = 1;  // Input is valid
                    total[i] += marks[i][j];  // Add to subject total
                }
            }
        }
        overallTotal += total[i];  // Add to overall total
    }

    // Calculate and display the average for each subject
    printf("\nAverage marks per subject:\n");
    for (int i = 0; i < SUBJECTS; i++) {
        printf("%s: %.2f\n", subjectNames[i], total[i] / TESTS);
    }

    // Calculate and display overall average
    printf("\nOverall average: %.2f\n", overallTotal / (SUBJECTS * TESTS));

    return 0;
}