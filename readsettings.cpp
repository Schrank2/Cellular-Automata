#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "functions.h"
#include "defs.h"
using namespace std;
int GameScale = 16; // The Dimensions of each tile in pixels
float mapDensity = 0.7; // The density of Cells in the beginning in 0.0 -> 1.0
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
	// Use a while loop together with the getline() function to read the file line by line
	while (getline(MyReadFile, settingsFile)) {
		// Output the text from the file
		cout << settingsFile << endl;
	}
	// Close the file
	MyReadFile.close();
	cout << endl;
	return 1;
}