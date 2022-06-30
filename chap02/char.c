#include <Stdio.h>
#include <string.h>
void unknown()
{
    int ch;
    if((ch = getchar()) != '\n')
        unknown();
    putchar(ch);
}

int main()
{
    unknown();
}