#include "pch.h"
#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

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
auto sum(vector<ExpressionTerm> expr1, vector<ExpressionTerm> expr2) {}

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
auto convertToBase(string strNum, int base) {
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
	cout << head->_data << " ";
	Node* node = head;
	while (node->_next != nullptr) {
		node = node->_next;
		cout << node->_data << " ";
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

int main()
{
	
}