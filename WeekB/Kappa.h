#ifndef __KAPPA__
#define __KAPPA__

class Kappa
{
private:
	int suka;
	int blqt;
public:
	Kappa();
	Kappa(int, int);
	Kappa(const Kappa&);
	Kappa& operator=(const Kappa&);
	virtual ~Kappa();

	virtual void print() const;
};

#endif // !__KAPPA__

