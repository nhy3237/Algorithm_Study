#include <iostream>
using namespace std;

void shell(int* arr, int n); // Á¤·Ä 
void print(int* arr, int n);
void mark(int n, int sel, int change);

int main()
{
	int arr[7] = { 1,4,6,7,3,9,8 };
	int n = sizeof(arr) / sizeof(arr[0]);

	shell(arr, n);
	print(arr, n);
}

void shell(int* arr, int n)
{
	for (int i = 1; i < n; i++)
	{
		print(arr, n);

		int cnt = 0;
		for (int j = i - 1; j >= 0; j--)
		{
			if (arr[j] < arr[i - cnt]) break;
			else
			{
				int temp = arr[i - cnt];
				arr[i - cnt] = arr[j];
				arr[j] = temp;
				cnt++;
			}
		}
		mark(n, i, i - cnt);
	}
}

void print(int* arr, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

void mark(int n, int sel, int change)
{
	for (int i = 0; i < n; i++)
	{
		if (i == sel) cout << "+";
		else if (i == change) cout << "^-";
		else if (i < sel && i > change) cout << "--";
		else cout << "  ";
	}
	cout << endl;
}