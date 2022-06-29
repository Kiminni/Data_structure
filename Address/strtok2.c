#include <stdio.h>
#include <string.h>

int main()
{
    char str[] = "   study hard,       or sleep.";
    char delim[] = " ";
    char *token;

    printf("before: %s\n",str);
    token = strtok(str,delim);
    while(token != NULL)
    {
        printf("next token is: %s-%d\n",token,strlen(token));
        token = strtok(NULL,delim); //NULL 삽입으로 원본 문자열 변화(\0 삽입) 보존 X
        // STRTOK이 새로운 배열을 생성하는 건 아님 (strdup와는 다름)
    }
    printf("after:#%s#\n",str); //NULL 문자 이전까지만 출력! 
    return 0;
}