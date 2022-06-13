#include <stdio.h>
#define SWAP(x,y,t)  ((t) = (x), (x) = (y) , (y) = (t))

void foo(char list[],int i , int n);
char list[] = {'a','b','c'};
int i = 0, n = 2;
int main()
{
    foo(list,i,n);
}
void foo(char *list,int i , int n)
{
    int j,temp;
    if(i == n)
    {
        for(j = 0; j<=n; j++)
        {
            printf("%c",list[j]);
            printf(" ");
        }
    }

    else   
        for(j = i; j<=n; j++)
            SWAP(list[i],list[j],temp);
            foo(list,i+1,n);
            SWAP(list[i],list[j],temp);        
    
}
