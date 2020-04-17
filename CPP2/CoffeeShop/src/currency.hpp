class Currency
{
protected:
	double value;
public: 
	double getValue();
};

class Quarter : public Currency
{
public:
	Quarter();
};

class Dime : public Currency
{
public:
	Dime();
};

class Nickle : public Currency
{
public:
	Nickle();
};

class Penny : public Currency
{
public:
	Penny();
};

class Twenty : public Currency
{
public:
	Twenty();
};


class Ten : public Currency
{
public:
	Ten();
};

class Five : public Currency
{
public: 
	Five();
};

class One : public Currency
{
public: 
	One();
};