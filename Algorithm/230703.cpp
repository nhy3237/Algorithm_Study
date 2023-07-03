#include <iostream>
using namespace std;

void heap(int* arr, int max); // Èü Á¤·Ä 
void sort(int* arr, int max);
void print(int* arr, int n);


int main()
{
	int arr[8] = { 0,2,7,3,4,5,6,1 };
	int n = sizeof(arr) / sizeof(arr[0]);

	heap(arr, n - 1);
	sort(arr, n - 1);
}

void heap(int* arr, int max)
{
	int Temp, iTemp = 0;
	int idx = max;

	while(idx != 1)
	{
		if (arr[idx] > arr[idx - 1])
		{
			iTemp = idx;
			Temp = arr[idx];
		}
		else
		{
			iTemp = idx - 1;
			Temp = arr[idx - 1];
		}
		
		if (arr[(idx - 1) / 2] < Temp)
		{
			arr[iTemp] = arr[(idx - 1) / 2];
			arr[(idx - 1) / 2] = Temp;


			if (iTemp < max)
			{
				int idx2;
				if (arr[iTemp * 2] > arr[iTemp * 2 + 1])
				{
					idx2 = iTemp * 2;
					Temp = arr[iTemp * 2];
				}
				else
				{
					idx2 = iTemp * 2 + 1;
					Temp = arr[iTemp * 2 + 1];
				}
				if (arr[iTemp] < Temp)
				{
					print(arr, max);
					arr[idx2] = arr[iTemp];
					arr[iTemp] = Temp;
				}
			}
		}
		print(arr, max);

		idx -= 2;
	}
}

void sort(int* arr, int max)
{
	int* arr1 = new int[max];

	for (int i = max; i < 0; i--)
	{

	}
}


void print(int* arr, int n)
{
	for (int i = 1; i <= n; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}