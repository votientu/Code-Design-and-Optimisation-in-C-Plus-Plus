#include "pch.h"
#include <iostream>
#include <string>
#include <vector>
#include <math.h>

#include <thread>
#include <mutex>
#include <memory>

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

/*
Design a multi-thread program with lock, mutex
*/

/*
Calculate the nth Fibonacci number by recursive call and dynamic programming
What is the time and space complexity of each method?
*/
auto fibonacci(int n) {
	if (n == 0) return 0;
	if (n == 1) return 1;
	return fibonacci(n - 1) + fibonacci(n - 2);
}
int fib[2000]{0};
int fibonacciCache(int n) {
	if (n == 0) return 0;
	if (n == 1) return 1;
	if (fib[n] != 0) return fib[n];							// return cached result
	fib[n] = fibonacciCache(n - 1) + fibonacciCache(n - 2);	// cache result
	return fib[n];											// return cached result
}

/*
Write a method to return all subset of a set
*/

/*
Write a method to compute all permutation of a string
*/

/*
Given an infinite number of quarters (25 cents), dimes (10 cents), nickel (5 cents)
and pennies (1 cent) 
Write code to calculate the number of ways of representing n cents
*/

/*
Write test code for addSorted function
*/

/*
Write a basis inheritance code
Forget about virtual keyword, what happen in these codes:
Person* a = new Student();	a->aboutMe(); delete a;
Student* a = new Student();	a->aboutMe(); delete a;
How to let the program handle delete automatically?
What is the difference between 
auto a = make_shared<Student>(); and auto a = make_unique<Student>();
What happen if we declare virtual void aboutMe() in the Person class?
Hint: What does the pointer a is in compile time and in run-time in 
this allocation: Person* a = new Student();
What is the objectif of pure virtual function?
In the virtual context, should the destructor be declared virtual?
Hint: Try this code Person* a = new Student();	a->aboutMe(); delete a;
What is the difference between the deep copy and shallow copy?
*/
const int NAME_SIZE = 80;
class Person {
	int id;
	char name[NAME_SIZE];
public:
	virtual void aboutMe() {
		cout << "I am a person" << endl;;
	}
	virtual bool addCourse(string s) = 0;
	virtual ~Person() {
		cout << "Deleting a person" << endl;
	}
};
class Student : public Person {
public:
	void aboutMe() {
		cout << "I am a student" << endl;
	}
	bool addCourse(string s) {
		cout << "Added course " << s << " to student." << endl;
		return true;
	}
	~Student() {
		cout << "Deleting a student" << endl;
	}
};

/*
Write a function with default value
Why should default values are on the right?
*/
auto increase(int a, int b = 5) {
	return a + b;
}

/*
Write an overloading operator 
*/

/*
What is the difference between pointer and reference?
How many bytes a reference and a pointer takes in the memory?
*/
int* p = new int(7); int* q = p;
int a = 5; int& b = a;
int* ar = new int[2];

/*
Write a template code
What is the advantage and disavantage of using template?
Hint: Will the compiler generate all code versions for different input types
*/
template <class T>
auto printVec(vector<T>& vec) {
	for (auto e : vec) cout << e << " ";
	cout << endl;
}

/*
Write a smart pointer class
*/

int main()
{
	auto dvec = vector<double>{ 1.2, 2.1, 3.3 };
	printVec(dvec);
}

