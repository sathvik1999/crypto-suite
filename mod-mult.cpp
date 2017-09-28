#include <iostream>
#include <cmath>
#include "bigint.h"
#include <map>
using namespace std;
bigint mult(bigint a,bigint b,bigint c)
{
	return (a%c*b%c)%c;	
}