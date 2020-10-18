// 1_HW3_203953682
// by furyan_naor


#include <iostream> 
#include <iomanip> 
#include "Date.h"
#include "IComparable.h" 
#include "IPrintable.h" 
#include "Interval.h"

using namespace std; 


void testDate() {
	Date independence(14, 5, 1948);
	Date otherDate = independence;
	//cout << "***lvl1:independence dd mm yy" << independence.getDay() << independence.getMonth() << independence.getYear() << endl;
	//cout << "***lvl2:otherDate dd mm yy" << otherDate.getDay() << otherDate.getMonth() << otherDate.getYear() << endl;
	cout << "Independence:" << independence << ", Other: " << otherDate << endl;
	otherDate.setMonth(2);
	//cout << "***lvl3:otherDate after setm to 2 dd mm yy" << otherDate.getDay() << otherDate.getMonth() << otherDate.getYear() << endl;

	cout << "Other date: " << otherDate << endl;
	otherDate.setDay(29);
	cout << "Other date: " << otherDate << endl;
	otherDate.setYear(1947);
	cout << "Other date: " << otherDate << endl;
	otherDate = Date(24, 1, 1959);
	cout << "Other date: " << otherDate << endl;
	cout << "Comparing using polymorphism" << endl;
	IComparable<Date> *indP = dynamic_cast < IComparable<Date> * > (&independence);
	cout << "Is independence <= otherDate ? " << (*indP <= otherDate) << endl;
	IComparable<Date> *otherP = dynamic_cast < IComparable<Date> * > (&otherDate);
	cout << "Is other date <= independence ? " << (*otherP <= independence) << endl;
} 

void testDateInput() {
	Date otherDate(1, 1, 1);
	do {
		cin >> otherDate;
		cout << otherDate << endl;
	} while (otherDate != Date(1, 1, 1));
} 

void testIntervalInt() {
	Interval<int> interval = Interval<int>(2, 1);
	cout << interval << endl;
	Interval<int> interval13(1, 3);
	Interval<int> interval24(2, 4);
	Interval<int> interval45(4, 5);
	cout << interval13 << endl;
	cout << interval24 << endl;
	cout << interval45 << endl;
	cout << "Does " << interval13 << " contain " << 2 << "? " << interval13.contains(2) << endl;
	cout << "Does " << interval24 << " contain " << 2 << "? " << interval24.contains(2) << endl;
	cout << "Does " << interval45 << " contain " << 2 << "? " << interval45.contains(2) << endl;
	cout << "Is " << interval13 << " before " << interval24 << "? " << interval13.isBefore(interval24) << endl;
	cout << "Is " << interval13 << " before " << interval45 << "? " << interval13.isBefore(interval45) << endl;
	cout << "Is " << interval24 << " before " << interval45 << "? " << interval24.isBefore(interval45) << endl;
	cout << "Is " << interval13 << " after " << interval24 << "? " << interval13.isAfter(interval24) << endl;
	cout << "Is " << interval13 << " after " << interval45 << "? " << interval13.isAfter(interval45) << endl;
	cout << "Is " << interval24 << " after " << interval45 << "? " << interval24.isAfter(interval45) << endl;
	cout << "Does " << interval13 << " intersect " << interval24 << "? " << interval13.intersects(interval24) << endl;
	cout << "Does " << interval13 << " intersect " << interval45 << "? " << interval13.intersects(interval45) << endl;
	cout << "Does " << interval24 << " intersect " << interval45 << "? " << interval24.intersects(interval45) << endl;
	cout << "Does " << interval24 << " intersect " << interval13 << "? " << interval24.intersects(interval13) << endl;
	cout << "Does " << interval45 << " intersect " << interval13 << "? " << interval45.intersects(interval13) << endl;
	cout << "Does " << interval45 << " intersect " << interval24 << "? " << interval45.intersects(interval24) << endl;
	cout << "interval13 && interval24 = " << (interval13 && interval24) << endl;
	cout << "interval13 && interval45 = " << (interval13 && interval45) << endl;
	cout << "interval24 && interval45 = " << (interval24 && interval45) << endl;
	cout << "interval24 && interval13 = " << (interval24 && interval13) << endl;
	cout << "interval45 && interval13 = " << (interval45 && interval13) << endl;
	cout << "interval45 && interval24 = " << (interval45 && interval24) << endl;
	cout << "interval13 || interval24 = " << (interval13 || interval24) << endl;
	cout << "interval24 || interval13 = " << (interval24 || interval13) << endl;
	cout << "interval13 || interval45 = " << (interval13 || interval45) << endl;
	cout << "interval24 || interval45 = " << (interval24 || interval45) << endl;
	cout << "interval45 || interval13 = " << (interval45 || interval13) << endl;
	cout << "interval45 || interval24 = " << (interval45 || interval24) << endl;
} 


int main() {
	int holder = 0; // just to hold termenal
	cout << boolalpha << setfill('0');
	testDate();
	cout << endl << endl;
	testIntervalInt();
	cout << endl << endl;
	testDateInput();
	cin >> holder;// just to hold termenal
	return 0;
}