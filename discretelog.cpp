#include <iostream>
#include <cmath>
#include "bigint.h"
#include <map>
using namespace std;
bigint discreteLogarithm(bigint a, bigint b, bigint m) 
{
    bigint n ;
    while(n*n<m)
    	n=n+1;
 	n=n+1;
    // Calculate a ^ n 
    bigint an = 1;
    for (bigint i = 0; i<n; i=i+1)
        an = (an * a) % m;
 
    map<bigint, bigint> value;
 
    // Store all values of a^(n*i) of LHS
    for (bigint i = 1; cur = an; i<= n; i=i+1)
    {
        if (!(value[cur])
        {
            value[ cur ] = i;
        	cur = (cur * an) % m;
        }
    }
 
    for (bigint i = 0, cur = b; i<= n; i=i+1)
    {
        // Calculate (a ^ j) * b and check
        // for collision
        if (value[cur])
        {
            bigint ans = value[cur] * n - i;
            if (ans < m)
                return ans;
        }
        cur = (cur * a) % m;
    }
    return -1;
}