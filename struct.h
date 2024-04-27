#ifndef STRUCT_H_INCLUDED
#define STRUCT_H_INCLUDED

typedef struct {
    int id;
    char name[50];
    char course[50];
    float gpa;
} StudentRecord;

typedef struct {
    char username[50];
    char password[50];
} AdminPassword;

#endif
