#include <iostream>

using namespace std;

int cnt = 0;

int move(int no, int i, int j, int &pos) // �� ����, ��, ��
{
	if (no > 1)
	{
		move(no - 1);
	}
}

int main()
{
	int n;

	cout << "���� ����(3������ ����:Exit) : ";
	cin >> n;

	while (n > 3)
	{
		if (n < 3) break;

		int* pos = new int(n);

		move(n, 0, 0, *pos);

		cout << "���� ����(3������ ����:Exit) : ";
		cin >> n;
	}
	return 0;
}