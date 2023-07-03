#include <iostream>
#include <string>

using namespace std;

void reverseDisplay(int value);
void reverseDisplay(const string &s);

int cnt = 1;

int main()
{
	/*
	Q3. 다음 함수를 사용하여 값을 역으로 화면에 출력하는 코드를 작성하라.
		재귀호출을 이용하라.

		void reverseDisplay(int value)
		void reverseDisplay(const string &s)

		ex > reverseDisplay(12345)
		결과 > 54321
		
		ex > reverseDisplay("abcd")
		결과 > dcba */

	reverseDisplay(123456789);
	reverseDisplay("abcdefghi");

	return 0;
}

void reverseDisplay(int value)
{
	cout << value % 10;
	if (value / 10 > 0) return reverseDisplay(value /= 10);
	cout << "\n";
}

void reverseDisplay(const string& s)
{
	cout << s[s.size() - cnt++];
	if (s.size() >= cnt) return reverseDisplay(s);
	cout << "\n";
}