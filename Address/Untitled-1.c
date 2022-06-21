#include <stdio.h>

char* s(char *p);

int main()
{
    char num[10] = {0,};
    printf("%d %d\n",num[0],num);
    s(num);
    printf("%d %d\n",num[0],num);
    

}

char* s(char *p)
{
    p[0] = 10;
    printf("%d \n",p);
    return p;
}