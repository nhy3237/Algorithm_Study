#include <iostream>
#include <iomanip>
#include "StopWatch.h"
using namespace std;

void print(int* arr, int n, int fix, int min)
{
	for (int i = 0; i < n; i++)
	{
		if (fix == i) cout << "* ";
		else if (min == i) cout << "+ ";
		else cout << "  ";
	}
	cout << endl;

	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

void selection1(int* arr, int n)
{
	//cout << "<선택 정렬 1>" << endl;
	for (int i = 0; i < n - 1; i++)
	{
		int min = i;
		for (int j = i + 1; j < n; j++)
		{
			if (arr[min] > arr[j])
			{
				min = j;
			}
		}
		//print(arr, n, i, min);

		int temp = arr[min];
		arr[min] = arr[i];
		arr[i] = temp;
	}
	//print(arr, n, n - 1, n);
}

void selection2(int* arr, int n)
{
	//cout << "<선택 정렬 2>" << endl;
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (arr[i] > arr[j])
			{
				//print(arr, n, i, j);
				int temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
	//print(arr, n, n - 1, n);
}

void bubble(int* arr, int n)
{
	cout << "<버블 정렬>" << endl;
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < n - i - 1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				for (int i = 0; i < n; i++)
				{
					cout << arr[i] << " ";
				}
				cout << endl;

				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
		cout << endl;
	}
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

int main()
{
	/* Q1.p226 Q7 처럼 단순 선택 정렬 과정을 표시하라.
		버블, 선택 정렬1, 2 속도를 비교*/
	int arr[7] = { 6, 4, 8, 3, 1, 9, 7 };
	int n = sizeof(arr) / sizeof(arr[0]);
	int* temp = new int[n];

	//selection1(arr, n);
	//selection2(arr, n);

	StopWatch sw;

	sw.start();

	for (double i = 0; i < 10000000; i++)
	{
		for (int j = 0; j < n; j++)
		{
			temp[j] = arr[j];
		}
		//bubble(temp, n);
		//selection2(temp, n);
		selection1(temp, n);
	}
	sw.stop();

	cout<< "선택 정렬1 걸린 시간 : " << sw.getElapsedTime() << endl;

	return 0;
}