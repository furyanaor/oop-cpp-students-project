#include "Date.h"
#include <iomanip>
using namespace std;


//Operators:

bool Date::operator>(const Date& received) const {
	if ((*this).getYear() > received.getYear())
		return true;
	else if ((*this).getYear() == received.getYear()) {
		if ((*this).getMonth() > received.getMonth())
			return true;
		else if ((*this).getMonth() == received.getMonth()) {
			if ((*this).getDay() > received.getDay())
				return true;
		}
	}
	return false;
}

//ostream& operator<<(std::ostream& output, const Date& received) {
void Date::Printer(std::ostream& output) const {
	int dd = (*this).getDay();
	int mm = (*this).getMonth();
	int yy = (*this).getYear();
	int max_day = 32;
	int flag = 0;

	if (!(yy >= 1))
		flag++;
	if (flag == 1) {
		cout << "Illegal Year";
		return;
	}
	switch (mm) {
	case 1:
		max_day = 31;
		break;
	case 2:
		max_day = 0;
		break;
	case 3:
		max_day = 31;
		break;
	case 4:
		max_day = 30;
		break;
	case 5:
		max_day = 31;
		break;
	case 6:
		max_day = 30;
		break;
	case 7:
		max_day = 31;
		break;
	case 8:
		max_day = 31;
		break;
	case 9:
		max_day = 30;
		break;
	case 10:
		max_day = 31;
		break;
	case 11:
		max_day = 30;
		break;
	case 12:
		max_day = 31;
		break;
	default:
		flag = 12;
	}
	if (flag == 12) {
		cout << "Illegal month";
		return;
	}
	else {
		if (!(dd >= 1 && dd <= max_day)) {
			if (max_day == 0 && dd >= 1 && dd <= 29) {
				if (dd == 29) {
					if (yy % 4 == 0) {
						if (yy % 100 == 0) {
							if (yy % 400 != 0) // the year is a leap year if it is divisible by 400.
								flag = 4;
						}
					}
					else
						flag = 4;
					if (flag == 4) {
						cout << "Not a leap year";
						return;
					}
				}
			}
			else
				flag = 31;
			if (flag == 31) {
				cout << "Illegal day for month";
				return;
			}
		}
	}
	output << setfill('0') << setw(2) << (*this).getDay() << "/" << setfill('0') << setw(2) << (*this).getMonth() << "/" << (*this).getYear();
	return;
}

//istream& operator >> (std::istream& user_input, Date& received) {
void Date::Scanner(std::istream& user_input) {
	int dd, mm, yy;
	int flag = 0;

	user_input >> dd;
	if (user_input.peek() == '/')
		user_input.get();
	else
		flag++; // illegal date pattren
	user_input >> mm;
	if (user_input.peek() == '/')
		user_input.get();
	else
		flag++; // illegal date pattren
	user_input >> yy;

	//if (flag != 0)
	//	cout << "***illegal date pattren inputed" << endl;

	(*this).setDay(dd);
	(*this).setMonth(mm);
	(*this).setYear(yy);

	//return user_input;
}

//catch (char* msg) { cout << msg << endl; }

