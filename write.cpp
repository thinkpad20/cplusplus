#include <iostream>
#include <fstream>

using namespace std;

void writeAFile(string filename) {
	ofstream f;
	f.open(filename.c_str());
	if (f.is_open()) {
		f << "this is a test " << "poopity poop poop" << 23 << 3.121 << "\n";
		f.close();
		cout << "wrote some stuff" << endl;
	}
	else cout << "error opening file " << filename << endl;
}

void readAFile(string filename) {
	ifstream f;
	string buffer;
	f.open(filename.c_str());

	if (f.is_open()) {
		cout << "[reading file " << filename << "]" << endl;
		while (f.good()) {
			getline(f, buffer);
			cout << buffer << endl;
		}
		f.close();
	}
	else cout << "error opening file " << filename << endl;
}

int main(int argc, char *argv[]) {

	if (argc==2) {
		writeAFile(string(argv[1]));
		readAFile(string(argv[1]));
	}
	return 0;

}