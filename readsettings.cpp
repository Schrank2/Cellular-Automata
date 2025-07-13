#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "functions.h"
#include "defs.h"
using namespace std;
// https://www.w3schools.com/cpp/cpp_files.asp

int readSettings() {
	string settingsFile;
	// Read from the text file
	ifstream MyReadFile("options.txt");
	// Use a while loop together with the getline() function to read the file line by line
	while (getline(MyReadFile, settingsFile)) {
		// Output the text from the file
		cout << settingsFile;
	}
	// Close the file
	MyReadFile.close();
	return 1;
}