#pragma once
#include <fstream>
#include <string>
#include <cstdlib>
#include "Map.h"
//#include "Coordinates.h"
//#include "Config.h"
using namespace std;

class Coordinates {
public:
	int x;
	int y;

	Coordinates() : x(0), y(0) {
	}

	Coordinates(int X, int Y) : x(X), y(Y) {
	}
};


bool clearRecent() {
	remove("recent_sim.temp");
	return true;
}

bool saveRecent(string text) {
	ofstream ofs("recent_sim.temp", ofstream::app);
	ofs << text;
	ofs.close();

	return true;
}

bool writeResults(string filename) {
	ifstream infile("recent_sim.temp");
	ofstream outfile("User_Results/" + filename + ".txt");
	string content = "";
	int i;

	for (i = 0; infile.eof() != true; i++) //get content of recent_sim into string
		content += infile.get();

	i--;
	content.erase(content.end() - 1);     //erase last character

	infile.close();

	outfile << content;                 //output string into the user's preferred file
	outfile.close();
	clearRecent();
	return true;
}


bool writeMap(string mapname, vector<Coordinates> ladderPositions, vector<Coordinates> snakePositions) {
	ifstream infile("recent_sim.temp");
	ofstream outfile("User_Maps/" + mapname + ".txt");
	string content = "";
	int i;

	for (i = 0; infile.eof() != true; i++) //get content of recent_sim into string
		content += infile.get();

	i--;
	content.erase(content.end() - 1);     //erase last character

	infile.close();

	outfile << content;                 //output string into the user's preferred file
	outfile.close();
	clearRecent();
	return true;
}


bool readMap(vector <string> &LoadHere, string readFrom="map.txt") {
	ifstream ifs;
	if (readFrom != "map.txt")
		readFrom = "User_Maps/" + readFrom;
	ifs.open(readFrom, ifstream::in);
	if (!ios::failbit) {
		ifs.close();
		throw logic_error ("Loading failed.");
	}
	if (ifs.eof()) {
		ifs.close();
		throw logic_error("File is empty.");
	}
	if (!ifs.good()) {
		ifs.close();
		throw logic_error("File couldn't be found. Either it was deleted, or has access issues.");
	}
	char c;

	c = ifs.get();
	string t = "";
	vector <string> temp;
	bool change = true;
	int i = 0;
	while (!ifs.eof()) {
		
		if (c != ' ' && c!='\n') {
			t += c;
		}
		else {

			if (c == '\n') {
				if (t != "") {
					if (change)
						LoadHere.push_back(t);
					else
						temp.push_back(t);
				}
				t = "";
				change = !change;
				if (!temp.empty()) {
					reverse(temp.begin(), temp.end());
					LoadHere.insert(LoadHere.end(), temp.begin(), temp.end());
					temp.clear();
				}

			}

			
			if (t != "") {
				if (change)
					LoadHere.push_back(t);
				else
					temp.push_back(t);				
			}
			t = "";

		}
		c = ifs.get();
		i++;
	}

	ifs.close();


	reverse(LoadHere.begin(), LoadHere.end());


	for (int i = 0; i < LoadHere.size(); i++) {
		cout<<LoadHere[i]<<", ";

	}

	return true;

}


//bool writeConfig(Config information) {
//	ofstream ofs("config.ini", ofstream::out);
//
//	ofs << information.gen << endl;
//	ofs << information.cell_no << endl;
//	for (int i = 0; i < information.positions.size(); i++)
//		ofs << information.positions[i].x << " " << information.positions[i].y << endl;
//
//
//	ofs.close();
//
//	return true;
//}


































//
//
//
//
//
//
//
//#pragma once
//#include <fstream>
//#include <string>
//#include <cstdlib>
//#include "Map.h"
////#include "Coordinates.h"
////#include "Config.h"
//using namespace std;
//
//class Coordinates {
//public:
//	int x;
//	int y;
//
//	Coordinates() : x(0), y(0) {
//	}
//
//	Coordinates(int X, int Y) : x(X), y(Y) {
//	}
//};
//
//
//bool clearRecent() {
//	remove("recent_sim.temp");
//	return true;
//}
//
//bool saveRecent(string text) {
//	ofstream ofs("recent_sim.temp", ofstream::app);
//	ofs << text;
//	ofs.close();
//
//	return true;
//}
//
//bool writeResults(string filename) {
//	ifstream infile("recent_sim.temp");
//	ofstream outfile("User_Results/" + filename + ".txt");
//	string content = "";
//	int i;
//
//	for (i = 0; infile.eof() != true; i++) //get content of recent_sim into string
//		content += infile.get();
//
//	i--;
//	content.erase(content.end() - 1);     //erase last character
//
//	infile.close();
//
//	outfile << content;                 //output string into the user's preferred file
//	outfile.close();
//	clearRecent();
//	return true;
//}
//
//
//bool writeMap(string mapname, vector<Coordinates> ladderPositions, vector<Coordinates> snakePositions) {
//	ifstream infile("recent_sim.temp");
//	ofstream outfile("User_Maps/" + mapname + ".txt");
//	string content = "";
//	int i;
//
//	for (i = 0; infile.eof() != true; i++) //get content of recent_sim into string
//		content += infile.get();
//
//	i--;
//	content.erase(content.end() - 1);     //erase last character
//
//	infile.close();
//
//	outfile << content;                 //output string into the user's preferred file
//	outfile.close();
//	clearRecent();
//	return true;
//}
//
//
//bool readMap(vector <string>& LoadHere, string readFrom = "map.txt") {
//	ifstream ifs;
//	if (readFrom != "map.txt")
//		readFrom = "User_Maps/" + readFrom;
//	ifs.open(readFrom, ifstream::in);
//	if (!ios::failbit) {
//		ifs.close();
//		throw logic_error("Loading failed.");
//	}
//	if (ifs.eof()) {
//		ifs.close();
//		throw logic_error("File is empty.");
//	}
//	if (!ifs.good()) {
//		ifs.close();
//		throw logic_error("File couldn't be found. Either it was deleted, or has access issues.");
//	}
//	char c;
//
//	c = ifs.get();
//	string t = "";
//	vector <string> temp;
//	bool change = true;
//	int i = 0;
//	while (!ifs.eof()) {
//
//		if (c != ' ' && c != '\n') {
//			t += c;
//		}
//		else {
//			if (c == '\n') {
//
//				i++;
//
//				if (i % 2 == 0) {
//					change = !change;
//					if (!temp.empty()) {
//						reverse(temp.begin(), temp.end());
//						LoadHere.insert(LoadHere.end(), temp.begin(), temp.end());
//					}
//
//				}
//
//
//				if (t != "") {
//					if (change)
//						LoadHere.push_back(t);
//					else
//						temp.push_back(t);
//
//
//
//				}
//				t = "";
//
//			}
//			c = ifs.get();
//			i++;
//		}
//
//		ifs.close();
//
//		for (int i = 0; i < LoadHere.size(); i++) {
//			cout << LoadHere[i] << ", ";
//			if (i % 10 == 0) {
//				cout << endl;
//			}
//		}
//
//		return true;
//
//	}
//
//
//	//bool writeConfig(Config information) {
//	//	ofstream ofs("config.ini", ofstream::out);
//	//
//	//	ofs << information.gen << endl;
//	//	ofs << information.cell_no << endl;
//	//	for (int i = 0; i < information.positions.size(); i++)
//	//		ofs << information.positions[i].x << " " << information.positions[i].y << endl;
//	//
//	//
//	//	ofs.close();
//	//
//	//	return true;
//	//}
