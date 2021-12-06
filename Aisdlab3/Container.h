#pragma once
#include <iostream>
#include <exception>
#include <stdlib.h>
#include <stdexcept>  


using namespace std;


class Container
{
private:
	size_t range;
	int capasity;
	int* massif;

public:

	Container() :range(0), capasity(100), massif(new int[capasity]) {}

	~Container()
	{
				range = 0;
	};

	int size()
	{
		return range;
	}

	int at(size_t elem)
	{
		if (elem >= range)
			throw out_of_range("Invalid index");

		else
			return massif[elem];
	}

	void puch_to_end(int value)
	{
		massif[range] = value;
		++range;
	}


	void pop_back()
	{
		if (range == 0)
			throw out_of_range("Container is empty");

		else
			range--;
	}


	void swap(size_t one, size_t two)
	{
		if (one >= range || two >= range)
			throw out_of_range("Invalid index");

		int temp = massif[one];

		massif[one] = massif[two];
		massif[two] = temp;
	}
};