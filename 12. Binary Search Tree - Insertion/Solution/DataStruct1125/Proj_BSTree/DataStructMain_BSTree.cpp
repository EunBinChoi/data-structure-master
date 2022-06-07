#include "CebBSTree.h" // 트리를 구현하는 클래스의 헤더 파일 선언

void main()
{
	printf("\n******************* [ 2015년도 2학기 자료구조 실습과제 12 ] *******************\n\n");
	printf("                1. 이진탐색트리로 구현한 Wish List 구현 프로그램   \n\n");
	
	CCebBSTree t; // 이진트리를 구현하는 클래스의 객체를 하나 생성/

	/*위에서 선언한 객체에 Add 함수를 호출하여 노드를 추가시킴, 데이터는 CCebTNode의 생성자를 이용하여 설정*/
	t.Add( new CCebTNode( 4, "정장", 80, "엄마카드로" ) );
	t.Add( new CCebTNode( 5, "노트북", 950, "내년에" ) );
	t.Add( new CCebTNode( 2, "안경", 15, "다음달에" ) );
	t.Add( new CCebTNode( 1, "신발", 10 ) );
	t.Add( new CCebTNode( 3, "외투", 10, "12월 전에" ) );
	t.Add( new CCebTNode( 6, "운동복", 10, "내년여름 위해" ) );
	t.Add( new CCebTNode( 7, "다이어리", 3, "새해맞이" ) );
	
	printf("-------------------   [트리내용출력-전위순회(PreOrder)]    ---------------------\n");
	t.PrintPreOrder(); // 전위 순회를 담당하는 함수 호출

	printf("-------------------   [트리내용출력-중위순회(InOrder)]    ----------------------\n\n");
	t.PrintInOrder(); // 중위 순회를 담당하는 함수 호출
	
	printf("-------------------   [트리내용출력-후위순회(PostOrder)]    --------------------\n");
	t.PrintPostOrder(); // 후위 순회를 담당하는 함수 호출

	printf("-------------------         [ t.SearchPriority(7) ]         -------------------\n\n");
	t.SearchPriority(7); // 우선순위 7인 노드를 찾아 그 노드의 데이터 출력

	printf("-------------------        [ t.SearchPriority(100) ]        --------------------\n\n");
	t.SearchPriority(100); // 우선순위 100인 노드를 찾아 그 노드의 데이터 출력
		
	printf("\n-------------------      [ t.SearchPriceRange(1, 30) ]      -------------------\n\n");
	t.SearchPriceRange(1, 30); // 가격이 1~30인 노드를 찾아 그 노드의 데이터 출력

	printf("\n-------------------     [ t.GetHeight(), t.GetCount() ]     -------------------\n\n");
	printf("[CCebBSTree의 객체 t의 높이     : %2d]\n", t.GetHeight());
	// 이진 트리의 높이를 반환하는 함수를 호출하여 반환값을 출력
	printf("[CCebBSTree의 객체 t의 노드개수 : %2d]\n", t.GetCount());
	// 이진 트리의 노드의 개수를 반환하는 함수를 호출하여 반환값을 출력
	
	getchar();// 실행 화면이 꺼지지 않도록 함
}
