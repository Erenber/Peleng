#include<string>
#include "RingQueue.h"


//STL List (Queue) �� �������� ������ ������ ������,
//������� � ��� �� ������������ � ������
void show(RingQueue<int>& rq1, std::string str) {
	std::cout << str;

	//����� ������������������ ������ � �����������
	for (RingQueue<int>::Iterator it = rq1.begin(); it != rq1.end(); it++) {
		std::cout << *it << " ";
	}
}

int main()
{
	RingQueue<int> rq1 = 5; //������� �� 5 ���������
	rq1.push(1); //���������� ���������
	rq1.push(2);
	rq1.push(3);
	rq1.push(4);


	RingQueue<int> rq2(rq1); //����������� �����������
	

	show(rq1, "First queue\n");
	show(rq2, "\nSecond queue\n");
	std::cout << "\nEqual: " << (rq1 == rq2) << "\n\n"; //�������� ��������� ���������


	rq2.push(5);
	show(rq1, "\nFirst queue\n");
	show(rq2, "\nSecond queue\n");
	std::cout << "\nEqual: " << (rq1 == rq2) << std::endl; //����� �������� ��������� ���������


	rq2.front(); //����������� ����� (3 ����), ����� ��������� 
	rq2.front(); //� ���������� ������ ��������� ������ ����� ������ ������
	rq2.front(); // 1 2 3 4 5 -> 4 5 1 2 3 (����� ������ ��� ��� "1")

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