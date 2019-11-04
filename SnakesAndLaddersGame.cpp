// SnakesAndLaddersGame.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "fileHandler.h"
#include "SnakesAndLadders.h"
#include "Queue.h"
using namespace std;

int main()
{

	std::cout << "Hello World!\n";

	/*vector<string> LoadHere;
	readMap(LoadHere);
*/
	int playerno;
	cout << "Welcome to Saad Bazaz's implementation of Snakes and Ladders!" << endl;
	cout << "How many players today?" << endl;
	cin >> playerno;
	
	Game* newGame;

	char userOption;
	bool wrong_input;

	cout << "Enter: \nD to load the default map, \nC to load a custom map from User_Maps, \nW to create your own custom map!" << endl;
	do {
		cin >> userOption;

		switch (userOption) 
		{
		case 'D': //loading config.ini from file system
		case 'd':
		{
			wrong_input = false;
			try {
				newGame = new Game ("map.txt", playerno);
				system("CLS");
				cout << "File loaded successfully!" << endl;

cout << "Let's play!" << endl << endl << endl;
char diceRoll='a';
bool winner = false;
int sixcount = 0;
while (diceRoll != 'Z' && diceRoll != 'z' || winner == true) {
	cout << endl;
	cout << endl;
	cout << "It is Player " << newGame->WhoseTurn() << "'s turn!" << endl;
	cout << "Enter any key other than Z to throw the dice. Enter Z to exit the game." << endl;
	int diceVal = 0;
	do{
	cin >> diceRoll;
	diceVal = newGame->ThrowDice();
	cout<< "The dice rolled "<< diceVal <<"."<<endl;
	if (!newGame->RollDice(diceVal)) {
		cout << "Something happened..." << endl;
		break;
	}
	if (diceVal == 6) {
		sixcount++;
		//newGame->GetTopPlayer().diceRoll.push(diceVal);
		if (sixcount == 3) {
			cout << "Oops! You miss this turn." << endl;
			break;
		}
		else
			cout << "You rolled a 6! You get another turn. Be careful, though!" << endl;
	}
	else {
		if (newGame->GetTopPlayer().position) {
			//newGame->GetTopPlayer().diceRoll.push(diceVal);
			//RollStack temp;
			Player& tempPlayer = newGame->GetTopPlayerReference();
			tempPlayer.diceRoll;
			//newGame->GetTopPlayer().diceRoll.
			//cout << "Displaying this player's stack..." << endl;
			//newGame->GetTopPlayer().diceRoll.Display();

			//while (!newGame->GetTopPlayer().diceRoll.isEmpty()) {
			//	try {
			//		int popped = newGame->GetTopPlayer().diceRoll.pop();
			//		cout << "Popping..." << popped << endl;
			//		temp.push_roll(popped);
			//		cout << "Pushing..." << popped << endl;

			//	}
			//	catch (invalid_argument e) {
			//		cout << e.what() << endl;
			//		break;
			//	}
			//}
			//cout << "You have moved to position " << newGame->GetTopPlayer().setPosition(newGame->TraverseBoard(newGame->GetTopPlayer().position, temp)) << "!" << endl;
			//

			cout << "You have moved to position " << newGame->GetTopPlayer().setPosition(newGame->TraverseBoard(newGame->GetTopPlayer().position, tempPlayer.diceRoll)) << "!" << endl;
			tempPlayer.diceRoll.empty();

			if (newGame->GetTopPlayer().position == 100) {
				cout << "Player " << newGame->WhoseTurn() << " wins the match!" << endl;
				winner = true;
			}
		}
		else {
			cout << "Aww... You aren't on the board yet!" << endl;
		}
		newGame->nextTurn();
	}
} while (diceVal == 6);

}




			}
			catch (const logic_error & e) {
				system("CLS");
				cout << "Error caught. " << e.what() << endl;
				wrong_input = true;
			}
			break;
		}
		case 'C': //creating or overwriting config.ini in file system
		case 'c':
		{
			wrong_input = false;
			cout << endl;
			cout << "Enter the file name you'd like to load: " << endl;
			string _filename;
			cin.ignore();
			getline(cin, _filename);
			try {
				newGame = new Game(_filename, playerno);
				system("CLS");
				cout << "File loaded successfully!" << endl;
			}
			catch (const logic_error& e) {
				system("CLS");
				cout << "Error caught. " << e.what() << endl;
				wrong_input = true;
			}
			break;
		}
		case 'W': //creating or overwriting config.ini in file system
		case 'w': {
			wrong_input = false;
			cout << endl;
			cout << "This feature is unfinished." << endl;
			//cout << "----------------- NEW CONFIGURATION -----------------" << endl;
			//cout << "How many rows?" << endl;
			//int gen;
			//cin >> gen;
			//userConfig.gen = gen;
			//cout << endl;

			//cout << "How many cells would be alive in the beginning?" << endl;
			//int cell;
			//cin >> cell;
			//userConfig.cell_no = cell;
			//cout << endl;

			//int tempx, tempy;
			//for (int i = 0; i < cell; i++) {
			//	cout << "Enter X coordinate of Cell #" << i + 1 << ": ";
			//	cin >> tempx;
			//	cout << "Enter Y coordinate of Cell #" << i + 1 << ": ";
			//	cin >> tempy;
			//	cout << endl;

			//	Coordinates TempCoordinate(tempx, tempy); //creating a temporary coordinate object which can be pushed into the Positions vector
			//	userConfig.positions.push_back(TempCoordinate);
			//}

			//if (writeConfig(userConfig)) {
			//	cout << "User Configuration successfully written to file." << endl;
			//}
			//else
			//	cout << "There was an error saving the configuration." << endl;
			break;

		}

		default:
			cout << "Please enter D, C or W.  ";
			wrong_input = true;
		}

	} while (wrong_input);


	

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
