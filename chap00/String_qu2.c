#include <stdio.h>
#include <string.h>
#include <ctype.h>

int compress_line(char str[],int limit);

int main() 
{   
    int n = 1;
    char str[100];
    n = compress_line(str,100);
    printf("%s:%d\n",str,n);

    return 0;

}
int compress_line(char compress_line[],int limit)
{
    int ch, i = 0;
    while((ch = getchar()) != '\n')
    {
        if(i < limit -1 &&(!isspace(ch)) || i > 0 && !isspace(compress_line[i-1]))
            compress_line[i++] = ch;
    }

    if (i>0 && isspace(compress_line[i-1]))
        i--;
    compress_line[i] = '\0';

    return i;
}
/*
공백 문자의 경우 직전 문자가 있고 걔가 공백이 아닌 경우에만 저장!
만약 맨 앞이 공백이라면 불필요한 공백이므로 무시하고 문자 사이에 나온다면
i-1이 공백인지 아닌지를 보면 된다
*/

/*
1. 문자열 배열과 제한 크기 설정
2. i가 limit -1 인 이유 : 맨 뒤에 NULL 문자를 넣어야 함
3. isspace() = 문자가 space인지 아닌지를 확인하는 함수 ==' '
4. 공백이 아니고 limit - 1 보다 작으면 저장
5. i가 0이 아니고 새 배열에 저장된 직전 문자가 공백이 아니라면 새 배열에 다음 문자를 저장
6. 마지막에 공백이 여러 칸 있다면 직전 문자가 공백이 아니므로 한 칸의 공백을 저장함
7. 마지막에 불필요한 공백을 없애기 위해 i가 0보다 크면서 직전 문자가 공백이라면 i값을 1 줄여라.
8. 마지막 문자는 종료문자로 선언(만약 limit까지 갔다면 limit에 해당하는 곳에 \0)
9. i를 리턴해 길이를 출력
*/