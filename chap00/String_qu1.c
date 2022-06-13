#include <stdio.h>
#include <string.h>

int read_line(char str[], int n);

int main()
{   
    int n = 0;
    char array[100];
    while(1)
    {
        printf("$ ");
        gets(array);
        //fgets(array,10,stdin);
        /* 
        fgets => 어디에, 사이즈는, 파일에서? 키보드로? => 2번쨰 매개변수로 버퍼 사이즈 제공
        버퍼 사이즈 초과해서 입력이 되지 않음 -> 0~99까지만 읽음 / 반복되면서 못 읽었던 부분을 다시 읽음
        마지막에 \n을 버퍼에 저장을 함! (카운트도 +1 증가)
        버퍼에 마지막 글자를 지워야 함*/
        array[strlen(array)-1] = '\0'; 
        /*
        strlen => 문자열 길이를 재는 함수 => strlen -1 => 문자열의 마지막 번호
        문자열 마지막에 종료문자를 넣어야 함 -> \n 없애고 \0 넣어서 한 줄 띄어쓰기 되는 문제 해결!
        */
        printf("%s:%d\n",array,strlen(array));
        n++;
    }
    return 0;
}

int read_line(char str[], int n)
{
    int ch, i = 0;
    
    while((ch = getchar())!= '\n')
        if(i<n-1)
            str[i++] = ch;
    str[i] = '\0';
    return i;
}
/*
1. 문자열 배열 str, 문자열 크기 n을 매개변수로 받아옴.
2. 정수 ch, i = 0으로 선언 후 초기화
3. ch가 문자 혹은 문자열을 \n(enter) 전까지 입력 받음
4. i가 크기 n보다 작다면 str에 0번째부터 저장
5. 여기서 주의!!!!!!!!!! str에 ch로 문자를 저장하고 난 후 i의 값 증가함
6. 이걸 0번째부터 i-1번째까지 반복함.(i 번째는 \n이므로 반복문 끝남)
7. 위 반복이 끝나면 마지막에 증가한 i에 \0 저장
8. i 리턴 -> 문자열 길이가 됨.

ex) 입력: super(\n) 
1) str[0] = s
2) str[1] = u
3) str[2] = p 
4) str[3] = e
5) str[4] = r
6) str[5] => 반복 종료 후 \0 저장
*/