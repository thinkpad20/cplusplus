#include <iostream>
#include <vector>
using std::vector;
using std::cout;
using std::endl;


int main() {
	vector<vector<int> > outer(10);
	for (int i=0; i<10; i++) {
		vector<int> inner(10);
		outer[i] = inner;
	}

	for (int i=0; i<10; i++) {
		for (int j=0; j<10; j++) {
			cout << outer[i][j];
		}
		cout << endl;
	}

	return 0;
}