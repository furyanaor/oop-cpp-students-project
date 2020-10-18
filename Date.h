#pragma once
#include <iostream>
#include "IComparable.h"
#include "IPrintable.h"

class Date : public IComparable<Date>, public IPrintable<Date> {
private:
	int Day = 0;
	int Month = 0;
	int Year = 0;
public:
	Date() {};
	Date(int _Day, int _Month, int _Year) : Day(_Day), Month(_Month), Year(_Year) {}
	~Date() {};

	const int getDay() const { return (*this).Day; }
	const int getMonth() const { return (*this).Month; }
	const int getYear() const { return (*this).Year; }
	const void setDay(int recived_Day) { (*this).Day = recived_Day; }
	const void setMonth(int recived_Month) { (*this).Month = recived_Month; }
	const void setYear(int recived_Year) { (*this).Year = recived_Year; }

	//Operators:
	virtual bool operator==(const Date& received) const { return (((*this).getDay() == received.getDay()) && ((*this).getMonth() == received.getMonth()) && ((*this).getYear() == received.getYear())); }
	virtual bool operator!=(const Date& received) const { return !(*this == received); }
	virtual bool operator>(const Date& received) const;
	virtual bool operator>=(const Date& received) const { return ((*this == received) || (*this > received)); }
	virtual bool operator<(const Date& received) const { return ((*this != received) && !(*this > received)); }
	virtual bool operator<=(const Date& received) const { return  ((*this == received) || (*this < received)); }

	//friend std::ostream& operator<<(std::ostream& output, const Date& received);
	virtual void Printer(std::ostream& output) const;
	virtual void Scanner(std::istream& user_input);

	//friend std::istream& operator >> (std::istream& user_input, Date& received);

};