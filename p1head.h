/*****************************************************************
 *
 * NAME: Russell Omo
 *
 * HOMEWORK: Project 1
 *
 * CLASS: ICS 212
 *
 * INSTRUCTOR: Ravi Narayan
 *
 * DATE: October 15, 2015
 *
 * FILE: p1head.h
 *
 * DESCRIPTION: This file contains all the prototypes for all functions
 * used in project 1.
 *
 *****************************************************************/
#include "record.h"
int addRecord (struct record **,char [],char [],int, char []);
int printRecord (struct record *, char []);
int modifyRecord (struct record *, char [],char [], char []);
void printAllRecords(struct record *);
int deleteRecord(struct record **, char []);
void cleanup(struct record **);
int readfile(struct record **, char []);
void writefile(struct record *, char []);
void getAddress(char [], int, FILE *);
