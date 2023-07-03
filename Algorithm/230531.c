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
		printf("a[%d](��)�� a[%d](��)�� ��ȯ�մϴ�.\n", i, n - i - 1);
		for (int j = 0; j < n; j++)
		{
			printf("%d ", a[j]);
		}
		printf("\n");
	}
	printf("���� ������ �����մϴ�.\n");
}

int main()
{
	// Q4. p78 5������
	/*int n;

	printf("����� ���� : ");
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
	Q5.�Ҽ��� �Ǻ��ϴ� ���α׷��� �ۼ��ϰ� �����϶�.
		1. 1�� �����ϸ鼭 �Ҽ� �Ǵ�
		2. Ȧ���θ� ����ϱ�
		3. ���� ���� �Ҽ��� ������ ���� �ʴ� �� 
		4. ������ n ������ ��� �Ҽ��� �������� ��
			������ �������� �ʴ� ���� �Ҽ���� �Ѵ�.
	*/
	int count = 0;

	// 1��
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
	printf("1. ������ ���� Ƚ�� : %lu\n", count);

	// 2��
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
	printf("2. ������ ���� Ƚ�� : %lu\n", count);

	// 3��
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

	printf("3. ������ ���� Ƚ�� : %lu\n", count);

	// 4��
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

	printf("4. ������ ���� Ƚ�� : %lu\n", count);
	return 0;
}