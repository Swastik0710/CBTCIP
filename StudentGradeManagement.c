#include <stdio.h>
#include <string.h>

// Defining the maximum number of students and subjects
#define MAX_STUDENTS 100
#define MAX_SUBJECTS 12

// Creating the structure to store student's information
struct Student {
    char name[50];
    int scores[MAX_SUBJECTS];
    float average;
};

int main() {
    struct Student students[MAX_STUDENTS];
    int numStudents, numSubjects;

    printf("Enter the number of students: ");
    scanf("%d", &numStudents);
    printf("Enter the number of subjects: ");
    scanf("%d", &numSubjects);

    // Input student information
    for (int i = 0; i < numStudents; i++) {
        printf("Enter student %d's name: ", i + 1);
        scanf(" %[^\n]", students[i].name);

        printf("Enter scores for student %d:\n", i + 1);
        for (int j = 0; j < numSubjects; j++) {
            printf("Enter score for subject %d: ", j + 1);
            scanf("%d", &students[i].scores[j]);
        }
    }

    // Calculating average scores
    for (int i = 0; i < numStudents; i++) {
        int sum = 0;
        for (int j = 0; j < numSubjects; j++) {
            sum += students[i].scores[j];
        }
        students[i].average = (float)sum / numSubjects;
    }

    // Finding the highest and lowest scores
    int highestScore = students[0].scores[0], lowestScore = students[0].scores[0];
    char highestStudent[50], lowestStudent[50];
    strcpy(highestStudent, students[0].name);
    strcpy(lowestStudent, students[0].name);

    for (int i = 0; i < numStudents; i++) {
        for (int j = 0; j < numSubjects; j++) {
            if (students[i].scores[j] > highestScore) {
                highestScore = students[i].scores[j];
                strcpy(highestStudent, students[i].name);
            }
            if (students[i].scores[j] < lowestScore) {
                lowestScore = students[i].scores[j];
                strcpy(lowestStudent, students[i].name);
            }
        }
    }

    // Displaying student performance summary
    printf("\nStudent Performance Summary:\n");
    printf("------------------------------\n");
    printf("Highest Score: %d by %s\n", highestScore, highestStudent);
    printf("Lowest Score: %d by %s\n", lowestScore, lowestStudent);
    printf("\nStudent Wise Scores and Average:\n");
    printf("--------------------------------\n");
    for (int i = 0; i < numStudents; i++) {
        printf("Student: %s\n", students[i].name);
        printf("Scores: ");
        for (int j = 0; j < numSubjects; j++) {
            printf("%d ", students[i].scores[j]);
        }
        printf("\nAverage Score: %.2f\n", students[i].average);
        printf("\n");
    }

    return 0;
}