#include <stdio.h>
#include <string.h>

int main()
{
    char word[5];
    word[0] = 'h';
    word[1] = 'i';
    word[2] = '\0'; //=> 문자열로 이루어지기 위한 필수 조건(끝을 표시 해야 함)

    printf("%s",word);
}