#pragma once
#include "4DLinkedList.h"
#include <vector>
#include "Stack.h"
#include "Queue.h"
using namespace std;
class Map {
public:
	int rows, col;
	List positions;

	Map() {
		rows = 0;
		col = 0;
	}

	Map(int Rows, int Columns, vector <string> Position) : rows(Rows), col(Columns) {

		//Stack <Stack <Tile*>> SnakeStack;
		//Queue <Queue <Tile*>> LadderQueue;
		vector <string> LadderCharacters;
		vector <Tile*> LadderAddresses;

		vector <string> SnakeCharacters;
		vector <Tile*> SnakeAddresses;

		Tile* prev=nullptr;
		Tile* below = nullptr;
		Tile* edgeprev = nullptr;
		for (int i = 1; i <= Rows*Columns;) {
			if (i % Columns == 0 && i != 1 && i != Rows * Columns) {
				//toDo: Try cleanup of code by rearranging
				edgeprev = positions.getCursor();
				if (Position[i - 1][0] > '9' || Position[i - 1][0] < '0')
					positions.insert(Position[i - 1], i);
				else
					positions.insert("", i);

				positions.setPreviousAtEnd(prev);
				prev = positions.getCursor();
				cout << "Is at " << prev->data << endl;

				below = positions.getCursor();
				//cout << "Data in edge prev: " << edgeprev->data << endl;
				//cout << "Data in prev: " << prev->data << endl;
				//i++;
				if (Position[i][0] > '9' || Position[i][0] < '0')
					positions.setUpAtEnd(Position[i], ++i);
				else
					positions.setUpAtEnd("", ++i);
				positions.setDownAtEnd(below);
				prev = positions.getCursor();
				cout << "Position " << Position[i] << " has been set upwards." << endl;
				i++;
			}
			else {
				edgeprev = positions.getCursor();
				if (Position[i - 1][0] > '9' || Position[i - 1][0] < '0'){
					Tile* temporary;

				temporary = positions.insert(Position[i - 1], i);
				std::vector<string>::iterator it;
				if (Position[i - 1][0] == 'L') {
					it = find(LadderCharacters.begin(), LadderCharacters.end(), Position[i - 1]);
					if (it != LadderCharacters.end()) {
						// Get index of element from iterator
						int index = std::distance(LadderCharacters.begin(), it);
						std::cout << "Element found in LadderCharacters: " << *it << '\n';
						LadderAddresses[index]->up = temporary;

						LadderAddresses[index] = temporary;
						cout << "Set the up pointer then updated the LadderAddresses" << endl;
					}
					else {
						std::cout << "Element not found in myvector\n";
						LadderCharacters.push_back(Position[i - 1]);
						LadderAddresses.push_back(temporary);
						cout << "so Pushed into LadderCharacters and LadderAddresses" << endl;
						}
					}
				else if (Position[i - 1][0] == 'S') {
					it = find(SnakeCharacters.begin(), SnakeCharacters.end(), Position[i - 1]);
					if (it != SnakeCharacters.end()) {
						// Get index of element from iterator
						int index = std::distance(SnakeCharacters.begin(), it);
						std::cout << "Element found in SnakeCharacters: " << *it << '\n';
						temporary->down = SnakeAddresses[index];

						SnakeAddresses[index] = temporary;
						cout << "Set the down pointer of current then updated the SnakeAddresses" << endl;
					}
					else {
						std::cout << "Element not found in myvector\n";
						SnakeCharacters.push_back(Position[i - 1]);
						SnakeAddresses.push_back(temporary);
						cout << "so Pushed into SnakeCharacters and SnakeAddresses" << endl;
					}
				}
				}
				
				else
					positions.insert("", i);
				positions.setPreviousAtEnd(prev);
				prev = positions.getCursor();
				cout << "Is at " << prev->data<<endl;
				i++;
			}

			//if (i % 10 == 0 && i != 0 && i != 100) {
			//	positions.setUpAtEnd(Position[i - 1]);
			//	cout << "Position " << Position[i - 1] << " has been set upwards." << endl;
			//}
			//else {
			//	positions.insert(Position[i - 1]);
			//	if (i!=0)
			//}
		}
		positions.Display();
	}

	//void addPosition(string temp) {
	//	positions.push_back(temp);
	//}

	string operator[](const int index) {
		return positions.getNodeSpecialData(index);
	}
};


