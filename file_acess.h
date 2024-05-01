#ifndef FILE_ACESS_H_INCLUDED
#define FILE_ACESS_H_INCLUDED
#include "struct.h"
/*
 * FILE: file_acess.h
 * AUTHOR: Yasmine Elmenofy
 * BRIEF: Header file for the File Access Module that
 *contain function prototypes
 * DATA: 27/04/2024
 */


void DFF_vWriteStudentRecord(const char *filename, const StudentRecord *record);
void DFF_vWriteAdminPassword(const char *filename, const AdminPassword *admin);
void DFF_vReadStudentRecords(const char *filename);
void DFF_vReadAdminPasswords(const char *filename);

#endif
