#include <iostream>
#include <cmath>
#include "bigint.h"
#include <map>
using namespace std;
bigint gcd(bigint a,bigint b)
{
	if(a%b==0)
		return b;
	else
		return gcd(b,a%b);
}