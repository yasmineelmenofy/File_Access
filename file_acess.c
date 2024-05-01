#include "file_acess.h"
#include <stdio.h>
#include "struct.h"
#define MAX_STUDENTS 100
#define MAX_FIELD_LENGTH 100
#define MAX_ADMIN 100
#define MAX_USERNAME_LENGTH 50
#define MAX_PASSWORD_LENGTH 50

/*
 * FILE: file_acess.c
 * AUTHOR: Yasmine Elmenofy
 * BRIEF: This section of the project handles file operations related to student records and admin passwords.
 *        The functions provided here allow for creating, reading, and writing data to files
 * DATA: 27/04/2024
 */

/*
 * Use this function to create a file for student records. If the file is created, it will open it.
 * ID, name, course, and GPA will be written as header in the file the first time the file is created only.
 */
/*
 * Use this function to record the information about a student in the file.
 */
void DFF_vWriteStudentRecord(const char *filename_studentrecord, const StudentRecord *record) {
    FILE *file = fopen(filename_studentrecord, "a");
    if (file != NULL) {
        fprintf(file, "%d,%s,%s,%.2f\n", record->id, record->name, record->course, record->gpa);
        fclose(file);
    } else {
        printf("Error: Unable to open student records file %s\n", filename_studentrecord);
    }
}
/*
 * Use this function to record an admin username and password in the file.
 */
void DFF_vWriteAdminPassword(const char *filename_password, const AdminPassword *admin) {
    FILE *file = fopen(filename_password, "a");
    if (file != NULL) {
        fprintf(file, "%s,%s\n", admin->username, admin->password);
        fclose(file);
    } else {
        printf("Error: Unable to open admin passwords file %s\n", filename_password);
    }
}
/*
 * Use this function to read and display student records from the file.
 */
void DFF_vReadStudentRecords(const char *filename_studentrecord) {
    FILE *file = fopen(filename_studentrecord, "r");
    if (file != NULL) {
        printf("Student Records:\n");
        char records[MAX_STUDENTS][MAX_FIELD_LENGTH];
        int row = 0;
        int col = 0;
        int ch;
        while ((ch = getc(file)) != EOF && row < MAX_STUDENTS) {
            if (ch == ',' || ch == '\n') {
                records[row][col] = '\0'; // Null-terminate the string
                row++; // Move to the next row
                col = 0; // Reset column index
            } else {
                records[row][col] = ch;
                col++; // Move to the next column
            }
        }
        fclose(file);
        for (int i = 0; i < row; i++) {
            printf("%s\n", records[i]);
        }
    } else {
        printf("Error: Unable to open student records file %s\n", filename_studentrecord);
    }
}

void DFF_vReadAdminPasswords(const char *filename_password) {
    FILE *file = fopen(filename_password, "r");
    if (file != NULL) {
        printf("Admin Passwords:\n");
        char usernames[MAX_ADMIN][MAX_USERNAME_LENGTH];
        char passwords[MAX_ADMIN][MAX_PASSWORD_LENGTH];
        int count = 0;
        while (count < MAX_ADMIN && fscanf(file, "%[^,],%s\n", usernames[count], passwords[count]) == 2) {
            count++;
        }
        fclose(file);


        for (int i = 0; i < count; i++) {
            printf("Username: %s\tPassword: %s\n", usernames[i], passwords[i]);
        }
    } else {
        printf("Error: Unable to open admin passwords file %s\n", filename_password);
    }
}




