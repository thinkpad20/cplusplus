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

/* updates the date, and gets the number of lines to process */
bool setup() {
	/* have a line with M= in it. let's get the tokens from that line */
	if (currentLine == lines.size()-1) return false;
	vector<string> tokens = tokenize(nextLine);
	if (contains(tokens[2], "M=")) {
		/* update the year */
		string date = tokens[1];
		currentYear = atoi(date.substr(date.size()-4).c_str());
		/*get the number of lines to read*/
		if (tokens[2] == "M=") /* then the next token tells us how many. */
			linesToRead = atoi(tokens[3].c_str());
		else /* then the number of lines to read is contained in this token. */
			linesToRead = atoi(tokens[2].substr(2).c_str());
		return true;
	}
	return false;
}

/* converts MPH to a storm category */
double cat(string mph_str) {
	int mph = atoi(mph_str.c_str());
	if (mph >= 74 && mph < 96) return 1.0;
	if (mph >= 96 && mph < 111) return 2.0;
	if (mph >= 111 && mph < 131) return 3.0;
	if (mph >= 131 && mph < 156) return 4.0;
	return 5.0;
}

/* gets the category from each line and adds it to that year's total */
void update() {
	double total = 0.0;
	for (int i=0; i<linesToRead; ++i) {
		vector<string> tokens = tokenize(nextLine);
		total += cat(tokens[3]);
		total += cat(tokens[6]);
		total += cat(tokens[9]);
		total += cat(tokens[12]);
	}
	yearlyStrength[currentYear-1851] += total/4.0;
	/*skip the next line*/
	nextLine;
}

int main(int argc, char **argv) {
	int numLines = INT_MAX, lineCount = 0;
	ifstream in;
	/* load the file into a vector of strings */
	in.open(filename.c_str());
	if (in.is_open()) {
		while(lineCount < numLines && in.good()) {
			string line;
			getline(in, line);
			lines.push_back(line);
			++lineCount;
		}
	} else { cout << "File Error" << endl; return 0; }
	in.close();
	/* zero the initial values */
	for (int i=0; i<161; ++i)
		yearlyStrength[i] = 0.0;
	/* compute the averages */
	while(setup()) update();
	/* print the results */
	for (int i=0; i<yearlyStrength.size(); ++i)
		cout << i+1851 << ": " << yearlyStrength[i] << endl;
	return 0;
}