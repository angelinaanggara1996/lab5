#ifndef HUGE_H
#define HUGE_H
#include <string>
using namespace std;

class HugeInt
{
	friend ostream &operator <<(ostream&,const HugeInt&);
	friend istream &operator >>(istream&,HugeInt&);
public:	
	HugeInt(long=0);
	HugeInt(const char *); 
	HugeInt operator+(const HugeInt & )const;
	HugeInt operator+(int)const;
	HugeInt operator+(const char *)const;
	HugeInt operator-(const HugeInt & )const;
	HugeInt operator-(int)const;
	HugeInt operator-(const char *)const;
	
private:
	short number[30];
};

#endif
