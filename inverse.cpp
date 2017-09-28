#include <iostream>
#include <cmath>
#include "bigint.h"
#include <map>
using namespace std;
bigint invhelp(bigint x1,bigint x2,bigint y1,bigint y2,bigint a,bigint b)
{
	if(a*y1+b*y2==1)
	{
		if(y1>0)
			return y1;
		else
			return y1+b;
	}
	else
	{
		bigint q=(a*x1+b*x2)/(a*y1+b*y2);
		return invhelp(y1,y2,x1-q*y1,x2-q*y2,a,b);
	}
}
bigint inverse(bigint a,bigint n)
{
	if (gcd(a,n)!=1||n==1)
		return -1;
	else
		return invhelp(1,0,0,1,a,n);
}