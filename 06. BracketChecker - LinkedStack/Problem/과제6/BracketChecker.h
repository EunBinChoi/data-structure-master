/*이 헤더파일은 괄호를 포함하는 조건문이 있으므로, 
check 함수에서는 괄호 닫기 결과가 정상으로 출력되지 않고
check2(주석이나 '' ""에 대한 예외 처리를 해줌) 함수에서는 괄호 닫기 결과가 정상으로 출력된다.
*/

#pragma once 

#include "CebLinkedStack.h" // 기본적인 연결된 스택의 기능을 담은 헤더 선언
#include <string.h>

class CCebBracketChecker // 파일에서 괄호 닫기가 정상적으로 이루어지는 지 확인하고, 문제점을 해결하는 클래스
{
	CCebLinkedStack m_st; // CCebLinkedStack(연결된 스택에서 필요한 기본적인 클래스)의 객체를 선언 
	int m_nLine; // 파일의 줄 수를 저장하는 변수 선언
	int m_nChar; // 파일의 단어 수를 저장하는 변수 선언
	char m_filename[200]; // 검사할 파일 이름을 저장할 변수 선언
	bool set; // check 함수의 검사 결과를 저장할 변수 선언

public:
	CCebBracketChecker(void){} // 생성자
	~CCebBracketChecker(void){} // 소멸자

	bool Check(char* filename){ // 파일에서 괄호 닫기가 정상적으로 이루어지는 지 확인하는 함수
		strcpy(m_filename, filename);  // Check 함수에서 인수로 받은 파일 이름을 멤버 변수인 m_filename에 저장
		FILE *fp = fopen(m_filename,"r");  // 멤버 변수에 저장된 파일을 "r"(읽기허용) 형태로 open 한다

		if(fp == NULL) // 만약 fp에 아무것도 들어오지 않으면(파일이 정상적으로 열리지 않으면)
		{ 
			printf("Error :파일 존재하지 않음\n"); // 파일이 존재하지 않는다는 메세지를 출력한다
			return 0;

		}

		m_nLine = 1; // 파일의 줄 수를 1로 초기화
		m_nChar = 0; // 파일의 단어 갯수를 0으로 초기화
		m_st.Reset(); // 연결된 스택에 값이 있으면 초기화

		char ch; // 파일을 처음부터 끝까지 읽어줄 문자형 변수 선언
		while((ch = getc(fp)) != EOF){ // fp에 담긴 파일을 EOF(end of file)까지 읽으면서 ch에 읽은 문자를 저장한다
			if(ch == '\n') // 만약 엔터가 나오면
				m_nLine ++;// 파일의 줄 수를 하나 증가시킨다
			m_nChar++; //  파일의 단어 갯수를 하나 증가시킨다
			if(ch == '[' || ch == '{' || ch == '(') { // 만약 괄호([ { ()가 나온다면

				m_st.Push(ch); // 그 값을 연결된 스택에 push 함수를 이용해서 저장한다
			}
			else if(ch == ']' || ch == '}' || ch == ')'){ // 만약 괄호(] } ))가 나온다면
				char prev = m_st.Pop(); // 바로 앞에 저장한 값을 pop 함수로 꺼내 prev에 저장한 다음
				if(((ch == ']') && (prev != '['))   
					|| ((ch == ')') && (prev != '('))
					||((ch == '}') && (prev != '{'))){ // 두 개의 값이 짝이 맞는 지 확인한다([],{},())

						set = false; // 만약 두 개의 짝이 맞지 않는다면 set을 false으로 바꿔주고,  
						break;	// 두 개의 짝이 맞지 않는다면 braek문으로 빠져나온다
				}
			} 
			set = true; 
			// 만약 break문으로 while문을 빠져나가지 않으면 정상적으로 while문이 종료하게 되므로 그것은 괄호닫기가 정상적으로 이루어진다는 것이다.
			// set을 true로 변경한다.
		}

		fclose(fp); // 괄호가 정상적으로 닫혔는 지 검사하기 위해 열었던 파일을 닫아준다
		PrintResult(); // 파일이 정상적으로 담겼는지, 파일의 줄 수와 파일의 단어 갯수는 몇개인지 출력해주는 함수 호출
		return set; // check 함수의 검사 결과를 저장한 set 변수를 반환한다

	}

	bool Check2(char* filename){ // 파일에서 괄호 닫기가 정상적으로 이루어지는 지 확인하고, 정상적으로 이루어지지 않는다면 그것을 해결하는 함수

		strcpy(m_filename, filename); // check2 함수의 인수로 들어온 파일의 이름을 멤버변수인 m_filename에 복사
		FILE *fp = fopen(m_filename,"r"); // 멤버 변수에 저장된 파일을 "r"(읽기허용) 형태로 open 한다

		if(fp == NULL) // 만약 fp에 아무것도 들어오지 않으면(파일이 정상적으로 열리지 않으면)
		{ 
			printf("Error :파일 존재하지 않음\n"); // 파일이 존재하지 않는다는 메세지를 출력한다
			return 0;

		}

		m_nLine = 1; // 파일의 줄 수를 1로 초기화
		m_nChar = 0; // 파일의 단어 갯수를 0으로 초기화
		m_st.Reset(); // m_top을 0으로 초기화함(다른 값이 들어와있을 수 있으므로 미리 방지하는 작업)


		char ch; // 파일을 처음부터 끝까지 읽어줄 문자형 변수 선언
		char ch2 = 0; // 파일을 처음부터 끝까지 읽을 때, 이전 값을 저장할 문자형 변수 선언

		int cnt1 = 0, cnt2 = 0, cnt3 = 0, cnt4 = 0; 
		// ' '나 " " 나 // */에 있는 괄호를 무시해주기 위한 작업
		// cnt1은  '의 갯수를 저장, cnt2는 "의 갯수를 저장, cnt3 //의 갯수를 저장, cnt4는 /*의 갯수를 저장


		while((ch = getc(fp)) != EOF) // 파일의 끝(end of file)일 때까지 파일을 돌면서 문자 하나를 받아들이면서
		{ 

			m_nChar++; // m_nChar(단어의 갯수)를 증가시킨다

			if(ch == '\n') { // 만약 받아들인 단어가 엔터라면

				cnt3 = 0; // cnt3(//의 갯수를 저장하는 변수)를 0으로 초기화 한다(//의 끝을 만났으므로)
				m_nLine ++; // 받아들인 단어가 엔터면 그 다음부터 다음 줄이 되므로 m_nLine(줄의 수)를 증가시킨다
			}

			else if(ch == 39 && cnt3 == 0 && cnt4 == 0) // 만약 받아들인 단어가 ' 이면(주석이 아닌 상태에서)
			{
				cnt1++;// cnt1('의 갯수를 저장하는 변수)를 하나 증가시킨다

				if(cnt1 == 2) // 만약 cnt1가 2가 되면
					cnt1 = 0; // cnt1은 0으로 초기화해준다('가 두개 만났다는 뜻이므로, ''안에 있는 값은 무시하기 위해)
			}

			else if(ch == 34 && cnt3 == 0 && cnt4 == 0)  // 만약 받아들인 단어가 "이면(주석이 아닌 상태에서)
			{
				cnt2++; // cnt2("의 갯수를 저장하는 변수)를 하나 증가시킨다

				if(cnt2 == 2) // 만약 cnt2가 2가 되면
					cnt2 = 0; // cnt2은 0으로 초기화해준다("를 두개 만났다는 뜻이므로, ""안에 있는 값은 무시하기 위해)
			}


			else if(ch2 == 47 ) 
			{
				if(ch == 47 && cnt3 == 0 && cnt4 == 0){ //만약 이전의 값과 현재 값이 // 이면 (주석이 아닌 상태에서)
					cnt3++; // cnt3(//의 갯수를 저장하는 변수)를 하나 증가시킨다

				}

				else if(ch == 42 && cnt3 == 0 && cnt4 == 0)  // 만약 이전의 값과 현재 값이 /*이면 (주석이 아닌 상태에서) 
				{
					cnt4++; // cnt4(/*의 갯수를 저장하는 변수)를 하나 증가시킨다
				}
			}


			else if(ch2 == 42 )
			{

				if(ch == 47 && cnt4 ==1){// 만약 이전의 값과 현재 값이 */이고, cnt4(/*의 갯수를 저장하는 변수)가 1이라면
					cnt4++;  // cnt4를 하나 증가시킨다
					if(cnt4  == 2) // 만약 cnt4가 2라면(/*~~*/가 짝을 만났다면) 
						cnt4 = 0; // cnt4는 0으로 초기화한다

				}
			}

			if(cnt1 == 0 && cnt2 == 0 && cnt3 == 0 && cnt4 == 0 ) // ' ', " ", //, /*~*/ 에 해당되지 않은 상태에서
			{

				if(ch == '[' || ch == '{' || ch == '(') { // ch 값에 [.{.(와 같은 괄호가 들어오면
					m_st.Push(ch); // 연결된 스택에 그 괄호를 집어넣고

				}
				else if(ch == ']' || ch == '}' || ch == ')'){ // 만약 위와 같은 괄호의 쌍(],},))가 들어오면
					char prev = m_st.Pop(); // 연결된 스택에 넣었던 괄호를 꺼내서
					if(((ch == ']') && (prev != '['))  
						|| ((ch == ')') && (prev != '('))
						||((ch == '}') && (prev != '{'))) {/*짝이 맞는지 확인하고 짝이 맞지 않으면 break문으로 빠져나온다*/
							set = false; // 만약 두 개의 짝이 맞지 않는다면 set을 false으로 바꿔주고,  
							break;	// 두 개의 짝이 맞지 않는다면 braek문으로 빠져나온다
					}
				}
			}

			ch2 = ch;// 현재(ch)값을 다시 받으면서 현재 값을 이전의 값으로 생각해줌
			set = true; // 만약 break문으로 while문을 빠져나가지 않으면 정상적으로 while문이 종료하게 되므로 그것은 괄호닫기가 정상적으로 이루어진다는 것이다.
			// set을 true로 변경한다.
		}

		fclose(fp); // 괄호 닫기의 프로그램을 하기위해 open 시켰던 파일을 닫아준다
		PrintResult(); // 파일의 괄호 검사결과를 출력하기 위한 함수 호출
		return set;  // check 함수의 검사 결과를 저장한 set 변수를 반환한다

	}

	void PrintResult(){ // 파일의 괄호 검사결과를 출력하기 위한 함수 
		printf("   [%s] 파일 검사결과\n",m_filename);

		if(set == true && m_st.IsEmpty() == true) 
			// 만약 check의 결과가 true이고 링크드 리스트가 비어있으면 괄호 닫기 프로그램이 정상적이라는 말이므로 다음과 같은 메시지를 출력한다
		{
			printf("     OK: 괄호닫기 정상\n"); 
			printf("      파일의 라인 개수 = %d\n", m_nLine); // 파일의 라인 개수를 저장한 m_nLine을 출력
			printf("      파일의 문자 개수 = %d\n", m_nChar); // 파일의 문자 개수를 저장한 m_nChar을 출력
		}

		else if(set == false || m_st.IsEmpty() == false){
			// 만약 check의 결과가 false이거나 연결된 스택이 비어있지 않으면
			// 괄호 닫기 프로그램이 비정상적이라는 말이므로 다음과 같은 메시지를 출력한다
			printf("    Error (Line %d): 괄호 닫기 문제 발견\n",m_nLine);
		}
		printf("\n");
	}
};
