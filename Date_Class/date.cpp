#include "date.h"
inline int get_day(int year,int month)
{
	int month_day[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
	if(month == 2 && ((year%4 == 0 && year%100 != 0) || year%400 == 0))
	{
		return month_day[2]+1;
	}
	else
	{
		return month_day[month];
	}
}
Date::Date(int year,int month,int day)
{
	//inspect date
	if(year >= 0 && month > 0 && month < 13 && 
			day >0 && day <= get_day(year,month))
	{
		year_ = year;
		month_ = month;
		day_ = day;
	}
	else
	{
		cout << "this a errro date" << endl;
	}
}
Date::Date(const Date& d)
{
	year_ = d.year_;
	month_ = d.month_;
	day_ = d.day_;
}
Date& Date::operator=(const Date& d)
{
	if(this != &d)
	{
		year_ = d.year_;
		month_ = d.month_;
		day_ = d.day_;
	}
}
Date& Date::operator+=(int day)
{
	if(day < 0)
	{
		*this -= -day;
	}
	else
	{
		day_ = day_ + day;
		int cur_day = get_day(year_,month_);
		while(day_ > cur_day)
		{
			day_ = day_ - cur_day; 
			month_++;
			if(month_ > 12)
			{
				year_ += 1;
				month_ = 1;
			}
		}
	}
	return *this;
}
Date Date::operator+(int day)
{
	Date tmp = *this;
	tmp += day;
	return tmp;
}
Date& Date::operator-=(int day)
{
	if(day < 0)
	{
		*this += -day;
	}
	else
	{
		day_ -= day;
		while(day_ < 1)
		{
			month_--;	
			if(month_ < 1)
			{
				year_ -= 1;
				month_ = 12;
			}
			int cur_day = get_day(year_,month_);
			day_ += cur_day;
		}
	}
	return *this;
}
Date Date::operator-(int day)
{
	Date tmp = *this;
	tmp -= day;
	return tmp;
}
Date& Date::operator++()
{
	*this += 1;
	return *this;
}
Date Date::operator++(int)
{
	Date tmp = *this;
	*this += 1;
	return tmp;
}
Date& Date::operator--()
{
	*this -= 1;
	return *this;
}
Date Date::operator--(int)
{
	Date tmp = *this;
	*this -= 1;
	return tmp;
}
int Date::operator-(const Date& d)
{
	Date max = *this;
	Date min = d;
	int flag = 1;
	if(*this < d)
	{
		max = d;
		min = *this;
		flag = -1;
	}
	int n = 0;
	while(max != min)
	{
		min++;
		n++;
	}
	return n*flag;
}
bool Date::operator>(const Date& d)
{
	if(year_ > d.year_)
	{
		return true;
	}
	else if(year_ == d.year_)
	{
		if(month_ > d.month_)
		{
			return true;
		}
		else if(month_ == d.month_)
		{
			if(day_ > d.day_)	
				return true;
			else
				return false;
		}
		else
			return false;
	}
	else
	{
		return false;
	}
}
bool Date::operator>=(const Date& d)
{
	if(/*true == */(*this > d) || *this == d)
		return true;
	else
		return false;
}
bool Date::operator==(const Date& d)
{
	if(year_ == d.year_ && month_ == d.month_ && day_ == d.day_)
		return true;
	else
		return false;
}
bool Date::operator<(const Date& d)
{
	if(true == (*this > d))
		return false;
	else
	{
		if(*this == d)
			return false;
		else
			return true;
	}
}
bool Date::operator<=(const Date& d)
{
	if(true == (*this < d) || *this == d)
		return true;
	else
		return false;
}
bool Date::operator!=(const Date& d)
{
	if(*this == d)
		return false;
	else
		return true;
}
void Date::Print()
{
	printf("%d-%d-%d\n",year_,month_,day_);
}
