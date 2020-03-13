

#include "pch.h"
#include <iostream>


#include <set>
#include <vector>
#include <algorithm>
#include <numeric>
#include <string>
#include <cassert>
#include <iterator>
#include <functional>

#include <fstream> 

using namespace std;


/*  it is from file now
	vector<int> sudc{
	2, 4, 5, 8, 9, 3, 7, 1, 6,
		8, 1, 3, 5, 7, 6, 9, 2, 4,
		7, 6, 9, 2, 1, 4, 5, 3, 8,
		5, 3, 6, 9, 8, 7, 1, 4, 2,
		4, 9, 2, 1, 6, 5, 8, 7, 3,
		1, 7, 8, 4, 3, 2, 6, 5, 9,
		6,8 ,4, 7, 2, 1 ,3, 9, 5,
		3 ,2 ,1 ,6, 5 ,9 ,4 ,8 ,7,
		9, 5 ,7 ,3, 4 ,8,2, 6, 1
	};
*/


template<typename T>
std::vector<T> parse_stream(std::istream &stream) {
	std::vector<T> v;
	std::istream_iterator<T> input(stream);
	std::copy(input, std::istream_iterator<T>(), std::back_inserter(v));
	return v;
}



int check_sudoku(vector<int>& sud)
{
	int * row_pointer = sud.data();

	//check row
	std::set<int> m;

	//row
	for (int j = 0; j < 9; j++)
	{
		for (int i = 0; i < 9; i++)
		{
			m.insert(row_pointer[i + j * 9]);
		}
		int sum = std::accumulate(m.begin(), m.end(), 0);
		if (sum != 45 && m.size() != 9) return 0;
		m.clear();
	}

	//row
	for (int j = 0; j < 9; j++)
	{
		for (int i = 0; i < 9; i++)
		{
			m.insert(row_pointer[i *9 + j]);
		}
		int sum = std::accumulate(m.begin(), m.end(), 0);
		if (sum != 45 && m.size() != 9) return 0;
		m.clear();
	}

	//square
	for (int k = 0; k < 1; k++)
	{

		for (int j = 0; j < 3; j++)
		{
			for (int i = 0; i < 3; i++)
			{
				m.insert(row_pointer[i + j * 9 + (k / 3)*(9 * 3) + (k % 3)*(3)]);
			}
		}
		int sum = std::accumulate(m.begin(), m.end(), 0);
		if (sum != 45 && m.size() != 9) return 0;
		m.clear();

	}

	return 1;
}

class F{};

	int main(int argc, char *argv[])
	{



		if (argc != 2) {
			cout << "enter file name" << endl;
			return -1;
		}


		const char * name_file =  "c:\\work\\sud.txt";
		std::fstream input(name_file);
		std::vector<int> vec = parse_stream<int>(input);



	int a = check_sudoku(vec);

	if (a)
		cout  << "Correct" << endl;
	else
		cout  << "Incorrect" << endl;


/////////////////////////////////////////////////

	//questions !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
#if 0
	C c;

	C * cc = &c;

	A aa;
	A* a = &c;
	B* b = &c;

	F f;

	A * ff = (rand()%2) ? (A*)(&f) : a;
	std::cout <<"a " <<a << std::endl;
	std::cout << "b " << b << std::endl;
	std::cout << "cc " << cc << std::endl;

	std::cout << "dynamic_cast<A*>(b) "<< dynamic_cast<A*>(b) << std::endl;
	std::cout << "dynamic_cast<B*>(a) "<< dynamic_cast<B*>(a) << std::endl;
	std::cout << "dynamic_cast<C*>(a) "<< dynamic_cast<C*>(a) << std::endl;
	std::cout << "dynamic_cast<C*>(b) "<< dynamic_cast<C*>(b) << std::endl;

	std::cout <<" dynamic_cast<C*>(&aa) " << dynamic_cast<C*>(&aa) << std::endl;

	std::cout << "dynamic_cast<C*>(ff) "<< dynamic_cast<C*>(ff) << std::endl;



	class A
	{
		int a = 0;

	public:
		virtual ~A() = default;
	};

	class B
	{
		int b = 0;

	public:
		virtual ~B() = default;
	};

	class C : public A, public B
	{
		int c = 0;

	public:
		virtual ~C() = default;
	};



#endif


/////////////////////////////////////////////////

}

