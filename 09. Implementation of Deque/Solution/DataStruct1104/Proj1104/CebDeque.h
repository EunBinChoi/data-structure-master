#pragma once
#include <stdio.h>
const int MaxQueueSize = 10; // 데크의 최대 크기
class CCebDeque // 상속을 이용하지 않은 데크 CCebDeque 클래스
{
	int m_front; // 가장 최근에 삭제된 위치
	int m_rear; // 가장 최근에 삽입된 위치
	int m_data[MaxQueueSize]; // 배열로 구현한 데크
public:

	CCebDeque(void)   {m_front = m_rear = 0;} // 생성자, 가장 최근에 삭제된 위치와 가장 최근에 삽입된 위치를 0으로 초기화
	~CCebDeque(void) {} // 소멸자

	bool IsEmpty() {return m_front == m_rear;} // 데크를 구현하는 배열이 비어 있는지를 검사한다(front와 rear가 같은 위치를 가리킴 -> 공백상태)
	bool IsFull() {return m_front == (m_rear+1) % MaxQueueSize;} // 데크를 구현하는 배열이 가득 찼는지를 검사한다(front가 rear보다 하나 앞에 있으면 -> 포화상태)

	void Display() { // 현재 데크 안의 데이터 출력
		if(!IsEmpty()) { // 만약 데크가 비어 있지 않다면
			int from = m_front+1; // 가장 최근에 삭제된 위치보다 하나 앞에서부터
			int to = m_rear; // 가장 최근에 삽입된 위치까지
			if(from > to) to += MaxQueueSize; // 만약 from이 to보다 큰 값이라면 to에 배열 최대 인덱스 크기를 더해줌
			printf("  덱 내용 : ");
			for(; from <= to ; from++) // from부터 to까지
				printf("%2d ", m_data[from % MaxQueueSize]); // 데크 안의 데이터 출력
		}
		printf("\n"); // 줄바꿈
	}

	bool AddRear(int i) { // 데크를 구현하는 배열의 뒤에 요소(i)를 추가
		if(IsFull()) { // 만약 데크가 가득 차있다면
			printf("덱이 가득 차 있습니다.\n");
			return false;
		}
		m_rear++; // 데크를 구현하는 배열의 뒤에 요소를 추가하는 것이므로, 가장 최근에 삽입된 위치인 m_rear을 하나 증가
		m_rear = m_rear % MaxQueueSize; // 만약 배열의 최대크기보다 넘어갈 수 있으므로 최대 크기를 고려해줌
		m_data[m_rear] = i; // 그 위치에 인수로 받아온 요소(i)를 대입
	}

	bool AddFront(int i) { // 데크를 구현하는 배열의 앞에 요소(i)를 추가
		if(IsFull()) { // 만약 데크가 가득 차있다면
			printf("덱이 가득 차 있습니다.\n");
			return false;
		}
		m_data[m_front] = i; // 가장 최근에 삭제된 위치인 m_front에는 배열이 비어있으므로 이 곳에 인수로 받아온 요소(i)를 추가
		m_front = (m_front-1+MaxQueueSize) % MaxQueueSize;
		// 그리고 가장 최근에 삭제된 위치의 값을 바꿔준다. 먼저 1을 감소시킨 뒤, 이게 음수 값일 수 있으므로 배열의 크기를 고려해준다

		// 위와 같은 코드
		// m_front--; //삽입될 위치 카운트
		// if( m_front < 0 ) m_front = MaxQueueSize - 1;

	}

	int DelFront() { // 데크를 구현하는 배열의 가장 앞에 요소를 삭제 (시험문제)
		if(IsEmpty()) { //만약 데크가 비어 있다면
			printf("덱이 비어 있습니다.\n");
			return -1 ;
		}
		m_front++; // 배열의 가장 앞에 요소 위치를 설정해줌
		m_front = m_front % MaxQueueSize; // 원형 큐 배열의 최대 크기 고려해줌
		return m_data[m_front]; // 그 위치에 해당되는 원소 값을 반환
	}

	int DelRear() { // 데크를 구현하는 배열의 가장 뒤에 요소를 삭제 (시험문제)
		if(IsEmpty()) { // 만약 데크가 비어 있다면
			printf("덱이 비어 있습니다.\n");
			return -1 ;
		}

		int ret = m_data[m_rear]; // 가장 최근에 삽입된 위치인 m_rear 위치에 해당하는 원소 값을 ret에 저장하고
		m_rear = (m_rear-1+MaxQueueSize) % MaxQueueSize; // 가장 최근에 삽입된 위치 m_rear을 다시 설정해준 다음

		return ret; // 그 원소 값을 반환
	}

	int GetFront() { // 데크를 구현하는 배열의 가장 앞에 요소를 반환
		if(IsEmpty()) { // 만약 데크가 비어 있다면
			printf("덱이 비어 있습니다.\n");
			return -1 ;
		}
		return m_data[(m_front+1)%MaxQueueSize]; // 가장 앞에 요소를 가리킬 수 있도록 인덱스의 값을 지정 한뒤, 그 인덱스에 해당하는 원소를 반환
		// 여기서 위의 DelFront와 다른 점은 이 것은 m_front 값 자체가 바뀌지 않는다는 것이다
	}

	int GerRear() { // 데크를 구현하는 배열의 가장 뒤에 요소를 반환
		if(IsEmpty()) { // 만약 데크가 비어 있다면
			printf("덱이 비어 있습니다.\n");
			return -1 ;
		}
		return m_data[m_rear]; // 가장 최근에 삽입된 위치를 가리키는 m_rear의 위치에 해당하는 원소값을 반환
	}
};
