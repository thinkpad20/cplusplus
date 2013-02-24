#include <iostream>
#include <vector>
using namespace std;

struct Cat {
	void speak() {
		cout << "Meow!" << endl;
	}
};

struct Dog {
	void speak() {
		cout << "Woof!" << endl;
	}
};

struct Pet {
	union petU {
		Dog d;
		Cat c;
	} pet;

	void (*speak) ();

	Pet() {}
};

int main() {
	Cat c1;
	Dog d1;
	Pet p1, p2;
	p1.pet.c = c1;
	p1.pet.speak = 
	p1.pet.d = d1;

}