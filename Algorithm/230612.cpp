#include "queue.h"
#include "stack.h"

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
	/*
	Q3. 스택 계산기
		[후위 표기식 만들기]
		1. 연산자 우선순위는 ( ) < + - < *
		2. 중위 표기법에서 한 글자씩 읽어들인다.
		3. 읽어들인 글자가 연산자이면
			- 왼쪽 괄호이면 그냥 스택에 추가(Operator Stack)
			- 오른쪽 괄호이면 스택에서 왼쪽 괄호를 만날 때까지 하나씩 꺼내 큐로 옮겨준다.
			  왼쪽 괄호와 만나면 둘 다 버린다.
			- 나머지 사칙 연산은 그 연산자가 스택에서 꺼낸 연산자보다
			  우선순위가 높거나 같은 동안에는 계속 큐로 옮겨준다.
			  그리고 자신을 스택에 추가한다.
		4. 읽어들인 글자가 피연산자이면 큐에 넣는다. (PostFix Queue)
		
		2~4의 과정을 반복해서 후위 표기식을 만든다. (PostFix Queue)
		
		[계산 과정]
		5. 큐에서 데이터를 읽어 스택으로 옮긴다 (Operand Stack)
			- 큐에서 값을 하나씩 읽는다.
			- 피연산자이면 스택에 저장
			- 연산자이면 스택에서 값을 두 개 꺼내서 연산자에 대한 연산을 하고
			  그 결과를 다시 스택에 저장
			 
		큐에 값이 없을 때까지 5의 과정을 반복해서 최종 계산 값을 구한다. */
	char c;
	ifstream file("Calc2.txt");

	if (!file.is_open())
	{
		cout << "파일을 열 수 없습니다." << endl;
		cout << "프로그램을 종료합니다.\n";
		exit(EXIT_FAILURE);
	}

	Stack s1, s2; Queue q;
	int totSize = 0, numSize = 0;

	while (!file.eof())
	{
		c = file.get();
		totSize++;

		if (isdigit(c)) numSize++;
	}
	file.close();

	s1.Initialize(totSize); s2.Initialize(totSize); q.Initialize(totSize);

	file.open("calc2.txt");
	if (!file.is_open())
	{
		cout << "파일을 열 수 없습니다." << endl;
		cout << "프로그램을 종료합니다.\n";
		exit(EXIT_FAILURE);
	}

	string str, str2;
	double temp;
	int i = 0, j = 0, dotcnt = 1, chkNum = 0;
	int* num = new int[sizeof(int) * (numSize+1)]; 

 	while (!file.eof())
	{
		c = file.get();
		str += c;
		
		if (!isdigit(c) && c != '.') // 문자
		{
			if (chkNum)
			{
				temp = stod(str2);
				q.Enque(temp);
				chkNum = 0;
				str2.clear();

				cout << "queue : "; q.Print();
			}

			if (c == '(' || c == '*' || c == '/')
			{
				s1.Push(c);
			}
			else if (c == ')')
			{
				s1.Peek(&temp);
				while (temp != '(')
				{
					s1.Pop(&temp);
					q.Enque(temp);
					s1.Peek(&temp);
				}
				s1.Pop(&temp);
			}
			else
			{
				if (s1.Peek(&temp) == '*' || temp == '/')
				{
					s1.Pop(&temp);
					q.Enque(temp);
				}
				s1.Push(c);
			}
		}
		else // 숫자나 소수점
		{
			chkNum = 1;
			if (c != '.')
			{
				str2 += c;
				/*if (j > 0 && (isdigit(str[i - 1]) || str[i-1] == '.'))
				{*/
					if (dotcnt > 1)
					{
						str[i - 1] = str[i - 1] * pow(0.1, dotcnt) + str[i];
					}
					else
					{
						str[i - 1] = str[i - 1] * 10 + str[i];
					}
					str[i--] = NULL;
				/*}
				j++;*/
			}
			else
			{
				dotcnt++;
			}
		}
		i++;

		cout << "\n" << i << "번째 " << c << "\nstack : "; s1.Print();
		
	}
	cout << str;
	for (int k = 0; k < j; k++)
	{
		cout << num[k] << " ";
	}
	s1.Terminate(); s2.Terminate(); q.Terminate();
	file.close();

	delete[] num;

	return 0;
}