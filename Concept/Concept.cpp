#include "pch.h"
#include <iostream>
#include <math.h>
#include <thread>
#include <mutex>
#include <Windows.h>

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

/*
Check prime number
Can you think about a better method?
*/
auto primeNaive(int num) {
	if (num < 2) return false;
	for (auto i = 2; i < num; ++i)
		if ((num % i) == 0) return false;
	return true;
}
auto prime(int num) {
	if (num < 2) return false;
	for (auto i = 2; i < (int) sqrt(num); ++i)
		if ((num % i) == 0) return false;
	return true;
}

/*
Design a Singleton pattern and make it thread safe
How you can test the thread safe? 
Hint:	for (auto i = 0; i < 100; ++i) {
			thread t(&Restaurant::getInstance);
			t.detach();
		}
		Sleep(10000);

		Restaurant() { Sleep(50); }
		cout << _instance << endl;
*/
class Restaurant {
private:
	Restaurant() {}
	static Restaurant* _instance;
public:
	static Restaurant* getInstance() {
		if (_instance == nullptr)
			_instance = new Restaurant();
		return _instance;
	}
}; Restaurant* Restaurant::_instance = nullptr;

mutex myMutex;
class RestaurantLock {
private:
	RestaurantLock() {}
	static RestaurantLock* _instance;
public:
	static RestaurantLock* getInstance() {
		lock_guard<mutex> myLock(myMutex);
		if (_instance == nullptr)
			_instance = new RestaurantLock();
		return _instance;
	}
}; RestaurantLock* RestaurantLock::_instance = nullptr;

class RestaurantThreadSafe {
private:
	RestaurantThreadSafe() {}
public:
	static RestaurantThreadSafe* getInstance() {
		static RestaurantThreadSafe _instance;
		return &_instance;
	}
};

/*
Design Factory pattern
*/

/*
Design classes and data structures for a generic deck of cards
Explain how you could implement blackjack
*/

/*
Design classes and data structures for a call center with three levels of 
employees: respondent, manager and director
Implement a method dispatchCall() which assigns a call 
to the first available employee
*/

int main()
{
	for (auto i = 0; i < 100; ++i) {
		thread t(&RestaurantLock::getInstance);
		t.detach();
	}
	Sleep(10000);
	return 0;
}

