#pragma once
template <class T>
class IComparable {
public:
	IComparable() {};
	virtual ~IComparable() {};

	//Operators:
	virtual bool operator==(const T& received) const = 0;
	virtual bool operator!=(const T& received) const = 0;
	virtual bool operator>(const T& received) const = 0;
	virtual bool operator>=(const T& received) const = 0;
	virtual bool operator<(const T& received) const = 0;
	virtual bool operator<=(const T& received) const = 0;

};

