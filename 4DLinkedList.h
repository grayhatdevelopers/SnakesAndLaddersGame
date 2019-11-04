#pragma once

#include <iostream>
using namespace std;

class Tile {
public:
	Tile* up;
	Tile* down;
	Tile* previous;
	Tile* next;

	int number;
	string data;

	Tile() {
		up = nullptr;
		down = nullptr;
		previous = nullptr;
		next = nullptr;
		//number = -1;
		//special = "";
	}

	Tile(string Data, int number = -1, string special = "") : data(Data),  number(number){
		up = nullptr;
		down = nullptr;
		previous = nullptr;
		next = nullptr;
		//special = "";

	}

};



class List {
	Tile* head;
	Tile* cursor;
public:
	List() {
		head = nullptr;
		cursor = nullptr;
	}


	bool isEmpty() {
		return head == nullptr;
	}

	void insertAtHead(const string& newDataItem, int number = -1) {
		Tile* newNode = new Tile (newDataItem, number);
		newNode->next = nullptr;
		head = newNode;
		cout << "Pointing cursor to head!" << endl;
		cursor = head;
	}

	void setUpAtEnd(const string& newDataItem, int number = -1) {
		//moveCursorToEnd();
		Tile* newNode = new Tile (newDataItem, number);
		cursor->up = newNode;
		cursor = newNode;
	}

	void setDownAtEnd(Tile* below) {
		cursor->down = below;
	}

	void setPreviousAtEnd(Tile* prev) {
			cursor->previous = prev;
	}

	void insert(const string& newDataItem, int number=-1) {

		if (isEmpty()) {
			insertAtHead(newDataItem, number);
			return;
		}
		else {
			Tile* newNode = new Tile (newDataItem, number);
			if (!cursor) {
				cout << "The cursor was NULLPTR, so moving to head." << endl;
				cursor = head;
				moveCursorToEnd();
			}
			cursor->next = newNode;
			cursor = newNode;
		}
	}

	void insertAt(const string& newDataItem, int index) {
		if (isEmpty() && index != 0) {
			cout << "The List is empty!" << endl;
			return;
		}
		else {
			if (index == 0) {
				insertAtHead(newDataItem);
				return;
			}
			else {
				Tile* newNode = new Tile (newDataItem);
				int i = index;
				cursor = head;
				while (i > 1) {

					if ((cursor == nullptr) && i != 1) {
						cout << "Index is out of range!" << endl;
						break;
					}
					cursor = cursor->next;
					i--;
				}

				if (i == 1) {
					newNode->next = cursor->next;
					cursor->next = newNode;
					return;
				}
				else {
					return;
				}
			}
		}

	}

	Tile* getNode(int index) {
		cursor = head;
		for (int i=0; i<index; i++){
			if (cursor->next == nullptr) {
				if (cursor->up == nullptr) {
					break;
				}
				else
					cursor = cursor->up;
			}
			else
				cursor = cursor->next;

		}
		return cursor;

	}

	int getNodeData(int index) {
		cursor = head;
		for (int i = 0; i < index; i++) {
			if (cursor->next == nullptr) {
				if (cursor->up == nullptr) {
					break;
				}
				else
					cursor = cursor->up;
			}
			else
				cursor = cursor->next;
		}
		return cursor->number;

	}


	string getNodeSpecialData(int index) {
		cursor = head;
		for (int i = 0; i < index; i++) {
			if (cursor->next == nullptr) {
				if (cursor->up == nullptr) {
					break;
				}
				else
					cursor = cursor->up;
			}
			else
				cursor = cursor->next;
		}
		return cursor->data;

	}

	int searchThroughID(string ID) {
		cursor = head;
		int i = 0;
		while (cursor != nullptr) {

			if (cursor->data == ID) {
				return i;
			}
			i++;
			cursor = cursor->next;
			if (cursor == nullptr) {
				return -1;
			}

		}
		return -1;
	}

	bool deleteThroughID(string ID) {
		cursor = head;
		Tile* prevNode = NULL;
		while (cursor) {
			prevNode = cursor;
			if (cursor->data == ID) {
				if (prevNode) {
					prevNode->next = cursor->next;
					delete cursor;
					cursor = head;
				}
				else {
					head = cursor->next;
					delete cursor;
					cursor = head;
				}
				return true;
			}
			if (cursor->next == nullptr) {
				break;
			}
			cursor = cursor->next;

		}
		return false;
	}


	Tile* getCursor() {
		return cursor;
	}
	int getCursorData() {
		return cursor->number;
	}

	string getCursorSpecialData() {
		return cursor->data;
	}

	void moveCursorToHead() {
		cursor = head;
	}

	/*string getCursorData() {
		return cursor->data;
	}*/

	bool goToNext() {
		if (!cursor->next) return false;
		cursor = cursor->next;
		return true;
	}
	bool moveCursorToEnd() {
		if (!isEmpty()) {
			while (cursor->next != nullptr && cursor->up != nullptr) {
				if (cursor->next == nullptr) {
					if (cursor->up == nullptr) {
						break;
					}
					else
						cursor = cursor->up;
				}
				else
					cursor = cursor->next;
			}
			return true;
		}
		return false;
	}


	bool moveCursorXTimes(int index) {
		cout << "Index is " << index << endl;
		if (!isEmpty()) {
			cout << "Entered condition " << index << endl;
			while ((cursor->next != nullptr && cursor->up != nullptr) || index!=0) {
				if (cursor->next == nullptr) {
					if (cursor->up == nullptr) {
						break;
					}
					else
						cursor = cursor->up;
				}
				else
					cursor = cursor->next;
				cout << "Iterated " << index << " times!" << endl;
				index--;
			}
			return true;
		}
		return false;
	}

	

	//void remove() {
	//	if (cursor->next == nullptr) {
	//		cout << "Removing the last element..." << endl;
	//		char option; 
	//		cin >> option;
	//		//*cursor = NULL;
	//		delete cursor;
	//		cursor = nullptr;
	//		cursor = head;
	//		cin >> option;
	//		return;
	//	}
	//	cursor->data = cursor->next->data;
	//	Node <T> tmp;
	//	Node <T>* tmpptr;
	//	tmpptr = cursor;
	//	cursor = cursor->next;
	//	tmpptr->next = cursor->next;
	//	delete cursor;
	//	cursor = tmpptr->next;
	//}

	void removeAt(int index) {
		int i = index;
		cursor = head;
		Tile* prevNode =NULL;
		while (i > 0) {

			if ((cursor == nullptr) && i != 0) {
				cout << "Index is out of range!" << endl;
				break;
			}
			prevNode = cursor;
			cursor = cursor->next;
			i--;
		}
		if (cursor == NULL) return;
		if (i == 0) {
			string temp = cursor->data;

			if (prevNode) {
				Tile* tempNode= cursor;
				prevNode->next = prevNode->next->next;
				delete tempNode;
				cursor = head;
			}
			else {
				Tile* tempNode = cursor;
				head = tempNode->next;
				delete tempNode;
				cursor = head;
			}
			cout << temp << " was deleted!";
			return;
		}
		else {
			return;
		}
	}

	string remove(string Emp) {
		cursor = head;
		Tile* prevNode = NULL;
		while (cursor != nullptr) {

			if (cursor->data == Emp) {
				cout << "Your data was found!" << endl;
				break;
			}
			prevNode = cursor;
			cursor = cursor->next;
			if (cursor == nullptr) {
				cout << "Out of range or not found!" << endl;
				break;
			}

		}

		if (cursor) {
			string temp = Emp;

			if (prevNode){
				prevNode->next = cursor->next;
				delete cursor;
				cursor = head;
			}
			else {
				head = cursor->next;
				delete cursor;
				cursor = head;
			}
			cout << temp << "was deleted!";
			return temp;
		}
		cout << "Reached end of function. " << endl;
		return NULL;
	}

	//bool remove(string Emp) {
	//	cursor = head;
	//	Node <T>* prevNode = NULL;
	//	while (cursor != nullptr) {

	//		if (cursor->data.ID == Emp) {
	//			cout << "Your data was found!" << endl;
	//			break;
	//		}
	//		prevNode = cursor;
	//		cursor = cursor->right;
	//		if (cursor == nullptr) {
	//			cout << "Out of range or not found!" << endl;
	//			break;
	//		}

	//	}

	//	if (cursor) {
	//		T temp = cursor->data;

	//		if (prevNode) {
	//			prevNode->next = cursor->right;
	//			delete cursor;
	//			cursor = head;
	//		}
	//		else {
	//			head = cursor->right;
	//			delete cursor;
	//			cursor = head;
	//		}
	//		cout << temp << " was deleted!"<<endl;
	//		return true;
	//	}
	//	cout << "Reached end of function. " << endl;
	//	return false;
	//}



	void sort() {
		if (isEmpty()) return;
		//cursor = head;
		Tile* tmp = head;
		string tempvar;
		while (tmp->next) {
			cursor = tmp;
			while (cursor->next) {
				if (cursor->data > cursor->next->data) {
					tempvar = cursor->data;
					cursor->data = cursor->next->data;
					cursor->next->data = tempvar;
				}
				cursor = cursor->next;
			}

			tmp = tmp->next;
		}
	}


	//bool updateSalary(int index, int amount) {
	//	int i = index;
	//	cursor = head;
	//	Tile* prevNode = NULL;
	//	while (i > 1) {

	//		if ((cursor == nullptr) and i != 1) {
	//			cout << "Index is out of range!" << endl;
	//			break;
	//		}
	//		prevNode = cursor;
	//		cursor = cursor->next;
	//		i--;
	//	}

	//	if (i == 1) {
	//		cursor->next->data.salary += amount;
	//		return true;
	//	}
	//	else {
	//		return false;
	//	}


	//}


	bool duplicate() {
		if (isEmpty()) return false;

		Tile* tmp = head;
		string tempvar;
		while (tmp) {
			cursor = tmp->next;
			while (cursor) {
				if (cursor->data == tmp->data) {
					return true;
				}
				cursor = cursor->next;
			}

			tmp = tmp->next;
		}
		return false;
	}

	//void splitList(int index) {
	//	if (isEmpty() or head->next->next == nullptr) return;

	//	int i = index;
	//	cursor = head;
	//	while (i > 1) {

	//		if ((cursor == nullptr) and i != 1) {
	//			cout << "Index is out of range!" << endl;
	//			break;
	//		}
	//		cursor = cursor->next;
	//		i--;
	//	}
	//	if (i == 1 and cursor->next) {
	//		List* newList = new List;
	//		while (cursor) {
	//			newList.insert(cursor.data);
	//			remove();
	//		}
	//		cout << "The splitted List is...";
	//		newList->Display();
	//		cout << endl;
	//	}
	//	else {
	//		return;
	//	}

	//}

	void Display() {
		Tile* displaycursor = head;
		cursor = head;
		char option;
		cin >> option;
		cout << "The Linked List is..." << endl;
		if (isEmpty()) {
			cout << "Empty!" << endl;
			return;
		}
		
		cout << "{ ";
		while (displaycursor) {
			//cin >> option;
			cout << displaycursor->number;
			if (displaycursor->next == nullptr) {
				if (displaycursor->up == nullptr) {
					break;
				}
				else
					displaycursor = displaycursor->up;
			}
			else
				displaycursor = displaycursor->next;			if (displaycursor != nullptr) {
				cout << ", ";
			}
		}
		cout << " }" << endl;
		cin >> option;
	}

	bool clear() {
		if (isEmpty()) {
			return false;
		}
		Tile* nextNode = nullptr;
		cursor = head;
		while (cursor != nullptr)
		{
			nextNode = cursor->next;
			// destroy the current node
			delete cursor;
			cursor = nextNode;
		}
		head = nullptr;
		return true;
	}

	~List() {
		clear();
		delete head;
		delete cursor;
	}
};
