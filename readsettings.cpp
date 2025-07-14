#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "functions.h"
#include "defs.h"
using namespace std;
int GameScale; // The Dimensions of each tile in pixels
float mapDensity; // The density of Cells in the beginning in 0.0 -> 1.0
int ScreenWidth; // The width of the game window in pixels
int ScreenHeight; // The height of the game window in pixels
float ThreadCountUsage; // The percentage of CPU threads to use for the game
int TickTime; // Time between game ticks in milliseconds
// https://www.w3schools.com/cpp/cpp_files.asp

int readSettings() {
	cout << endl << "Reading Settings from options.txt" << endl;
	string settingsFile;
	// Read from the text file
	ifstream MyReadFile("options.txt");
	vector<string> lines;
	vector<vector<string>> settings;
	string line;
	while (getline(MyReadFile, line)) {
		lines.push_back(line);
	}
	for (int i = 0; i < lines.size(); i++) {
		istringstream iss(lines[i]);  // create a string stream from the line
		string key;
		size_t pos = lines[i].find_first_not_of(" \t");
		if (pos != string::npos) {
			if (lines[i][pos] != '#') {
				settings.push_back(vector<string>());
				while (getline(iss, key, '=')) {
					settings.back().push_back(key);
				}
			}
		}
	}
	// Close the file
	MyReadFile.close();
	for (const auto& l : settings) {
		cout << l[0] << "///" << l[1] << endl;
	}
	for (int i = 0; i < settings.size(); i++) {
		string key = settings[i][0];
		string value = settings[i][1];
		if (key== "GameScale") {
			GameScale = stoi(value);
		} else if (key == "mapDensity") {
			mapDensity = stof(value);
		} else if (key == "ScreenWidth") {
			ScreenWidth = stoi(value);
		} else if (key == "ScreenHeight") {
			ScreenHeight = stoi(value);
		} else if (key == "ThreadCountUsage") {
			ThreadCountUsage = stof(value);
		} else if (key == "TickTime") {
			TickTime = stoi(settings[i][1]);
		}
	}
	return 1;
}