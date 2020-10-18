#pragma once
//#include "IPrintable.h"
template <class I>

//class Interval : public IPrintable<Interval> {
class Interval {
private:
	I a;
	I b;
public:
	Interval() {};
	Interval(I _a, I _b) : a(_a), b(_b) {};
	~Interval() {};

	//Opperations:
	bool isEmpty() const { return ((*this).a == (*this).b) ? true : false; }
	bool isBefore(const Interval received) const { return ((*this).b <= received.a) ? true : false; }
	bool isAfter(const Interval received) const { return ((*this).a >= received.b) ? true : false; }
	bool intersects(const Interval received) const { if (!(*this).isEmpty() && !received.isEmpty() && !(*this).isBefore(received) && !(*this).isAfter(received)) return true; else return false; }
	bool contains(const I c) const { return (((*this).a < c) && (c < (*this).b)) ? true : false; }

	friend std::ostream& operator<<(std::ostream& output, const Interval received) {
		if (received.a > received.b)
			output << "Invalid interval";
		else if (received.isEmpty())
			output << "EMPTY";
		else
			output << "(" << received.a << ", " << received.b << ")";
		return output;
	}

	//virtual void Printer(std::ostream& output) const { output << "(" << Interval<I>::a << ", " << Interval<I>::b << ")"; }
	//virtual void Scanner(std::istream& user_input) {}


	Interval operator&&(const Interval received) const {
		Interval cutting_interval;

		if (received.intersects(*this)) {
			if ((*this).contains(received.a) && (*this).contains(received.b))
				cutting_interval = received;
			else if (received.contains((*this).a) && received.contains((*this).b))
				cutting_interval = *this;
			else {
				if ((*this).a < received.a) {
					cutting_interval.a = received.a;
					cutting_interval.b = (*this).b;
				}
				else {
					cutting_interval.a = (*this).a;
					cutting_interval.b = received.b;
				}
			}
		}
		else
			cutting_interval.a = cutting_interval.b = 0;

		return cutting_interval;
	}

	Interval operator||(const Interval received) const {
		Interval cutting_interval;

		if (received.intersects(*this)) {
			if ((*this).contains(received.a) && (*this).contains(received.b))
				cutting_interval = *this;
			else if (received.contains((*this).a) && received.contains((*this).b))
				cutting_interval = received;
			else {
				if ((*this).a < received.a) {
					cutting_interval.a = (*this).a;
					cutting_interval.b = received.b;
				}
				else {
					cutting_interval.a = received.a;
					cutting_interval.b = (*this).b;
				}
			}
		}
		else {
			cutting_interval.a = 1;
			cutting_interval.b = 0;
		}

		return cutting_interval;
	}
};


