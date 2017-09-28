#include <iostream>
#include <cmath>
#include "bigint.h"
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
bigint discretelog(bigint a,bigint b,bigint m)
{
	
}
bigint powgen(bigint n)
{
	bigint a=2;
	if(n==1)
		return a;
	else if(n%2==1)
		return a*powgen(n-1);
	else
		return powgen(n/2)*powgen(n/2);
}
bool isprime(bigint n)
{
	int count=200;
	bigint a=2;
	while(count--&&a<n)
	{
		if(gcd(a,n)!=1||expo(a,n-1,n)!=1)
			return false;
	}
	return true;
}
void keygeneration(int b)
{
	bigint p,q,e,n=3,a=2;
	int count=0;
	while(count<b)
	{
		if(isprime(n))
		{
			n=powgen(n)-1;
			count=count+1;
		}
		else 
			n=n+2;
		if(count==b-1)
			p=n;
		if(count==b-1)
			e=n;
	}
	q=n;
	n=p*q;
	cout<<p<<endl;
	cout<<q<<endl;
	}
int main()
{
	int n;
	cin>>n;
	//cout<<powgen(3);
	//cout<<isprime(71);
	keygeneration(n);
}