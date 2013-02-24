#include <iostream>
using namespace std;

/*Use for returning the address of a local variable:
the g() function returns, essentially, its location on the stack.
f() checks this address against the minimum address it's been given
(recall that the stack grows downwards) and returns if g's location on the
stack is below the minimum. So g acts like a "check" to make sure that f(), 
which would normally recurse infinitely, only recurses to a certain level 
and prevents a stack overflow.*/

int *g() {
	int i;
	return &i;
}

void f(unsigned long minaddr) {
	int *addr = g();
	printf("found address at 0x%lX\n", (unsigned long)addr);
	if ((unsigned long)addr < minaddr)
		return;
	f(minaddr);
}

int main(int argc, char **argv) {
	int j, numsteps;
	printf("initially the stack is at location 0x%lX\n", (unsigned long)&j);
	if (argc==2) numsteps = atoi(argv[1]);
	else numsteps = 5;
	unsigned long minaddr = (unsigned long)&j - 48*numsteps;
	printf("going down to address 0x%lX\n", minaddr);
	f(minaddr);
	return 0;
}