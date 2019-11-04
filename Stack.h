#pragma once
#include <iostream>
using namespace std;

template <typename T>
struct Item {
	Item <T>* prevNode;
	T data;
	Item() {
		prevNode = nullptr;
	}

	Item(T Data) : data(Data) {
		prevNode = nullptr;
	}
};

template <typename T>
class Stack {
	Item <T>* top;
	//int Ssize;

public:
	Stack() {
		top = nullptr;
	}

	void push(T dataItem) {
		Item<T>* newItem = new Item<T>(dataItem);
		newItem->prevNode = top;
		top = newItem;
	}
	
	T getTop() {
		return top->data;
	}

	bool isEmpty() {
		return top == nullptr;
	}

	//Throw an error in isEmpty().
	T pop() {
		if (isEmpty()) {
			throw std::invalid_argument("ERROR: Stack is empty.");
		}
		T data = top->data;
		Item<T>* toDelete = top;
		top = top->prevNode;
		delete toDelete;
		return data;
	}

	void empty() {
		while (top != nullptr) {
			Item<T>* toDelete = top;
			top = top->prevNode;
			delete toDelete;
		}
		cout << "Stack cleared successfully." << endl;
	}

	void Display() {
		cout << "Displaying Stack..." << endl<<endl;
		Item <T>* cursor = top;
		while (cursor) {
			cout << cursor->data << ", "<<endl;
			cursor = cursor->prevNode;
		}
		cout << endl<<endl;
		cout << "That's it." << endl;
	}

	//haven't checked for all datatypes
	string parseStack() {
		Item <T>* cursor = top;
		string returnTo = "";

		while (cursor) {
			string converted = to_string(cursor->data);
			returnTo += converted;
			if (cursor->prevNode)
				returnTo += ",";
			cursor = cursor->prevNode;
		}
		return returnTo;
	}


};



struct Roll {
	Roll* prevNode;
	int data;
	Roll() {
		prevNode = nullptr;
	}

	Roll(int Data) : data(Data) {
		prevNode = nullptr;
	}
};


class RollStack {
	Roll* top;
	//Roll* cursor;
	//int Ssize;

public:
	RollStack() {
		top = nullptr;
	}

	RollStack(const RollStack& toCopy) {
		//push_roll();

	}

	void push_roll(string dataItem) {
		Roll* newItem = new Roll(stoi(dataItem));
		newItem->prevNode = top;
		top = newItem;
	}

	void push_roll(int dataItem) {
		Roll* newItem = new Roll(dataItem);
		newItem->prevNode = top;
		top = newItem;
	}

	int getTop() {
		return top->data;
	}

	bool isEmpty() {
		return top == nullptr;
	}
	
	int returnSum() {
		int sum = 0;
		Roll * cursor = top;
		while (cursor) {
			sum += cursor->data;
			cursor = cursor->prevNode;
		}
		return sum;
	}

	//Throw an error in isEmpty().
	int pop() {
		if (isEmpty()) {
			throw std::invalid_argument("ERROR: Stack is empty.");
		}
		int data = top->data;
		Roll* toDelete = top;
		top = top->prevNode;
		delete toDelete;
		return data;
	}

	void empty() {
		int i = 0;
		while (!isEmpty()) {
			try {
				pop();
			}
			catch(string message) {

			}
		}
		cout << "Stack cleared successfully." << endl;
	}

	void Display() {
		cout << "Displaying Stack..." << endl << endl;
		Roll* cursor = top;
		while (cursor) {
			cout << cursor->data << ", " << endl;
			cursor = cursor->prevNode;
		}
		cout << endl << endl;
		cout << "That's it." << endl;
	}

	//haven't checked for all datatypes
	string parseStack() {
		Roll* cursor = top;
		string returnTo = "";

		while (cursor) {
			string converted = to_string(cursor->data);
			returnTo += converted;
			if (cursor->prevNode)
				returnTo += ",";
			cursor = cursor->prevNode;
		}
		return returnTo;
	}


};
