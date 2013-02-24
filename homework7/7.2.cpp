#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <algorithm>
#include <iterator>

using namespace std;

/* define a macro to get the line and increment currentLine */
#define nextLine lines[currentLine++]

string filename = "hurdat_atlantic_1851-2011.txt";
int currentLine, currentYear, linesToRead;
vector<string> lines;
vector<double> yearlyStrength(161);

/*
1) Find a line with 'M=' in it
2) Record the number of lines to read
3) set the year
4) set currentLine to one after the 'M=' line
*/

vector<string> tokenize(string s) {
	istringstream iss(s);
	vector<string> tokens;
	copy(istream_iterator<string>(iss),
         istream_iterator<string>(),
         back_inserter<vector<string> >(tokens));
	return tokens;
}

bool contains(string str, string target) {
	return str.find(target) != string::npos;
}

bool setUpNextLine() {
	/* have a line with M= in it. let's get the tokens from that line */
	if (currentLine == lines.size()-1) return false;
	vector<string> tokens = tokenize(nextLine);
	if (contains(tokens[2], "M=")) {
		string date = tokens[1];
		currentYear = atoi(date.substr(date.size()-4).c_str());
		if (tokens[2] == "M=")
			linesToRead = atoi(tokens[3].c_str());
		else
			linesToRead = atoi(tokens[2].substr(2).c_str());
		return true;
	}
	return false;
}

double cat(string mph_str) {
	int mph = atoi(mph_str.c_str());
	if (mph >= 74 && mph < 96) return 1.0;
	if (mph >= 96 && mph < 111) return 2.0;
	if (mph >= 111 && mph < 131) return 3.0;
	if (mph >= 131 && mph < 156) return 4.0;
	return 5.0;
}

void averageLines() {
	double total = 0.0;
	for (int i=0; i<linesToRead; ++i) {
		vector<string> tokens = tokenize(nextLine);
		double subtotal = cat(tokens[3]);
		subtotal += cat(tokens[6]);
		subtotal += cat(tokens[9]);
		subtotal += cat(tokens[12]);
		subtotal /= 4.0;
		total += subtotal;
	}
	yearlyStrength[currentYear-1851] += total;
	if (currentLine < lines.size()-1) nextLine;
}

int main(int argc, char **argv) {
	int numLines = INT_MAX, lineCount = 0;
	ifstream in;

	in.open(filename.c_str());
	if (in.is_open()) {
		while(lineCount < numLines && in.good()) {
			string line;
			getline(in, line);
			lines.push_back(line);
			++lineCount;
		}
	}
	in.close();

	cout << "Total " << lines.size() << " lines to read" << endl;

	while(setUpNextLine())
		averageLines();

	for (int i=0; i<yearlyStrength.size(); ++i)
		cout << i+1851 << ": " << yearlyStrength[i] << endl;
	return 0;
}