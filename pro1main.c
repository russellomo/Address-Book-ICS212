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
 * FILE: pro1main.c
 *
 * DESCRIPTION: This file contains the user interface functions
 * for the project 1 address book.
 *
 *****************************************************************/
#include <stdio.h>
#include <string.h>
#include "p1head.h"
int debugmode = 0;


int main(int argc, char* argv[])
{

	int run;
	int input, num, age;
	char name[25], add[80], tel[15];
	char clear [20];
	struct record * start = NULL;
	run = 1;

	if(argc > 2)
	{
		printf("pro1: Excessive Arguments (%d)\n", argc - 1);
		run = 0;
		return 0;
	}
	else if(argc == 2)
	{
		if(strcmp(argv[1], "debug") == 0)
		{
			printf("Entering Debug mode\n");
			debugmode = 1;
		}
		else
		{
			printf("pro1: Unrecognized argument (%d)\n", argc - 1);
			run = 0;
			return 0; 
		}
	}

	if(readfile(&start, "save.txt") == 1)
	{
		printf("Save data found, resuming from last session...\n");
	}

	printf("Welcome. Please enter a value from the menu below\n");
	printf("*************************************************\n");

	while(run)
	{
		printf("===========================\n");
		printf("1 Add new record\n");
		printf("2 Modify record (Requires Name as key)\n");
		printf("3 Print information from record (Requires name as key)\n");
		printf("4 Print all information in database\n");
		printf("5 Delete an existing record (Requires name as key)\n");
		printf("0 Exit program\n");
		printf("===========================\n");

		input = scanf("%d", &num);
		getchar();

		if(input != 1)
		{
			printf("error, not valid value\n");

			fgets(clear, 20, stdin);
		}

		if(num == 1)
		{
			printf("Please enter a name and press ENTER\n");
			fgets(name, 20, stdin);
			strtok(name, "\n");
			printf("Please enter the person's year of birth and press ENTER\n");
			scanf("%d", &age);
			getchar();
			printf("Please enter an address. End with '~' when finished\n");
			getAddress(add, 80, stdin);
			getchar();
			printf("Lastly, please enter the person's telephone number and press ENTER\n");
			fgets(tel, 15, stdin);
			strtok(tel, "\n");

			addRecord(&start, name, add, age, tel);

			printf("Record added!\n");
		}
		else if(num == 2)
		{
			printf("Please enter the name of the person's address you wish to modify'\n");
			fgets(name, 20, stdin);
			strtok(name, "\n");

			printf("Please enter a new address. End with '~' when finished\n");
			getAddress(add, 80, stdin);
			getchar();

			printf("Please enter a new phone number.\n");
			fgets(tel, 15, stdin);
			strtok(tel, "\n");


			if(modifyRecord(start, name, add, tel) == 1)
			{
				printf("Modification Sucessful.\n");
			}
			else
			{
				printf("No such record to modify\n");
			}
		}
		else if(num == 3)
		{
			printf("Please type the name of the person whose information you want printed\n");
			fgets(name, 20, stdin);
			strtok(name, "\n");
			printRecord(start, name);
		}
		else if(num == 4)
		{
			printAllRecords(start);
		}
		else if(num == 5)
		{
			printf("Please enter the name of the person whose entry you wish to delete\n");
			fgets(name, 20, stdin);
			strtok(name, "\n");

			if(deleteRecord(&start, name) == 1)
			{
				printf("Deletion Sucessful\n");
			}
			else
			{
				printf("No such records to delete.\n");
			}
		}
		else if(num == 0)
		{
			printf("Exit\n");
			writefile(start, "save.txt");
			cleanup(&start);
			run = 0;
		}

	}
 return 0;
}
/*****************************************************************
 *
 * Function name: getAddress
 *
 * DESCRIPTION: A user interface function which reads all characters
 * execpt for the special character '~'
 *
 * Parameters: add (char []) : the array to store the address
 * stream (FILE *) : the input stream to read from
 *
 * Return values: 0 : void
 *
 *****************************************************************/
void getAddress(char add[], int size, FILE *stream)
{
	char c;
	int i = 0;

	while(1)
	{
		c = fgetc(stream);
		if(c == '~')
		{
			break;
		}
		else
		{
			add[i] = c;
			i++;
		}
	}
	add[i] = '~';
	i++;
	add[i] = '\0';

	if(debugmode == 1)
	{
		printf("-------DEBUGMODE--------\n");
		printf("Function = getAddress\n");
		printf("add = %p\n", add);
		printf("size = %d\n", size);
		printf("stream = %p\n", stream);
		printf("-------DEBUGMODE--------\n");
	}
}
