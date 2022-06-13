#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *array = malloc(4 * sizeof(int));
    array[0] = 1;
    array[1] = 2;
    *(array+2) = 3;
    *(array+3) = 4;

    int* tmp = malloc(8 * sizeof(int));
    for(int i = 0;i<4;i++)
        tmp[i] = array[i];

    array = tmp; // array = tmp의 시작 주소를 저장! 배열이 커짐   

    array[5] = 5;
    printf("%d\n",array[5]);
    printf("%d\n",tmp[5]);
}