#pragma once
#include <iostream>
template <class T>

class IPrintable {
public:
	IPrintable() {};
	virtual ~IPrintable() {};

	//Operators:
	virtual void Printer(std::ostream& output) const = 0;
	virtual void Scanner(std::istream& user_input) = 0;

	friend std::ostream& operator<<(std::ostream& output, const T& received) { received.Printer(output); return output; };
	friend std::istream& operator >> (std::istream& user_input, T& received) { received.Scanner(user_input); return user_input; };
};