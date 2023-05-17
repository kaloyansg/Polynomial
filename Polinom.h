#pragma once
#include "Ednochlen.h"
#include <iostream>
class Polinom
{
private:
	size_t numberOfEdnochlens;
	Ednochlen* polinom;

public:
	Polinom();
	Polinom(size_t numberOfEdnochlens, const Ednochlen* polinom);
	Polinom(const Polinom&);
	Polinom& operator=(const Polinom&);
	~Polinom();

	void print() const;

	Polinom& operator+= (const Ednochlen& ednochlen);
	Polinom operator+ (const Ednochlen& rhs);

	Polinom& operator-= (const Ednochlen& ednochlen);
	Polinom operator- (const Ednochlen& rhs);

	double operator() (double x);
};

