// 프로젝트 3번 이후부터는 추가로 구현한 프로그램
// 3. 원소 값이 문자형인 연결 큐 프로그램

#include "CebLinkedQueue.h"  // 연결 큐를 구현하기 위한 클래스가 선언되어있는 헤더파일을 포함시킨다

void main(){ 

	printf("\n***************** [ 2015년도 2학기 자료구조 실습과제 9 ] *****************\n\n");
	printf("                       3. (추가) 원소 값이 문자형인 연결 큐 프로그램   \n\n");

	CCebLinkedQueue que; // 연결 큐를 구현하기 위한 클래스의 객체 생성

	printf(" CCebLinkedQueue 삽입 26번 실행 => ");
	for( char i='a' ; i <= 'z' ; i++){
		que.EnQueue(new CCebNode(i)); 
		// CCebLinkedQueue클래스의 EnQueue 함수를 호출하여 연결 큐의 노드를 추가한다
		// 여기서 반복문을 문자 a~z까지 실행하면 노드의 데이터 값에 문자형이 들어간다
	}
	que.Display(); // Display 함수를 호출하여 원소 값을 출력한다
	printf("\n");
	
	printf(" CCebLinkedQueue 삭제 3번 실행 => ");
	CCebNode* n; // CCebNode* 형 변수를 하나 선언한다(이는 DeQueue 함수에서 반환된 값을 저장)
	n = que.DeQueue(); delete n; // DeQueue 함수에서 반환된 값을 n에 저장하고 그 값을 delete 함수로 삭제
	n = que.DeQueue(); delete n; // DeQueue 함수에서 반환된 값을 n에 저장하고 그 값을 delete 함수로 삭제
	n = que.DeQueue(); delete n; // DeQueue 함수에서 반환된 값을 n에 저장하고 그 값을 delete 함수로 삭제

	que.Display(); // Display 함수를 호출하여 원소 값을 출력한다
	printf("\n");
	printf(" CCebLinkedQueue 반환 Peek() 실행 => %2c", que.Peek()->GetChar() );

	getchar();
	getchar(); // exe 실행파일이 꺼지지 않게 하기를 위함
}