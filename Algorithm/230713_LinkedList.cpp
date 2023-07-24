/*
Q1. �л����� �ϴ� ����ü�� �����ϰ�
	��ȣ, �̸��� ����� ����
	����ü ����Ʈ �����
	1. �Է�
		> ��ȣ, �̸� �Է¹޾Ƽ� ����Ʈ�� �߰�

	2. ����
		> ��ȣ �Է� �޾Ƽ� ����Ʈ���� ����
	
	3. ��ü ���
		> ����Ʈ�� �ִ� �л��� ��ȣ�� �̸��� ���
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

	cout << "<�л� ���� ���α׷�>\n(1) �Է� (2) ���� (3) ��ü ���� (4) ����\n : ";
	cin >> n;

	while (n != 4)
	{
		switch (n)
		{
		case 1:
			cout << "\n(1) �Է�\n > ��ȣ : ";
			cin >> num;
			cout << " > �̸� : ";
			cin >> name;
			AddList(list.head, list.selNode, num, name);
			break;
		case 2:
			cout << "\n(2) ����\n> ��ȣ : ";
			cin >> num;
			DelList(list.head, list.selNode, list.preNode, num);
			break;
		case 3:
			cout << "\n(3) ��ü ����\n";
			PrintList(list.head, list.selNode);
			break;
		}

		cout << "\n----------------------------------------------";
		cout << "\n(1) �Է� (2) ���� (3) ��ü ���� (4) ����\n : ";
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
	cout << "\n���������� �߰��Ǿ����ϴ�.\n";
}

void DelList(Student*& head, Student*& selNode, Student*& preNode, int num)
{
	if (head == nullptr)
	{
		cout << "������ ����Ʈ�� �����ϴ�.";
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
	cout << "\n�����Ǿ����ϴ�.\n";
}

void PrintList(Student*& head, Student*& selNode)
{
	selNode = head;

	while(selNode != nullptr)
	{ 
		cout << " " << selNode->num << "��  ";
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