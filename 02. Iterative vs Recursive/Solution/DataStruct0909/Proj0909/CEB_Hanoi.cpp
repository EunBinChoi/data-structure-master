//�ϳ���ž ���α׷�
#include<stdio.h>
int count = 0;
void hanoi_tower(int n, char from, char tmp, char to)
{
	printf("[%6d]\n", ++count );
	if(n==1) printf("���� 1�� %c���� %c���� �ű��\n",from,to);
	else{
		hanoi_tower(n-1, from, to, tmp);
		printf("���� %d�� %c���� %c���� �ű��\n",n,from,to);
		hanoi_tower(n-1, tmp, from, to);
	}

}
int main()
{
	hanoi_tower(4,'A','B','C');
	return 0;
}