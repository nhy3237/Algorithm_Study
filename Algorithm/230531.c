#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void ary_reverse(int a[], int n)
{
	int temp;

	for (int i = 0; i < n / 2; i++)
	{
		temp = a[i];
		a[i] = a[n - i - 1];
		a[n - i - 1] = temp;
		printf("a[%d](와)과 a[%d](을)를 교환합니다.\n", i, n - i - 1);
		for (int j = 0; j < n; j++)
		{
			printf("%d ", a[j]);
		}
		printf("\n");
	}
	printf("역순 정렬을 종료합니다.\n");
}

int main()
{
	// Q4. p78 5번문제
	/*int n;

	printf("요소의 개수 : ");
	scanf("%d", &n);

	int* a = malloc(sizeof(int) * n);

	for (int i = 0; i < n; i++)
	{ 
		printf("a[%d] : ", i);
		scanf("%d", &a[i]);
	}

	ary_reverse(a, n);

	free(a);*/

	/*
	Q5.소수를 판별하는 프로그램을 작성하고 개선하라.
		1. 1씩 증가하면서 소수 판단
		2. 홀수로만 계산하기
		3. 이전 계산된 소수로 나누어 지지 않는 수 
		4. 제곱근 n 이하의 모든 소수로 나누었을 때
			나누어 떨어지지 않는 수를 소수라고 한다.
	*/
	int count = 0;

	// 1번
	for (int n = 2; n <= 1000; n++)
	{
		int i;
		for (i = 2; i < n; i++)
		{
			count++;
			if (n % i == 0)
			{
				break;
			}
		}

		if (n == i)
		{
			printf("%d ", n);
		}
	}
	printf("1. 나눗셈 실행 횟수 : %lu\n", count);

	// 2번
	count = 0;

	for (int n = 3; n < 1000; n += 2)
	{
		for (int i = 3; i < n; i += 2)
		{
			count++;
			if (n % i == 0)
			{
				break;
			}
		}
	}
	printf("2. 나눗셈 실행 횟수 : %lu\n", count);

	// 3번
	count = 0;
	int prime1[500];
	int arr = 0;

	prime1[arr] = 2;

	for (int n = 3; n < 1000; n += 2)
	{
		int i;
		for (i = 1; i < arr + 1; i++)
		{
			count++;
			if (n % prime1[i] == 0)
			{
				break;
			}
		}
		if (i == arr + 1)
		{
			arr++;
			prime1[arr] = n;
		}
	}

	printf("3. 나눗셈 실행 횟수 : %lu\n", count);

	// 4번
	count = 0;
	arr = 0;
	int prime2[500];

	prime2[arr] = 2;

	for (int n = 3; n < 1000; n += 2)
	{
		int i, flag = 0;
		for (i = 0; prime2[i] <= sqrt(n); i++)
		{
			count++;
			if (n % prime2[i] == 0)
			{
				flag = 1;
				break;
			}
		}
		if (flag != 1)
		{
			arr++;
			prime2[arr] = n;
		}
	}

	printf("4. 나눗셈 실행 횟수 : %lu\n", count);
	return 0;
}