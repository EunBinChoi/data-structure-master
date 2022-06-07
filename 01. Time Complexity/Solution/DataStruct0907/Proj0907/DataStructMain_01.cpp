// 1. 프로그램의 실제 실행 시간 측정

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<windows.h>

/*1부터 n까지의 합을 구하는 함수를 다음과 같은 3가지의 알고리즘으로 구현*/
int ceb_sum_O1(int n);// 알고리즘 A를 저장하는 함수
int ceb_sum_On(int n);// 알고리즘 B를 저장하는 함수
int ceb_sum_Onn(int n);// 알고리즘 C를 저장하는 함수


int main()
{
	int size; // n의 값을 저장하기 위한 변수 선언
	int r1,r2,r3; // 각각의 함수의 1부터 n까지의 합을 대입하기 위한 변수 선언  
	clock_t t0,t1,t2,t3; // 함수의 실행 전,후의 시간을 대입하기 위한 변수 선언
	double d1,d2,d3; // 실제 실행 시간(실행 후-실행 전)을 대입하기 위한 변수 선언

	printf("\n******************** [ 2015학년도 2학기 자료구조 실습과제 ] ********************\n");
	printf("			1. 프로그램의 실제 실행 시간 측정	\n\n");

	
	for(int n=0;n<1000;n+=10){ // n은 0부터 1000까지 10씩 증가한다(반복횟수는 마음대로 지정)
	size = n; // 현재 n의 값을 size에 대입
	t0 = clock(); // 알고리즘 A를 저장하는 함수를 실행하기 전에 시간을 t0에 저장
	r1=ceb_sum_O1(size); // 알고리즘 A의 방법으로 1부터 n까지의 합을 구하는 함수
	t1 = clock(); // 알고리즘 A를 저장하는 함수를 실행한 후에 시간을 t1에 저장
	r2=ceb_sum_On(size); // 알고리즘 B의 방법으로 1부터 n까지의 합을 구하는 함수
	t2 = clock(); // 알고리즘 B를 저장하는 함수를 실행하기 후에 시간을 t2에 저장
	r3=ceb_sum_Onn(size); // 알고리즘 C의 방법으로 1부터 n까지의 합을 구하는 함수
	t3 = clock(); // 알고리즘 C를 저장하는 함수를 실행하기 후에 시간을 t2에 저장
	
	//d1, d2, d3는 각 알고리즘의 실제 실행 시간(초단위)
	d1=(double)(t1-t0) / CLOCKS_PER_SEC; // t0~t1 까지 걸린 시간
	d2=(double)(t2-t1) / CLOCKS_PER_SEC; // t0~t1 까지 걸린 시간
	d3=(double)(t3-t2) / CLOCKS_PER_SEC; // t0~t1 까지 걸린 시간
	/*여기서 CLOCKS_PER_SEC로 나눠준 이유는 clock 함수가 CLOCKS_PER_SEC 단위로 반환하기 때문*/
	
	printf("  size : %3d\tO1: %.6f\tOn : %.6f\tOnn : %.6f\n", size,d1, d2, d3);
	} // 현재 n의 값과 각각의 알고리즘에 걸린 시간을 출력해준다
	return 0;
}

int ceb_sum_O1(int n)// 알고리즘 A를 저장하는 함수
{/*1부터 n까지 더하는 공식 중에 n(n+1)/2 을 사용*/

	int sum;

	sum = n*(n+1) / 2;
	Sleep(1);
	return sum;

}

int ceb_sum_On(int n)// 알고리즘 B를 저장하는 함수
{/*1부터 n까지 더하기 기호와 반복문을 이용해서 n까지 더함*/

	int sum=0;

	for(int i=1;i<=n;i++)
	{
		sum += i;
		Sleep(1);
	}

	return sum;

}

int ceb_sum_Onn(int n)// 알고리즘 C를 저장하는 함수
{/*1은 1, 2는 (1+1)을 한 것, 3은 (1+1+1)을 한 것과 같은 개념으로 접근함
 이중 반복문을 사용하면 된다*/

	int sum=0;

	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=i;j++)
		{
			sum+=1;
			Sleep(1);
		}
	}

	return sum;

}

