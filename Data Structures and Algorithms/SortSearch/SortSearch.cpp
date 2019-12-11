#include "pch.h"
#include <iostream>
#include <vector>

using namespace std;

/*
Swap the minimum and maximum element in an interger array
What is the advantage and disavantage of making four functions with different 
objectives?
*/
auto getMinIndex(const vector<int>& vec) {
	if (vec.empty()) return -1;
	auto minIndex = 0;
	for (auto i = 0; i < vec.size(); ++i)
		if (vec[i] < vec[minIndex])
			minIndex = i;
	return minIndex;
}
auto getMaxIndex(const vector<int>& vec) {
	if (vec.empty()) return -1;
	auto maxIndex = 0;
	for (auto i = 0; i < vec.size(); ++i)
		if (vec[i] > vec[maxIndex])
			maxIndex = i;
	return maxIndex;
}
auto swap(vector<int>& vec, int m, int n) {
	if (m < 0 || n < 0) return;
	auto temp = vec[m];
	vec[m] = vec[n];
	vec[n] = temp;
}
auto swapMinMax(vector<int>& vec) {
	auto minIndex = getMinIndex(vec);
	auto maxIndex = getMaxIndex(vec);
	swap(vec, minIndex, maxIndex);
}

/*
Determine of a string has all unique characters
*/

/*
Reverse a null-terminated string
*/

/*
Check if a string is a permutation of the other
*/

/*
Replace all space character in a string by %20
Mr John Smith to Mr%20John%20Smith
*/

/*
Compress a string and return the compressed string only if it is shorter
aabccccaaa to a2b1c5a3
*/

/*
Given an image represented by an NxN matrix, where each pixel in the image is 4 bytes,
write a method to rotate the image by 90 degree, do it also in place
*/

/*
Check if a string is the rotation of the other by using only one time the check
if a string is a substring of another
*/



int main()
{
	
}