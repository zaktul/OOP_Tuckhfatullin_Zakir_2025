#pragma once
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class VeryLong {
private:
	long double a;
public:
	VeryLong();
	VeryLong(long double a1);
	void getdata();
	VeryLong operator-(const VeryLong& other);
	VeryLong operator+(const VeryLong& other);
	VeryLong operator*(const VeryLong& other);
	VeryLong operator/(const VeryLong& other);
	void putdata();
};