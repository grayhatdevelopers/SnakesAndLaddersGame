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
	Game game("map.txt", 4);
	cout << "end the world" << endl;
	cout << "Is Ladder? "<<game.IsLadder(4) << endl;
	cout << "Now test linkage..." << endl;

	//cout << "At 10... "<< game.GetTile(10)->data << endl;

	//cout << "nullptr == nullptr..." << (nullptr == nullptr) << endl;
	//for (int i = 1; i < 100; ++i) {

	//	Tile* current = game.GetTile(i);
	//	Tile* next = game.GetTile(i + 1);

	//	if (i % 10 != 0) {
	//		cout<< (current->next == next) <<", ";
	//		cout << (next->previous == current) << endl;

	//		//if 
	//		if (current->next != next or next->previous != current) {
	//			cout << "Data (current->next == next): " << current->next << " == " << next << endl;
	//			cout << "Data inside of next..." << next->data << endl;
	//			cout << "Data (next->previous == current): " << next->previous << " == " << current << endl;
	//			cout << "Data inside of current..." << current->data << endl;

	//		}
	//	}
	//	else {
	//		cout << (current->up == next)<<endl;
	//		cout << (next->down == current) << endl;
	//	}
	//}

	//Game game("map.txt", 4);

	for (int i = 1; i <= 4; ++i) {
		// bringing all players on the board
		game.RollDice(6);
	}

	auto& queue = game.GetTurnQueue();

	cout<<queue.front()<<" == "<<1 << endl;

	// roll divisible by 3, queue should reverse
	game.RollDice(3);

	cout << queue.front()<<" == "<<4<<endl;

	cout << queue.back()<<" == "<<1 << endl;


	cout << endl << "Now testing MovePlayer..." << endl;


	RollStack stack;

	stack.push_roll(6);
	stack.push_roll(5);
	cout << "Trying to move here bro..." << endl;
	cout << game.TraverseBoard(44, stack);
	cout << " == " << 55 << endl;
	stack.Display();

	stack.empty();
	stack.Display();


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
