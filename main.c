#include <stdio.h>
#include <string.h>
#include "file_acess.h"
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
                {
                    printf("Enter student ID: ");
                    int id;
                    scanf("%d", &id);
                    getchar();
                    printf("Enter student name: ");
                    char name[50];
                    scanf(" %[^\n]", name);
                    printf("Enter student course: ");
                    char course[50];
                    scanf(" %[^\n]", course);
                    printf("Enter student GPA: ");
                    float gpa;
                    scanf("%f", &gpa);
                    StudentRecord newStudent = {id, "", "", 0.0};
                    strncpy(newStudent.name, name, sizeof(newStudent.name));
                    strncpy(newStudent.course, course, sizeof(newStudent.course));
                    newStudent.gpa = gpa;

                    DFF_vWriteStudentRecord(filename_studentrecord, &newStudent);
                    printf("Student record added successfully!\n");
                }
                break;
            case 2:
                {
                    printf("Enter admin username: ");
                    char username[50];
                    scanf("%s", username);

                    printf("Enter admin password: ");
                    char password[50];
                    scanf("%s", password);

                    AdminPassword newAdmin = {"", ""}; 
                    strncpy(newAdmin.username, username, sizeof(newAdmin.username));
                    strncpy(newAdmin.password, password, sizeof(newAdmin.password));

                    DFF_vWriteAdminPassword(filename_password, &newAdmin);
                    printf("Admin password added successfully!\n");
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




