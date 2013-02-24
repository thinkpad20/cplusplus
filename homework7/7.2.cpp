#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <algorithm>
#include <iterator>

using namespace std;

string filename = "hurdat_atlantic_1851-2011.txt";
string currentLine, currentYear, linesToRead;
vector<string> lines;
vector<int> yearlyStrength;

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

// bool setUpNextLine() {
// 	while (currentLine < lines.size() && currentLine.find("M=") != string::npos)
// 		++currentLine;
// 	/* Now we have a line with M= in it. let's pull some data from that line */

// 	return false;
// }


int main(int argc, char **argv) {
	// int numLines, lineCount = 0;
	// if (argc == 1) numLines = 10;
	// else numLines = atoi(argv[1]);
	// ifstream in;
	// in.open(filename.c_str());
	// if (in.is_open()) {
	// 	while(lineCount < numLines && in.good()) {
	// 		getline(in, currentLine);
	// 		lines.push_back(currentLine);
	// 		++lineCount;
	// 	}
	// }
	// in.close();
	// for (int i=0; i<lines.size(); ++i)
	// 	cout << lines[i] << endl;

	string foo = "this is a big string";
	vector<string> fooTokens = tokenize(foo);
	for (int i=0; i<fooTokens.size(); ++i)
		cout << fooTokens[i] << endl;

	return 0;
}