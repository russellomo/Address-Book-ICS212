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
 * FILE: pro1func.c
 *
 * DESCRIPTION: This file contains the database functions required
 * for project 1
 *
 *****************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "p1head.h"
extern int debugmode;

/*****************************************************************
 *
 * Function name: addRecord
 *
 * DESCRIPTION: A database function which adds records to a list
 *
 * Parameters: pstart (struct record **) : pointer to pointer to beginning
 * of the list
 * uname (char []) : the name entered by the user
 * uadd (char []) : the address entered by the user
 * udate (int) : the year of birth entered by the user
 * utelno (char []) : the telno entered by the user
 *
 * Return values: 1 : sucessful addition
 *
 *****************************************************************/
int addRecord(struct record ** pstart, char uname[], char uadd[], int udate, char utelno[])
{

	struct record * new, * temp;
	new = (struct record *) malloc(sizeof(struct record));
	strcpy(new->name, uname);
	strcpy(new->address, uadd);
	strcpy(new->telno, utelno);
	new->yearofbirth = udate;
	new->next = NULL;

	if(*pstart == NULL)
	{
		*pstart = new;
	}
	else
	{
		temp = *pstart;
		while(temp->next!= NULL)
		{
			temp = temp->next;
		}

		temp->next = new;
	}
	if(debugmode == 1)
	{
		printf("-------DEBUGMODE--------\n");
		printf("Function = addRecord\n");
		printf("pstart = %p\n", pstart);
		printf("name = %s\n", uname);
		printf("add = %s\n", uadd);
		printf("date = %d\n", udate);
		printf("telnum = %s\n", utelno);
		printf("-------DEBUGMODE--------\n");
	}
	return 0;
}
/*****************************************************************
 *
 * Function name: printRecord
 *
 * DESCRIPTION: A data base function which prints specified
 * records
 *
 * Parameters: start (struct record *) : pointer to beginning of
 * the list
 * uname (char []) : name entered by the user
 *
 * Return values: 0 : no such records to print
 * 1 : records have been found to print
 *
 *****************************************************************/
int printRecord(struct record * start, char uname[])
{
	int ret;
	struct record * temp;
	temp = start;
	ret = 0;

	if(temp == NULL)
	{
		return ret;
	}

	printf("-------------\n");

	while(temp != NULL)
	{
		if(strcmp(temp->name, uname) == 0)
		{
			printf("Name : %s\n", temp->name);
			printf("Address : %s\n", temp->address);
			printf("Year of Birth : %d\n", temp->yearofbirth);
			printf("Telephone : %s\n", temp->telno);
			printf("-------------\n");
			ret = 1;
		}
		temp = temp->next;
	}
	if(debugmode == 1)
	{
		printf("-------DEBUGMODE--------\n");
		printf("Function = printRecord\n");
		printf("Start : %p\n", start);
		printf("name = %s", uname);
		printf("-------DEBUGMODE--------\n");
	}
	return ret;
}

/*****************************************************************
 *
 * Function name: modifyRecord
 *
 * DESCRIPTION: A database function that modifies records specified by the
 * name entered by the user.
 *
 * Parameters: start (struct record *) : pointer to the start of the list
 * uname (char []) : the name entered by the user
 * uadd (char []) : the new address to set
 * utelno (char []) : the new telno to set
 *
 * Return values: 1 : successful modification
 * 0 : no such records to modify;
 *
 *****************************************************************/
int modifyRecord(struct record * start, char uname[], char uadd[], char utelno[])
{
	int ret;
	struct record * temp;
	temp = start;
	ret = 0;

	if(debugmode == 1)
	{
		printf("-------DEBUGMODE--------\n");
		printf("Function = modifyRecord\n");
		printf("start = %p", start);
		printf("name = %s\n", uname);
		printf("add = %s\n", uadd);
		printf("telnum = %s\n", utelno);
		printf("-------DEBUGMODE--------\n");

	}

	if(temp == NULL)
	{
		return ret;
	}

	while(temp != NULL)
	{
		if(strcmp(temp->name, uname) == 0)
		{
			strcpy(temp->address, uadd);
			strcpy(temp->telno, utelno);
			ret = 1;
		}

		temp = temp->next;
		}

	return ret;
}
/*****************************************************************
 *
 * Function name: printAllRecords
 *
 * DESCRIPTION: A database function that prints all of the current
 * records;
 *
 * Parameters: start (struct record *) : Pointer to the start of the
 * list
 *
 * Return values: void
 *
 *****************************************************************/
void printAllRecords(struct record * start)
{
	struct record * temp;
	temp = start;

	printf("-------------\n");
	while(temp != NULL)
	{
		printf("Name : %s\n", temp->name);
		printf("Address : %s\n", temp->address);
		printf("Year of Birth: %d\n", temp->yearofbirth);
		printf("Telephone : %s\n", temp->telno);
		printf("-------------\n");
		temp = temp->next;
	}

	if(debugmode == 1)
	{
		printf("-------DEBUGMODE--------\n");
		printf("Function = printAllRecords\n");
		printf("Start : %p\n", start);
		printf("-------DEBUGMODE--------\n");
	}

}
/*****************************************************************
 *
 * Function name: deleteRecord
 *
 * DESCRIPTION: A database function which deletes records
 * specified by the name the user entered
 *
 * Parameters: pstart (struct record **) : The pointer to the pointer
 * of the beginning of the list
 * uname (char []) : the name entered by the user
 *
 * Return values: 1 : successful deletion
 * 0 : no such records to be deleted
 *
 *****************************************************************/
int deleteRecord(struct record ** pstart, char uname[])
{
	struct record * curr, * prev, * temp;
	int ret = 0;

	if(*pstart == NULL)
	{
		return ret;
	}

	curr = *pstart;
	prev = NULL;

	while(curr != NULL)
	{
		if(strcmp(uname, curr->name) == 0)
		{
			ret = 1;
			if(prev == NULL)
			{
				temp = curr;
				curr = curr->next;
				*pstart = curr;
				free(temp);
			}
			else
			{
				temp = curr;
				prev->next = curr->next;
				curr = prev->next;
				free(temp);
			}
		}
		else
		{
		prev = curr;
		curr = curr->next;
		}
	}


	if(debugmode == 1)
	{
		printf("-------DEBUGMODE--------\n");
		printf("Function = deleteRecord\n");
		printf("pstart = %p\n", pstart);
		printf("name = %s\n", uname);
		printf("-------DEBUGMODE--------\n");

	}
		return ret;
}
/*****************************************************************
 *
 * Function name: readfile
 *
 * DESCRIPTION: A database function which reads from a file
 * into the list
 *
 * Parameters: pstart (struct record **) : Pointer to the pointer
 * of the start of the list
 * filename (char []) : Name of the file to be read
 *
 * Return values: 1 : success
 * 0 : no such file found
 *
 *****************************************************************/
int readfile(struct record ** pstart, char filename[])
{

	char name[25], add[80], tel[15];
	int yob;
	FILE *infile = fopen(filename, "r");


	if(infile == NULL)
	{
		return 0;
	}

	while(1)
	{

		if(feof(infile))
		{
			break;
		}
		else
		{

			if(fgets(name, 25, infile) != NULL)
			{
    		strtok(name, "\n");
				getAddress(add, 80, infile);
				fgetc(infile);
				fscanf(infile, "%d ", &yob);
				fgets(tel, 15, infile);
				strtok(tel, "\n");


				addRecord(pstart, name, add, yob, tel);


			}
		}
	}

	fclose(infile);

	if(debugmode == 1)
	{
		printf("-------DEBUGMODE--------\n");
		printf("Function = readfile\n");
		printf("pstart = %p\n", pstart);
		printf("filename = %s\n", filename);
		printf("-------DEBUGMODE--------\n");

	}
	return 1;
}
/*****************************************************************
 *
 * Function name: writefile
 *
 * DESCRIPTION: A database function which writes the entire list into a file
 *
 * Parameters: start (struct record *) : the pointer to the start of the list
 * filename (char []) : the name of the file to write to
 *
 * Return values: void
 *
 *****************************************************************/
void writefile(struct record *start, char filename[])
{
	struct record *temp;
	FILE *outfile = fopen(filename, "w");
	temp = start;
	while(temp != NULL)
	{
		fprintf(outfile, "%s\n", temp->name);
		fprintf(outfile, "%s\n", temp->address);
		fprintf(outfile, "%d\n", temp->yearofbirth);
		fprintf(outfile, "%s\n", temp->telno);
		temp = temp->next;
	}

	if(debugmode == 1)
	{
		printf("-------DEBUGMODE--------\n");
		printf("Function = writefile\n");
		printf("start = %p\n", start);
		printf("filename = %s\n", filename);
		printf("-------DEBUGMODE--------\n");

	}
	fclose(outfile);
}
/*****************************************************************
 *
 * Function name: cleanup
 *
 * DESCRIPTION: A database function which destroys the entire list
 *
 * Parameters: pstart (struct record **) : Pointer to the pointer to
 * start of the list
 *
 * Return values: void
 *
 *****************************************************************/
void cleanup(struct record ** pstart)
{
	struct record * curr, * next;
	curr = *pstart;

	while(curr != NULL)
	{
		next = curr->next;
		free(curr);
		curr = next;
	}

	*pstart = NULL;

	if(debugmode == 1)
	{
		printf("-------DEBUGMODE--------\n");
		printf("Function = cleanup\n");
		printf("start = %p\n", pstart);
		printf("-------DEBUGMODE--------\n");

	}

}
