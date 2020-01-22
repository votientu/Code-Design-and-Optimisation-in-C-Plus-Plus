#include "pch.h"
#include <iostream>
#include <vector>
#include <string>
#include <cmath>

/*
Create a data structure to calculate:
A*x^a + B*x^b + C*x^c ...
where the coefficients and exponents can be any positive and negative real number
What are the other implementations?
*/
struct ExpressionTerm {
	double coefficient;
	double exponent;
};
auto sum(std::vector<ExpressionTerm> expr1, std::vector<ExpressionTerm> expr2) {}

/*
Convert a string number to number
"34" to 34
0b1000 to 8
0x30 to 48
How to compare two string numbers in different bases?
*/
auto digitToValue(const char& c) {
	if (c >= '0' && c <= '9') return c - '0';
	if (c >= 'A' && c <= 'F') return c - 'A' + 10;
	if (c >= 'a' && c <= 'f') return c - 'a' + 10;
	return -1;
}
auto convertToBase(std::string strNum, int base) {
	if (base < 2 || (base > 10 && base != 16)) return -1;
	auto value = 0;
	for (auto i = strNum.length(); i > 0; --i) {
		auto digit = digitToValue(strNum[i-1]);
		if (digit < 0 || digit > base) return -1;
		value += digit * (int) pow(base, strNum.length() - i);
	}
	return value;
}

/*
Implement a hash table using an array, a linked list and a binary tree
Insert an element in the hash table
What is the advantages and disavantages between theses implementations?
*/

/*
Compare hash table and STL map
If the number of inputs is small, which data structure options can be used
instead of a hash table?
*/

/*
Extend an array
*/

/*
Delete an element in a linked list
What does happen if we replace auto headNext = head->_next; head = headNext;
in the block if (head->_data == data)?
Hint: Suppose in the main we have
	auto* head = new Node(1);
	append(head, 2);
	deleteNode(head, 1);
	display(head);
*/
class Node {
public:
	Node* _next = nullptr;
	int _data;
public:
	Node(int data) : _data(data) {}
};
auto append(Node* head, int data) {
	Node* end = new Node(data);
	Node* node = head;
	while (node->_next != nullptr)
		node = node->_next;
	node->_next = end;
}
auto display(Node* head) {
	std::cout << head->_data << " ";
	Node* node = head;
	while (node->_next != nullptr) {
		node = node->_next;
		std::cout << node->_data << " ";
	}
}
auto deleteNode(Node* head, int data) {
	if (head->_data == data) {
		auto headNext = head->_next;
		head->_data = headNext->_data;
		head->_next = headNext->_next;
		delete headNext;
		return;
	}
	auto node = head;
	while (node->_next != nullptr) {
		if (node->_next->_data == data) {
			auto nodeToDelete = node->_next;
			node->_next = node->_next->_next;
			delete nodeToDelete;
			return;
		}
		node = node->_next;
	}
	return;
}

/*
Implement a stack by an array and a linked list
What is the advantages and disavantages of these implementations? 
*/
class StackFromList {
	Node* _top = nullptr;
public:
	auto pop() {
		if (_top != nullptr) {
			auto item = _top->_data;
			auto top = _top;
			_top = _top->_next;
			delete top;
			return item;
		}
		return NULL;
	}
	auto push(int item) {
		auto top = new Node(item);
		top->_next = _top;
		_top = top;
	}
	auto peek() { 
		if (_top != nullptr) 
			return _top->_data;
		return NULL;
	}
};
class Stack {
	static const auto MAX = 1000;
	int _top = 0;
	int ar[MAX];
public:
	auto pop() {
		if (_top > 0) {
			--_top;
			return ar[_top];
		}
		return NULL;
	}
	auto push(int item) {
		if (_top < MAX) {
			ar[_top] = item;
			++_top;
			return true;
		}
		std::cout << "Stack Overflow" << std::endl;
		return false;
	}
	auto peek() { 
		if (_top > 0) return ar[_top - 1]; 
		return NULL;
	}
};

/*
Implement a queue by an array and a linked list
What is the objectif of these lines of code?
if (last < first + MAX) {
	ar[last % MAX] = item;
	++last;
	return true;
}
*/
class Queue {
	static const int MAX = 1000;
	int _first = 0, _last = 0;
	int ar[MAX];
public:
	auto enqueue(int item) {
		if (_last < MAX) {
			ar[_last] = item;
			++_last;
			return true;
		}
		if (_last < _first + MAX) {
			ar[_last % MAX] = item;
			++_last;
			return true;
		}
		std::cout << "Queue Overflow" << std::endl;
		return false;
	}
	auto dequeue() {
		if (_first < _last) {
			++_first;
			if (_first < MAX) return ar[_first - 1];
			return ar[_first % MAX - 1];
		}
		return NULL;
	}
};
class QueueFromList {
	Node* _first = nullptr;
	Node* _last = nullptr;
public:
	auto enqueue(int item) {
		if (_last != nullptr) {
			auto last = new Node(item);
			_last->_next = last;
			_last = last;
		}
		else {
			_first = new Node(item);
			_last = _first;
		}
	}
	auto dequeue() {
		if (_first != nullptr) {
			auto item = _first->_data;
			auto first = _first;
			_first = _first->_next;
			delete first;
			return item;
		}
		return NULL;
	}
};

/*
Implement three stacks using a single array
*/

/*
Design a stack with a min function so that its 0(1) time?
Do it with decorator design pattern.
*/

/*
Implement a stack which can consists of multiple stacks
so that its size can be big without posing the constraint on the memory
*/

/*
Implement a queue using two stacks
*/

/*
Implement a deque structure consist of two dequeues to save dogs and cats
It must support enqueue, dequeueAny, dequeueDog and dequeueCat
Use build-in linked list data structure
*/

/*
Create a data structure represent a graph with addEdge and adjacent operations
*/

int main()
{
	
}