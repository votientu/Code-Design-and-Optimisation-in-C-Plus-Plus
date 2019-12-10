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
 
int main()
{
	cout << convertToBase("10", 16);
}