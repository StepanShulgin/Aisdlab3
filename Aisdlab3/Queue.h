#pragma once
#include <iostream>
#include <exception>
#include <stdlib.h>
#include <stdexcept>  
#include "..\Aisdlab3\Stack.h"

using namespace std;

class Queue
{
private:

	class Node
	{
	public:
		int value;
		Node* Next;
		Node() :value(), Next(0) {}
	};
	int size_of_queue;
	Node* Head;
	Node* Tail;

public:

	Queue()
	{
		Head = new Node;
		Head->Next = NULL;
		Tail = Head;
		size_of_queue = 0;
	}

	~Queue()
	{
		while (Head != Tail)
		{
			Remove();
		}
	}
	
	bool isEmpty()
	{
		return (Head == Tail);
	}

	void insert(int element)
	{
		Tail->Next = new Node;
		Tail = Tail->Next;
		Tail->value = element;
		Tail->Next = NULL;
		size_of_queue++;
	}

	int peak()
	{
		if (size_of_queue)
			return Head->Next->value;
		else {
			throw out_of_range("Queue is empty");
		}
	}

	void Remove()
	{
		Head = Head->Next;
		size_of_queue--;
	}


	
};