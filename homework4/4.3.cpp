#include <iostream>

/*
1  int *
2  int &
3  double
4  A * (A is any appropriate class).
5  const char *
6  const char & 
7  long[7]
8  int **
9  int *&
10 float &
11 int (*)()
12 int (*&)()
13 char *(*)(char *, char *)
14 int A::*
15 int (A::*)(int *)
16 int (A::**)(int *)
17 int (A::*&)(int *)
18 int (A::*)(double (*)(float &))
19 void (*p[10]) (void (*)() );
*/

struct A {
	A(int k) : i(k) {}
	int i;
	void f() {};
	int banana(int *icecream) {
		return *icecream;
	}
	int pear (double (*peach) (float &)) {
		return 5;
	}
};

int foo() {
	return 10;
}

void *bazinga() {
	void *q = malloc(8);
	return q;
}

char *baz(char *s1, char *s2) {
	memcpy(s1, s2, strlen(s2));
	return s1;
}

void lala(void (*voip)()) {
	voip();
}

int main() {
	int i = 2;
	//1
	int *ip = &i;
	//2
	int &ir = i;
	//3
	double d = 5.5;
	//4
	A *a = new A(3);
	//5
	char const *s = "Hello";
	//6
	char c='z';
	char &cr(c);
	//7
	long *lv = new long[7];
	//8
	int **int_matrix = new int*[10];
	//9
	int *&kp = ip;
	//10
	float f = 3.14159;
	float &fr = f;
	//11
	int (*foop)() = foo;
	//12
	int (*&foopp)() = foop;
	//13
	char *(*bazp)(char *, char *) = baz;
	//14
	int A::*aip = &A::i;
	//15
	int (A::*bananap)(int *) = &A::banana;
	//16 
	int (A::**bananapp)(int *) = &bananap;
	//17 
	int (A::*&bananapr)(int *) = bananap;
	//18
	int (A::*pearp)(double (*)(float &));
	//19
	void (*p[10]) (void (*)() ) = {lala, lala, lala, lala, lala, 
								   lala, lala, lala, lala, lala};


	return 0;
}