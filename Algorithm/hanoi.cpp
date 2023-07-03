#include <iostream>
#include "stack.h"

using namespace std;

int n, chk;
double x;

void Move(class Stack *A, class Stack* B, class Stack* C, int no, int start, int end);

int main()
{
	cout << "원반 최대 크기(0:exit) : ";
	cin >> n;

	while (n != 0)
	{
		if (n == 0) continue;

		Stack A, B, C;
		A.Initialize(n); B.Initialize(n); C.Initialize(n);

		for (int i = n; i > 0; i--)
		{
			A.Push(i);
		}

		Move(&A, &B, &C, n, 1, 3);

		for (int i = n - 1; i >= 0; i--) // 출력
		{
			if (A.getS(i) == 0) cout << "[ ] ";
			else cout << "[" << A.getS(i) << "] ";
			if (B.getS(i) == 0) cout << "[ ] ";
			else cout << "[" << B.getS(i) << "] ";
			if (C.getS(i) == 0) cout << "[ ] " << endl;
			else cout << "[" << C.getS(i) << "] " << endl;
		}
		cout << " A   B   C" << endl << endl;

		cout << "\n원반 최대 크기(0:exit) : ";
		cin >> n;
	}
	return 0;
}

void Move(class Stack* A, class Stack* B, class Stack* C, int no, int start, int end)
{
	if (no > 1)
	{
		Move(A, B, C, no - 1, start, 6 - start - end);
	}

	chk = 2;

	for (int i = n - 1; i >= 0; i--) // 출력
	{
		if (A->getS(i) == 0) cout << "[ ] ";
		else cout << "[" << A->getS(i) << "] ";
		if (B->getS(i) == 0) cout << "[ ] ";
		else cout << "[" << B->getS(i) << "] ";
		if (C->getS(i) == 0) cout << "[ ] " << endl;
		else cout << "[" << C->getS(i) << "] " << endl;
	}
	cout << " A   B   C" << endl << endl;

	while (chk != 0)
	{
		if (chk == 2)
		{
			if (start == 1) A->Pop(&x);
			else if(start == 2) B->Pop(&x);
			else C->Pop(&x);
		}
		else
		{
			if(end == 1) A->Push(no);
			else if(end==2) B->Push(no);
			else C->Push(no);
		}
		if (--chk == 0) break;
	}

	if (no > 1)
	{
		Move(A, B, C, no - 1, 6 - start - end, end);
	}
}