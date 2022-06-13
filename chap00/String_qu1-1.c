#include <stdio.h>
#include <string.h>
int read_line(char str[], int n);

int main()
{   
    int ret = 0;
    char array2[100];
    ret = read_line(array2,5);
    printf("%s %d %d\n",array2,ret,strlen(array2));
    return 0;
}

int read_line(char str[], int n)
{
    int ch, i = 0; //getchar이 int 여야 함. -> getchar 우ㅕㄴ형이 int라 ㄱ
    
    while((ch = getchar())!= '\n')
        if(i<n - 1) // 마지막 n번째엔 \0 들어가야 하니까
            str[i++] = ch;
    str[i] = '\0';
    return i;
    // 처음 선언한 글자 수까지만 출력!
}