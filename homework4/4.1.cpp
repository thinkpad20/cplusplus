#include <iostream>
using namespace std;

void g();
int h();

struct A {
	A() {
		cout << "created A" << endl;
	}

	~A() {
		cout << "flushing cout" << endl;
		cout.flush();
	}
};

int f() {
	// A a;
	cout << "call to f\n";
	g(); // g and h are functions whose definitions are unknown
	cout << "h returns: " << h() << "\n";
	cout.flush();
	return 0;
}

void g() {
	cout << "call to g" << endl;

}

int h() {
	cout << "call to h\n";
	throw 10;
	return 5;
}

A a;

int main() {
	try {
		f();
	} catch (...) {
		cout << "exception happened" << endl;
	}
	return 0;
}