#include <iostream>
#include <math.h>
#include <string>
#include <conio.h>

using namespace std;

class Administrirovanie
{
protected:
	
public:
	virtual void show() = 0;
};

class Director : public Administrirovanie
{
	int age, zp;
	char* name;
	char* surname;
	char* gender;
	char* obrazovanie;
public:
	Director(int n, int zp1, char* name1, char* surname1, char* gender1, char* obrazovanie1)
	{
		age = n;
		zp = zp1;
		name = new char[strlen(name1) + 1];
		strcpy_s(name, strlen(name1) + 1, name1);
		surname = new char[strlen(surname1) + 1];
		strcpy_s(surname, strlen(surname1) + 1, surname1);
		obrazovanie = new char[strlen(obrazovanie1) + 1];
		strcpy_s(obrazovanie, strlen(obrazovanie1) + 1, obrazovanie1);
		gender = new char[strlen(gender1) + 1];
		strcpy_s(gender, strlen(gender1) + 1, gender1);
	}
	~Director()
	{
		delete[]name;
		delete[]surname;
		delete[]gender;
		delete[]obrazovanie;
	}
	void show()
	{
		cout << surname << " " << name << " " << age << " years old" << "\nSalary: " << zp << "$" << "\nGender: " << gender << "\nEducation: " << obrazovanie << endl << endl;
	};
};

class productManager : public Administrirovanie
{
	int age, zp;
	char* name;
	char* surname;
	int numberOfKids;
	char* type;
public:
	productManager(int n, int zp1, char* name1, char* surname1, int l, char* type1)
	{
		age = n;
		zp = zp1;
		name = new char[strlen(name1) + 1];
		strcpy_s(name, strlen(name1) + 1, name1);
		surname = new char[strlen(surname1) + 1];
		strcpy_s(surname, strlen(surname1) + 1, surname1);
		numberOfKids = l;
		type = new char[strlen(type1) + 1];
		strcpy_s(type, strlen(type1) + 1, type1);
	}
	~productManager()
	{
		delete[]name;
		delete[]surname;
		delete[]type;
	}
	void show()
	{
		cout << surname << " " << name << " " << age << " years old" << "\nSalary: " << zp << "$" << "\nAmount of children: " << numberOfKids << "\nType: " << type << endl << endl;
	};
};

class Programmer : public Administrirovanie
{
	int age, zp;
	char* name;
	char* surname;
	char* role;
	int stazh;
public:
	Programmer(int n, int zp1, char* name1, char* surname1, int p, char* role1)
	{
		age = n;
		zp = zp1;
		name = new char[strlen(name1) + 1];
		strcpy_s(name, strlen(name1) + 1, name1);
		surname = new char[strlen(surname1) + 1];
		strcpy_s(surname, strlen(surname1) + 1, surname1);
		stazh = p;
		role = new char[strlen(role1) + 1];
		strcpy_s(role, strlen(role1) + 1, role1);
	}
	~Programmer()
	{
		delete[]name;
		delete[]surname;
		delete[]role;
	}
	void show()
	{
		cout << surname << " " << name << " " << age << " years old" << "\nSalary: " << zp << "$" << "\nRole: " << role << "\nExperience: " << stazh << endl << endl;
	};
};

int writeNumbers() {
	string numbers;
	while (true) {
		int key;
		key = _getch();
		if (key == 224) {
			key = _getch();
		}
		else
			if (key == 8) {
				if (numbers.length() != 0) {
					cout << '\b' << " " << '\b';
					numbers.erase(numbers.length() - 1);
				}
			}
			else
				if (key == 13) break;
				else
					if (key >= '0' && key <= '9') {
						numbers = numbers + (char)key;
						cout << (char)key;
					}
	}
	return stoi(numbers);
}

string writeWords() {
	string slovo;
	while (true) {
		int Knopka;
		char sumbol;
		Knopka = _getch();
		if (Knopka == 224) {
			Knopka = _getch();
		}
		else
			if (Knopka == 8) {
				if (slovo.length() != 0) {
					cout << '\b' << " " << '\b';
					slovo.erase(slovo.length() - 1);
				}
			}
			else
				if (Knopka == 13) {
					break;
				}
				else {
					sumbol = (char)Knopka;
					if ((sumbol >= 'a' && sumbol <= 'z') || (sumbol >= 'A' && sumbol <= 'Z')) {
						slovo = slovo + sumbol;
						cout << sumbol;
					}
				}
	}
	return slovo;
}

int menu()
{
	int choiceButton = 0, button = 0;
	system("cls");
	while (true)
	{
		choiceButton = (choiceButton + 4) % 4;

		if (choiceButton == 0) cout << "-> Information about Director" << endl;
		else cout << " Information about Director" << endl;

		if (choiceButton == 1) cout << "-> Information about Manager" << endl;
		else cout << " Information about Manager" << endl;

		if (choiceButton == 2) cout << "-> Information about Programmer" << endl;
		else cout << " Information about Programmer" << endl;

		if (choiceButton == 3) cout << "-> Exit" << endl;
		else cout << " Exit" << endl;

		button = _getch();
		if (button == 224)
		{
			button = _getch();
			if (button == 72) choiceButton--;
			if (button == 80) choiceButton++;
		}
		if (button == 13) { system("cls"); return choiceButton; }
		system("cls");
	}
}

void directorF(Administrirovanie **p)
{
	char surnameD[80], nameD[80], genderD[80], educD[80];
	int ageD, zpD;
	cout << "Enter Director's surname: ";
	string surnameD1 = writeWords();
	strcpy_s(surnameD, surnameD1.c_str());
	cout << "\nEnter Director's name: ";
	string nameD1 = writeWords();
	strcpy_s(nameD, nameD1.c_str());
	cout << "\nEnter Director's age: ";
	ageD = writeNumbers();
	cout << "\nEnter Director's salary: ";
	zpD = writeNumbers();
	cout << "\nEnter Director's gender: ";
	string genderD1 = writeWords();
	strcpy_s(genderD, genderD1.c_str());
	cout << "\nEnter Director's education: ";
	string educD1 = writeWords();
	strcpy_s(educD, educD1.c_str());
	system("cls");
	Director director(ageD, zpD, nameD, surnameD, genderD, educD);
	p[0] = &director;
	p[0]->show();
	system("pause");
};

void managerF(Administrirovanie **p)
{
	char surnameM[80], nameM[80], typeM[80];
	int ageM, zpM, numberOfKidsM;
	cout << "Enter Manager's surname: ";
	string surnameM1 = writeWords();
	strcpy_s(surnameM, surnameM1.c_str());
	cout << "\nEnter Manager's name: ";
	string nameM1 = writeWords();
	strcpy_s(nameM, nameM1.c_str());
	cout << "\nEnter Manager's age: ";
	ageM = writeNumbers();
	cout << "\nEnter Manager's salary: ";
	zpM = writeNumbers();
	cout << "\nEnter the number of children of the manager: ";
	numberOfKidsM = writeNumbers();
	cout << "\nEnter Manager's type(junior, middle, higher): ";
	string typeM1 = writeWords();
	strcpy_s(typeM, typeM1.c_str());
	system("cls");
	productManager manager(ageM, zpM, nameM, surnameM, numberOfKidsM, typeM);
	p[1] = &manager;
	p[1]->show();
	system("pause");
};

void programmerF(Administrirovanie **p)
{
	char surnameP[80], nameP[80], roleP[80];
	int ageP, zpP, expP;
	cout << "Enter Programmer's surname: ";
	string surnameP1 = writeWords();
	strcpy_s(surnameP, surnameP1.c_str());
	cout << "\nEnter Programmer's name: ";
	string nameP1 = writeWords();
	strcpy_s(nameP, nameP1.c_str());
	cout << "\nEnter Programmer's age: ";
	ageP = writeNumbers();
	cout << "\nEnter Programmer's salary: ";
	zpP = writeNumbers();
	cout << "\nEnter Programmer's experience(how many years): ";
	expP = writeNumbers();
	cout << "\nEnter Programmer's role(application, web, systemic): ";
	string roleP1 = writeWords();
	strcpy_s(roleP, roleP1.c_str());
	system("cls");
	Programmer programmer(ageP, zpP, nameP, surnameP, expP, roleP);
	p[2] = &programmer;
	p[2]->show();
	system("pause");
};


int main()
{
	Administrirovanie *p[3];
	while (true)
	{
		int choose = menu();
		if (choose == 0)
			directorF(p);
		else
			if (choose == 1)
				managerF(p);
			else
				if (choose == 2)
					programmerF(p);
				else break;
	}
	return 0;
}