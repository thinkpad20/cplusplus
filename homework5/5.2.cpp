#include <iostream>
#include <thread>

using namespace std;

template <typename T>
struct Node {
	T data;
	Node *next;
	Node(T t) : data(t), next(NULL){}
};

template <typename T>
struct Stack {
	mutex m;
	int size;
	Node<T> *first;
	Node<T> *last;

	Stack() : size(0), first(NULL), last(NULL) {}

	void push(T new_element, bool make_report = true) {
		lock_guard<mutex> lg(m);

		Node<T> *new_node = new Node<T>(new_element);
		if (size==0) {
			first = new_node;
		} else {
			last->next = new_node;
		}
		last = new_node;
		++size;

		if (make_report)
			report();
	}

	T pop(bool make_report = true) {
		lock_guard<mutex> lg(m);
		
		if (size != 0) {
			T return_val = last->data;

			Node<T> *current = first; 
			while (current->next != last)
				current = current->next;
			current->next = NULL;
			delete last;
			last = current;

			--size;

			if (make_report)
				report();
			return return_val;
		} else {
			throw 0;
		}
	}

	bool is_empty() {
		return size == 0;
	}

	void report() {
		cout << "Stack contains " << size << " elements." << endl;
	}
};

int main(int argc, char *argv[])
{
	int *nums = new int[10];
	Stack<int> s;
	s.push(1);
	s.push(3);
	s.push(4456);
	s.push(451);
	s.push(13);
	s.push(567);

	while (!s.is_empty()) {
		cout << s.pop() << endl;
	}

	return 0;
}