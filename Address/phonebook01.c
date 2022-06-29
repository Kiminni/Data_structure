#include <stdio.h>
#include <string.h>

#define BUFFER_MAX 100
#define NAME_MAX 20

void add(void);
void find(void);
void status(void);
void delete(void);
void load(void);
void save(void);
void search(void);


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
        else if(strcmp(string, "load") == 0)
            load();      
        else if(strcmp(string, "save") == 0)
            save();        
        else if(strcmp(string, "exit") == 0)
            break;
    }
    return 0;
    
}

void add(void)
{
    int i = n-1;
    char number[BUFFER_MAX],name[BUFFER_MAX];
    scanf("%s",name);
    scanf("%s",number);
    
    while(i>=0 && strcmp(names[i],name) >0)
    {
        names[i+1] = names[i];
        numbers[i+1] = numbers[i];
        i--;
    }
    names[i+1] = strdup(name);
    numbers[i+1] = strdup(number);
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
/*
void remove(void)
{
    int index, j;
    char buf[BUFFER_MAX];
    
    index = search(buf) //추후 추가!
    if (index = -1)
    {
        printf("No Person named %s exists",buf);
        return;
    } 
    
    scanf("%s",buf);

    int j = index;
    for( ;j<n-1; j++) //빈 칸을 지우고 뒤에 걸 앞으로 땡겨야 함
    {
        names[j] = names[j+1];
        numbers[j] = numbers[j+1];
    }
    //n-1보다 작은 동안인 이유 j가 n-1까지 되어버리면 j+1은 n이 되는데 names[n]은 빈칸
    //names[0] ~ names[n-1] 까지 있기 때문
    

    n--;
}
*/

void load(void)
{
    char fileName[NAME_MAX];
    char buf1[BUFFER_MAX],buf2[BUFFER_MAX];
    FILE *fp = fopen(fileName, "r");
    if(fp = NULL)
    {
        printf("load failed\n");
        return;
    }
    while(fscanf(fp,"%s",buf1) != EOF) //'\n'을 종료로 간주 -> 이름만 저장!
    {
        fscanf(fp, "%s",buf2); // '\n'을 종료로 간주 -> 번호만 저장!
        names[n] = strdup(buf1);
        numbers[n] = strdup(buf2);
        n++;
    }
    fclose(fp);
}
void load(void)
{
    int i;
    char tmp[BUFFER_MAX];
    char fileName[BUFFER_MAX];

    scanf("%s",tmp);
    scanf("%s",fileName);

    FILE *fp = fopen(fileName, "w");
    if(fp = NULL)
    {
        printf("load failed\n");
        return;
    }

    for(i = 0; i<n; i++)
        fprintf(fp,"%s %s\n",names[i],numbers[i]);
    
    fclose(fp);
}
void save(void);



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