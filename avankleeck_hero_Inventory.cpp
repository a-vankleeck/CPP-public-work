#include <iostream>

using namespace std;

const int MAX_ITEMS = 6;
int numItems = 3;
int favoriteItem;
string inventory[MAX_ITEMS] = {"Dracos","Fiera","Blancos"};
string item;

//logicalFunctions;
void game();
void intro();
void addItem(string item);
int checkItemPOS(string item);
void removeItem(int pos);
void drawInventory();
void returnItem();
string itemName();

//story functions
void intro();
void firstItem();
void secondItem();
void thirdItem();
void loseItem();
void theBridge();
void outro();



int main() {
	game();
	
}
void game() {
	intro();
	firstItem();
	addItem(itemName());
	drawInventory();
	secondItem();
	addItem(itemName());
	drawInventory();
	loseItem();
	returnItem();
	drawInventory();
	thirdItem();
	addItem(itemName());
	drawInventory();
	theBridge();
	returnItem();
	drawInventory();
	outro();
}

string itemName() {
	cin >> item;
	return item;
}
void addItem(string item) {
	if (numItems == MAX_ITEMS) {
		cout << "You inventory is full! You cannot pick up anymore items.\n \n";
		return;
	}
	inventory[numItems++] = item;
	cout << numItems << endl << endl;
	return;
}

void returnItem() {
	bool checkPOS = false;
	while (!checkPOS) {
		itemName();
		if (checkItemPOS(item) != -1) {
			removeItem(checkItemPOS(item));
			checkPOS = true;
			break;
		}
		drawInventory();
		cout << item << " is not in your inventory please try again: ";

	}
	cout << item << " was removed from your inventory!";
}

int checkItemPOS(string item) {
	int i = 0;
	do {
		if (inventory[i] == item) {
			return i;
		}
		i++;
	} while (i < MAX_ITEMS);
	return -1;
}
void removeItem(int pos) {
	inventory[pos].clear();
	numItems--;
}
void drawInventory(){
	cout << "\nYou have " << numItems << " items in your inventory. You have " << MAX_ITEMS - numItems << " spaces left.\n";
	for (int i = 0; i < MAX_ITEMS; ++i) {
		if (inventory[i].empty()) {
			cout << "-" << endl;
			continue;
		}
		cout << inventory[i] << endl;
	}
}
void intro() {
	cout << "Hello hero," << endl <<
		"You start the game with 3 dice, Dracos, Fiera, and Blancos. As you defeat your oponnets you will" << endl <<
		"gain more dice as you play, however if you lose they will take one of your dice. if you lose all dice you will"<< endl <<
		"lose the tournement.";

}
void firstItem() {
	cout << "The first opponent you faced rolled low and has lost to you, you now get to take one of their dice. Name the die: ";
}
void secondItem() {
	cout << "You defeated this opponent quickly and now have taken one of their dice. Name the die: ";
}
void thirdItem() {
	cout << "Your last opponent fought bravely but quickly succumbed to your might and now you take one of their die.\nName the die: ";
}
void loseItem() {
	cout << "you were defeated this round and they are going to take one of your dice.\nMake a suggestion for which one to take: ";
}
void theBridge() {
	cout << "As you make your way up to the castle to challenge the grandmaster, you spot an old man blocking the way." << endl <<
		"'if you wish to challenge the grand master you must first give up your most prized die!'./n Pick your die: ";
}
void outro() {
	cout << "You hand him your die, you cross the bridge and begin to make the climp up the tower to challenge the master." << endl;
}