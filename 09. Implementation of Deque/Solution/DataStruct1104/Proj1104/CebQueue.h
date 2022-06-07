#pragma once
#include <stdio.h>
//const int MaxQueueSize = 10; //큐의 최대 크기
//#define MAX_QUEUE_SIZE 10 //위와 같은 코드

class CCebQueue // 큐를 구현하는데 필요한 기본적인 함수와 변수가 담긴 클래스
{

protected:

   int m_front; // 가장 최근에 삭제된 위치
   int m_rear; // 가장 최근에 삽입된 위치
   int m_data[MaxQueueSize]; // 배열로 구현한 큐

public:

   CCebQueue(void)   {m_front = m_rear = 0;} // 생성자, 가장 최근에 삭제된 위치와 가장 최근에 삽입된 위치를 저장하는 front와 rear를 0으로 초기화
   ~CCebQueue(void) {} // 소멸자
   bool IsEmpty() {return m_front == m_rear;} // 큐가 비어 있는지를 검사한다(front와 rear가 같은 위치를 가리킴 -> 공백상태)
   bool IsFull() {return m_front == (m_rear+1)%MaxQueueSize;} //큐가 가득 찼는지를 검사한다(front가 rear보다 하나 앞에 있으면 -> 포화상태)

   bool EnQueue(int i) { // 큐의 가장 뒤에 요소(i)를 추가
      if(IsFull()) { // 만약 큐가 가득 차있다면
         printf("큐가 가득 차 있습니다.\n");
         return false;
      }

      m_rear++; // 큐의 가장 뒤에 요소를 추가하기 위해서 가장 최근에 삽입된 위치를 저장하는 m_rear 를 하나 증가시킨다
      m_rear = m_rear % MaxQueueSize; // 원형 큐 배열의 최대 크기 고려해줌
      m_data[m_rear] = i; // 가장 최근에 삽입된 위치를 저장하는 m_rear을 하나 증가시킨 위치의 배열에 인수로 받아온 i 값을 저장
   }


   int DeQueue() { // 큐의 가장 앞에 있는 요소를 삭제
      if(IsEmpty()) { // 만약 큐가 비어 있다면
         printf("큐가 비어 있습니다.\n");
         return -1 ;
      }
      m_front++; // 가장 최근에 삭제된 위치인 m_front을 하나 증가시킨다(왜냐하면 큐의 가장 앞에 있는 요소를 삭제하기 때문// 원형 큐 배열의 최대 크기 고려해줌)
      m_front = m_front % MaxQueueSize; // 원형 큐 배열의 최대 크기 고려해줌
      return m_data[m_front]; // 가장 최근에 삭제된 위치를 저장하는 m_front을 하나 증가시킨 위치의 배열의 원소 값을 반환한다
   }

   int Peek() { // 큐에서 삭제하지 않고 가장 앞에 있는 값을 반환
      if(IsEmpty()) { // 만약 큐가 비어 있다면
         printf("큐가 비어 있습니다.\n");
         return -1 ;
      }
      return m_data[(m_front+1)%MaxQueueSize]; // 가장 앞에 있는 값을 삭제 하지 않고 반환(여기서 DeQueue와 다른 점은 m_front 값이 변하지 않는다는 것이다)
   }

   void Display() { // 현재 큐 안의 데이터를 출력
      if(!IsEmpty()) { // 만약 큐가 비어 있지 않다면
         int from = m_front+1; // 가장 최근에 삭제된 위치보다 하나 앞에서부터
         int to = m_rear; // 가장 최근에 삽입된 위치까지
         if(from > to) to += MaxQueueSize; // 만약 from이 to보다 큰 값이라면 to에 배열 최대 인덱스 크기를 더해줌
		 printf("  덱 내용 : ");
		 for(; from <= to ; from++) // from부터 to까지 from을 증가시키면서 
            printf("%2d ", m_data[from % MaxQueueSize]); // 큐 안의 요소(데이터) 출력
      }
      printf("\n"); //줄바꿈
   }

};
