#include "pch.h"

#include <iostream>

#include <algorithm>	/* To compare some of my funtions to STL functions */

#include <vector>
#include <list>
#include <string>

/*
Swap the minimum and maximum element in an interger array
What is the advantage and disavantage of making four functions with different 
objectives?
*/
auto getMinIndex(const std::vector<int>& vec) {
	if (vec.empty()) return -1;
	auto minIndex = 0;
	for (auto i = 0; i < vec.size(); ++i)
		if (vec[i] < vec[minIndex])
			minIndex = i;
	return minIndex;
}
auto getMaxIndex(const std::vector<int>& vec) {
	if (vec.empty()) return -1;
	auto maxIndex = 0;
	for (auto i = 0; i < vec.size(); ++i)
		if (vec[i] > vec[maxIndex])
			maxIndex = i;
	return maxIndex;
}
auto swap(std::vector<int>& vec, int m, int n) {
	if (m < 0 || n < 0) return;
	auto temp = vec[m];
	vec[m] = vec[n];
	vec[n] = temp;
}
auto swapMinMax(std::vector<int>& vec) {
	auto minIndex = getMinIndex(vec);
	auto maxIndex = getMaxIndex(vec);
	swap(vec, minIndex, maxIndex);
}

/*
Determine of a string has all unique characters
What is the difference between the ASCII and Unicode string?
*/
auto isUniqueChars(const std::string& s) {
	/* Suppose dealing with an ASCII string where each character 
	is encoded by one byte */
	if (s.size() > 256) return false;

	/* Use an array to track the presence of characters */
	bool isPresent[256]{false};
	for (auto i = 0; i < s.size(); ++i) {
		if (isPresent[s.at(i)])
			return false;
		else isPresent[s.at(i)] = true;
	}

	return true;	/* No duppliation */
}

/*
Reverse a null-terminated string
How can you do it using STL?
Answer: char s[] = "My string"; std::reverse(&s[0], &s[9]);
*/
auto reverse(char* s) {
	/* Find the end of the string */
	char *end = s;
	if (s) {
		while (*end)	/* end points to '\0' */
			++end;
		--end;			/* end points to the character before '\0' */

		/* Swap the start and the end of the string
		then increase start by 1 and decrease end by 1 */
		char *start = s;
		char temp;
		while (start < end) {
			temp = *start;
			*start++ = *end;
			*end-- = temp;
		}
	}
}


/*
Check if a string is a permutation of the other
Is it case sensitive, is the space counts?
*/
/* Sort then compare */
auto sort(std::string& s) {
	std::sort(s.begin(), s.end());
}
auto permuatation_sorted(const std::string& s1, const std::string& s2) {
	return s1 == s2;
}
/* Create an array which counts all letters */
auto permutation(const std::string& s1, const std::string& s2) {
	int letters[256]{};		// assume ASCII decode
	
	if (s1.size() != s2.size())
		return false;

	/* count letters in the s1 */
	for (auto i = 0; i < s1.size(); ++i)
		++letters[s1.at(i)];

	/* check letters in the s2 */
	for (auto i = 0; i < s2.size(); ++i)
		if (letters[s2.at(i)]-- == 0)
			return false;

	return true;	/* s2 is a permutation of s1 */
}

/*
Replace all space character in a string by %20
Mr John Smith to Mr%20John%20Smith
Have I do this operation in place?
What is the problem with this code for (int i = size - 1; i >= 0; --i) ?
*/
/* Count string size then replace ' ' by "%20" from the end */
auto replaceSpaces(std::string& s) {
	auto spaceCount = 0;
	const auto size = s.size();
	for (auto i = 0; i < size; ++i)
		if (s.at(i) == ' ')
			++spaceCount;
	const auto newSize = size + spaceCount * 2;
	
	auto end = std::string(newSize - size, '?');
	s.append(end);
	auto pos = newSize - 1;
	for (int i = size - 1; i >= 0; --i)
		if (s.at(i) == ' ') {
			s.at(pos--) = '0';
			s.at(pos--) = '2';
			s.at(pos--) = '%';
		}
		else
			s.at(pos--) = s.at(i);
}


/*
Compress a string and return the compressed string only if it is shorter
aabccccaaa to a2b1c4a3
How about the time complexity if the string is long and not compressible? 
Hint: critical operation myCompress.append(temp);
*/
auto compress(const std::string& s) {
	std::string myCompress{};
	char letter;
	auto count = 0;		/* count of repeated characters */
	for (auto i = 0; i < s.size(); ++i) {
		if (i == 0)
			letter = s.at(i);

		if (s.at(i) == letter)
			++count;
		else {
			/* write the old letter and count to myCompress, 
			increase size by the number of written characters */
			auto temp = letter + std::to_string(count);
			myCompress.append(temp);
			
			/* restart the count on this new letter */
			letter = s.at(i);
			count = 1;
		}

		if (i == s.size() - 1) {
			auto temp = letter + std::to_string(count);
			myCompress.append(temp);
		}
	}

	/* return myCompress if its size is smaller than the size of s */
	if (myCompress.size() < s.size())
		return myCompress;
	else
		return s;
}
/* Check if the string is compressible before creating compressed string */
auto compressSize(const std::string& s) {
	char letter;
	auto newSize = 0;
	for (auto i = 0; i < s.size(); ++i) {
		if (i == 0)
			letter = s.at(i);
		if (s.at(i) != letter) {
			newSize += 2;
			letter = s.at(i);
		}
		if (i == s.size() - 1)
			newSize += 2;
	}
	return newSize;
}
auto compressSafe(const std::string& s) {
	/* Check if the string is compressible */
	auto newSize = compressSize(s);
	if (newSize >= s.size())
		return s;
	
	/* Compress the string */
	std::string myCompress(newSize, ' ');
	char letter;
	auto count = 0;		/* count of repeated characters */
	auto posNext = 0;	/* next position to write */
	for (auto i = 0; i < s.size(); ++i) {
		if (i == 0)
			letter = s.at(i);

		if (s.at(i) == letter)
			++count;
		else {
			/* write the old letter and count to myCompress,
			increase size by the number of written characters */
			auto temp = letter + std::to_string(count);
			myCompress.insert(posNext, temp);

			/* restart the count on this new letter */
			letter = s.at(i);
			posNext += 2;
			count = 1;
		}

		if (i == s.size() - 1) {
			auto temp = letter + std::to_string(count);
			if (posNext + 2 == newSize)		// second check
				myCompress.insert(posNext, temp);
			else
				return s;
		}
	}

	return myCompress;
}

/*
Given an image represented by an NxN matrix, where each pixel in the image is 4 bytes,
write a method to rotate the image by 90 degree, do it also in place
*/
auto rotate(int **matrix, int N) {
	for (auto layer = 0; layer < (int) N / 2; ++layer) {
		auto last = N - 1 - layer;
		for (auto i = layer; i < last; ++i) {
			auto offset = i - layer;
			// save top
			auto top = matrix[layer][i];

			// left to top
			matrix[layer][i] = matrix[last - i][layer];

			// bottom to left
			matrix[last - i][layer] = matrix[last][last - offset];

			// right to bottom
			matrix[last][last - offset] = matrix[i][last];

			// top to right
			matrix[i][last] = top;
		}
	} 
}
auto print(int **matrix, int rows, int cols) {
	for (auto r = 0; r < rows; ++r) {
		for (auto c = 0; c < cols - 1; ++c)
			std::cout << matrix[r][c] << " ";
		std::cout << matrix[r][cols-1] << std::endl;
	}
}
auto assign(int **matrix, int rows, int cols) {
	for (auto r = 0; r < rows; ++r)
		for (auto c = 0; c < cols; ++c)
			matrix[r][c] = r * 4 + c;
}
auto create(int rows, int cols) {
	int** matrix = new int*[rows];
	for (int r = 0; r < rows; ++r)
		matrix[r] = new int[cols];
	return matrix;
}
auto free(int **matrix, int rows) {
	for (int r = 0; r < rows; ++r)
		delete matrix[r];
}

class Node {
public:
	Node* _next = nullptr;
	int _data;
public:
	Node(int data) : _data(data) {}
};
Node* append(Node* node, int data) {
	/* node can be a head or another node in the list
	   optimal way: node is the last node */
	Node* end = new Node(data);
	while (node->_next != nullptr)
		node = node->_next;
	node->_next = end;
	return end;
}
Node* append(Node* end, Node* aHead) {
	if (aHead != nullptr) {
		end->_next = aHead;
		return aHead;
	}
	else
		return end;
}
auto display(Node* head) {
	std::cout << head->_data << " ";
	Node* node = head;
	while (node->_next != nullptr) {
		node = node->_next;
		std::cout << node->_data << " ";
	}
	std::cout << std::endl;
}
/*
Access the kth to last element of a singly linked list
What are the other methods using only one pointer?
Traverse the linked list by two pointers, who are k elements one to another.
So, when one arrives to the last element, the other is the kth to last.
*/
Node* kthToLast(Node* head, unsigned int k) {
	auto node = head;
	auto nodeFast = head;

	/* Move nodeFast by k elements */
	for (auto i = 0; i < k; ++i)
		if (nodeFast->_next != nullptr)
			nodeFast = nodeFast->_next;
		else 
			return nullptr;	// list has less than k + 1 elements

	/* Move both node and nodeFast */
	while (nodeFast->_next != nullptr) {
		node = node->_next;
		nodeFast = nodeFast->_next;
	}

	return node;
}

/*
Delele a node in the middle of a single linked list, 
given only access to that node
Copy the next node to the given node then delete the next node
*/
auto deleteNode(Node* node) {
	if (node == nullptr || node->_next == nullptr)
		return false;	// Can't delete this node
	else {				// Delete this node
		auto next = node->_next;
		node->_data = next->_data;
		node->_next = next->_next;
		delete next;
		return true;
	}
}

/*
Partition a linked list around a value x
Iterate through the list, insert elements into a smaller and bigger list
in function of its value
*/
Node* partition(Node* head, int x) {
	Node* smallerStart = nullptr;
	Node* smallerEnd = nullptr;
	Node* biggerStart = nullptr;
	Node* biggerEnd = nullptr;

	auto node = head;
	while (node != nullptr) {
		auto next = node->_next;
		node->_next = nullptr;
		if (node->_data < x) 	// insert into the smaller list
			if (smallerStart == nullptr) {
				smallerStart = node;
				smallerEnd = node;
			}
			else
				smallerEnd = append(smallerEnd, node);
		else 					// insert into the bigger list
			if (biggerStart == nullptr) {
				biggerStart = node;
				biggerEnd = node;
			}
			else
				biggerEnd = append(biggerEnd, node);

		node = next;
	}

	/* Merge the smaller and bigger lists */
	if (smallerStart == nullptr)
		return biggerStart;

	append(smallerEnd, biggerStart);
	return smallerStart;
}

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
auto binarySearch(std::vector<int>& a, int x) {
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
auto binarySearchRecursive(std::vector<int>& a, int x, int low, int high) {
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
	auto head = new Node(10);

	auto end = append(head, 11);
	end = append(head, 19);
	end = append(head, 15);
	end = append(head, 14);
	end = append(head, 8);
	end = append(head, 23);
	append(head, 27);

	display(head);	

	return 0;
}