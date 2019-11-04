#pragma once

#include <iostream>
#include <ctime>
#include "fileHandler.h"
#include "Stack.h"
#include "Queue.h"
using namespace std;


class Player {
public:
	int number;
	int position;
	int score;
	Stack<int> diceRoll;

	Player(): score(0) {
		position = 0;
		//position.y = -1;
	}

	Player(int Number) : number(Number), score(0) {
		position = 0;

		//position.x = -1;
		//position.y = -1;
	}
};

class Game {
	Map* gameMap;
	Queue<Player> Players;
	Stack <int> diceRollStack;

public:
	Game(string mapLocation, int players, int rows=10, int cols=10) {
		vector<string> LoadHere;
		readMap(LoadHere);
	
		gameMap = new Map(rows,cols,LoadHere);

		Player toAdd;
		for (int i = 0; i < players; i++) {
			toAdd.number = i + 1;
			Players.enqueue(toAdd);
		}
	}

	Game(int players) {

		vector<string> LoadHere;
		readMap(LoadHere);

		gameMap = new Map(10, 10, LoadHere);


		Player toAdd;
		for (int i = 0; i < players; i++) {
			toAdd.number = i + 1;
			Players.enqueue(toAdd);
		}
	}

	bool IsLadder(int index) {
		cout << "Ladder at index " << index << " " << gameMap->positions.getNodeData(index-1) << endl;
		//char option;
		//cin>>option;
		return gameMap->positions.getNodeSpecialData(index - 1)[0]=='L';
		//return gameMap[index + 1][0] == "L";
	}

	bool IsSnake(int index) {
	
		return gameMap->positions.getNodeSpecialData(index - 1)[0] == 'S';
	}

	Tile* GetTile(int index) {
		return gameMap->positions.getNode(index-1);
	}

	void BringOnBoard() {
		Players.getTop()->data;
	}

	int TraverseBoard(int position, RollStack &rollThese) {
		rollThese.Display();
		int sum = rollThese.returnSum();
		rollThese.Display();
		
		if (sum + position > 100) {
			return 100;
		}
		
		gameMap->positions.moveCursorToHead();
		cout<<"At head..." << (gameMap->positions.getCursorData()) << endl;

		gameMap->positions.moveCursorXTimes(position);
		cout << "At starting..." << (gameMap->positions.getCursorData()) << endl;

		gameMap->positions.moveCursorXTimes(sum-1);
		cout << "At ending..." << (gameMap->positions.getCursorData()) << endl;
		return gameMap->positions.getCursorData();


		
	}


	void checkSpecialTile(int index) {

	}

	int ThrowDice() {
		srand(time(NULL));
		return rand() % 6 + 1;
	}

	void RollDice(int diceVal=-1, int sixcount=0) {
	
	if (diceVal == 6) {
		if (Players.getTop()->data.position == 0) {
			Players.getTop()->data.position++;
			nextTurn();
		}
		else{
			Players.getTop()->data.diceRoll.push(diceVal);
			//RollDice(-1, sixcount + 1);
		}
	}
	else if (diceVal == 3) {
		Players.reverse();
	}
}



	//void RollDice(int diceVal=-1, int sixcount=0) {
	//	
	//	if (sixcount == 3) {
	//		return;
	//	}
	//	if (diceVal == -1) {
	//		diceVal = ThrowDice();
	//	}
	//	if (diceVal == 6) {
	//		if (Players.getTop()->data.position == 0) {
	//			Players.getTop()->data.position++;
	//		}
	//		else{
	//			RollDice(-1, sixcount + 1);
	//		}
	//	}
	//}



	bool nextTurn() {
		Players.enqueue(Players.dequeue());
		return true;
	}

	Queue<Player>& GetTurnQueue() {
		return Players;
	}

};







//
//
//
//
//
//
//
//
//
//
//
//
//
//
//#pragma once
//
//#include <iostream>
//#include <ctime>
//#include "fileHandler.h"
//#include "Stack.h"
//#include "Queue.h"
//using namespace std;
//
//
//class Player {
//public:
//	int number;
//	int position;
//	int score;
//	Stack<int> diceRoll;
//
//	Player() : score(0) {
//		position = 0;
//		//position.y = -1;
//	}
//
//	Player(int Number) : number(Number), score(0) {
//		position = 0;
//
//		//position.x = -1;
//		//position.y = -1;
//	}
//};
//
//class Game {
//	Map* gameMap;
//	Stack <int> diceRollStack;
//
//public:
//	Queue<Player>* Players;
//
//	Game(string mapLocation, int players, int rows = 10, int cols = 10) {
//		vector<string> LoadHere;
//		readMap(LoadHere);
//
//		gameMap = new Map(rows, cols, LoadHere);
//		Players = new Queue <Player>;
//		Player toAdd;
//		for (int i = 0; i < players; i++) {
//			toAdd.number = i + 1;
//			Players->enqueue(toAdd);
//		}
//	}
//
//	Game(int players) {
//
//		vector<string> LoadHere;
//		readMap(LoadHere);
//
//		gameMap = new Map(10, 10, LoadHere);
//
//		Players = new Queue <Player>;
//		Player toAdd;
//		for (int i = 0; i < players; i++) {
//			toAdd.number = i + 1;
//			Players->enqueue(toAdd);
//		}
//	}
//
//	bool IsLadder(int index) {
//		cout << "Ladder at index " << index << " " << gameMap->positions.getNodeData(index - 1) << endl;
//		//char option;
//		//cin>>option;
//		return gameMap->positions.getNodeData(index - 1)[0] == 'L';
//		//return gameMap[index + 1][0] == "L";
//	}
//
//	bool IsSnake(int index) {
//
//		return gameMap->positions.getNodeData(index - 1)[0] == 'S';
//	}
//
//	Tile* GetTile(int index) {
//		return gameMap->positions.getNode(index - 1);
//	}
//
//	void BringOnBoard() {
//		Players.getTop()->data;
//	}
//
//	int TraverseBoard(int position, RollStack) {
//
//	}
//
//	int ThrowDice() {
//		srand(time(NULL));
//		return rand() % 6 + 1;
//	}
//
//	void RollDice(int diceVal = -1, int sixcount = 0) {
//
//		if (diceVal == 6) {
//			if (Players->getTop()->data.position == 0) {
//				Players->getTop()->data.position++;
//				nextTurn();
//			}
//			else {
//				RollDice(-1, sixcount + 1);
//			}
//		}
//	}
//
//
//
//	//void RollDice(int diceVal=-1, int sixcount=0) {
//	//	
//	//	if (sixcount == 3) {
//	//		return;
//	//	}
//	//	if (diceVal == -1) {
//	//		diceVal = ThrowDice();
//	//	}
//	//	if (diceVal == 6) {
//	//		if (Players.getTop()->data.position == 0) {
//	//			Players.getTop()->data.position++;
//	//		}
//	//		else{
//	//			RollDice(-1, sixcount + 1);
//	//		}
//	//	}
//	//}
//
//
//
//	bool nextTurn() {
//		Players->enqueue(Players->dequeue());
//		return true;
//	}
//
//	Queue<Player>& GetTurnQueue() {
//		return &Players;
//	}
//
//};