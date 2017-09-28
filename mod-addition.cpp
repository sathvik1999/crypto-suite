#include <iostream>
#include <cmath>
#include "bigint.h"
#include <map>
using namespace std;
bigint addi(bigint a,bigint b,bigint c)
{
	return (a+b)%c;
}