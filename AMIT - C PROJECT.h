#ifndef AMIT_-_C_PROJECT_H_INCLUDED
#define AMIT_-_C_PROJECT_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include "STD_Types.h"
#define MAX_SIZE 10


 struct SDB
{
	uint8 Student_ID;
	uint8 Student_Year ;
	uint8 Courses[3];
	uint8 Courses_Grades[3];


}database[10];





// 1st Function: Check if the database is full //
Bool SDB_isFull(void);

// 2nd Function : Get the number of entries in the database //
uint8 SDB_GetUsedSize(void);

// 3rd Function :  Add new entry to the database //
Bool SDB_AddEntry(uint8 id, uint8 year, uint8* subjects, uint8* grades);

// 4th Function : Delete the entry with the given ID //
void SDB_DeleteEntry(uint8 id);

// 5th Function : Read an entry matching the provided Id //
Bool SDB_ReadEntry(uint8 id, uint8* year, uint8* subjects, uint8* grades);

// 6th Function : Get the list if IDs if the students //
void SDB_GetIdList(uint8* Count, uint8* List);

// 7th Function : Checks if the provided student ID exists //
Bool SDB_IsIdExist(uint8 ID);











#endif // AMIT_-_C_PROJECT_H_INCLUDED#pragma once
