#include<string>
#include "RingQueue.h"


//STL List (Queue) does not contain a method to output data,
//that's why I didn't implement it in the class
void show(RingQueue<int>& rq1, std::string str) {
	std::cout << str;

	//here is a demonstration of working with iterators
	for (RingQueue<int>::Iterator it = rq1.begin(); it != rq1.end(); it++) {
		std::cout << *it << " ";
	}
}

int main()
{
	RingQueue<int> rq1 = 5; // queue for 5 elements
	rq1.push(1); //add items
	rq1.push(2);
	rq1.push(3);
	rq1.push(4);


	RingQueue<int> rq2(rq1);  //copy constructor
	

	show(rq1, "First queue\n");
	show(rq2, "\nSecond queue\n");
	std::cout << "\nEqual: " << (rq1 == rq2) << "\n\n"; //проверка оператора сравнения


	rq2.push(5);
	show(rq1, "\nFirst queue\n");
	show(rq2, "\nSecond queue\n");
	std::cout << "\nEqual: " << (rq1 == rq2) << std::endl; //снова проверка оператора сравнения


	rq2.front(); // Cyclic shift (3 times) to make ensure
	rq2.front(); // the correct operation of the algorithm to find the oldest data
	rq2.front(); // 1 2 3 4 5 -> 4 5 1 2 3(oldest still "1")

	show(rq2, "\n\nShift\nSecond queue\n");

	rq2.push(9);


	show(rq2, "\nSecond queue(1 shift)\n");
	rq2.push(14);
	rq2.push(15);
	rq2.push(999);
	show(rq2, "\nSecond queue(3 more)\n");


	std::cout << "\n\nSwap";
	rq1.swap(rq2);
	show(rq1, "\nFirst queue\n");
	show(rq2, "\nSecond queue\n");

	RingQueue<int> r0 = 5;

	try
	{
		r0.back();
	}
	catch (std::logic_error err) 
	{
		std::cout << err.what();
	}

	return 0;
}