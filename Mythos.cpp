#include "stdafx.h"
#include "windows.h"
#include <iostream>
#include <string>
#include <vector>
#include <random>

HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
using namespace std;

random_device rng;

struct Cha {
	int maxHP;
	int maxSP;
	int hp;
	int sp;
	string name = "None";
	string clas = "None";
	string race = "None";
	int str = 1;
	int def = 1;
	int wis = 1;
	int agl = 1;
	int crt = 1;
	int co;
	int ca;
} Cha;

void wait_enter(void) //Method of wait_enter, call it to create a Press Enter to continue screen.
{
	cin.ignore();
	cout << "Press ENTER to continue...";
	cin.ignore();
}

void swapColor()
{
	static bool accent = true;
	if(accent)
		SetConsoleTextAttribute(hConsole, Cha.ca);
	else
		SetConsoleTextAttribute(hConsole, Cha.co);
	accent = !accent;
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
	cout << "-*- Console Color -*- \n\nWhat color do you want your console?\n\n1) White\n\n2) Yellow\n\n3) Green\n\n4) Red" << endl;
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
	cout << "-*- Accent Color -*-\n\nWhat is your choice/marker color?\n\n1) White\n\n2) Red\n\n3) Magenta\n\n4) Cyan\n\n5) Same as Console Color" << endl;
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
	cout << "Example Console:\n";
	swapColor();
	cout << "1";
	swapColor();
	cout << ") Choice 1\nName: ";
	swapColor();
	cout << "Name";
	swapColor();
	cout << "\n\nIs this ok?\n1) Yes\n2) No" << endl;
	cin >> colorc;
	switch (colorc) {
	case 2:
		characcr();
		break;
	}
	cin.ignore();
	int randin;
	system("cls");
	string fname[10] = { "Dzal", "R'vor", "Taz", "Mi't", "Nhiz", "F'rot", "Zar", "Krzaf", "Son", "Laztor" };
	string lname[10] = { "enor", "amok", "ionas", "uov", "ek", "ort", "anaz", "yuz", "opat", "easea" };
	cout << "-*- Name -*-\n\nWhat's your name? (Type '1' for Random)" << endl;
	getline(cin, Cha.name);
	if (Cha.name == "1") {
		bool randcheck = false;
		while (randcheck == false) {
			system("cls");
			Cha.name = fname[rng() % 10] + lname[rng() % 10];
			cout << "Is '";
			swapColor();
			cout << Cha.name;
			swapColor();
			cout << "' Ok?\n1) Yes\n2) No" << endl;
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
	bool charunfin = false;
	int creatput;
	while (charunfin == false) {
		system("cls");
		cout << "-*- Generation Screen -*-\nName: ";
		swapColor();
		cout << Cha.name << endl;
		swapColor();
		cout << "Class: ";
		swapColor();
		cout << Cha.clas << endl;
		swapColor();
		cout << "Race: ";
		swapColor();
		cout << Cha.race << "\n\n1";;
		swapColor();
		cout << ") Class" << endl;
		swapColor();
		cout << "2";
		swapColor();
		cout << ") Race" << endl;
		swapColor();
		cout << "3";
		swapColor();
		cout << ") Proficiency\n\n-*- Stats -*-\nStrength: ";
		swapColor();
		cout << Cha.str << endl;;
		swapColor();
		cout << "Defense: ";
		swapColor();
		cout << Cha.def << endl;
		swapColor();
		cout << "Agility: ";
		swapColor();
		cout << Cha.agl << endl;
		swapColor();
		cout << "Wisdom: ";
		swapColor();
		cout << Cha.wis << endl;
		swapColor();
		cin >> creatput;
		switch (creatput) {
		case 1:
			system("cls");
			cout << "-*- Class Selection Screen -*-\n" << endl;
			swapColor();
			cout << "1";
			swapColor();
			cout << ") Warrior:\n     Warriors focus on high damage melee attacks and better physical moves.\n     Some Warriors learn combat spells to boost their physical damage, or to \n     block magic attacks." << endl;
			swapColor();
			cout << "\n2";
			swapColor();
			cout << ") Wizard:\n     Wizards are all about magic. Their spells are more powerful, and can\n     heal greater or deal more damage" << endl;
			swapColor();
			cout << "\n3";
			swapColor();
			cout << ") Rogue:\n     Rogues pay more attention to where strikes land, giving them more\n     critical hits. They can cast spells to boose their agility and strength" << endl;
			cin >> creatput;
			switch (creatput) {
			case 1:
				Cha.clas = "Warrior";
			break;
			case 2:
				Cha.clas = "Wizard";
			break;
			case 3:
				Cha.clas = "Rogue";
			break;
			}
			break;
		case 2:
			system("cls");
			cout << "-*- Race Selection -*-" << endl;
			swapColor();
			cout << "\n1";
			swapColor();
			cout << ") Human - +3 STR, +2 DEF" << endl;
			swapColor();
			cout << "\n2";
			swapColor();
			cout << ") Skelekin - +5 DEF, -1 WIS" << endl;
			swapColor();
			cout << "\n3";
			swapColor();
			cout << ") Kobold - +4 AGL, +1 STR, -1 WIS" << endl;
			swapColor();
			cout << "\n4";
			swapColor();
			cout << ") Spaceslug - +5 WIS, +2 DEF" << endl;
			swapColor();
			cout << "\n5";
			swapColor();
			cout << ") Kenku - +2 AGL, +2 WIS, +2 STR" << endl;
			swapColor();
			cout << "\n6";
			swapColor();
			cout << ") Arachnid - +3 AGL, +3% CRT-CHANCE" << endl;
			cin >> creatput;
			switch (creatput) {
			case 1:
				Cha.race = "Human";
				Cha.str = 4;
				Cha.def = 3;
			break;
			case 2:
				Cha.race = "Skelekin";
				Cha.def = 6;
				Cha.wis = 0;
			break;
			case 3:
				Cha.race = "Kobold";
				Cha.agl = 5;
				Cha.str = 2;
				Cha.wis = 0;
			break;
			case 4:
				Cha.race = "Spaceslug";
				Cha.wis = 6;
				Cha.def = 3;
			break;
			case 5:
				Cha.race = "Kenku";
				Cha.agl = 3;
				Cha.wis = 3;
				Cha.str = 3;
			break;
			case 6:
				Cha.race = "Arachnid";
				Cha.agl = 4;
				Cha.crt = 4;
			break;
			}
		}
	}
}


int main()
{
	characcr();
    return 0;
}

