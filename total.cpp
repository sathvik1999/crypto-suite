#include <iostream>
#include <cmath>
#include "bigint.h"
#include <map>
using namespace std;
bigint addi(bigint a,bigint b,bigint c)
{
	return (a+b)%c;
}
bigint mult(bigint a,bigint b,bigint c)
{
	return (a%c*b%c)%c;	
}
bigint expo(bigint a,bigint b,bigint c)
{
	if(b==1)
		return a%c;
	else if(b%2==0)
		return (expo(a%c,b/2,c)*expo(a%c,b/2,c))%c;
	else 
		return (a%c*expo(a%c,b-1,c))%c;
}
bigint gcd(bigint a,bigint b)
{
	if(a%b==0)
		return b;
	else
		return gcd(b,a%b);
}
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
    for (bigint i = 1, cur = an; i<= n; i=i+1)
    {
        if (!(value[cur])
            value[ cur ] = i;
        cur = (cur * an) % m;
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
bool rabinMiller(bigint n){
     bigint s = n-1;
     bigint t = 0;
     while (s%2 == 0)
     {
         s = s/2;
         t=t+1;
     }
     int k= 0;
     while (k<128){
         bigint a = random.randrange(2,n-1);
         bigint v = expo(a,s,n) ;
         if (v!=1)
         {
             bigint i=0;
             while (v != (n-1))
             {
                 if (i == t-1)
                     return false;
                 else
                 {
                     i = i+1;
                     v = (v**2)%n;
              	 }
             } 
     	 }
     	 k+=2;
     	}
     return true;
}
bool isPrime(bigint n){
     bigint low[] =   {3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97
                   			,101,103,107,109,113,127,131,137,139,149,151,157,163,167,173,179
                   			,181,191,193,197,199,211,223,227,229,233,239,241,251,257,263,269
                   			,271,277,281,283,293,307,311,313,317,331,337,347,349,353,359,367
                   			,373,379,383,389,397,401,409,419,421,431,433,439,443,449,457,461
                   			,463,467,479,487,491,499,503,509,521,523,541,547,557,563,569,571
                   			,577,587,593,599,601,607,613,617,619,631,641,643,647,653,659,661
                   			,673,677,683,691,701,709,719,727,733,739,743,751,757,761,769,773
                   			,787,797,809,811,821,823,827,829,839,853,857,859,863,877,881,883
                   			,887,907,911,919,929,937,941,947,953,967,971,977,983,991,997};
      if (n >= 3)
      {
         if (n&1 != 0)
         {
             for(int i=0;i<167;i++)
             {
                 if (n == low[i])
                    return true;
                 if (n % low[i] == 0)
                     return false;
             }
             return rabinMiller(n);
          }
      }
     return false;
}
int main()
{
	int n;
	cin>>n;
	//cout<<powgen(3);
	//cout<<isprime(71);
	//keygeneration(n);
}