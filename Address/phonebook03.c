#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define INIT_CAPACITY 3 //재할당 테스트를 위해서
#define BUFFER_SIZE  50

void init_directory(void);
void process_command(void);

void load(char *fileName);
void add(char *name, char *number);
void find(char *name);
void status(void);
void delete(char *name);
void save(char *name);
void reallocate(void);

int read_line(char str[], int limit);
int search(char *name);

char delim[] = " ";
char** names; //char * 타입의 배열 이름이므로 char ** 타입의 변수(저장하는 애들의 타입이 char *)
char** numbers;

int capacity = INIT_CAPACITY;
int n = 0;


int main()
{
    init_directory();
    process_command();    
    
    return 0;
}

void init_directory()
{
    names = (char **)malloc((INIT_CAPACITY) * sizeof(char *));
    numbers = (char **)malloc((INIT_CAPACITY) * sizeof(char *));
}

int read_line(char str[], int limit)
{
    int ch, i = 0;
    while((ch = getchar()) != '\n')
        if(i < limit - 1)
            str[i++] = ch;

    str[i] = '\0';

    return i;
}

void process_command()
{
    char command_line[BUFFER_SIZE]; //하나의 라인을 통으로 읽기 위한 버퍼
    char *command, *argument1, *argument2;

    while(1)
    {
        printf("$ ");
        if(read_line(command_line, BUFFER_SIZE) <= 0) //입력을 하나도 안 했을 때
            continue;

        command = strtok(command_line, delim); // 첫 토큰 명령어
        if(command == NULL) 
            continue;
        
        if(strcmp(command, "read") == 0) //
        {
            argument1 = strtok(NULL,delim); //두번 째 토큰 파일명 ex> read xxxx.txt
            if (argument1 == NULL)
            {
                printf("File name required. \n");
                continue;
            }
            load(argument1);
        }
        
        else if(strcmp(command, "add") == 0)
        {
            argument1 = strtok(NULL,delim);
            argument2 = strtok(NULL,delim);
            
            if(argument1 == NULL || argument2 == NULL)
            {
                printf("Invalid arguments.\n"); //이름만 치거나 전화번호를 깜박 한 경우
                continue;
            }

            add(argument1, argument2); //이름과 번호를 인자로 넘김
            printf("%s is added successfully.\n",argument1);
        }
        
        else if(strcmp(command, "find") == 0) // 사람 이름 찾는거니까 하나만
        {
            argument1 = strtok(NULL,delim); //두번 째 토큰 파일명 ex> find Henry
            if (argument1 == NULL)
            {
                printf("Invalid arguments.\n");
                continue;
            }
            find(argument1);
        }
        else if(strcmp(command, "status") == 0)
            status();   

        else if(strcmp(command, "delete") == 0) // 사람 이름 찾는거니까 하나만
        {
            argument1 = strtok(NULL,delim); //두번 째 토큰 파일명 ex> delete Henry
            if (argument1 == NULL)
            {
                printf("Invalid arguments.\n");
                continue;
            }
            delete(argument1);
        }
        else if(strcmp(command, "save") == 0)
        {
            argument1 = strtok(NULL,delim);
            argument2 = strtok(NULL,delim);
            
            if(argument1 == NULL || strcmp("as", argument1) != 0 || argument2 == NULL)
            {
                printf("Invalid arguments.\n"); //이름만 치거나 전화번호를 깜박 한 경우
                continue;
            }

            add(argument1, argument2); //이름과 번호를 인자로 넘김
            printf("%s is added successfully.\n",argument1);
        }
    }
}


void load(char *fileName) //이미 파일 이름을 읽었음
{
    char buf1[BUFFER_SIZE]; //이름
    char buf2[BUFFER_SIZE]; //번호

    FILE *fp = fopen(fileName, "r");
    if(fp = NULL)
    {
        printf("Open failed. \n");
        return;
    }
    while(fscanf(fp,"%s",buf1)!= EOF) //파일에서 이름 읽고, 종료가 아닐 때까지
    {
        fscanf(fp,"%s",buf2); //파일에서 번호 읽음
        add(buf1,buf2); // 이름 번호 추가
    }
    fclose(fp);
}

void add(char *name, char *number)
{
   if(n>=capacity)
        reallocate(); //배열 꽉차면 재할당
    int i = n - 1;
    while(i>=0 && strcmp(names[i], name) > 0) // 두개의 문자열을 비교해서 다를 시 첫번째가 크면 음수, 반대면 양수
    {
        names[i+1] = names[i]; //i번째 방에 있는 사람을 i+1 번으로
        numbers[i+1] = numbers[i]; //i번째 방에 있는 사람을 i+1번으로
        i--; // 감소 시키면서 처음까지 감 
    }
    names[i+1] = strdup(name); //name과 number가 매개변수인데 add 함수의 buf1,buf2는 이 함수가 종료되면 사라져 버리는 지역 변수들 
    numbers[i+1] = strdup(number);  // 프로그램이 실행되는 동안에는 살아있어야 함 복제한 문자열을 저장할 수 있게.
    //i가 -1이 되면 맨 처음에 저장 시키면 되니까 그리고 마지막에 i를 줄였기 떄문에 제 위치를 찾으려면 +1을 
    n++;
}

void find(char *name)
{
    int index = search(name);
    if (index == -1)
        printf("No person named '%s' exists.\n",name);
    else
        printf("%s\n",numbers[index]);
}

int search(char *name)
{
    int i;
    for(i = 0;i < n;i++)
    {
        if(strcmp(name,names[i]) == 0)
            return i;
    }
    return -1;
}

void status(void)
{
    int num;
    for(num = 0; num<n; num++)
        printf("%s %s \n",names[num],numbers[num]);
}


void delete(char *name)
{
    int i = search(name);
    if (i == -1)
        printf("No person named '%s' exists.\n",name);
    int j = i;
    for( ;j<n-1; j++) //빈 칸을 지우고 뒤에 걸 앞으로 땡겨야 함
    {
        names[j] = names[j+1];
        numbers[j] = numbers[j+1];
    }
    //n-1보다 작은 동안인 이유 j가 n-1까지 되어버리면 j+1은 n이 되는데 names[n]은 빈칸
    //names[0] ~ names[n-1] 까지 있기 때문
    n--;
}
void save(char *fileName)
{
    FILE *fp = fopen(fileName,"w");
    int i = 0;
    if(fp = NULL)
    {
        printf("Open failed.\n");
        return;
    }
    for(i = 0; i<n; i++)
        fprintf(fp,"%s %s\n",names[i],numbers[i]);
    
    fclose(fp);
}

void reallocate(void)
{
    capacity *= 2;
    char **tmp1;
    char **tmp2;

    int i = 0;
    
    tmp1 = (char **)malloc(sizeof(char *) * capacity); //원 크기의 2배인 배열 생성
    tmp2 = (char **)malloc(sizeof(char *) * capacity); //원 크기의 2배인 배열 생성

    for(i = 0; i<n; i++)
    {
        tmp1[i] = names[i];  //names의 요소 새 배열에 복사
        tmp2[i] = numbers[i]; //numbers의 요소 새 배열의 복사
    }

    free(names); //기존에 쓰던 메모리 할당 종료
    free(numbers); //기존에 쓰던 메모리 할당 종료
    
    names = tmp1; // names = 포인터 변수 tmp1 = 포인터 변수 (크기 2배인 새 배열 가리키도록 함!)
    numbers = tmp2; //numbers = 포인터 변수 tmp2 = 포인터 변수 (크기 2배인 새 배열 가리키도록 함!)
}