#include <iostream>
#include <vector>
#include <algorithm>

#define MAXVAL 100

using namespace std;

vector<int> v;

int main() {
	for (int i=0; i<MAXVAL; ++i) {
		//fill with ints that are variously positive and negative
		if (rand() % 2)
			v.push_back(rand() % MAXVAL);
		else
			v.push_back((rand() % MAXVAL) * -1);
	}

	cout << "Before: " << endl;
	for (int i=0; i != v.size(); ++i) {
		cout << v[i] << ", ";
		if (!(i % 20)) 
			cout << endl;
	}
	cout << endl;
	sort(v.begin(), v.end(), [](int x, int y){return abs(x) < abs(y);});

	cout << "After: " << endl;
	for (int i=0; i != v.size(); ++i) {
		cout << v[i] << ", ";
		if (!(i % 20)) 
			cout << endl;
	}
	cout << endl;

}