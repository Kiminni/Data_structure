#include <stdio.h>

int main()
{
    int data[3] = {1,2,3};
    char data2[3] = {1,2,3};
    int* p = NULL;
    char* q = NULL;
    p = &data[0];
    q = &data2[0];
    
    for(int i = 0; i<3; i++)
        printf("%d %x\n",p+i,p+i);
    
    for(int j = 0; j<3; j++)
        printf("%d %x\n",q+j,q+j);

}