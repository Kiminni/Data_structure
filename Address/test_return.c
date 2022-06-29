#include <stdio.h>

char* s(char *p);

int main()
{
    /*
    char num[10] = {0,};
    printf("%d %d\n",num[0],num);
    s(num);
    printf("%d %d\n",num[0],num);
    */

   /*
    char* numbers[20] = {0,};

    char** p_numbers;

    p_numbers = numbers;
    printf("%d %d %d %d",p_numbers[0],numbers[0],p_numbers,numbers);
    */

    /*
    int array[5] = {0,};
    int i = 0;
    while(i<5)
    {
        printf("%d \n", array[0],array[1],array[2],array[3],array[4]);
        array[i++] += 1; //작업 후 1을 더함
    }
    */

}

/*
char* s(char *p)
{
    p[0] = 10;
    printf("%d \n",p);
    return p;
}
*/

/*
char * strdup(char *s) //주소를 리턴하는 함수!
{
    char *p;
    p = (char *)malloc(strlen(s)+1);
    if (p != NULL)
        strcpy(p,s)
    return p;
}
*/