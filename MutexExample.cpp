#include <iostream>
#include <thread>
#include <list>
#include <algorithm>

using namespace std;

/**An example to help understand mutex from:
 * https://stackoverflow.com/questions/35252119/stdlock-guard-example-explanation-on-why-it-works
*/


// a global variable
std::list<int>myList;

void addToList(int max, int interval)
{
	for (int i = 0; i < max; i++) {
		if( (i % interval) == 0) {
            myList.push_back(i);
        }
	}
}

void printList()
{
	for (auto itr = myList.begin(), end_itr = myList.end(); itr != end_itr; ++itr ) {
		cout << *itr << ",";
	}
}

int main()
{
	int max = 100;

	std::thread t1(addToList, max, 1);
	std::thread t2(addToList, max, 10);
	std::thread t3(printList);

	t1.join();
	t2.join();
	t3.join();

	return 0;
}

/**To compile, use: clang++ -std=c++11 MutexExample.cpp
 * reference: https://stackoverflow.com/questions/22031640/thread-in-c-in-macos-x
*/