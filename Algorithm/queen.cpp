#include <iostream>

using namespace std;

int cnt = 0;

int move(int no, int i, int j, int &pos) // 퀸 개수, 행, 열
{
	if (no > 1)
	{
		move(no - 1);
	}
}

int main()
{
	int n;

	cout << "퀸의 개수(3이하의 정수:Exit) : ";
	cin >> n;

	while (n > 3)
	{
		if (n < 3) break;

		int* pos = new int(n);

		move(n, 0, 0, *pos);

		cout << "퀸의 개수(3이하의 정수:Exit) : ";
		cin >> n;
	}
	return 0;
}