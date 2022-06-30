#include <stdio.h>
#include <time.h>
int power1(int x, int n);  
int power2(int x, int n);

int main()
{   
    clock_t s1,s2,e1,e2;
    double dur1,dur2;
    s1 = clock();
    power1(2,10000);
    e1 = clock();
    dur1 = (double)(e1-s1)/CLOCKS_PER_SEC;

    s2 = clock();
    power2(2,10000);
    e2 = clock();
    dur2 = (double)(e2-s2)/CLOCKS_PER_SEC;

    printf("%f %f\n",dur1,dur2);
}

int power1(int x, int n)
{
    if( n==0 ) return 1;
	else if ( (n%2)==0 ) 
		return power1(x*x, n/2);
	else return x*power1(x*x, (n-1)/2);
}

int power2(int x, int n)
{
    if( n==0 ) return 1;
	else
        return x*power2(x,n-1);
}