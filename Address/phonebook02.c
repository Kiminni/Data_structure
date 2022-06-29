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

char *names[BUFFER_MAX]; //각 char 배열의 주소 저장
char *numbers[BUFFER_MAX]; //각 char 배열의 주소 저장
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
        else if(strcmp(string, "load") == 0)
            load();
        else if(strcmp(string, "save") == 0)
            save();
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
    int i = n-1; //맨 뒤에서 보니까
    char number[BUFFER_MAX],name[BUFFER_MAX];
    scanf("%s",name);
    scanf("%s",number);
    
    while(i>=0 && strcmp(names[i], name) > 0) // 두개의 문자열을 비교해서 다를 시 첫번째가 크면 음수, 반대면 양수
    {
        names[i+1] = names[i]; //i번쨰 방에 있는 사람을 i+1 번으로
        numbers[i+1] = numbers[i]; //i번째 방에 있는 사람을 i+1번으로
        i--; // 감소 시키면서 처음까지 감 
    }
    names[i+1] = strdup(name);
    numbers[i+1] = strdup(number);
    //i가 -1이 되면 맨 처음에 저장 시키면 되니까 그리고 마지막에 i를 줄였기 떄문에 제 위치를 찾으려면 +1을 해야 함
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
    /*
    int j = index;
    for(;j = n-1; j++) 
        names[j] = names[j+1];
        numbers[j] = numbers[j+1];
        */
}

void load()
{
    char fileName[BUFFER_MAX];
    char buf1[BUFFER_MAX];
    char buf2[BUFFER_MAX];

    scanf("%s",fileName);
    
    FILE *fp = fopen(fileName,"r");
    if(fp = NULL)
    {
        printf("Open failed.\n");
        return ;
    }
    
    while(fscanf(fp,"%s",buf1) != EOF) // 파일 끝이면 EOF 리턴 -> 파일 끝까지 읽으니까 EOF
    {
        fscanf(fp,"%s",buf2);
        names[n] = strdup(buf1);
        numbers[n] = strdup(buf2);
        n++;
    }
    fclose(fp);
}

void save(void) //변경 된 사항 저장
{
    int i;
    char fileName[BUFFER_MAX];
    char tmp[BUFFER_MAX];
    
    scanf("%s",tmp); // which is "as", discarded
    scanf("%s",fileName);
    
    FILE *fp = fopen(fileName,"w");
    if(fp = NULL)
    {
        printf("Open failed.\n");
        return ;
    }

    for(i = 0; i<n; i++)
        fprintf(fp,"%s %s\n",names[i],numbers[i]);
    
    fclose(fp);
}

