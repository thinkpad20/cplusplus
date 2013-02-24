#include <iostream>
#include <vector>
#include <thread>
#include <future>
#include <numeric>

#define NUM_THREADS 100

/*There are essentially two ways to do this. One is to use 
the __thread modifier on your counter, and then each thread
gets its own copy of the counter, allowing you to sum over
each counter at the end (which requires you to lock only when
updating the sum, not when calling doWork(). This is 
illustrated in func.

The second method is to initialize a vector of counters equal
in size to the number of threads, and assign each thread a
unique index in that vector, so that even without a lock, the
threads will not update over each other. This array could then
be summed over after all threads have completed (or, using a
lock, even in the middle of execution). This is illustrated
in func2.

func3 uses futures, but is applying the same concepts as with
threads.
*/

using namespace std;

__thread unsigned work_units;

mutex work_mutex;

void doWork() {}

void func(int *result) {
	work_units = 0;
	int count = 0;
	int times = rand() % 100000;
	while (count < times) {
		++work_units;
		doWork();
		++count;
	}

	lock_guard<mutex> lck(work_mutex);
	*result += work_units;
}

void func2(int *counter_vector, int index) {
	counter_vector[index] = 0;
	int count = 0;
	int times = rand() % 100000;
	while (count < times) {
		counter_vector[index] += 1;
		doWork();
		++count;
	}
}

int func3() {
	work_units = 0;
	int count = 0;
	int times = rand() % 100000;
	while (count < times) {
		++work_units;
		doWork();
		++count;
	}
	return work_units;
}

int main() {
	int result=0;
	int result2 = 0;
	int result3 = 0;
	vector<thread> threads;
	int *counter = new int[NUM_THREADS];
	srand((unsigned)time(NULL));

	vector<future<int> > futures(NUM_THREADS);

	for (int i=0; i<NUM_THREADS; ++i) {
		threads.push_back(thread(func2, counter, i));
		futures[i] = async(func3);
	}

	for (int i=0; i<NUM_THREADS; ++i) {
		threads[i].join();
	}

	for (int i=0; i<NUM_THREADS; ++i) {
		result3 += futures[i].get();
	}

	for (int i=0; i<NUM_THREADS; ++i) {
		result2 += counter[i];
	}

	cout << "doWork() was called " << result3 << " times" << endl;
}
