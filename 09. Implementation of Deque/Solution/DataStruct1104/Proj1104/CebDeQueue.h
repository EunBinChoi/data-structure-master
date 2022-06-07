#pragma once
#include "CebQueue.h"
class CCebDeQueue : // 상속을 이용한 CCebDeQueue 클래스(자식 클래스)
   public CCebQueue // CCebQueue 클래스(큐를 구현하는데 필요한 기본적인 함수와 변수가 담긴 클래스)를 상속받는다(부모 클래스)
{
public:

   CCebDeQueue(void){} // 생성자
   ~CCebDeQueue(void){} // 소멸자

   void AddRear(int i ) { EnQueue(i);} // 데크를 구현하는 배열의 뒤에 요소(i)를 추가(여기서는 배열에 요소를 추가하는 함수인 EnQueue 호출(CCebQueue에 정의되어있음))
   bool AddFront(int i) { // 데크를 구현하는 배열의 앞에 요소(i)를 추가(배열에 앞에 추가하는 함수는 CCebQueue 이 클래스에서 정의되어 있지 않음)
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

   int DelFront() // 데크를 구현하는 배열의 가장 앞에 요소를 삭제 
   {
	   return DeQueue(); // 데크를 구현하는 배열의 앞에 요소를 삭제(여기서는 배열에 요소를 삭제하는 함수인 DeQueue 호출(CCebQueue에 정의되어있음))
   } 

   int DelRear() { // 데크를 구현하는 배열의 가장 뒤에 요소를 삭제
      if(IsEmpty()) { // 만약 데크가 비어 있다면
         printf("덱이 비어 있습니다.\n");
         return -1 ;
      }

	  int ret = m_data[m_rear]; // 가장 최근에 삽입된 위치인 m_rear 위치에 해당하는 원소 값을 ret에 저장하고
      m_rear = (m_rear-1+MaxQueueSize) % MaxQueueSize; // 가장 최근에 삽입된 위치 m_rear을 다시 설정해준 다음

      return ret; // 그 원소 값을 반환
   }

   int GetFront() {return Peek();} // 데크를 구현하는 배열의 가장 앞에 요소를 반환
   // (여기서는 배열에 요소를 반환하는 함수인 Peek 호출(CCebQueue에 정의되어있음))

  
   int GerRear() { // 데크를 구현하는 배열의 가장 뒤에 요소를 반환
   if(IsEmpty()) { // 만약 데크가 비어 있다면
         printf("덱이 비어 있습니다.\n");
         return -1 ;
      }
      return m_data[m_rear]; // 가장 최근에 삽입된 위치를 가리키는 m_rear의 위치에 해당하는 원소값을 반환
   }
};
