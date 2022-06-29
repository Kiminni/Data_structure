#include <stdio.h>
#include <string.h>

int main()
{
    char str[] = "now # is the time # to start preparing ### for the exam#";
    char delim[] = "#";
    char *token;

    token = strtok(str, delim); // 첫 번째 호출
    while(token != NULL)
    {
        printf("next token is: %s-%d\n",token,strlen(token));
        token = strtok(NULL,delim);
    }
    return 0;  
}