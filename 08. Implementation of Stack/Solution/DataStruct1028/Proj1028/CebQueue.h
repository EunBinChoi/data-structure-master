#pragma once // #ifndef ~~ #define ~~ #endif 을 줄여넣은 것
#include <stdio.h> // 표준 입출력 라이브러리 함수를 가지고 있는 헤더선언
const int MaxQueueSize = 10;
//#define MAX_QUEUE_SIZE 10 라고도 할 수 있음
// 원형큐를 구현하기 위해 배열의 크기를 담는 정수형 변수선언(여기서는 배열의 크기를 10으로 값을 줌)
typedef int CebElement;
// typedef 연산자를 이용해 int형을 CebElement로 자료형 재정의

// 원형큐 : 선입선출(가장 먼저 삽입된 것이 가장 먼저 나가고, 마지막에 들어온 것은 마지막에 나간다)
class CCebQueue // 원형큐를 구현하기 위해 기본적으로 필요한 멤버함수와 멤버변수를 가지고 있는 클래스
{
	CebElement m_data[MaxQueueSize]; // 원형큐의 데이터 값을 담기 위한 CebElement형 배열
	
	// 모두 인덱스를 가리키는 변수이므로 정수형(int) 인 것에 주의해야한다  
	int m_rear; // 가장 최근에 삽입된 위치를 저장하는 정수형 변수
	int m_front; // 가장 처음의 위치를 저장하는 정수형 변수

public: // 외부에서 접근을 가능하도록 만드는 public 

	CCebQueue(void){m_rear = 0, m_front = 0;}
	// 생성자에서 가장 최근에 삽입된 위치를 저장하는 변수(m_rear)과 가장 처음의 위치를 저장하는 변수(m_front)를 0으로 초기화해준다
	~CCebQueue(void){} // 소멸자

	bool IsEmpty(){ // 원형큐를 구현하는 배열이 비어있는 지 확인하는 함수
		return m_front == m_rear;
		// 만약 m_front와 m_rear의 값이 같다면 원형큐의 최근에 삽입된 위치와 처음의 위치가 같다는 말이므로
		// 아직 배열에 아무런 값이 들어오지 않았다는 것을 의미한다
		// 만약 저 연산이 true이면 배열이 비어있다는 의미이고, false이면 배열이 비어있지 않다는 의미이다
	}

	bool IsFull(){ // 원형큐를 구현하는 배열이 꽉차 있는 지 확인하는 함수
		return m_front == (m_rear + 1)%MaxQueueSize;
		// 만약 m_front와 (m_rear + 1)%MaxQueueSize의 값이 같다면 원형큐의 최근에 삽입된 위치의 다음 값과 처음의 위치가 같다는 말이므로
		// 배열이 이미 꽉 차 있다는 것을 의미한다
		// 만약 저 연산이 true이면 배열이 꽉차있다는 의미이고, false이면 배열이 꽉차있지 않다는 의미이다
	}

	void EnQueue(CebElement &e){ // 원형큐의 새로운 값을 삽입하는 함수
		// 이 함수의 반환형을 bool으로 할 수도 있다. 제대로 반환되면 true, 아니면 false로 반환

		if(IsFull()){ // 만약 배열이 꽉 차 있다면
			printf("큐가 가득 차 있습니다\n"); // 배열이 꽉 차 있다는 메세지를 출력하고
			return; // return으로 함수를 빠져나온다
		}

		// 만약 그게 아니라면 배열에 새로운 값을 집어넣기 위해서 
		m_rear = (m_rear+1)%MaxQueueSize;
		/* 가장 최근에 삽입된 위치를 하나 증가시킨다. 
		하지만 여기서 조심해야할 것은 삽입된 위치를 하나 증가시키는데 배열이 접근할 수 있는 인덱스의 값이
		넘어갈 수 있으므로 MaxQueueSize로 나눈 나머지 값을 저장한다(원형큐는 원형배열이라는 것에 주의)*/
		m_data[m_rear] = e; // 배열의 m_rear 위치에 새로운 값을 집어넣는다

	}

	CebElement DeQueue(){ // 원형큐의 처음 값을 삭제하는 함수
		// DeQueue 함수의 반환형이 왜 이것인지, 인수로는 다른 값을 받아오지 않는지 중요하다!
		
		if(IsEmpty()){ // 만약 배열이 비어있다면
			printf("큐가 비어 있습니다\n");// 배열이 비어있다는 메세지를 출력하고
			return -1; // return 값으로 -1을 주고, 함수를 빠져나온다
		}

		m_front = (m_front+1)%MaxQueueSize; 
		/* 가장 처음의 위치를 하나 증가시킨다. 
		하지만 여기서 조심해야할 것은 처음의 위치를 하나 증가시키는데 배열이 접근할 수 있는 인덱스의 값이
		넘어갈 수 있으므로 MaxQueueSize로 나눈 나머지 값을 저장한다(원형큐는 원형배열이라는 것에 주의)*/
		return m_data[m_front];
		// 배열의 m_front 위치의 데이터 값을 반환한다

	}

	CebElement Peek(){ // 원형큐의 처음 값을 확인하는 함수
		if(IsEmpty()){ // 만약 배열이 비어있다면
			printf("큐가 비어 있습니다\n");// 배열이 비어있다는 메세지를 출력하고
			return -1; // return 값으로 -1을 주고, 함수를 빠져나온다
		}

		/* 여기서 DeQueue() 함수와 다른 점은 가장 처음의 위치를 저장하는 m_front를 
		바꾸지 않는다는 점이다. 이 함수에서는 처음 값을 삭제하지는 않고, 무엇인지 확인하는 함수이기 때문이다*/ 
		return m_data[(m_front+1)%MaxQueueSize]; 
		/* 가장 처음의 위치를 하나 증가시킨다. 
		하지만 여기서 조심해야할 것은 처음의 위치를 하나 증가시키는데 
		배열이 접근할 수 있는 인덱스의 값이 넘어갈 수 있으므로 MaxQueueSize로 나눈 인덱스에 해당하는 값을 반환한다 */

	}

	void Display(){ // 원형큐 배열에 들어있는 원소들을 출력하는 함수
		if(!IsEmpty()){ // 만약 배열이 비어있지 않다면
			int from = m_front + 1; // 여기서 from은 원소 출력을 시작할 위치를 저장하는 변수이다
			// 가장 처음의 위치를 저장하는 변수에는 아무 값이 들어가지 않으므로 그 곳에서 + 1한 값을 from에 넣어준다
			int to = m_rear; // 원소 출력을 끝낼 위치를 저장하는 변수

			if(from > to) to += MaxQueueSize; 
			/* 만약 원형큐의 값의 삽입, 삭제를 통해 from이 to보다 크다면, to에 배열의 크기를 더해준다
			 이렇게 하는 이유는 만약 배열의 크기가 8이고, 
			 from이 7이었고, to가 1이면 to를 +배열의 크기(8)을 더해줘서 
			 from이 to보다 클 경우에도 7~9까지 라는 from <= to라는 조건을 만족하기 위해 이렇게 바꿔주는 것이다
			 */

			for(; from <= to ; from++) // from이 to와 같아질 떄까지 반복문을 돌면서
				printf("%d ", m_data[from % MaxQueueSize]);
			// 배열의 원소의 값을 출력해주면 된다. 여기서도 인덱스가 배열의 크기보다 커지는 것을 고려해
			// MaxQueueSize(배열의 크기)로 나눈 나머지 값으로 해준다
			
		}
		printf("\n"); // 엔터를 출력
	}
	
};

