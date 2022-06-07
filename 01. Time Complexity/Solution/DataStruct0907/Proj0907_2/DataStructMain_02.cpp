// 2. 시간 복잡도가 다른 두 알고리즘의 비교

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<windows.h>

int ceb_mul_On(int n);//알고리즘 A(O(n))를 저장하는 함수
int ceb_mul_Onn(int n);//알고리즘 B(O(n^2))를 저장하는 함수

int main()
{
	
	int size;// n의 값을 저장하기 위한 변수 선언
	int r1,r2;//알고리즘 A와 알고리즘 B의 반환값을 받을 변수 선언
	clock_t t0,t1,t2;// 함수의 실행 전,후의 시간을 대입하기 위한 변수 선언
	double d1,d2;// 실제 실행 시간(실행 후-실행 전)을 대입하기 위한 변수 선언

	printf("\n******************** [ 2015학년도 2학기 자료구조 실습과제 ] ********************\n");
	printf("			2. 시간 복잡도가 다른 두 알고리즘의 비교	\n\n");

	
	for(int n=300;n<10000;n+=10){// n은 300부터 10000까지 10씩 증가한다(반복횟수는 마음대로 지정)
	size = n;// 현재 n의 값을 size에 대입
	t0 = clock();// 알고리즘 A를 저장하는 함수를 실행하기 전에 시간을 t0에 저장
	r1=ceb_mul_On(size); // 알고리즘 A의 방법으로 구현된 함수의 반환값을 r1에 저장
	t1 = clock();// 알고리즘 A를 저장하는 함수를 실행한 후에 시간을 t1에 저장
	r2=ceb_mul_Onn(size);// 알고리즘 B의 방법으로 구현된 함수의 반환값을 r2에 저장
	t2 = clock();// 알고리즘 B를 저장하는 함수를 실행한 후에 시간을 t2에 저장

	
	//d1, d2, d3는 각 알고리즘의 실제 실행 시간(초단위)
	d1=(double)(t1-t0) / CLOCKS_PER_SEC; // t0~t1 까지 걸린 시간
	d2=(double)(t2-t1) / CLOCKS_PER_SEC; // t1~t2 까지 걸린 시간

	if(d1<d2){ //만약 t0~t1까지 시간보다 t1~t2까지 걸린 시간이 더 길다면
		printf("  size : %3d\tA 시간 : %.6f\tB 시간 : %.6f\t역전\n", size,d1, d2);
		//현재 n의 값과 각각 알고리즘에 걸린 시간을 출력(걸리는 시간이 역전됨)
	}
	else if(d1>d2){
		printf("  size : %3d\tA 시간 : %.6f\tB 시간 : %.6f\n", size,d1, d2);
		//현재 n의 값과 각각 알고리즘에 걸린 시간을 출력
	}

	
	
	}
	return 0;



}

int ceb_mul_On(int n)// 알고리즘 A를 저장하는 함수(O(n)인 프로그램)
{
	int mul =1;
	for(int i=0;i<n;i++){
		for(int j=1;j<1000;j++)
			mul = mul*j;
	}

	return mul;

}

int ceb_mul_Onn(int n)// 알고리즘 B를 저장하는 함수(O(n^2)인 프로그램)
{
	int mul =1;
	for(int i=0;i<n;i++){
		for(int j=1;j<n;j++)
			mul = mul*j;
	}

	return mul;
}