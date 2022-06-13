#include <stdio.h>

char strdup(char *s) //s는 문자 배열의 시작 주소를 저장하는 포인터
{
    char *p;
    p = (char *)malloc(strlen(s)+1); //malloc으로 새로운 배열 할당 (NULL 까지 포함해야해서 +1) 
    if(p != NULL)
        strcpy(p,s); //strcpy를 이용해 s를 p로 복사 후 
    return p; //p 리턴
} 

int main()
{
    int n = 0;
    char* words[100];
    char buffer[100];
    while(scanf("%s",buffer) != EOF) //scanf("%d",&a);
    {
       words[n] = strdup(buffer); //strcpy(str2,str1) str1 -> str2로 
       //strdup가 문자열의 복제본을 만들어 그 복제본의 주소를 리턴함.
       /*
       words[n] = buffer => 다 같은 주소값을 갖게 됨.(이전 값도 지워짐!)
       결국 처음 세 번의 문자열은 지워지고 마지막 값만 남아 4번 반복함 
       */
       n++;
     
    }
    for (int i  = 0; i<4; i ++)
        printf("%s\n",words[i]);    
    return 0;
}