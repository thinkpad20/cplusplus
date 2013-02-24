#include <iostream>

using namespace std;

class ComplexInt {
	public:
		int r, i;
		ComplexInt(int r, int i) : r(r), i(i) {}
		ComplexInt operator+ (ComplexInt &c) {
			return ComplexInt(r + c.r, i + c.i);
		}
		ComplexInt operator- (ComplexInt &c) {
			return ComplexInt(r - c.r, i - c.i);
		}
		ComplexInt operator* (ComplexInt &c) {
			int real = (r * c.r - i *c.i);
			int imaginary = (r * c.i + i *c.r);
			return ComplexInt(real, imaginary);
		}
		inline friend ostream &operator<<(ostream &out, ComplexInt &c) {
			out << "(" << c.r << ", " << c.i << ")";
			return out;
		}
};

int main() {
	ComplexInt a(1,2), b(3,4);
	ComplexInt c = a + b;
	ComplexInt d = a * b;
	cout <<c << endl;
	cout <<d << endl;
}