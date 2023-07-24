/*
Q1. 학생관리 하는 구조체를 생성하고
	번호, 이름을 멤버로 포함
	구조체 리스트 만들고
	1. 입력
		> 번호, 이름 입력받아서 리스트에 추가

	2. 삭제
		> 번호 입력 받아서 리스트에서 삭제
	
	3. 전체 출력
		> 리스트에 있는 학생의 번호와 이름을 출력
	*/

#include <iostream>
#include <string>
using namespace std;

struct Student
{
	int num;
	string name;

	Student* next;
};

struct List
{
	Student* head;
	Student* selNode;
	Student* preNode;
};

void AddList(Student*& head, Student*& selNode, int num, string name);
void DelList(Student*& head, Student*& selNode, Student*& preNode, int num);
void PrintList(Student*& head, Student *&selNode);

int main()
{
	List list;
	int n, num;
	string name;

	list.head = nullptr;

	cout << "<학생 관리 프로그램>\n(1) 입력 (2) 삭제 (3) 전체 보기 (4) 종료\n : ";
	cin >> n;

	while (n != 4)
	{
		switch (n)
		{
		case 1:
			cout << "\n(1) 입력\n > 번호 : ";
			cin >> num;
			cout << " > 이름 : ";
			cin >> name;
			AddList(list.head, list.selNode, num, name);
			break;
		case 2:
			cout << "\n(2) 삭제\n> 번호 : ";
			cin >> num;
			DelList(list.head, list.selNode, list.preNode, num);
			break;
		case 3:
			cout << "\n(3) 전체 보기\n";
			PrintList(list.head, list.selNode);
			break;
		}

		cout << "\n----------------------------------------------";
		cout << "\n(1) 입력 (2) 삭제 (3) 전체 보기 (4) 종료\n : ";
		cin >> n;
	}

	while (list.head != nullptr)
	{
		Student* std = list.head;
		list.head = list.head->next;
		delete std;
	}
}

void AddList(Student *&head, Student*& selNode, int num, string name)
{
	Student* std = new Student;
	std->num = num;
	std->name = name;
	std->next = nullptr;

	if (head == nullptr)
	{
		head = std;
	}
	else
	{
		selNode = head;

		while (selNode->next != nullptr)
		{
			selNode = selNode->next;
		}
		selNode->next = std;
	}
	cout << "\n성공적으로 추가되었습니다.\n";
}

void DelList(Student*& head, Student*& selNode, Student*& preNode, int num)
{
	if (head == nullptr)
	{
		cout << "삭제할 리스트가 없습니다.";
		return;
	}

	selNode = head;
	preNode = nullptr;

	while (selNode != nullptr)
	{
		if (selNode->num == num)
		{
			if (preNode == nullptr)
			{
				head = selNode->next;
			}
			else
			{
				preNode->next = selNode->next;
			}
			delete selNode;
			break;
		}
		preNode = selNode;
		selNode = selNode->next;
	}
	cout << "\n삭제되었습니다.\n";
}

void PrintList(Student*& head, Student*& selNode)
{
	selNode = head;

	while(selNode != nullptr)
	{ 
		cout << " " << selNode->num << "번  ";
		cout << selNode->name << endl;

		selNode = selNode->next;
	}
}

//list<int> intList;
//
//for (list<int>::iterator it = intList.begin(); it != intList.end(); it++)
//{
//}
//
//for (list<int>::reverse_iterator rit = intList.rbegin(); rit != intList.rend(); rit++)
//{
//}