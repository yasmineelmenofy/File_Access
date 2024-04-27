#include "file_acess.h"
#include <stdio.h>
#include <string.h>
#include "struct.h"

int main() {
    const char *filename_studentrecord = "studentrecord.txt";
    const char *filename_password = "password.txt";

    DFF_vCreateStudentRecordsFile(filename_studentrecord);

    DFF_vCreateAdminPasswordsFile(filename_password);

    int choice;
    do {
        printf("\nChoose an option:\n");
        printf("1. Add student record\n");
        printf("2. Add admin password\n");
        printf("3. View student records\n");
        printf("4. View admin passwords\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter student ID: ");
                int id;
                scanf("%d", &id);
                getchar();

                printf("Enter student name: ");
                char name[50];
                scanf("%s", name);

                printf("Enter student course: ");
                char course[50];
                scanf("%s", course);

                printf("Enter student GPA: ");
                float gpa;
                scanf("%f", &gpa);

                StudentRecord newStudent = {id, name, course, gpa};
                if (!DFF_bIsDuplicateStudentRecord(filename_studentrecord, &newStudent)) {
                    DFF_vWriteStudentRecord(filename_studentrecord, &newStudent);
                    printf("Student record added successfully!\n");
                } else {
                    printf("Error: Student record already exists!\n");
                }
                break;
            case 2:
                printf("Enter admin username: ");
                char username[50];
                scanf("%s", username);

                printf("Enter admin password: ");
                char password[50];
                scanf("%s", password);
                if (!DFF_bIsDuplicateAdminPassword(filename_password, username)) {

                    DFF_vWriteAdminPassword(filename_password, &(AdminPassword){username, password});
                    printf("Admin password added successfully!\n");
                } else {
                    printf("Error: Admin password already exists!\n");
                }
                break;
            case 3:

                DFF_vReadStudentRecords(filename_studentrecord);
                break;
            case 4:

                DFF_vReadAdminPasswords(filename_password);
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Please enter a number between 1 and 5.\n");
                break;
        }
    } while (choice != 5);

    return 0;
}


