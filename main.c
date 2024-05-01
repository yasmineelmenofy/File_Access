#include <stdio.h>
#include <string.h>
#include "file_acess.h"
#include "struct.h"

int main() {
    const char *filename_studentrecord = "Student.record.txt";
    const char *filename_password = "password.txt";

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
                   StudentRecord student;
    printf("Enter student ID: ");
    scanf("%d", &student.id);
    printf("Enter student name: ");
    scanf(" %[^\n]", student.name);
    printf("Enter student course: ");
    scanf(" %[^\n]", student.course);
    printf("Enter student GPA: ");
    scanf("%f", &student.gpa);

    DFF_vWriteStudentRecord(filename_studentrecord, &student);
}

                break;
            case 2:
                {
                     AdminPassword admin;
    printf("Enter admin username: ");
    scanf(" %[^\n]", admin.username);
    printf("Enter admin password: ");
    scanf(" %[^\n]", admin.password);


    DFF_vWriteAdminPassword(filename_password, &admin);
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
