/*
OVERVIEW: You are given 2 bank statements that are ordered by date - 
Write a function that produces a single merged statement ordered by dates.
E.g.: Input: A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
B[2] = { { 10, "09-10-2003", "First" }, { 220, "18-01-2010", "Sixth" } };
Output: { { 10, "09-10-2003", "First" }, { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" },  30, "03-03-2005", "Third" }, { 220, "18-01-2010", "Sixth" } }

INPUTS: Two bank statements (array of transactions).

OUTPUT: Combined statement ordered by transaction date.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

#include <iostream>
#include<malloc.h>

struct transaction {
	int amount;
	char date[11];
	char description[20];
};


typedef struct transaction *sptr;

int compareStr(char *str1, char *str2,int len){
	int i;
	for (i = 0; i < len; i++){
		if (str1[i] == str2[i])
			continue;
		else{
			if (str1[i] < str2[i])
				return -1;
			else
				return 1;
		}
	}
	return 0;
}

int CompareDates(char *str1, char *str2){
	int day=0,month=0,year=0;

	year = compareStr(str1 + 6, str2 + 6, 4);
	month = compareStr(str1 + 3, str2 + 3, 2);
	day = compareStr(str1, str2, 2);

	if (year == 0){
		if (month == 0){
			if (day == 0)
				return 0;
			else{
				if (day < 0)
					return -1;
				else
					return 1;
			}
		}
		else{
			if (month < 0)
				return -1;
			else
				return 1;
		}
	}
	else{
		if (year < 0)
			return -1;
		else
			return 1;
	}

}



struct transaction * mergeSortedArrays(struct transaction *A, int ALen, struct transaction *B, int BLen) {

	int i, j, k;
	sptr ptr = NULL;

	
	if (A == NULL || ALen < 0|| B == NULL ||BLen < 0)
		return NULL;
	

	ptr = (sptr)malloc((ALen + BLen)*sizeof(struct transaction));
	
	i = j = k = 0;

	while (i <= ALen - 1 && j <= BLen - 1){

		if (CompareDates(A[i].date, B[j].date) == 0){
			ptr[k++] = A[i++];
			ptr[k++] = B[j++];
		}
		else{
			if (CompareDates(A[i].date, B[j].date) < 0)
				ptr[k++] = A[i++];
			else
				ptr[k++] = B[j++];
		}
	}
	while (i <= ALen - 1)
		ptr[k++] = A[i++];

	while (j <= BLen - 1)
		ptr[k++] = B[j++];

	return ptr;

}





