#pragma once
#include <iostream>
#include <List.h>
#include <cmath>



const int maxPower = 21;

class monom
{
public:
	monom(int _coeff, int x, int y, int z);
	monom(int _coeff, int _P = 0);

	int getX() const;
	int getY() const;
	int getZ() const;
	int getS() const;
	int getCoeff() const;

	bool operator==(const monom& m) const;
	bool operator!=(const monom& m) const;
	bool operator>(const monom& m) const;
	bool operator>=(const monom& m) const;
	bool operator<(const monom& m) const;
	bool operator<=(const monom& m) const;

	monom operator*(const int& val);
	monom& operator*=(const int& val);

	monom operator+(const monom& m) const;
	monom& operator+=(const monom& m);
	monom operator-(const monom& m) const;
	monom& operator-=(const monom& m);
	monom operator*(const monom& m) const;
	monom& operator*=(const monom& m);

	monom operator-() const;

	void print();

	friend ostream& operator<<(ostream& ostr, const monom& m);

private:
	int coeff;
	int P;
};


class polynom {
private:
	List<monom>* liMonom;
	listIterator<monom> iter;

public:
	polynom();
	polynom(const polynom& p);
	~polynom();

	polynom& operator=(const polynom& p);

	polynom operator*(const int& val);
	polynom& operator*=(const int& val);

	polynom operator+(const monom& m);
	polynom& operator+=(const monom& m);
	polynom operator-(const monom& m);
	polynom& operator-=(const monom& m);
	polynom operator*(const monom& m);
	polynom& operator*=(const monom& m);

	polynom operator+(const polynom& m);
	polynom& operator+=(const polynom& m);
	polynom operator-(const polynom& m);
	polynom& operator-=(const polynom& m);
	polynom operator*(const polynom& m);
	polynom& operator*=(const polynom& m);

	void print();

	friend ostream& operator<<(ostream& ostr, const polynom& m);
};
