#include <iostream>
#include "bigint.h"
#include <utility>
using namespace std;

bigint add(bigint a,bigint b,bigint c)
{
	return (a+b)%c;
}

bigint mult(bigint a,bigint b,bigint c)
{
	return ((a%c)*(b%c))%c;
}

bigint exp(bigint a,bigint b,bigint c)
{
	bigint m=b/2,r=b%2,t=a%c;
	for(bigint i=0;i<m;i=i+1)
	{
		t=t*t;
		t=t%c;
	}
	if(r!=0) return (t*(a%c))%c;
	else return t;
}

bigint gcd(bigint a ,bigint b)
{
	if (a%b==0)return b;
	else gcd(b,a%b);
}

/*pair <bigint,bigint> coef(bigint a ,bigint n)
{
	if(a%n==0) return pair <bigint,bigint> (0,1);
	else{
	pair <bigint,bigint> c=coef(n,a%n);
	bigint x = c.second;
	bigint y = c.first-((a/n)*x);
	return pair <bigint,bigint> (x,y);
}
}

bigint inverse(bigint a,bigint n)
{
	bigint x=n;
	pair <bigint,bigint> c=coef(a,n);
	if (a%n!=0 && n%a!=0)
		if (c.first<0) return c.first+x;
		else return c.first;
	else {cout<<"doesnt exist";return 0;}

}

bigint keygeneration(bigint p,bigint q)
{
	bigint c= (p-1)*(q-1);
	bigint i=c;
	for(i;i>0;i=i-1)
	{
		if(gcd(i,c)==1)break;
	}
	return i;
}

bigint encryption(bigint m,bigint e,bigint n)
{
	return exp(m,e,n);
}


bigint decryption(bigint c,bigint e,bigint p,bigint q)
{
	bigint d=inverse(e,(p-1)*(q-1));
	return exp(c,e,p*q);
}

bigint dislog(bigint g,bigint y,bigint p){
    bigint i;
    g=g%p;y=y%p;
    bigint arr[p];
    arr[0]=1;
    for(i=1;i<p;i++){
        arr[i]=(arr[i-1]*g)%p;
        if(y==arr[i]) return i;
    }
}
*/
int main()
{
	bigint a=1000000000000000;
	bigint b=1000000000000000;
	cout<<add(a,b,a)<<endl;
	return 0;
}