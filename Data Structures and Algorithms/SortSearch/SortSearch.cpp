#include "pch.h"
#include <iostream>
#include <vector>
#include <list>

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

/*
Access the kth to last element of a singly linked list
What are the other methods using only one pointer?
*/

/*
Remove duplicates from un unsorted linked list
*/

/*
Delele a node in the middle of a single linked list, 
given only access to that node
*/

/*
Partition a linked list around a value x
*/

/*
Add two numbers represented by two linked list
*/

/*
Recover a corrupt linked list
A -> B -> C -> D -> E -> C to C
*/

/*
Check if a linked list is a palindrome
*/

/*
Solve the problem of the Towers of Hanoi using stacks
*/

/*
Sort the stack in acceding order (with biggest items on top)
using at most one additional stack to hold items, but not copy
items into array for example.
The stack supports push, pop, peek and isEmpty operations.
*/

/*
Iterate through nodes in a graph using Depth First Search (DFS)
and Breadth First Search (BFS)
Hint: Use queue to implement BFS
*/

/*
Check if there is a route between two nodes in a directed graph
Can you do it with decorator design pattern?
*/

/*
Implement Bubble Sort, Selection Sort, Merge Sort, Quick Sort and Radix Sort
*/

/*
Implement Binary Search with and without recursion
What is the space complexity of the recursive method?
*/
auto binarySearch(vector<int>& a, int x) {
	auto low = 0;
	auto high = a.size() - 1;
	auto mid = low;
	while (low <= high) {
		mid = (low + high) / 2;
		if (a[mid] < x) low = mid + 1;
		else if (a[mid] > x) high = mid - 1;
		else return mid;
	}
	return -1;	// not found
}
auto binarySearchRecursive(vector<int>& a, int x, int low, int high) {
	if (low > high) return -1;	// not found
	
	auto mid = (low + high) / 2;
	if (a[mid] < x)
		return binarySearchRecursive(a, x, mid + 1, high);
	else if (a[mid] > x)
		return binarySearchRecursive(a, x, low, mid - 1);
	else return mid;
}

int main()
{
}