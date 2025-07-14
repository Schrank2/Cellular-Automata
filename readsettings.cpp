#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "functions.h"
#include "defs.h"
using namespace std;
int GameScale = 10; // The Dimensions of each tile in pixels
float mapDensity = 0.5; // The density of Cells in the beginning in 0.0 -> 1.0
int ScreenWidth = 1600; // The width of the game window in pixels
int ScreenHeight = 900; // The height of the game window in pixels
float ThreadCountUsage = 0.5; // The percentage of CPU threads to use for the game
int TickTime = 150; // Time between game ticks in milliseconds
// https://www.w3schools.com/cpp/cpp_files.asp

int readSettings() {
	cout << endl << "Reading Settings from options.txt" << endl;
	string settingsFile;
	// Read from the text file
	ifstream MyReadFile("options.txt");
	vector<string> lines;
	vector<string> linesDivided;
	vector<vector<string>> settings;
	string line;
	while (getline(MyReadFile, line)) {
		lines.push_back(line);
	}
	for (int i = 0; i < lines.size(); i++) {
		std::istringstream iss(lines[i]);  // create a string stream from the line
		std::string key;
		while (getline(iss, key, '=')) {
			linesDivided.push_back(key);
		}
	}
	// Close the file
	MyReadFile.close();
	for (const auto& l : linesDivided) {
		cout << l << endl;
	}
	return 1;
}