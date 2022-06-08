//하노이탑 프로그램
#include<stdio.h>
int count = 0;
void hanoi_tower(int n, char from, char tmp, char to)
{
	printf("[%6d]\n", ++count );
	if(n==1) printf("원판 1을 %c에서 %c으로 옮긴다\n",from,to);
	else{
		hanoi_tower(n-1, from, to, tmp);
		printf("원판 %d을 %c에서 %c으로 옮긴다\n",n,from,to);
		hanoi_tower(n-1, tmp, from, to);
	}

}
int main()
{
	hanoi_tower(4,'A','B','C');
	return 0;
}