#include <stdio.h>

int main()
{
FILE *fp = fopen("input.txt","r"); //파일에서 읽어옴
FILE *fp2= fopen("output.txt","w"); //파일에서 읽어와서 다른 파일에 씀
char buffer[100];

while(fscanf(fp,"%s",buffer) != EOF) //파일에서 fscanf를 이용해 문자를 읽어옴
    fprintf(fp2,"%s",buffer); //파일에서 fscanf를 이용해 읽어온 문자를 fprintf를 이용해 다른 파일에 씀

fprintf(stdout,"%s",buffer);
fclose(fp);
fclose(fp2);
return 0;
}