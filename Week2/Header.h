#ifndef HEADER
#define HEADER


struct Date
{
	unsigned day;
	unsigned month;
	unsigned year;
};


struct Datecompact
{
	unsigned day : 5;
	unsigned month : 4;
	unsigned year : 11;
};


// следващите 2 са примери 
// за това как действа подравняването 
// имената нямат значение #322 

// sizeof == 24 
struct foo
{
	int Suka;
	double Blqt;
	int nigga;
};

// sizeof == 16 
struct bar
{
	double Kappa;
	int Keepo;
	int nigga;
};

#endif // !HEADER

