#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int sumof(int a, int b);
void nrpira(int n);

int main()
{
	////p.33 Q8
	//int N, sum;

	//scanf("%d", &N);

	//sum = 0;

	//for (int i = 0; i < N / 2; i++)
	//{
	//	sum += 1 + N;
	//}

	//if (N % 2 != 0)
	//{
	//	sum += N / 2 + 1;
	//}

	//printf("%d", sum);

	////p.33 Q9, 문제 8번을 확장해서 작성
	//int a, b;

	//scanf("%d %d", &a, &b);

	//if (a < b)
	//{
	//	printf("%d", sumof(a, b));
	//}
	//else
	//{
	//	printf("%d", sumof(b, a));
	//}
	
	/*Q4.p.42 연습문제 18을 응용해서 n단의 숫자 모래시계를 출력하는 프로그램을 작성하라.
		ex> 3				2 
			1 1 1 1 1		1 1 1
			  2 2 2			  2
			    3			1 1 1
			  2 2 2
			1 1 1 1 1				*/

	int n;

	scanf("%d", &n);

	nrpira(n);
	return 0;
}

void nrpira(int n)
{
	int num, totLength = 2 * n - 1; // 출력할 숫자, 행열 길이

	for (int i = 0; i < totLength; i++)
	{
		if (i < n)
		{
			num = i + 1;
		}
		else
		{
			num = totLength - i;
		}

		for (int j = 0; j < totLength; j++)
		{
			if (num - 1 <= j && j <= totLength - num )
			{
				printf("%d", num);
			}
			else
			{
				printf(" ");
			}
		}
		printf("\n");
	}
}

int sumof(int a, int b)
{
	int sum;
	sum = 0;

	for (int i = 0; i < (b - a + 1) / 2; i++)
	{
		sum += a + b;
	}

	if ((b - a + 1) % 2 != 0)
	{
		sum += (b - a) / 2 + a;
	}

	return sum;
}
