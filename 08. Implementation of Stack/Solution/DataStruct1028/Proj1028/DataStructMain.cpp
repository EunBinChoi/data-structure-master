#include "CebQueue.h"
// 원형큐를 구현하기 위해 기본적으로 필요한 멤버함수와 멤버변수를 가지고 있는 클래스가 정의되어있는 헤더 선언

void main()
{

	CCebQueue q; // 원형큐를 구현하기 위해 기본적으로 필요한 멤버함수와 멤버변수를 가지고 있는 클래스의 객체 q를 만들어준다
	for(int i = 0 ; i < 10; i ++) // 반복문을 0~9까지 돌면서
	{
		q.EnQueue(i); // CCebQueue 클래스에 정의되어있는 EnQueue 함수를 이용해 값을 삽입한다
	}

	q.Display(); // CCebQueue 클래스에 정의되어있는 Display 함수를 이용해 값을 출력한다
	// 0 1 2 3 4 5 6 7 8 
	q.DeQueue(); // CCebQueue 클래스에 정의되어있는 DeQueue 함수를 이용해 값을 삭제한다
	q.DeQueue();
	q.DeQueue();
	q.Display();
	// 3 4 5 6 7 8
	q.DeQueue(); // 3 제거
	q.DeQueue(); // 4 제거
	q.DeQueue(); // 5 제거
	q.DeQueue(); // 6 제거
	q.DeQueue(); // 7 제거
	q.DeQueue(); // 8 제거
	q.DeQueue();
	q.DeQueue();
	q.DeQueue();
	q.Display(); 
	// 출력할 원형큐의 원소가 없다

	getchar();
	getchar(); // exe 파일이 꺼지지 않게 하기 위함
}