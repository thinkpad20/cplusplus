#include <iostream>
#include <vector>
#include <thread>

using namespace std;

template<typename T>
struct AtomicStack {
	vector<T> array;
	mutex m;
	void push(T datum) {
		lock_guard<mutex> guard(m);
		array.push_back(datum);
	}
	T pop() {
		lock_guard<mutex> guard(m);
		T toReturn = array.back();
		array.pop_back();
		return toReturn;
	}
	bool is_empty() {
		return array.size() == 0;
	}
};

int main() {
	AtomicStack<int> stack;
	stack.push(5);
	stack.push(1);
	stack.push(4);
	stack.push(9);

	while (!stack.is_empty()) {
		cout << stack.pop() << endl;
	}
}