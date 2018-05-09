#include "stdafx.h"
#include "windows.h"
#include <iostream>
#include <string>
#include <vector>

HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
using namespace std;

struct Cha {
	int maxHP;
	int maxMP;
	int hp;
	int mp;
	string name = "None";
	int co;
	int ca;
} Cha;

void wait_enter(void) //Method of wait_enter, call it to create a Press Enter to continue screen.
{
	cin.ignore();
	cout << "Press ENTER to continue...";
	cin.ignore();
}

void board() {

}
void inn() {

}
void shop() {

}
void inven() {

}



void town() {
	int townput;
	system("cls");
	cout << "1) Board\n2) Inn\n3) Shop\n4) Inventory" << endl;
	cin >> townput;
	switch (townput) {
	case 1:
		board();
	break;
	case 2:
		inn();
	break;
	case 3:
		shop();
	break;
	case 4:
		inven();
	break;


	}
}

void characcr() {
	int colorc;
	system("cls");
	cout << "What color do you want your console?\n1) White\n\n2) Yellow\n\n3) Green\n\n4) Red" << endl;
	cin >> colorc;
	switch (colorc) {
	case 1:
		Cha.co = 15;
	break;
	case 2:
		Cha.co = 14;
	break;
	case 3:
		Cha.co = 10;
	break;
	case 4:
		Cha.co = 12;
	break;
	}
	SetConsoleTextAttribute(hConsole, Cha.co);
	system("cls");
	cout << "What is your choice/marker color?\n1) White\n\n2) Red\n\n3) Magenta\n\n4) Cyan\n\n5) Same as Console Color" << endl;
	cin >> colorc;
	switch (colorc) {
	case 1:
		Cha.ca = 15;
		break;
	case 2:
		Cha.ca = 12;
		break;
	case 3:
		Cha.ca = 13;
		break;
	case 4:
		Cha.ca = 11;
		break;
	case 5:
		Cha.ca = Cha.co;
		break;
	}
	system("cls");
	cout << "Example Console:";
	SetConsoleTextAttribute(hConsole, Cha.ca);
	cout << "1";
	SetConsoleTextAttribute(hConsole, Cha.co);
	cout << ") Choice 1\nName: ";
	SetConsoleTextAttribute(hConsole, Cha.ca);
	cout << "Name";
	SetConsoleTextAttribute(hConsole, Cha.co);
	cout << "\n\nIs this ok?\n1) Yes\n2) No" << endl;
	cin.ignore();
	int randin;
	string fname[10] = { "Dzal", "R'vor", "Taz", "Mi't", "Nhiz", "F'rot", "Zar", "Krzaf", "Son", "Laztor"};
	string lname[10] = { "enor", "amok", "ionas", "uov", "ek", "ort", "anaz", "yuz", "opat", "easea" };
	cout << "What's your name? (Type '1' for Random)" << endl;
	getline(cin, Cha.name);
	if (Cha.name == "1") {
		bool randcheck = false;
		while (randcheck == false) {
			system("cls");
			Cha.name = fname[rand() % 10] + lname[rand() % 10];
			cout << "Is '" << Cha.name << "' Ok?\n1) Yes\n2) No" << endl;
			cin >> randin;
			switch (randin) {
			case 1:
				randcheck = true;
				break;
			case 2:
				
				break;
			}
		}
	}
	system("cls");
	cout << "-*- Generation Screen -*-\nName: ";
	SetConsoleTextAttribute(hConsole, Cha.ca);
	cout << Cha.name << "\n1"; 
	SetConsoleTextAttribute(hConsole, Cha.co);
	cout << ") Class" << endl;

	cin >> randin;
}


int main()
{
	characcr();
    return 0;
}

