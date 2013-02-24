#include <iostream>
#include <string>
#include <vector>
using std::cout;
using std::endl;
using std::vector;

int main()
{
	const int NUM_ROWS = 5;

	//SET UP THE MATRIX
	vector<vector<int> > matrix(NUM_ROWS);
	for (int i=0; i<NUM_ROWS; i++) {
		vector<int> row(NUM_ROWS);
		matrix[i] = row;
	}

	//FILL IN THE TRIANGLE'S VALUES
	for (int i=0; i<NUM_ROWS; i++) {
		for (int j=0; j<=i; j++) {
			if (j==0 || j==i)
				matrix[i][j] = 1;
			else if (j > i)
				matrix[i][j] = 0;
			else
				matrix[i][j] = matrix[i-1][j-1] + matrix[i-1][j];
		}
	}

	//PRINT
	for (int i=0; i<NUM_ROWS; i++) {
		//print initial spaces
		for (int k = 0; k<(((NUM_ROWS)*6 + 1)/2 - 3*(i+1)); k++)
			cout << " ";
		for (int j=0; j<=i; j++) {
			int val = matrix[i][j];
			if (val != 0) {
				if (val > 999) cout << val << "  ";
				else if (val > 99) cout << val << "   ";
				else if (val > 9) cout << val << "    ";
				else cout << val << "     ";
			}
		}
		cout << endl;
	}
    return 0;
}