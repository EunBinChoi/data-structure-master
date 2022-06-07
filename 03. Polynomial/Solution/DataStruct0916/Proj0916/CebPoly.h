#pragma once 
//#include할 때 여러번 include 되는 것을 방지
//#ifndef ~ #def .. 이걸 줄임말로 pragma once이다
#include <stdio.h> // 표준 라이브러리 헤더를 선언한다
#define MAX_DEGREE 100  // MAX_DEGREE를 100으로 매크로를 이용하여 상수선언을 한다

class CCebPoly // 다항식의 계산을 수행하는 클래스
{
	int m_degree; // 다항식의 최고차항의 차수(지수)
	double m_coef[MAX_DEGREE]; // 각 항의 대한 계수

public: // 접근 가능한 pulic
	CCebPoly(void) : m_degree(0){}; // 생성자(멤버 초기화 리스트)->최대 차수를 0으로 초기화
	~CCebPoly(void){} // 소멸자


	//다항식의 내용을 입력받는 멤버함수로, str의 디폴트값을 CCebPoly로 준다
	void Read(char *str = "CCebPoly"){ 
		
		printf("\t다항식 %s의 최고 차수 입력 : ",str); // 다항식의 최고 차수를 입력받기 위한 출력문
		scanf("%d", &m_degree); // 멤버변수 m_degree에 최고 차수를 입력받음
		printf("\n");
		printf("\t각 항의 계수 %d개 입력 (예 : 2 -2 4 2)\n", m_degree + 1); // 다항식의 항의 계수를 입력받기 위한 출력문
		printf("\t  계수 입력 : ");  
		for(int i = 0 ;i<=m_degree; i++) // 반복문을 최고 차수까지 돌면서 사용자에게 항의 계수를 입력받는다
		{
			scanf("%lf", &m_coef[i]); // m_coef + i와 같다

		}
		printf("\n");
	};

	//다항식의 내용을 화면에 출력하는 멤버함수로, str의 디폴트값을 CCebPoly로 준다
	void Print(char *str = "CCebPoly"){
		printf("%s", str); // str 출력

		for(int i = 0 ; i < m_degree ; i++) // 반복문을 최고 차수까지 돌면서 항의 계수를 출력해준다
		{
			printf("(%4.2lfx^%d) + ", m_coef[i], m_degree-i );
		}

		printf("(%4.2lf)", m_coef[m_degree]); // 마지막 항은 + 을 출력할 필요없으므로, 따로 처리해준다
		printf("\n");
	};


	//다항식의 내용을 화면에 출력하는 함수로, 위의 Print 함수와 다른 점은 항의 계수 값이 0이면 출력하지 않는 다는 것이다
	void Print2(char *str = "CCebPoly"){

		printf("%s", str); // str 출력

		if(m_degree > 0) // 만약 최고차항이 양수이면
		{
			printf("%4.2lfx^%d ", m_coef[0], m_degree ); // 최고차항의 계수부터 출력하고 .. 

			for(int i = 1; i < m_degree; i ++) // 반복문을 돌면서 .. 
			{
				if(m_coef[i] > 0) // 만약 최고차항의 계수를 제외하고 0보다 큰 계수가 나오면
				{
					printf(" + %4.2lfx^%d ", m_coef[i], m_degree - i); // + 로 출력
				}


				else if(m_coef[i] < 0) // 만약 최고차항의 계수를 제외하고 0보다 작은 계수가 나오면

				{
					printf(" - %4.2lfx^%d ", -m_coef[i], m_degree - i); // - 로 출력
				}


				else if(m_coef[i]==0){} // 만약 최고차항의 계수를 제외하고 0과 같은 계수가 나오면 출력하지 않음



			}


			/* 마지막 상수항을 출력하는 부분 */

			if(m_coef[m_degree] > 0){ // 상수항이 0보다 크면

				printf(" + %4.2lf ", m_coef[m_degree]); // + 로 출력
			}
			 
			else if (m_coef[m_degree] < 0){ // 상수항이 0보다 작으면

				printf(" - %4.2lf ", -m_coef[m_degree]); // - 로 출력
			}

			else // 만약 상수항이 0과 같으면
			{} // 출력하지 않는다

		}

		else if(m_degree == 0){ // 만약 최고차항이 0이면 
			printf("%4.2lf", m_coef[m_degree]); // 상수항만 출력
		}

		else{} // 만약 최고차항이 음수이면 아무것도 출력하지 않는다.

		printf("\n");

	};




	
	//다항식 a와 b를 더하는 함수
	void Add(CCebPoly& a, CCebPoly& b){ // CCebPoly 클래스의 객체인 a와 b를 참조함 
		if(a.m_degree > b.m_degree){// 만약 a의 최고차수가 b의 최고차수보다 크면..
			*this = a; // 객체 a를 자기 자신으로 가리킴(최고차수가 큰 다항식이 기준이 됨)
			for(int i = 0 ; i <= b.m_degree; i++){ //  b의 최고차수만큼 반복문을 돌면서

				m_coef[i + (m_degree-b.m_degree)] += b.m_coef[i]; 
				// 인덱스에는 a와 b의 최고차수를 뺀 것과 i를 더한 것을 저장하고, 이 인덱스의 값과 b에서 i번째에 해당하는 계수를 더해준다
				// 이렇게 해주는 이유는 i의 0번째에는 이미 객체 a를 자기 자신을 가르키게 하였으므로, 0번째 값에는 a의 최고차수에 해당하는 값이 이미 대입되어있다.
				// 그리고 인덱스에 a와 b의 차수를 뺀 것만큼 더하면서 a의 계수와 b의 계수를 더해주면 되는 것이다.
			}

		}
		else{ // 만약 b의 최고차수가 a의 최고차수보다 크면..
			*this = b; // 객체 b를 자기 자신으로 가리킴(최고차수가 큰 다항식이 기준이 됨)
			for(int i = 0 ; i <= a.m_degree; i++){ // a의 최고차수만큼 반복문을 돌면서

				m_coef[i + (m_degree-a.m_degree)] += a.m_coef[i];
				// 인덱스에는 b와 a의 최고차수를 뺀 것과 i를 더한 것을 저장하고, 이 인덱스의 값과 a에서 i번째에 해당하는 계수를 더해준다
				// 이렇게 해주는 이유는 i의 0번째에는 이미 객체 b 자기 자신을 가르키게 하였으므로, 0번째 값에는 b의 최고차수에 해당하는 값이 이미 대입되어있다.
				// 그리고 인덱스에 b와 a의 차수를 뺀 것만큼 더하면서 a의 계수와 b의 계수를 더해주면 되는 것이다.
			}

		}

	}

	//다항식 a와 b를 곱하는 함수
	void Mult(CCebPoly& a, CCebPoly& b){ // CCebPoly 클래스의 객체인 a와 b를 참조함

		m_degree = a.m_degree + b.m_degree; // 다항식 a와 b를 곱했을 때, 최고차수는 a의 최고차수와 b의 최고차수를 더한 만큼이다.

		for(int k =0 ; k <= m_degree ; k ++) // 반복문을 돌면서 m_coef를 초기화해준다.
		{
			m_coef[k] = 0;
		}
		
		for(int z =0 ; z <= m_degree ; z++){ // m_coef의 인덱스를 변화시켜줄 반복문
			for(int x = 0 ; x <= a.m_degree ; x ++){ // a.m_coef의 인덱스를 변화시켜줄 반복문
				for(int y = 0 ; y <= b.m_degree ; y ++){ // b.m_coef의 인덱스를 변화시켜줄 반복문

					if(z == x+y){ // 만약 x와 y를 더한 것이 z와 같으면 x의 인덱스에 해당하는 계수의 값과 y의 인덱스에 해당하는 계수의 값을 곱해서 m_coef에 대입한다
					m_coef[z] += a.m_coef[x] * b.m_coef[y];
					}


				}

			}
		}

	}



	// 최고차항 계수가 0이면 최고차항 줄이는 함수
	void Trim() {
		int k = 0;


		/*상수항만 뺴고 나머지의 최고차항의 계수가 0인 경우*/
		for(int i=0; i <= m_degree; i++) { 
			if(i == m_degree ) { // 모든 차수의 계수가 0이라 상수항만 남은 경우

				
				m_coef[0] = m_coef[m_degree]; 
				m_degree = 0; 
				return;
			}
			if(m_coef[i] != 0) break; // 만약 차수의 계수가 0이 아니면 반복문에서 빠져나온다
		}

		/*상수항 말고 나머지항에 0이 있는 경우*/
		for(int i=0; i<= m_degree ; i++) {
			if(m_coef[i] == 0) {
				m_degree = m_degree -1;
				k++;  // 0이 있는 항이 몇개인지 알기 위해 k라는 변수에 젖아한다.
			}
			else if (m_coef[i] != 0) break; 
		}


		for(int i=0; i <= m_degree; i++) { // 0이 k만큼 있으니, 계수가 0인 것은 최고차항을 줄여야 하므로, 인덱스에 k만큼 더해서 미뤄주면 된다.
			m_coef[i] = m_coef[i+k];
		}


	}
};


