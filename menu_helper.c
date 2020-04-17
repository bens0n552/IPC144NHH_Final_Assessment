/* DIGITAL SIGNATURE(S):
   ====================

   List the student author(s) of this code below:

   Fullname                    Seneca Email Address
   --------------------------- ----------------------------
   1) Le Minh Nhat Dang        lmndang@myseneca.ca
   2)
   3)

   +--------------------------------------------------------+
   |                   FILE: main.c                         |
   +--------------------------------------------------------+
   |           2  0  2  0  ~  W  I  N  T  E  R              |
   |                 I  P  C  :  B  T  P                    |
   |                 1  4  4  :  1  0  0                    |
   |              FINAL ASSESSMENT PART - 2                 |
   |                                                        |
   |     S  E  N  E  C  A            C  O  L  L  E  G  E    |
   +--------------------------------------------------------+ */

#define _CRT_SECURE_NO_WARNINGS
#define SIZE 5000

#include "file_helper.h"
#include "menu_helper.h"

void clearKeyboard(void)
{
	while (getchar() != '\n');
	return;
}

int getInt(void)
{
	char NL = 'x';
	int value = 0;
	while (NL != '\n')
	{
		scanf("%d%c", &value, &NL);
		if (NL != '\n')
		{
			clearKeyboard();
			printf("*** INVALID INTEGER *** <Please enter an integer>: ");
			scanf("%d%c", &value, &NL);
		}
	}
	return value;
}

int getIntInRange(int min, int max)
{
	int number = 0;
	number = getInt();
	while (number < min || number > max)
	{
		printf("*** OUT OF RANGE *** <Enter a number between %d and %d>: ", min, max);
		number = getInt();
	}
	return number;
}

int menu(void)
{
	int option = 0;
	printf("What would you like to do?\n");
	printf("0 - Exit\n");
	printf("1 - Print top 3 riders in a category\n");
	printf("2 - Print all riders in a category\n");
	printf("3 - Print last 3 riders in a category\n");
	printf("4 - Print winners in all categories\n");
	printf(": ");
	option = getIntInRange(0, 4);
	return option;
}

void managerSystem(void)
{
	const char filename[] = "data.txt";
	struct RiderInfo info[SIZE] = { 0 };
	int result = 0;
	int i = 0;
	int stop = 0;
	int realSize = 0;

	int selection = 1;
	int flag = 1;

	/*---------------Load File data.txt---------------*/
	FILE* data = fopen(filename, "r");

	if (data == NULL)
	{
		printf("\nERROR: Unable to open the file for reading.\n");
		flag = 0;
	}
	else
	{
		for (i = 0; i < SIZE && stop == 0; i++)
		{
			result = readFileRecord(data, &info[i]);
			if (result == 1)
			{
				stop = 1;
				realSize = i;
			}
		}
		if (realSize == 1 && strlen(info[0].name) == 0)
		{
			printf("\nThe file data.txt is empty! Exiting the program...\n");
			flag = 0;
		}
	}

	/*---------------Display Menu And Call The Functions---------------*/
	while (flag != 0)
	{
		selection = menu();

		if (selection == 1)
		{
			printf("\nNot available\n");
			//findBestThreeRiders(info, realSize);
		}

		if (selection == 2)
		{
			printf("\nNot available\n");
			//displayAllRiders(info, realSize);
		}

		if (selection == 3)
		{
			printf("\nNot available\n");
			//findWorstThreeRiders(info, realSize);
		}

		if (selection == 4)
		{
			printf("\nNot available\n");
			//displayWinners(info, realSize);
		}

		if (selection == 0)
		{
			printf("\nKeep on Riding!\n");
			flag = 0;
		}
	}
	return;
}
