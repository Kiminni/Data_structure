#include <stdio.h>

int sub(int n);

int main()
{
    sub(10);
    return 0;
}

int sub(int n)
{
    if(n < 0) 
        return 0;
    printf("%d ",n);
    return n + sub(n-3);
}
