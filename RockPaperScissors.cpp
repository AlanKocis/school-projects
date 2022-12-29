#include <iostream>
using namespace std;

int main() {
	char userCond;
	char userChoice = 'z';
	int contCond = 0;
	char playerRoll;
	int botRoll;
	char rps[3][3];
	// 0 -Rock 1 -Paper 2 -Scissors
	rps[0][0] = 'd';
	rps[0][1] = 'l';
	rps[0][2] = 'w';
	rps[1][0] = 'w';
	rps[1][1] = 'd';
	rps[1][2] = 'l';
	rps[2][0] = 'l';
	rps[2][1] = 'w';
	rps[2][2] = 'd';
	int arrNum;

	unsigned seed = time(0);
	srand(seed);

	//random letter 0 to 2;
	botRoll = (rand() % 3);
	
	do {
		userCond = 'x';
		userChoice = 'x';

		cout << "Let's play Rock-Paper-Scissors.\n";
		while (userChoice != 'r' && userChoice != 'R' && userChoice != 'p' && userChoice != 'P' && userChoice != 's' && userChoice != 'S') {
			cout << "Enter R P or S:\n";
			cin >> userChoice;
		}

		if (userChoice == 'r' || userChoice == 'R') { arrNum = 0; }
		else if (userChoice == 'p' || userChoice == 'P') { arrNum = 1; }
		else if (userChoice == 's' || userChoice == 'S') { arrNum = 2; }

		cout << "I picked ";
		if (botRoll == 0) { cout << "rock!\n"; }
		else if (botRoll == 1) { cout << "paper!\n"; }
		else if (botRoll == 2) { cout << "scissors!\n"; }

		if (rps[arrNum][botRoll] == 'd') {
			cout << "Draw!\n";
		}
		else if (rps[arrNum][botRoll] == 'w') {
			cout << "You win!\n";
		}
		else if (rps[arrNum][botRoll] == 'l') {
			cout << "You lose!\n";
		}

		while (userCond != 'y' && userCond != 'Y' && userCond != 'n' && userCond != 'N') {
			cout << "Continue? Enter Y or N:\n";
			cin >> userCond;
			cout << endl;
		}

	} while (userCond == 'Y' || userCond == 'y');

	return(0);
}