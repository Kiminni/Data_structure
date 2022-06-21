#include <stdio.h>
#include <string.h>

#define BUFFER_MAX 100
#define NAME_MAX 20

void add(void);
void find(void);
void status(void);
void delete(void);

char *names[BUFFER_MAX];
char *numbers[BUFFER_MAX];
int n = 0;

int main()
{
    char string[20];
    while(1)
    {
        printf("$ ");
        scanf("%s",string);

        if(strcmp(string, "add") == 0)
            add();
        else if(strcmp(string, "find") == 0)
            find();
        else if(strcmp(string, "status") == 0)
            status();
        else if(strcmp(string, "delete") == 0)
            delete();      
        else
            break;
    }
    return 0;
    
}

void add(void)
{
    char number[BUFFER_MAX],name[BUFFER_MAX];
    scanf("%s",name);
    scanf("%s",number);
    
    names[n] = strdup(name);
    numbers[n] = strdup(number);
    n++;

    printf("%s is added completely. \n",name);
}
void find(void)
{
    int i = 0;
    char buf1[BUFFER_MAX];
    scanf("%s",buf1);
    
    for(i = 0;i<n;i++)
        if(strcmp(buf1,names[i]) == 0)
            printf("%s\n",numbers[i]);
}
void status(void)
{
    int num;
    for(num = 0; num<n; num++)
        printf("%s %s \n",names[num],numbers[num]);
}
void delete(void)
{
    int i = 0;
    char dnf[BUFFER_MAX];
    scanf("%s",dnf);
    for(i = 0;i<n;i++)
        if(strcmp(dnf,names[i]) == 0)
            {
                names[i] == names[n-1];
                numbers[i] == numbers[n-1];
            }
    n--;
}




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