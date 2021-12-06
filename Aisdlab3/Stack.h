#pragma once
#include <iostream>
#include <exception>
#include <stdexcept>  
#include <stdlib.h>


using namespace std;

class Stack
{
private:
	
	struct Node
	{
	public:
		int value;
		Node* Pervious;
		Node(const int element) :value(element), Pervious(0) {}
	};
	Node* root;
	size_t size_of_stack;

public:
	
	Stack() :root(nullptr), size_of_stack(0) {}

	
	~Stack()
	{
		while (!empty())
			pop();
	}
	bool empty()
	{
		return root == nullptr;
	}
	
	size_t size()
	{
		return size_of_stack;
	}
	
	void push(const int element)
	{
		Node* temp = root;
		root = new Node(element);
		root->Pervious = temp;
		size_of_stack++;
	}

	
	void pop()
	{
		if (size_of_stack) {
			Node* temp = root->Pervious;
			delete root;
			root = temp;
			size_of_stack--;
		}
		else 
			throw out_of_range("Stack is empty");
		
	}

	
	int top()
	{
		if (empty())
			
			throw out_of_range("Stack is empty");
		
		return root->value;
	}

	
	

	
	
};




