#include "Concordance.h"
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

string getWord(string& line) {
	string word = "";
	for (int i = 0; i < line.size(); ++i) {
		if ((line[i] >= 'A' && line[i] <= 'Z') || (line[i] >= 'a' && line[i] <= 'z')) {
			line = line.substr(i);
			break;
		}
	}
	for (int i = 0; i < line.size(); ++i) {
		if ((line[i] >= 'A' && line[i] <= 'Z') || (line[i] >= 'a' && line[i] <= 'z')) {
			word += (char)toupper(line[i]);
		}
		else {
			line = line.substr(i);
			for (int j = 0; j < line.size(); ++j) {
				if (((line[j] >= 'A' && line[j] <= 'Z') || (line[j] >= 'a' && line[j] <= 'z'))) {
					line = line.substr(j);
					return word;
				}
			}
			line = "";
			return word;
		}
	}
	line = "";
	return word;
}

int main() {
	ifstream infile;
	string fileName, line, word;
	Concordance c;
	cout << "Enter a file name: ";
	cin >> fileName;
	infile.open(fileName);
	if (infile.is_open()) {
		while (getline(infile, line)) {
			while (line != "") {
				word = getWord(line);
				if (word.size() > 8) {
					word = word.substr(0, 8);
				}
				if (word.size() != 0)
					c.insert(word.c_str());
			}
		}
		c.print();
	}
	else {
		cout << "Can not open file " + fileName << endl;
	}
	return 0;
}