#include "Polinom.h"
#include <cmath>

Polinom::Polinom()
{
	numberOfEdnochlens = 1;
	polinom = new Ednochlen[1];
}

Polinom::Polinom(size_t numberOfEdnochlens, const Ednochlen* polinom)
{
	this->numberOfEdnochlens = numberOfEdnochlens;
	this->polinom = new Ednochlen[numberOfEdnochlens];	
	for (size_t i = 0; i < numberOfEdnochlens; i++)
	{
		this->polinom[i] = polinom[i];
	}
}

Polinom::Polinom(const Polinom& other)
{
	this->numberOfEdnochlens = other.numberOfEdnochlens;
	this->polinom = new Ednochlen[numberOfEdnochlens];
	for (size_t i = 0; i < numberOfEdnochlens; i++)
	{
		this->polinom[i] = other.polinom[i];
	}
}

Polinom& Polinom::operator=(const Polinom& other)
{
	if (this != &other)
	{

		this->numberOfEdnochlens = other.numberOfEdnochlens;
		delete[] this->polinom;
		this->polinom = new Ednochlen[numberOfEdnochlens];

		for (size_t i = 0; i < numberOfEdnochlens; i++)
		{
			this->polinom[i] = other.polinom[i];
		}
	}

	return *this;
}

Polinom::~Polinom()
{
	delete[] this->polinom;
}

void Polinom::print() const
{
	for (size_t i = 0; i < this->numberOfEdnochlens; i++)
	{
		std::cout << polinom[i].coef << "x^" << polinom[i].power << " + ";
	}
}

Polinom& Polinom::operator+=(const Ednochlen& ednochlen)
{

	for (int i = 0; i < numberOfEdnochlens; i++)
	{
		if (polinom[i].power == ednochlen.power) 
		{
			polinom[i].coef += ednochlen.coef;
			return *this;
		}
	}
	
	Ednochlen* tempPolinom = new Ednochlen[numberOfEdnochlens+1];
	numberOfEdnochlens++;
	for (size_t i = 0; i < numberOfEdnochlens-1; i++)
	{
		tempPolinom[i] = polinom[i];
	}

	tempPolinom[numberOfEdnochlens - 1] = ednochlen;

	delete[] polinom;
	polinom = tempPolinom;

	return *this;
}

Polinom Polinom::operator+(const Ednochlen& rhs)
{
	Polinom lhs = *this;
	return lhs+=rhs;
}

Polinom& Polinom::operator-=(const Ednochlen& ednochlen)
{
	Ednochlen temp = { ednochlen.coef * -1, ednochlen.power };
	return *this += temp;
}

Polinom Polinom::operator-(const Ednochlen& rhs)
{
	Polinom lhs = *this;
	return lhs -= rhs;
}

double Polinom::operator()(const double x)
{
	double result = 0;

	for (size_t i = 0; i < numberOfEdnochlens; i++)
	{
		result += this->polinom[i].coef * pow(x, this->polinom[i].power);
	}

	return result;
}
