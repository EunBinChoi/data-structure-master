#include "CebLinkedList.h"

void main() {

	printf("\n******************* [ 2015년도 2학기 자료구조 실습과제 10 ] *******************\n\n");
	printf("                          2. Wish List 구현 프로그램   \n\n");

	printf("-------------------         Addtail 2회, AddHead 2회        -------------------\n\n");
	
	CCebLinkedList list1; // CLinkedList 클래스의 list1 객체 생성
	list1.AddTail(new CCebItemNode("정장", 8000000, 4, "엄마카드로")); // list1의 마지막 위치에 리스트 추가
	list1.AddTail(new CCebItemNode("노트북", 9500000, 5, "내년에")); // list1의 마지막 위치에 리스트 추가
	list1.AddHead(new CCebItemNode("안경", 150000, 2, "다음달에"));	// list1의 맨 처음 위치에 리스트 추가
	list1.AddHead(new CCebItemNode("신발", 100000, 1));	// list1의 맨 처음 위치에 리스트 추가
	list1.Display( "list1 " ); // list1의 리스트 전체 출력

	printf("-------------------   우선순위값이 2인 노드 탐색 & AddNext  -------------------\n\n");
	CCebItemNode *n = list1.FindNodePriority( 2 ); // list1의 우선순위값이 2인 노드 탐색
	list1.AddNext(n, new CCebItemNode("외투", 100000, 3, "12월 전에"));	// list1의 우선순위값이 2인 노드 뒤에 새로운 노드 삽입
	list1.Display( "list1 " ); // list1의 리스트 전체 출력		

	printf("-------------- RemoveHead() , 우선순위값이 2인 노드 탐색 & 삭제 ---------------\n\n");
	list1.RemoveHead();	// list1의 리스트 맨 앞 노드 삭제
	n = list1.FindNodePriority( 2 ); // list1의 우선순위값이 2인 노드 탐색
	list1.Remove( n ); // list1의 Remove 함수를 호출하여 인수로 받은 n의 노드 삭제
	list1.Display( "list1 " ); // list1의 리스트내용 화면출력
	
	printf("-------------- Clear() , 리스트 클리어 -----------------------------------------\n");
	list1.Clear(); // list1 리스트의 모든 노드 삭제
	list1.Display( "list1 " ); // list1 리스트내용 화면출력
	
	printf("-------------- (추가) Merge() , 인수로 받은 연결 리스트를 뒤에서 연결하기 ---\n\n");
	CCebLinkedList list2; // CLinkedList 클래스의 list2 객체 생성
	list2.AddTail(new CCebItemNode("정장2", 8000000, 6, "엄마카드로"));	// list2의 마지막 위치에 리스트 추가
	list2.AddTail(new CCebItemNode("노트북2", 9500000, 7, "내년에")); // list2의 마지막 위치에 리스트 추가
	list2.AddHead(new CCebItemNode("안경2", 150000, 2, "다음달에")); // list2의 맨 처음 위치에 리스트 추가
	list2.AddHead(new CCebItemNode("신발2", 100000, 1)); // list2의 맨 처음 위치에 리스트 추가	
	list2.Display( "list2 " ); // list2의 list2의 리스트내용 화면출력

	list1.AddTail(new CCebItemNode("마우스", 700000, 8, "엄마카드로"));
	list1.Display( "list1 " ); // list2의 list2의 리스트내용 화면출력
	list1.Merge(list2); // 리스트 list1에 list2를 병합시키는 데 뒤에서 부터 병합시킴
	list1.Display( "list1 " );	// list1에는 list2을 병합시킨 리스트가 출력됨
	list2.Display( "list2 " ); // list2는 병합한 후 아무것도 남지 않은 리스트가 출력됨
	printf("\n");
	

	printf("-------------- (추가) HeadMerge() , 인수로 받은 연결 리스트를 앞에서 연결하기 --\n\n");
	list2.AddTail(new CCebItemNode("전자회로", 8000000, 9, "이번월급으로"));	// list2의 마지막 위치에 리스트 추가
	list2.AddTail(new CCebItemNode("침대", 9500000, 10, "다음달에")); // list2의 마지막 위치에 리스트 추가
	list1.Display( "list1 " );	// list1 리스트 항목 출력
	list2.Display( "list2 " ); // list2 리스트 항목 출력
	list1.HeadMerge(list2); // 리스트 list1에 list2를 병합시키는 데 앞에서부터 병합시킴
	list1.Display("list1 " ); // 병합된 list1의 리스트내용 화면출력
	list2.Display( "list2 " ); // list2는 병합한 후 아무것도 남지 않은 리스트가 출력됨
	printf("\n");

	printf("-------------- (추가) Reverse() , 단순 연결 리스트 반대로 출력하기 -------------\n\n");
	list1.Reverse(); // list1을 반대로 출력하는 함수 Reverse 함수를 출력
	list1.Display("list1 " ); // list1의 리스트내용 화면출력

	
	
	printf("-------------- (추가) PriorityArrange() , 우선순위가 높은 것부터 출력 ---------\n\n");
	list1.PriorityArrange(); // 우선순위가 높은 것부터 출력하는 함수
	list1.Display("list1 " ); // list의 리스트 내용 화면 출력
	
	printf("--------------    (추가) FindNodeName() \n\t  이름으로 노드 탐색 && 해당 노드 삭제 --------------------------------\n\n");
	n = list1.FindNodeName( "노트북2" ); // list1의 이름이 "노트북2"인 노드 탐색
	list1.Remove( n ); // list1의 Remove 함수를 호출하여 인수로 받은 n의 노드 삭제
	list1.Display( "list1 " ); // list1의 리스트내용 화면출력
	
	printf("--------------    (추가) FindNodePrice() \n\t  가격으로 노드 탐색 && 해당 노드 삭제 --------------------------------\n\n");
	n = list1.FindNodePrice( 150000 ); // list1의 가격이 150000인 노드 탐색
	list1.Remove( n ); // list1의 Remove 함수를 호출하여 인수로 받은 n의 노드 삭제
	list1.Display( "list1 " ); // list1의 리스트내용 화면출력

	printf("--------------    (추가) FindNodeMethod() \n\t  사는방법으로 노드 탐색 && 해당 노드 삭제 -----------------------------\n\n");
	n = list1.FindNodeMethod( "..." ); // list1의 사는방법이 "엄마카드로"인 노드 탐색
	list1.Remove( n ); // list1의 Remove 함수를 호출하여 인수로 받은 n의 노드 삭제
	list1.Display( "list1 " ); // list1의 리스트내용 화면출력

	printf("-------------- (추가) PrintPriceRange() , min max 사이에 가격인 물품출력 -------\n\n");
	list1.AddTail(new CCebItemNode("가방", 300000, 2, "엄마카드로"));	// list1의 마지막 위치에 리스트 추가
	list1.AddTail(new CCebItemNode("핸드폰", 9500000, 3, "내년에")); // list1의 마지막 위치에 리스트 추가
	list1.Display( "list1 " ); // list1의 리스트내용 화면출력

	int min,max; // 최소와 최대값을 저장할 정수형 변수선언
	printf("최소, 최대값을 입력하세요 (예:<300000 500000>) : ");
	scanf("%d %d",&min,&max); // 사용자에게 최소값과 최대값을 입력받음
	printf("\n");

	list1.PrintPriceRange(min,max); // 최소값과 최대값 사이에 있는 항목들을 출력

	getchar();
	getchar(); // exe 실행파일이 꺼지지 않기 위함


}
