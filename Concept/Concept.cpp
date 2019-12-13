#include "pch.h"
#include <iostream>

using namespace std;

/*
Extend a string using string and string buffer
*/

/*
Implement bit manipulations methods: getBit, setBit, clearBit, updateBit
*/
auto getBit(const int& num, int pos) {
	return ( (num & (1 << pos)) != 0 );
}
auto setBit(int& num, int pos) {
	num = num | (1 << pos);
}
auto clearBit(int& num, int pos) {
	num = num & ~(1 << pos);
}
auto clearBitsMSBThroughPos(int& num, int pos) {
	int mask = (1 << pos) - 1;
	num = num & mask;
}
auto clearBitsPosThroughO(int& num, int pos) {
	int mask = ~( ( 1 << (pos + 1) ) - 1 );
	num = num & mask;
}
auto updateBit(int& num, int pos, bool value) {
	num = num & ~(1 << pos); // clearBit(num, pos);
	if (value) // if (value) setBit(num, pos);
		num = num | (1 << pos);
}

/*
Given two 32-bit numbers, N and M, and two bit positions, i and j.
Insert M into N that M starts at bit j and ends at bit i.
N = 10 000 000 000, M = 10 011, i = 2, j = 6 => N = 10 001 001 100
*/

/*
Given a real number between 0 and 1 (e.g., 0.72) that is passed as a double,
print the binary representation. If the number cannot be reresented accurately
in binary with at most 32 characters, print "ERROR."
*/

/*
Count the number of bits required to convert integer A to integer B
31, 14 => 2
*/

/*
Swap odd and even bits in an integer with as few instructions as possible
(e.g., bit 0 and bit 1 are swapped, bit 2 and bit 3 are swapped, and so on)
*/



int main()
{
	auto num = 3;
	updateBit(num, 1, 0);
	cout << num;
}

