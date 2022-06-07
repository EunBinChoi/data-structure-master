// 배열을 이용한 원형 데크 구현
#include "CebDeque.h" // 상속을 이용하지 않은 클래스
#include "CebDeQueue.h" // 상속을 이용한 클래스 

void main(){

	printf("\n************* [ 2015년도 2학기 자료구조 실습과제 9 ] *************\n\n");
	printf("                       1. 배열로 구현한 덱 테스트 프로그램\n\n");

	printf("------------ [ 상속을 이용하지 않은 덱 CCebDeque 클래스 ] -----------\n\n");
	CCebDeque q; // 상속을 이용하지 않은 클래스의 객체를 생성

	printf(" CCebDeque 전단삽입 8번 실행 => ");
	for( int i=1 ; i<9 ; i++){
		q.AddFront(i); // 반복문을 돌면서 상속을 이용하지 않은 클래스의 객체에 전단삽입
	}
	q.Display(); // 데크의 원소를 모두 출력해주는 함수 호출
	printf("\n");
	
	printf(" CCebDeque 전단삭제 3번 실행 => ");
	q.DelFront(); // 상속을 이용하지 않은 클래스의 객체에 전단삭제를 해주는 함수 호출
	q.DelFront(); // 상속을 이용하지 않은 클래스의 객체에 전단삭제를 해주는 함수 호출
	q.DelFront(); // 상속을 이용하지 않은 클래스의 객체에 전단삭제를 해주는 함수 호출
	
	q.Display(); // 데크의 원소를 모두 출력해주는 함수 호출
	printf("\n");

	printf(" CCebDeque 후단삽입 3번 실행 => ");
	q.AddRear(9); // 상속을 이용하지 않은 클래스의 객체에 후단삽입를 해주는 함수 호출
	q.AddRear(10); // 상속을 이용하지 않은 클래스의 객체에 후단삽입를 해주는 함수 호출
	q.AddRear(11); // 상속을 이용하지 않은 클래스의 객체에 후단삽입를 해주는 함수 호출
	
	q.Display(); // 데크의 원소를 모두 출력해주는 함수 호출
	printf("\n");

	printf(" CCebDeque 후단삭제 2번 실행 => ");
	q.DelRear(); // 상속을 이용하지 않은 클래스의 객체에 후단삭제를 해주는 함수 호출
	q.DelRear(); // 상속을 이용하지 않은 클래스의 객체에 후단삭제를 해주는 함수 호출

	q.Display(); // 데크의 원소를 모두 출력해주는 함수 호출
	printf("\n");

	printf("\n\n---------------- [ 상속을 이용한 CCebDeQueue 클래스 ] ---------------\n\n");
	
	CCebDeQueue q2; // 상속을 이용한 클래스의 객체를 생성

	printf(" CCebDeQueue 전단삽입 8번 실행 => ");
	for( int i=21 ; i<29 ; i++){
		q2.AddFront(i); // 반복문을 돌면서 상속을 이용한 클래스의 객체에 전단삽입
	} 
	q2.Display(); // 데크의 원소를 모두 출력해주는 함수 호출
	printf("\n");
	
	printf(" CCebDeQueue 전단삭제 3번 실행 => ");
	q2.DelFront(); // 상속을 이용한 클래스의 객체에 전단삭제를 해주는 함수 호출
	q2.DelFront(); // 상속을 이용한 클래스의 객체에 전단삭제를 해주는 함수 호출
	q2.DelFront(); // 상속을 이용한 클래스의 객체에 전단삭제를 해주는 함수 호출
	
	q2.Display(); // 데크의 원소를 모두 출력해주는 함수 호출
	printf("\n");

	printf(" CCebDeQueue 후단삽입 3번 실행 => ");
	q2.AddRear(29); // 상속을 이용한 클래스의 객체에 후단삽입를 해주는 함수 호출
	q2.AddRear(30); // 상속을 이용한 클래스의 객체에 후단삽입를 해주는 함수 호출
	q2.AddRear(31); // 상속을 이용한 클래스의 객체에 후단삽입를 해주는 함수 호출
	
	q2.Display(); // 데크의 원소를 모두 출력해주는 함수 호출
	printf("\n");

	printf(" CCebDeQueue 후단삭제 2번 실행 => ");
	q2.DelRear(); // 상속을 이용한 클래스의 객체에 후단삭제를 해주는 함수 호출
	q2.DelRear(); // 상속을 이용한 클래스의 객체에 후단삭제를 해주는 함수 호출

	q2.Display(); // 데크의 원소를 모두 출력해주는 함수 호출
	printf("\n");

	getchar();
	getchar(); // exe 실행파일이 꺼지지 않게 하기를 위함
}