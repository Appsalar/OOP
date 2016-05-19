#ifndef __KEEPO__
#define __KEEPO__
#include "Kappa.h"
class Keepo : public Kappa
{
private:
	int nigga;
public:
	Keepo();
	Keepo(int, int, int);
	Keepo(const Keepo&);
	Keepo& Keepo::operator=(const Keepo&);
	virtual ~Keepo();

	virtual void print() const;
};

#endif // !__KEEPO__
