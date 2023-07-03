#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <time.h>

/*p20 연습문제1*/
int max4(int a, int b, int c, int d)
{
	int max = a;
	if (b > max) max = b;
	if (c > max) max = c;
	if (d > max) max = d;
}

int med3(int a, int b, int c)
{
	if (a >= b)
		if (b >= c)
			return b;
		else if (a <= c)
			return a;
		else
			return c;
	else if (a > c)
		return a;
	else if (b > c)
		return c;
	else
		return b;
}

int med5(int a, int b, int c)
{
	if ((b >= a && c <= a) || (b <= a && c >= a))
		return a;
	else if ((a > b && c < b) || (a<b && c>b))
		return b;
	return c;
}

int main()
{
	/*int a, b, c, d;

	printf("네 정수를 입력하세요 : ");
	scanf("%d %d %d %d", &a, &b, &c, &d);

	printf("네 정수의 최댓값 : %d\n", max4(a, b, c, d));*/

	/*p.23 연습문제 Q4 프로그램을 작성하고 Q5와 효율성을 비교하라.*/


	int a, b, c;
	int start_time, end_time;
	float time;

	printf("세 정수의 중앙값을 구합니다.\n");
	printf("a값: "); scanf("%d", &a);
	printf("b값: "); scanf("%d", &b);
	printf("c값: "); scanf("%d", &c);

	start_time = clock();
	for (int i = 0; i < 10000000; i++)
	{
		med3(a, b, c);
	}
	end_time = clock();
	time = (double)(end_time - start_time) / CLOCKS_PER_SEC;
	printf("걸린 시간: %f\n", time);

	start_time = clock();
	for (int i = 0; i < 10000000; i++)
	{
		med5(a, b, c);
	}
	end_time = clock();
	time = (double)(end_time - start_time) / CLOCKS_PER_SEC;
	printf("걸린 시간: %f\n", time);
	return 0;
}