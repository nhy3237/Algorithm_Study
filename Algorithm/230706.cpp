#include <iostream>
using namespace std;

void freq(int* arr, int n);
void print(int* arr, int n);

int main()
{
	int arr[9] = { 5,7,0,2,4,10,3,1,3 };
	int n = sizeof(arr) / sizeof(arr[0]);

	freq(arr, n);
	print(arr, n);

	return 0;
}

void freq(int *arr, int n)
{
	int max = arr[0];

	for (int i = 1; i < n; i++)
	{
		if (max < arr[i]) max = arr[i];
	}

	int* f = new int[max + 1];
	
	for (int i = 0; i < max + 1; i++)
	{
		f[i] = 0;
	}

	for (int i = 0; i < n; i++)
	{
		f[arr[i]]++;
	}

	int cnt = 0;

	for (int i = 0; i < max + 1; i++)
	{
		for (int j = 0; j < f[i]; j++)
		{
			arr[cnt] = i;
			cnt++;
		}
	}
	delete[] f;
}

void print(int* arr, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}