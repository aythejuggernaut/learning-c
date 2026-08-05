#include <stdio.h>

#define STUDENTS 5
#define QUIZZES 5

int main(void) {
    int grades[STUDENTS][QUIZZES];

    for (int i = 0; i < STUDENTS; i++) {
        printf("Enter five quiz grades for student %d: ", i + 1);
        for (int j = 0; j < QUIZZES; j++) {
            scanf("%d", &grades[i][j]);
        }
    }

    /* Students total and average */
    printf("\nStudent Results\n");
    for (int i = 0; i < STUDENTS; i++) {
        int total = 0;
        for (int j = 0; j < QUIZZES; j++) {
            total += grades[i][j];
        }

        double average = (double)total / QUIZZES;
        printf("Student %d: Total = %d, Average = %.2f\n", i + 1, total, average);
    }

    printf("\nQuiz Results\n");
    for (int j = 0; j < QUIZZES; j++) {
        int total = 0;
        int high = grades[0][j];
        int low = grades[0][j];
        for (int i = 0; i < STUDENTS; i++) {
            int score = grades[i][j];

            if (score > high)
                high = score;
            
            if (score < low)
                low = score;

            total += score;
        }

        double average = (double)total / STUDENTS;
        printf("Quiz %d: Average = %.2f, High = %d, Low = %d\n", j + 1, average, high, low);
    }


/* TEST DATA */
// 87 76 68 37 58
// 68 76 57 87 67
// 89 78 89 86 97
// 76 78 98 87 65
// 78 65 68 76 85

    return 0;
}

