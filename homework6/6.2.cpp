#include <iostream>

using namespace std;

template<class T>
class ComplexNum {
	public:
		T r, i;
		ComplexNum(T r, T i) : r(r), i(i) {}
		ComplexNum operator+ (ComplexNum const &c) const {
			return ComplexNum(r + c.r, i + c.i);
		}
		ComplexNum operator- (ComplexNum const &c) const {
			return ComplexNum(r - c.r, i - c.i);
		}
		ComplexNum operator* (ComplexNum const &c) const {
			int real = (r * c.r - i *c.i);
			int imaginary = (r * c.i + i *c.r);
			return ComplexNum(real, imaginary);
		}
		inline friend ostream &operator<<(ostream &out, ComplexNum &c) {
			string op = (c.i > 0) ? "+" : (c.i < 0) ? "-" : "";
			if (op.length() > 0)
				out << c.r << op << c.i << "i";
			else
				out << c.r << endl;
			return out;
		}
};

int main() {
	ComplexNum<double> a(1.5,2.6), b(3.7,4.8);
	ComplexNum<double> c = a + b;
	ComplexNum<double> d = a * b;
	cout <<c << endl;
	cout <<d << endl;
}