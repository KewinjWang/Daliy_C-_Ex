#pragma once
#include <iostream>
#include <stdio.h>
using std::cout;
using std::cin;
using std::endl;
class Date
{
	public:
		Date(int year = 1900,int month = 1,int day = 1);
		Date(const Date& d);
		Date& operator=(const Date& d);
		Date& operator+=(int day);
		Date operator+(int day);
		Date& operator-=(int day);
		Date operator-(int day);
		Date& operator++();
		Date operator++(int);
		Date& operator--();
		Date operator--(int);
		int operator-(Date& d);
		bool operator>(const Date& d);
		bool operator>=(const Date& d);
		bool operator==(const Date& d);
		bool operator<(const Date& d);
		bool operator<=(const Date& d);
		bool operator!=(const Date& d);
		int operator-(const Date& d);
		void Print();
	private:
		int year_;
		int month_;
		int day_;
};
