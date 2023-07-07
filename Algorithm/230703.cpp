#include <iostream>
using namespace std;

void heap(int* arr, int max); // Èü Á¤·Ä 
void print(int* arr, int n);

int main()
{
	int arr[8] = { 0,2,7,3,4,5,6,1 };
	int arr2[8];
	int n = sizeof(arr) / sizeof(arr[0]);


	heap(arr, n - 1);
}

void heap(int* arr, int max)
{
	while (max != 1)
	{
		int Temp, iTemp = 0;
		int idx = max;

		while (idx != 1)
		{
			if (idx % 2 == 0 && idx == max)
			{
				iTemp = idx;
				Temp = arr[idx];

			}


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
		int temp = arr[1];
		arr[1] = arr[max];
		arr[max] = temp;
		max--;
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