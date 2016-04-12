/*
OVERVIEW: You are given a bank statement where transactions are ordered by date. Write a function that finds the number of transactions in that statement after a given date.
-- find the count of numbers greater than a given number in a sorted array.
E.g.: Input: A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
date = "19-10-2004"
Output: 1 (as there is only one transaction { 30, "03-03-2005", "Third" })

INPUTS: One bank statement (array of transactions) and date.

OUTPUT: Return the number of transactions in that statement after a given date.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

struct transaction {
	int amount;
	char date[11];
	char description[20];
};



int comparestr(char *str1, char *str2,int len){
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


int compareDates(char *str1, char *str2){
	int year,month,day;
	
	year = comparestr(str1 + 6, str2 + 6, 4);
	month = comparestr(str1 + 3, str2 + 3, 2);
	day = comparestr(str1, str2, 2);
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



int countGreaterNumbers(struct transaction *Arr, int len, char *date) {

	int matches = 0,i,j;

	if (Arr == nullptr || date == nullptr|| len <= 0)
		return -1;

	for (i = 0; i < len; i++)
		if (compareDates(Arr[i].date, date) > 0)
			matches++;

	return matches;

}
