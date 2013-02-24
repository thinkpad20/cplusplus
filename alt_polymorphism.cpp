#include <iostream>
#include <vector>

using namespace std;

void catSpeak() {
	printf("Meow!\n");
}

void dogSpeak() {
	printf("Woof!\n");
}

struct Cat {
	void (*speak)();
};

struct Dog {
	void (*speak)();
};

struct Pet {
	void *orig;
	void (*speak)();

	Pet(void *original) {
		orig = original;
	}
};

int main() {
	Cat c1;
	c1.speak = catSpeak;
	Dog d1;
	d1.speak = dogSpeak;
	Pet p1(&c1), p2(&d1);
	p1.speak = c1.speak;
	p2.speak = d1.speak;

	p1.speak(); p2.speak();
}