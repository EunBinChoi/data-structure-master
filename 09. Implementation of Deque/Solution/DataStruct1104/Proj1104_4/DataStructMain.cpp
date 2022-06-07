// 프로젝트 3번 이후부터는 추가로 구현한 프로그램
// 4. 링크로 구현한 연결 덱 프로그램

#include "CebLinkedDeque.h"  // 연결 덱을 구현하기 위한 클래스가 선언되어있는 헤더파일을 포함시킨다

void main(){ 

	printf("\n***************** [ 2015년도 2학기 자료구조 실습과제 9 ] *****************\n\n");
	printf("                       4. (추가) 헤드포인터로 구현한 연결 덱 프로그램   \n\n");

	CCebLinkedDeque que; // 연결 덱를 구현하기 위한 클래스의 객체 생성

	printf(" CCebLinkedDeque 후단 삽입 8번 실행 => ");

	for( int i = 9 ; i < 17 ; i++){
		que.AddRear(new CCebNode(i)); // CCebLinkedDeque클래스의 AddRear 함수를 호출하여 후단삽입을 한다
	}
	que.Display(); // Display 함수를 호출하여 원소 값을 출력한다
	printf("\n");


	printf(" CCebLinkedDeque 전단 삽입 8번 실행 => ");

	for( int i = 1 ; i < 9 ; i++){
		que.AddFront(new CCebNode(i)); // CCebLinkedDeque클래스의 AddFront 함수를 호출하여 전단삽입을 한다
	}
	que.Display(); // Display 함수를 호출하여 원소 값을 출력한다
	printf("\n");

	printf(" CCebLinkedDeque 전단 삭제 3번 실행 => ");
	CCebNode* n; // CCebNode*형 변수를 하나 선언한 뒤
	n = que.DeleteFront();  delete n; // CCebLinkedDeque클래스의 DeleteFront 함수를 호출하여 전단삭제를 하고 그 반환값을 delete 를 통해 삭제한다
	n = que.DeleteFront();  delete n; // CCebLinkedDeque클래스의 DeleteFront 함수를 호출하여 전단삭제를 하고 그 반환값을 delete 를 통해 삭제한다
	n = que.DeleteFront();  delete n; // CCebLinkedDeque클래스의 DeleteFront 함수를 호출하여 전단삭제를 하고 그 반환값을 delete 를 통해 삭제한다

	que.Display(); // Display 함수를 호출하여 원소 값을 출력한다
	printf("\n");

	printf(" CCebLinkedDeque 후단 삭제 3번 실행 => ");
	n = que.DeleteRear();  delete n; // CCebLinkedDeque클래스의 DeleteRear 함수를 호출하여 후단삭제를 하고 그 반환값을 delete 를 통해 삭제한다
	n = que.DeleteRear();  delete n; // CCebLinkedDeque클래스의 DeleteRear 함수를 호출하여 후단삭제를 하고 그 반환값을 delete 를 통해 삭제한다
	n = que.DeleteRear();  delete n; // CCebLinkedDeque클래스의 DeleteRear 함수를 호출하여 후단삭제를 하고 그 반환값을 delete 를 통해 삭제한다

	que.Display(); // Display 함수를 호출하여 원소 값을 출력한다
	printf("\n");
	
	getchar();
	getchar(); // exe 실행파일이 꺼지지 않게 하기를 위함
}