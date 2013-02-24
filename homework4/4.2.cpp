#include <iostream>

int main()
{
	int i;
	int *ip = new int[10];
	// delete &i;
	// ^ this doesn't work since i has been allocated on the stack. Further,
	// there's no need to worry about deallocating it since it will do so
	// automatically when the function returns.

	// delete ip;
	// ^ since ip is an array, we need to use the delete[] function
	delete[] ip;
}