#include <stdio.h>
void hanoi_tower(int n, char from, char tmp, char to)
{
	if( n==1 ) printf("원판 1을 %c 에서 %c으로 옮긴다.\n",from,to);
	else {
		hanoi_tower(n-1, from, to, tmp);
		printf("원판 %d을 %c에서 %c으로 옮긴다.\n",n,from,to);
		hanoi_tower(n-1, tmp, from, to);
	}
}
int main(void)
{
	hanoi_tower(4, 'A', 'B', 'C');
	return 0;
}

/*
1. N개의 원반이 from에 있을 때 우선 N번째 원반 말고 to를 경유하여 나머지 N-1개의 원반을 tmp 로 옮김.
2. N번째 원반을 to로 옮김.
3. tmp에서 N-1개의 원반이 있을 때 N-1번째의 원반을 제외하고 tmp를 경유하여 나머지 N-2번째 원반을 from으로 옮김
3. N-1번째 원반을 to로 옮김.
... 반복 
*/