//#include "stdafx.h"
#include "windows.h"
#include <conio.h>
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
	int guildgold;
	string name = "None";
	string clas = "None";
	string race = "None";
	string prof = "None";
	string difficultyn = "Normal";
	double difficulty = 1;
	int gold = 100;
	int str = 1;
	int def = 1;
	int wis = 1;
	int agl = 1;
	int crt = 1;
	int crtx = 2;
	int alloc = 3;
	int week = 1;
	int day = 1;
	double melx = 1;
	double splx = 1;
	int co;
	int ca;
	bool guildtutorial = false;
} Cha;

void wait_enter(void) //Method of wait_enter, call it to create a Press Enter to continue screen.
{
	cin.ignore();
	cout << "Press ENTER to continue...";
	cin.ignore();
}

int waitForKey()
{
	return _getch() - 48;
}

void swapColor()
{
	static bool accent = true;
	if (accent)
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
void guild() {
	string guildname;
	int guildvar;
	string guildranks[5] = {"Apprentice ", " ", " ", "Baron ", "Duke "};
	if (Cha.guildtutorial == false) {
		system("cls");
		cout << "The guild is where you can donate gold for special rewards, eg: Ranks, \nItems, and more. As you fight in the land of Sarin, the guild will gain a \nlittle bit of gold, and you can withdraw whenever.\n\nYou have gained the rank, Apprentice, to start off." << endl;
		wait_enter();
		guildname = guildranks[0] + Cha.name;
		Cha.guildtutorial = true;
		guild();
	}
	system("cls");
	cout << "-*- Guild -*-" << endl;
	swapColor();
	cout << "1";
	swapColor();
	cout << ") Deposit Gold" << endl;
	swapColor();
	cout << "2";
	swapColor();
	cout << ") Withdrawal Gold" << endl;
	swapColor();
	cout << "3";
	swapColor();
	cout << ") Rankup\n\nCurrent Gold in Guild: ";
	swapColor();
	cout << Cha.guildgold;
	swapColor();
	guildvar = waitForKey();
	switch (guildvar) {
	case 1:
		system("cls");
		cout << "-*- Deposit Screen -*-\n\nYou have ";
		swapColor();
		cout << Cha.gold;
		swapColor();
		cout << " gold to donate." << endl;
		cin >> guildvar;
		if (guildvar < 1) {}
		else if (guildvar > Cha.gold) {
			system("cls");
			cout << "You do not have enough gold!" << endl;
			wait_enter();
		} else {
			system("cls");
			cout << "You donated ";
			swapColor();
			cout << guildvar;
			swapColor();
			cout << " gold." << endl;
			Cha.gold -= guildvar;
			Cha.guildgold += guildvar;
			wait_enter();
		}
	break;
	case 2:
		system("cls");
		cout << "-*- Withdrawl Screen -*-\n\nYou can take out ";
		swapColor();
		cout << Cha.guildgold;
		swapColor();
		cout << " gold." << endl;
		cin >> guildvar;
		if (guildvar < 1) {}
		else if (guildvar > Cha.guildgold) {
			system("cls");
			cout << "The guild does not have enough gold!" << endl;
			wait_enter();
		} else {
			system("cls");
			cout << "You withdrew ";
			swapColor();
			cout << guildvar;
			swapColor();
			cout << " gold." << endl;
			Cha.guildgold -= guildvar;
			Cha.gold += guildvar;
			wait_enter();
		}
	break;
	}
}



void town() {
	int townput;
	bool townhole = false;
	while (townhole == false) {
		if (Cha.day == 7) {
			Cha.week += 1;
			Cha.day = 1;
		}
		system("cls");
		cout << "-*- Town of Elc, Sarin || Week " << Cha.week << " Day " << Cha.day << " -*-" << endl;
		swapColor();
		cout << "\n1";
		swapColor();
		cout << ") Board" << endl;
		swapColor();
		cout << "2";
		swapColor();
		cout << ") Inn" << endl;
		swapColor();
		cout << "3";
		swapColor();
		cout << ") Shop" << endl;
		swapColor();
		cout << "4";
		swapColor();
		cout << ") Guild" << endl;
		swapColor();
		cout << "5";
		swapColor();
		cout << ") Inventory & Stats" << endl;
		swapColor();
		cout << "6";
		swapColor();
		cout << ") Save\n\nName: ";
		swapColor();
		cout << Cha.name;
		swapColor();
		cout << "\n\nHealth: ";
		swapColor();
		cout << Cha.hp;
		swapColor();
		cout << "\nSoul: ";
		swapColor();
		cout << Cha.sp;
		swapColor();
		townput = waitForKey();
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
			guild();
			break;
		case 5:
			inven();
			break;

		}
	}
}

void characcr() {
	int colorc;
	int colorce;
	system("cls");
	cout << "-*- Console Color -*- \n\nWhat color do you want your console?\n\n1) White\n\n2) Yellow\n\n3) Green\n\n4) Red" << endl;
	colorc = waitForKey();
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
	colorc = waitForKey();
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
	cout << "Your Name Here!";
	swapColor();
	cout << "\n\nIs this ok?\n1) Yes\n2) No" << endl;
	colorce = waitForKey();
	switch (colorce) {
	case 1:
		break;
	case 2:
		characcr();
		break;
	}
	int randin;
	string oldname;
	bool randcheck = false;
	string fhname[10] = { "Crow", "Haruki", "Goblin", "Jerry", "Coagula", "Jaroslav", "Jason", "Garfield", "Willace", "Sage" };
	string lhname[10] = { " Harakiri", " Kubo", " The King Gizzard and the Lizard Wizard", " Seinfeld", " Fortunas", " Elc", " Flips", " Crust", " Gamer", " Jorhanavere" };
	string fname[10] = { "Dzal", "R'vor", "Taz", "Mi't", "Nhiz", "F'rot", "Zar", "Krzaf", "Son", "Laztor" };
	string lname[10] = { "enor", "amok", "ionas", "uov", "ek", "ort", "anaz", "yuz", "opat", "easea" };
	while (randcheck == false) {
		oldname = Cha.name;
		system("cls");
		cout << "-*- Name -*-\n\nWhat's your name?\nType anything for a custom name\n\n";
		swapColor();
		cout << "1";
		swapColor();
		cout << ") Finish\n\n";
		swapColor();
		cout << "2";
		swapColor();
		cout << ") Random Real Name\n";
		swapColor();
		cout << "3";
		swapColor();
		cout << ") Random Eldritch Name\n\nCurrent Name: ";
		swapColor();
		cout << Cha.name << endl;
		swapColor();
		getline(cin, Cha.name);
		if (Cha.name == "1") {
			randcheck = true;
		}
		if (Cha.name == "2") {
			system("cls");
			Cha.name = fhname[rng() % 10] + lhname[rng() % 10];
		}
		if (Cha.name == "3") {
			system("cls");
			Cha.name = fname[rng() % 10] + lname[rng() % 10];
		}
	}
	Cha.name = oldname;
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
		cout << Cha.race << endl;
		swapColor();
		cout << "Proficiency: ";
		swapColor();
		cout << Cha.prof << "\n\n1";
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
		cout << Cha.wis << "\n\n4";
		swapColor();
		cout << ") Finish Creation" << endl;
		creatput = waitForKey();
		switch (creatput) {
		case 4:
			if (Cha.race == "None" || Cha.clas == "None" || Cha.prof == "None") {
				system("cls");
				cout << "Please finish your character!\n" << endl;
				wait_enter();
			}
			else {
				charunfin = true;
				system("cls");
				cout << "-*- Difficulty Selection -*-\n" << endl;
				swapColor();
				cout << "1";
				swapColor();
				cout << ") Easy - Difficulty Multiplier: .75x" << endl;
				swapColor();
				cout << "2";
				swapColor();
				cout << ") Normal - Difficulty Multiplier: 1x" << endl;
				swapColor();
				cout << "3";
				swapColor();
				cout << ") Hard - Difficulty Multiplier: 1.5x" << endl;
				creatput = waitForKey();
				switch (creatput) {
				case 1:
					Cha.difficulty = .75;
					Cha.difficultyn = "Easy";
					break;
				case 2:
					Cha.difficulty = 1;
					Cha.difficultyn = "Normal";
					break;
				case 3:
					Cha.difficulty = 1.5;
					Cha.difficultyn = "Hard";
					break;
				}
				system("cls");
				cout << "-*- Main Story -*-" << endl;
				cout << "\n     Eldritch monsters have invaded the world of Azoth. As a young " << Cha.race << " living in Elc, you decide to fight \nthese beings and save the world. Starting small, you only have your fists and a few potions to help you in fights.\n\n     Elc is a small trading town located in Sarin. There's a board with listings of bandits, monsters, and eldritch \nhorrors, each increasing in pay. As a";
				if (Cha.clas == "Knight") {
					cout << " Knight, you've learned the ways of fighting only with swords and fists. \nYou've practiced spells, but none are powerful enough to deal noticeable damage to an enemy.\nYou take advantage of speed and high damage, your attacks are relentless." << endl;
				}
				else if (Cha.clas == "Wizard") {
					cout << " Wizard, you've spent your entire life studying magic, never leaving the\nstudy. Your spells are potent, capable of healing and destroying. You take advantage of an enemy's weak defenses." << endl;
				}
				else if (Cha.clas == "Rogue") {
					cout << " Rogue, you've lived your life in the shadows. Assassinating high officials\nand robbing unsuspecting victims. Your moves are fast and calculated. You take advantage of high damaging \ncritical hits and speed." << endl;
				}
				if (Cha.difficultyn == "Easy") {
					cout << "\n     You've learned from a protective childhood that fighting just aint in your nature. The Azoth gods look down upon \nyou in pity and bless you with fortune and good luck." << endl;
				}
				else if (Cha.difficultyn == "Normal") {
					cout << "\n     You've spent your life wandering in the forest, hunting for food. Your knowledge of the outdoors helps you explore \nSorin well, and your decent understanding of hunting and fighting prove you well in combat." << endl;
				}
				else if (Cha.difficultyn == "Hard") {
					cout << "\n     You've killed so many things in your lifetime that even the gods are worried. They see your potential for \ndestruction and try everything to stop you from destroying the world in your death-quest. You are cursed with bad luck and misery." << endl;
				}
				cout << "\n     You wake up outside, pine trees towering over you. The sky is covered in clouds. As you sit up you see \nthe town of Elc next to you. You get up and walk over, your bag hung over your back." << endl;
				cout << "\nPress ENTER to continue..." << endl;
				cin.ignore();
				town();
			}
			break;
		case 1:
			system("cls");
			cout << "-*- Class Selection Screen -*-\n" << endl;
			swapColor();
			cout << "1";
			swapColor();
			cout << ") Knight:\n     Knights focus on high damage melee attacks and better physical moves.\n     Some Knights learn combat spells to boost their physical damage, or to \n     block magic attacks." << endl;
			swapColor();
			cout << "\n2";
			swapColor();
			cout << ") Wizard:\n     Wizards are all about magic. Their spells are more powerful, and can\n     heal greater or deal more damage" << endl;
			swapColor();
			cout << "\n3";
			swapColor();
			cout << ") Rogue:\n     Rogues pay more attention to where strikes land, giving them more\n     critical hits. They can cast spells to boose their agility and strength" << endl;
			creatput = waitForKey();
			switch (creatput) {
			case 1:
				Cha.clas = "Knight";
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
			Cha.str = 1;
			Cha.def = 1;
			Cha.wis = 1;
			Cha.crt = 1;
			Cha.agl = 1;
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
			creatput = waitForKey();
			switch (creatput) {
			case 1:
				Cha.race = "Human";
				Cha.str += 3;
				Cha.def += 2;
				break;
			case 2:
				Cha.race = "Skelekin";
				Cha.def += 5;
				Cha.wis -= 1;
				break;
			case 3:
				Cha.race = "Kobold";
				Cha.agl += 4;
				Cha.str += 1;
				Cha.wis -= 1;
				break;
			case 4:
				Cha.race = "Spaceslug";
				Cha.wis += 5;
				Cha.def += 2;
				break;
			case 5:
				Cha.race = "Kenku";
				Cha.agl += 2;
				Cha.wis += 2;
				Cha.str += 2;
				break;
			case 6:
				Cha.race = "Arachnid";
				Cha.agl += 3;
				Cha.crt += 3;
				break;
			}
			break;
		case 3:
			system("cls");
			cout << "-*- Proficiency -*-\n\n";
			swapColor();
			cout << "1";
			swapColor();
			cout << ") Melee Proficiency\n     - Gives all melee hits more damage\n" << endl;
			swapColor();
			cout << "2";
			swapColor();
			cout << ") Soul Proficiency\n     - All spells are more potent\n" << endl;
			swapColor();
			cout << "3";
			swapColor();
			cout << ") Critical Proficiency\n      - Crits deal 3x Damage instead of 2x\n" << endl;
			creatput = waitForKey();
			switch (creatput) {
			case 1:
				Cha.prof = "Melee Proficiency";
				Cha.melx = 1.25;
				break;
			case 2:
				Cha.prof = "Soul Proficiency";
				Cha.splx = 1.25;
				break;
			case 3:
				Cha.prof = "Critical Proficiency";
				Cha.crtx = 3;
				break;
			}

			break;
		}
	}
}


int main()
{
	characcr();
	return 0;
}
