#pragma once
#include <iostream>
#include <exception>
#include <stdlib.h>
#include <stdexcept>  
#include "..\Aisdlab3\Stack.h"
#include "..\Aisdlab3\Queue.h"
#include "..\Aisdlab3\Container.h"


using namespace std;


class Iterator 
{
public:
	virtual int next() = 0;
	virtual bool has_next() = 0;
};


class BinaryHeap 
{
private:
	size_t size_of_heap; 
public:
	Iterator* breadth_search();
	Iterator* depth_search();
	
	Container binaryconrainer; 
		
	class breadth_search_Iterator : public Iterator 
	{
	public:

		breadth_search_Iterator(Container& BinaryHeap_Array);

		~breadth_search_Iterator();

		int next() override;
		bool has_next() override;
	
private:

		Queue* temporary;
		
		size_t parameter_of_heap_iterator;
		
		int elem = 0;
		
		Container iterate_Container;
	
	};

	

	class depth_search_Iterator : public Iterator 
	{
	public:

		depth_search_Iterator(Container& BinaryHeap_Array);

		~depth_search_Iterator();

		int next() override;
		bool has_next() override;

	private:
		
		Stack* temporary;

		size_t parameter_of_heap_iterator;

		int elem = 0;

		Container iterate_Container;

		int counter;
	};

	
	BinaryHeap() 
	{
		binaryconrainer;
	}

	
	~BinaryHeap() 
	{
		binaryconrainer.~Container();
	}

	
	void insert(int element)
	{
		size_of_heap = binaryconrainer.size();

		binaryconrainer.puch_to_end(element); 

		if (size_of_heap != 0) 
		{ 
			size_t currentelem = size_of_heap;
			size_t parentelem = (currentelem - 1) / 2;
			

			while ((currentelem > 0) && (binaryconrainer.at(parentelem) < binaryconrainer.at(currentelem)))
			{
				binaryconrainer.swap(currentelem, parentelem);

				currentelem = parentelem;

				parentelem = (currentelem - 1) / 2;
			}
		}
		

	}


	bool Contains(int component) 
	{
		size_of_heap = binaryconrainer.size();

		if (size_of_heap != 0)
		{
			bool isFound = false;
			
			Iterator* startIterator = breadth_search();

			while (startIterator->has_next()) 
			{
				if (startIterator->next() == component) 
					isFound = true;
			}
			
			return isFound;
		}
		
		else 
			throw invalid_argument("BinaryHeap is empty");
		
	}
	void restoring(int elem) 
	{
			int maxNumber = elem;
			int left;
			int right;

			while (elem < size_of_heap) 
			{
				left = 2 * elem + 1;
				right = 2 * elem + 2;

				if (binaryconrainer.at(left) > binaryconrainer.at(maxNumber))
					maxNumber = left;

				if (binaryconrainer.at(right) > binaryconrainer.at(maxNumber))
					maxNumber = right;

				if (maxNumber == elem) 
					break;
				binaryconrainer.swap(elem, maxNumber);
				elem = maxNumber;
			}
		}
	
	void remove(int elem)
	{
		size_of_heap = binaryconrainer.size();

		if (size_of_heap != 0) 
		{
			for (size_t i = 0; i < size_of_heap; i++)
			{
				if (binaryconrainer.at(i) == elem) 
				{ 
					if (i == (size_of_heap - 1)) 
					
						binaryconrainer.pop_back();
					
					else 
					{
						binaryconrainer.swap(i, (size_of_heap - 1));

						binaryconrainer.pop_back();

						size_of_heap--;

						restoring(i);
					}
				}
			}
		}
		else {
			throw invalid_argument("BinaryHeap is empty");
		}
	}
};



Iterator* BinaryHeap::breadth_search() 
{
	return new breadth_search_Iterator(binaryconrainer);
}

BinaryHeap::breadth_search_Iterator::breadth_search_Iterator(Container& binaryconrainer) 
{
	const size_t parameter = binaryconrainer.size();

	temporary = new Queue;

	parameter_of_heap_iterator = parameter;

	iterate_Container = binaryconrainer;

	temporary->insert(iterate_Container.at(elem));
}

BinaryHeap::breadth_search_Iterator::~breadth_search_Iterator() 
{
	delete[] temporary;
}

bool BinaryHeap::breadth_search_Iterator::has_next()
{
	return !temporary->isEmpty();
}

int BinaryHeap::breadth_search_Iterator::next() 
{
	if (temporary->isEmpty()) 
		throw out_of_range("No more elements");

	
	if ((2 * elem + 1) <= parameter_of_heap_iterator - 1) temporary->insert(iterate_Container.at(2 * elem + 1));
	if ((2 * elem + 2) <= parameter_of_heap_iterator - 1) temporary->insert(iterate_Container.at(2 * elem + 2));
	elem++;

	int temp = temporary->peak();

	temporary->Remove();

	return temp;
}

Iterator* BinaryHeap::depth_search()
{
	return new depth_search_Iterator(binaryconrainer);
}

BinaryHeap::depth_search_Iterator::depth_search_Iterator(Container& binaryconrainer)
{
	const size_t parameter = binaryconrainer.size();

	temporary = new Stack;

	parameter_of_heap_iterator = parameter;

	iterate_Container = binaryconrainer;

	int visited = 0;
}

BinaryHeap::depth_search_Iterator::~depth_search_Iterator() 
{
	delete[] temporary;
}

bool BinaryHeap::depth_search_Iterator::has_next()
{
	if ((elem > parameter_of_heap_iterator - 1) && (counter < parameter_of_heap_iterator))
	{
		elem = temporary->top();

		temporary->pop();

		return BinaryHeap::depth_search_Iterator::has_next();
	}
	return ((!temporary->empty()) || ((elem <= parameter_of_heap_iterator - 1) && (counter < parameter_of_heap_iterator)));
}

int BinaryHeap::depth_search_Iterator::next() 
{
	int temp;
	if (elem <= parameter_of_heap_iterator - 1) 
	{
		temp = iterate_Container.at(elem);

		if (2 * elem + 2 <= parameter_of_heap_iterator - 1)
		{
			temporary->push(2 * elem + 2);
		}

		elem = 2 * elem + 1;
	}
	else 
	{
		elem = temporary->top();
		temporary->pop();
		temp = iterate_Container.at(elem);
	}
	counter++;
	return temp;
}