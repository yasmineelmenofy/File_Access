#include "file_acess.h"
#include <stdio.h>
#include "struct.h"
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
void DFF_vCreateStudentRecordsFile(const char *filename_studentrecord) {
    FILE *file = fopen(filename_studentrecord, "a");
    if (file != NULL) {
        fseek(file, 0, SEEK_END);
        long size = ftell(file);
        if (size == 0) {
            fprintf(file, "ID,Name,Course,GPA\n");
        }
        fclose(file);
    } else {
        printf("Error: Unable to create student records file %s\n", filename_studentrecord);
    }
}
/*
 * Use this function to create a file to record admin usernames and passwords.
 */
void DFF_vCreateAdminPasswordsFile(const char *filename_password) {
    FILE *file = fopen(filename_password, "a");
    if (file != NULL) {
        fclose(file);
    } else {
        printf("Error: Unable to create admin passwords file %s\n", filename_password);
    }
}
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
        int ch;
        while ((ch = getc(file)) != EOF) {
            putchar(ch);
        }
        fclose(file);
    } else {
        printf("Error: Unable to open student records file %s\n", filename_studentrecord);
    }
}

/*
 * Use this function to read and display admin usernames and passwords from the file.
 */
void DFF_vReadAdminPasswords(const char *filename_password) {
    FILE *file = fopen(filename_password, "r");
    if (file != NULL) {
        printf("Admin Passwords:\n");
        char username[50], password[50];
        while (fscanf(file, "%[^,],%s\n", username, password) != EOF) {
            printf("Username: %s\tPassword: %s\n", username, password);
        }
        fclose(file);
    } else {
        printf("Error: Unable to open admin passwords file %s\n", filename_password);
    }
}



