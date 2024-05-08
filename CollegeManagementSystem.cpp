#include <bits/stdc++.h>
using namespace std;
class Student
{
public:
	long int rollNo;
	string name, branch;
	void input()
	{
		system("CLS");
		cout << "\n Enter Your Name : ";
		cin >> name;
		cout << "\n Enter Your Roll No. : ";
		cin >> rollNo;
		fflush(stdin);
		cout << "\n Enter Your Branch : ";
		cin >> branch;
	}
	void display()
	{
		system("CLS");
		system("color 0E");
		cout << "\t \t Displaying Records : \n";
		cout << "\n Name :- " << name;
		cout << "\n Roll No. :- " << rollNo;
		cout << "\n Branch :- " << branch;
		cout << "\n";
		system("PAUSE");
		system("CLS");
	}
	bool operator==(Student a)
	{
		if (rollNo == a.rollNo)
			return true;
		else
			return false;
	}
};

vector<Student> V;

int search_rollNo(long int rollNo, int &i);

void get_file()
{
	Student x;
	int i = 0;
	fstream f;
	f.open("College.txt", ios::in);
	if (f)
	{
		f.read((char *)&x, sizeof(class Student));
		while (!f.eof())
		{
			V.push_back(x);
			f.read((char *)&x, sizeof(class Student));
		}
	}
	else
		;
	f.close();
}

void bubblesort()
{
	int i, j;
	Student x;
	for (i = 0; i < V.size(); i++)
		for (j = 0; j < V.size() - i - 1; j++)
			if (V[j].rollNo > V[j + 1].rollNo)
			{
				x = V[j];
				V[j] = V[j + 1];
				V[j + 1] = x;
			}
}

void Add()
{
	char ch = 'y';
	int ta;
	while (ch == 'y')
	{
		fflush(stdin);
		Student x;
		x.input();
		if (search_rollNo(x.rollNo, ta) == 0)
			V.push_back(x);
		else
			cout << "\nTHE REGISTRATION NO. ALREADY EXIST!!!\nCANNOT ADD";
		cout << "\n Press [Y] to enter more and any other character to exit : ";
		cin >> ch;
		fflush(stdin);
	}
}

void write_file()
{
	bubblesort();
	fstream f;
	f.open("College.txt", ios::out);
	for (int i = 0; i < V.size(); i++)
	{
		Student x = V[i];
		f.write((char *)&x, sizeof(class Student));
	}
	f.close();
}

int search_rollNo(long int rollNo, int &i)
{
	int ta = 0;
	for (i = 0; i < V.size(); i++)
		if (V[i].rollNo == rollNo)
		{
			ta = 1;
			break;
		}
	return ta;
}

int search_name(string name, vector<int> &vi)
{
	int i, ta = 0;
	for (i = 0; i < V.size(); i++)
		if (strcmp((V[i].name).c_str(), name.c_str()) == 0)
		{
			ta = 1;
			vi.push_back(i);
		}
	return ta;
}
int search_branch(string branch, vector<int> &vj)
{
	int i, ta = 0;
	for (i = 0; i < V.size(); i++)
		if (strcmp((V[i].branch).c_str(), branch.c_str()) == 0)
		{
			ta = 1;
			vj.push_back(i);
		}
	return ta;
}

void Search()
{
	int ch, i, ta = 0;
	string name, branch;
	vector<int> vi;
	vector<int> vj;
	long int rollNo;
poi:
	system("CLS");
	system("color 01");
	cout << "\n Press '1' to search roll no."
		 << "\n Press '2' to search name"
		 << "\n Press '3' to search branch \n";
	cin >> ch;
	switch (ch)
	{
	case 1:
		cout << "\n Enter roll no. : ";
		cin >> rollNo;
		if (search_rollNo(rollNo, i) == 1)
			V[i].display();
		else
			cout << "\n Record NOT FOUND!!!";
		break;
	case 2:
		cout << "\n Enter name : ";
		fflush(stdin);
		cin >> name;
		if (search_name(name, vi) == 1)
		{
			for (int j = 0; j < vi.size(); j++)
				V[vi[j]].display();
		}
		else
			cout << "\n Record NOT FOUND!!!";
		break;
	case 3:
		cout << "\n Enter branch: ";
		fflush(stdin);
		cin >> branch;
		if (search_branch(branch, vj) == 1)
		{
			for (int j = 0; j < vj.size(); j++)
				V[vj[j]].display();
		}
		else
			cout << "\n Record NOT FOUND!!!";
		break;
	default:
		cout << "\n Wrong CHOICE!!!";
		goto poi;
	}
}

void Display()
{
	int i;
	for (i = 0; i < V.size(); i++)
		V[i].display();
}

void Remove()
{
	int i, j;
	long int rollNo;
	vector<Student>::iterator p = V.begin();
	system("CLS");
	system("color 04");
	cout << "\nEnter Roll no.: ";
	cin >> rollNo;
	if (search_rollNo(rollNo, i) == 1)
	{
		Student x = V[i];
		cout << "\nThe following data is being deleted";
		x.display();
		p += i;
		V.erase(p, p + 1);
	}
}

void Edit()
{
	int i, j;
	long int rollNo;
	vector<Student> vi;
	system("CLS");
	system("color 05");
	cout << "\nEnter Roll no.: ";
	cin >> rollNo;
	if (search_rollNo(rollNo, i) == 1)
	{
		cout << "\nEnter new data:";
		fflush(stdin);
		V[i].input();
	}
}

int main()
{
	int i = 1;
	get_file();
	while (i)
	{
		system("CLS");
		system("color 0A");
		cout << "\t\t\t-----------------------------------------\n";
		cout << "\t\t\t        College Management System\n";
		cout << "\t\t\t-----------------------------------------\n";
		cout << "\n\t\t\tEnter <1> to Add new student"
			 << "\n\t\t\tEnter <2> to Display all student"
			 << "\n\t\t\tEnter <3> to Remove student"
			 << "\n\t\t\tEnter <4> to Edit student"
			 << "\n\t\t\tEnter <5> to Search student"
			 << "\n\t\t\tEnter <0> to Exit\n";
		cout << "\n\n\t\t\tEnter Your Choice:";
		cin >> i;
		switch (i)
		{
		case 1:
			Add();
			break;
		case 2:
			Display();
			break;
		case 3:
			Remove();
			break;
		case 4:
			Edit();
			break;
		case 5:
			Search();
			break;
		case 0:
			write_file();
			break;
		default:
			cout << "\n Wrong Choice !!! \n Try Again";
		}
	}
	return 0;
}
