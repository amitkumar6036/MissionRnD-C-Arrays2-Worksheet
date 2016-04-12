/*
OVERVIEW: Given an array where every element occurs three times, except one element which occurs only
once. Find the element that occurs once.
E.g.: Input: arr = 12, 1, 12, 3, 12, 1, 1, 2, 3, 3
ouput: 2

INPUTS: Integer array and length of the array.

OUTPUT: Element that occurs only once.

ERROR CASES: Return -1 for invalid inputs.

NOTES:
There are better ways of solving the problem than a brute-force solution which is of O(n^2)
complexity .
*/

int findSingleOccurenceNumber(int *A, int len) {
	int elem, i, ones=0,twos=0,notThrees=0;

	if (A == nullptr || len <= 0)
		return -1;

	for (i = 0; i < len; i++){
		twos |= (ones&A[i]);
		ones ^= A[i];
		notThrees = ~(ones&twos);
		ones &= notThrees;
		twos &= notThrees;
	}

	return ones;
}