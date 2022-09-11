// Chapter 2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cstdlib>
#include <ctime>


using namespace std;

void intro();
void winStatement();
void loseStatement();
void strikeMiss();
void strikeHit();
int randomNumber(int modulo);
bool winner(int result);
void combat(bool isHit);
void gameOver(int health);
void sleep();




int main() {
	srand(static_cast<unsigned int>(time(0)));
	const int MAX_ROUNDS = randomNumber(10) + 5;
	int turns = 0;
	int attack = randomNumber(5);
	int defense;
	int results;
	int lowHealthWarning = 0;
	int health = 10;
	string fightResults;
	bool isHit;
	char seeStatistics;
	cout << "Before we begin would you like to see all the numbers ran for this game? [Y]Yes [N]No" << endl;
	cin >> seeStatistics;
	while (true) {
		if (seeStatistics == 'N' || seeStatistics == 'n'|| seeStatistics == 'Y' || seeStatistics == 'y') {
			break;
		}
		cout << "Before we begin would you like to see all the numbers ran for this game? [Y]Yes [N]No" << endl;
		cin >> seeStatistics;
	}
		//intro();
		while (true) {
			defense = randomNumber(5);
			results = defense - attack;
			isHit = false;
			if (winner(results)) {
				health -= attack;
				isHit = true;
			}
			turns++;
			attack = randomNumber(5);
			combat(isHit);
			if (seeStatistics == 'Y' || seeStatistics == 'y') {
				cout << "Health: " << health << " Attack Roll: " << attack << " Defense Roll: " << defense << endl << endl;
			}
			if (turns >= MAX_ROUNDS || health <= 0) {
				break;
			}
			if (turns == MAX_ROUNDS / 2) {
				sleep();
			}
			if (health <= 3 && lowHealthWarning == 0) {
				cout << "(You have sustained heavy damage and should seek immediate medical attention!)" << endl << endl;
				lowHealthWarning = 1;
			}
		}
		gameOver(health);
		return 0;
	}
	int randomNumber(int modulo) {
		int randomNumber = rand();
		int returnedNumber = (randomNumber % modulo);
		return returnedNumber;
	}

	bool winner(int result) {
		if (result < 0) {
			return true;
		}
		return false;
	}

	void combat(bool isHit) {
		if (isHit) {
			strikeHit();
			return;
		}
		strikeMiss();
		return;
	}
	void gameOver(int health) {
		if (health <= 0) {
			loseStatement();
			return;
		}
		winStatement();
		return;
	}
	void intro() {
		cout << "Hello Adventurer," << endl << "Welcome to the land of Elspire, a land of mythical heros and villians." << endl <<
			"Your adventure begins in the small town of Hucklefire, a calm fishing village. You are a local hero" << endl <<
			"to the townsfolk as you have saved them on multiple occasions, with introductions out of the way. Let's begin!" << endl <<
			"You are abruptly awakened from your slumber by a loud crashing noise outside your window." << endl <<
			"You look out the window, and to your suprise, you see a large group of Orcs raiding the town." << endl <<
			"You put your armor on and grab your sword. As you begin to descend the stairs, you hear the mayor's voice" << endl <<
			"'There you are adventurer, Our village is being raided, and we need all the help we can get!'" << endl <<
			" You realize what must be done and charge out the door. As the door swings wide open to an orc cutting down a gaurd." << endl <<
			"You draw up all of your courage, and charge!" << endl << endl;
	}

	void sleep() {
		cout << "As the day turns to night you feel yourself becoming more tired, you decide to retreat" << endl <<
			"to the sanctuary made at the temple. whilst there you manage to get a meal," << endl <<
			"the high priest speaks a prayer to keep the fighters safe in the fight to come," << endl <<
			"and though unconfortable in your armor, you manage to get a few hours of sleep." << endl << endl <<
			"You awaken to the alarm going off and people screaming, the orcs have breached your sanctuary" << endl <<
			"and the fighting has entered the temple. You see the first orc come through the door and you charge at him." << endl << endl;
	}

	void winStatement() {

		cout << "You overcome your foe, impaling it on your blade" << endl <<
			"you look around for your next target, but see the orcs are fleeing!" << endl <<
			"You struggle to withdraw the blade from the orc's body but you finally remove it" << endl <<
			"You clean the blood off of your blade and begin to sheath it again as" << endl <<
			"the mayor comes up to congratulates you on your victory." << endl <<
			"CONGRATS ADVENTURER YOU HAVE WON THE FIGHT!!!!" << endl << endl;
	}
	void loseStatement() {
		cout << "As you face this orc you feel the wear on your body as you begin to slow down." << endl <<
			"You go to strike at the orc but your movement has become sluggish and you are to slow to react." << endl <<
			"You see the axe coming in and try to duck but it is too late." << endl <<
			"You feel the cold steel of the orc's battle axe as it slips between your armor!" << endl <<
			"Your bones crack and shatter as the massve axe cleaves your head from your body." << endl <<
			"Your vision begins to blur, as the world spins around you, and finally you hit the ground hard" << endl <<
			"Where you landed you can see your headless body slump over and collapse to the ground." << endl <<
			"You close your eyes and the darkness takes you for, forever." << endl <<
			"SORRY ADVENTURER, YOU HAVE DIED!!" << endl << endl;
	}
	void strikeHit() {
		int random = randomNumber(3);
		switch (random) {
		case 0:
			cout << "You feel the orc's great axe slam into you, caving your armor in," << endl <<
				"dazing you, and knocking the wind out of you." << endl << endl;
			break;
		case 1:
			cout << "The orc's great axe slams into your shield, denting the metal in." << endl <<
				"The pain shoots through your arm and into your shoulder." << endl << endl;
			break;
		case 2:
			cout << "The orc manages to backhand you in the face, luckily your helmet absorbs" << endl <<
				"most of the damage but it still causes you to become disorientated." << endl << endl;
			break;
		}

	}
	void strikeMiss() {
		int random = randomNumber(3);
		switch (random) {
		case 0:
			cout << "You feel your blade sink deep into the orcs flesh, you have dealt a fatal blow." << endl <<
				"You pull your blade out and charge at the next orc you can see!" << endl << endl;
			break;
		case 1:
			cout << "As the orc swings his massive battle axe down at you, you side step the blow and the axe plants" << endl <<
				"firm in the ground, as the orc tries to pull his battle axe out of the ground you slip through his defense," << endl <<
				"and plunge your blade into his heart. You charge the next orc!" << endl << endl;
			break;
		case 2:
			cout << "As you swing at the orc, he side steps your attack. You quickly counter by planting your armored elbow" << endl <<
				"into his gut causing him to lose balance for a second." << endl << endl;
		}

	}


