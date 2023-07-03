#include <iostream>
using namespace std;

void quick(int* arr, int n); // Á¤·Ä 
void print(int* arr, int n);

int main()
{
	int arr[8] = { 8,1,4,2,7,6,3,5 };
	int n = sizeof(arr) / sizeof(arr[0]);

	quick(arr, n);
	print(arr, n);
}

void quick(int* arr, int n)
{
	int a  = 0, b = n - 1;
	int *arr1 = new int[n];
	int *arr2 = new int[n];

	while (a != b)
	{
		if (a > b)
		{
			if (arr[a] < arr[b])
			{
				int temp = arr[a];
				arr[a] = arr[b];
				arr[b] = temp;

				temp = a;
				a = b;
				b = temp + 1;
			}
			else
			{
				b++;
			}
		}
		else
		{
			if (arr[a] > arr[b])
			{
				int temp = arr[a];
				arr[a] = arr[b];
				arr[b] = temp;

				temp = a;
				a = b;
				b = temp + 1;
			}
			else
			{
				b--;
			}
		}
		print(arr, n);
	}

	delete[] arr1;
	delete[] arr2;
}

void print(int* arr, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}