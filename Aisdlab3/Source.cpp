#include "..\Aisdlab3\Stack.h"
#include "..\Aisdlab3\Container.h"
#include "..\Aisdlab3\BinaryHeap.h"
#include <stdlib.h>
#include <stdexcept> 
#include <conio.h>



int main()
{
	int length = 10;

	int* array = new int[length];
	for (int i = 0; i < length; i++)
	{
		array[i] = rand() % 20;

	}

	BinaryHeap Heap;

	cout << "current array: " << endl;;

	for (int i = 0; i < 10; i++)
		cout << array[i] << " ";

	cout << endl << endl;

	
	for (int i = 0; i < length; i++)
	{
		Heap.insert(array[i]);
		if (i > 6) 
		{
			cout << "Breadth-first search: ";

			Iterator* newIteratorB = Heap.breadth_search();

			while (newIteratorB->has_next()) 
			{
				cout << newIteratorB->next() << " ";
			}
			cout << endl;

			cout << "Depth-first search: ";

			Iterator* newIteratorD = Heap.depth_search();

			while (newIteratorD->has_next()) 
			{
				cout << newIteratorD->next() << " ";
			}
			cout << endl<<endl;
		}
	}
	
	cout << "Does the Binary Heap consists 7?" << Heap.Contains(7) << endl;


	cout << "Removing 10 from the Heap: ";
		
	Heap.remove(10);

	cout << "Breadth-first search: ";

	Iterator* newIteratorB = Heap.breadth_search();

	while (newIteratorB->has_next()) 
	{
		cout << newIteratorB->next() << " ";
	}
	cout << endl;

	cout << "Depth-first search: ";

	Iterator* newIteratorD = Heap.depth_search();

	while (newIteratorD->has_next()) 
	{
		cout << newIteratorD->next() << " ";
	}

	cout << endl << endl;

	cout << "Insert 54 to the MyBinaryHeap :  "<< endl << endl;;
	
	Heap.insert(54);

	cout << "Breadth-first search: ";

	newIteratorB = Heap.breadth_search();

	while (newIteratorB->has_next()) 
	{
		cout << newIteratorB->next() << " ";
	}
	cout << endl;

	cout << "Depth-first search: ";

	newIteratorD = Heap.depth_search();

	while (newIteratorD->has_next()) 
	{
		cout << newIteratorD->next() << " ";
	}
	cout << endl << endl;
	
	_getch();
	return 0;

}