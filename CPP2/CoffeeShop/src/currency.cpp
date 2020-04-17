#include "currency.hpp"

class Currency
{
protected:
	double value;
public: 
	double getValue()
	{
		return value;
	}
};

class Quarter : public Currency
{
public:
	Quarter()
	{
		value = .25;
	}
};

class Dime : public Currency
{
public:
	Dime()
	{
		value = .10;
	}
};

class Nickle : public Currency
{
public:
	Nickle()
	{
		value = .05;
	}
};

class Penny : public Currency
{
public:
	Penny()
	{
		value = .1;
	}
};

class Twenty : public Currency
{
public:
	Twenty()
	{
		value = 20;
	}
};


class Ten : public Currency
{
public:
	Ten()
	{
		value = 10;
	}
};

class Five : public Currency
{
public: 
	Five()
	{
		value = 5;
	}
};

class One : public Currency
{
public: 
	One()
	{
		value = 1;
	}
};