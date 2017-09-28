#include <iostream>
#include <cmath>
#include "bigint.h"
#include <map>
using namespace std;
bigint expo(bigint a,bigint b,bigint c)
{
	if(b==1)
		return a%c;
	else if(b%2==0)
		return (expo(a%c,b/2,c)*expo(a%c,b/2,c))%c;
	else 
		return (a%c*expo(a%c,b-1,c))%c;
}