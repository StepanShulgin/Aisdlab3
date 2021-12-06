#include "pch.h"
#include "CppUnitTest.h"
#include "..\Aisdlab3\Container.h"
#include "..\Aisdlab3\Queue.h"
#include "..\Aisdlab3\Stack.h"
#include "..\Aisdlab3\BinaryHeap.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestAisdlab3
{
	TEST_CLASS(UnitTestAisdlab3)
	{
	public:
		
		//Test for Queue
		TEST_METHOD(ConsrtructorQueue)
		{
			Queue newQueue;
			Assert::IsTrue(newQueue.isEmpty() == 1);
		}

		TEST_METHOD(DesrtructorQueue)
		{
			Queue newQueue;
			newQueue.insert(3);
			Assert::IsTrue(newQueue.isEmpty() == 0);
			newQueue.~Queue();
			Assert::IsTrue(newQueue.isEmpty() == 1);
		}
		TEST_METHOD(IsEmptyQueue)
		{
			Queue newQueue;
			Assert::IsTrue(newQueue.isEmpty() == 1);
			newQueue.insert(7);
			Assert::IsTrue(newQueue.isEmpty() == 0);
			
		}
		TEST_METHOD(InsertQueue)
		{
			Queue newQueue;
			newQueue.insert(1);
			Assert::IsTrue(newQueue.peak() == 1);
			newQueue.insert(6);
			Assert::IsTrue(newQueue.peak() == 1);
		}
		TEST_METHOD(PeakQueue)
		{
			Queue newQueue;
			try 
			{
				newQueue.peak();
			}
			catch (const out_of_range error) 
			{
				Assert::AreEqual("Queue is empty", error.what());
			}
			newQueue.insert(4);
			try 
			{
				newQueue.peak();
			}
			catch (const out_of_range error) {
				Assert::AreEqual("Queue is empty", error.what());
			}
			Assert::IsTrue(newQueue.peak() == 4);
		
		}
		
		//Tests for Stack
		TEST_METHOD(ConsrtructorStack)
		{
			Stack newStack;
			Assert::IsTrue(newStack.size() == 0);
		}
		TEST_METHOD(DesrtructorStack)
		{
			Stack newStack;
			newStack.push(0);
			newStack.push(1);
			Assert::IsTrue(newStack.size() == 2);
			newStack.~Stack();
			Assert::IsTrue(newStack.size() == 0);
		}
		TEST_METHOD(emptyStack) 
		{
			Stack newStack;
			Assert::IsTrue(newStack.empty() == 1);
			newStack.push(3);
			Assert::IsTrue(newStack.empty() == 0);
			newStack.pop();
			Assert::IsTrue(newStack.empty() == 1);
		}
		TEST_METHOD(sizeStack)
		{
			Stack newStack;
			Assert::IsTrue(newStack.size() == 0);
			newStack.push(3);
			Assert::IsTrue(newStack.size() == 1);
			newStack.pop();
			Assert::IsTrue(newStack.size() == 0);
		}
		TEST_METHOD(pushStack)
		{
			Stack newStack;
			newStack.push(11);
			Assert::IsTrue(newStack.top() == 11);
			newStack.push(10);
			Assert::IsTrue(newStack.top() == 10);
		}
		TEST_METHOD(popStack)
		{
			Stack newStack;
			newStack.push(0);
			Assert::IsTrue(newStack.size() == 1);
			newStack.pop();
			Assert::IsTrue(newStack.size() == 0);
		}
		TEST_METHOD(topStack)
		{
			Stack newStack;
			try
			{
				newStack.top();
			}
			catch (const out_of_range error) 
			{
				Assert::AreEqual("Stack is empty", error.what());
			}
			newStack.push(3);
			Assert::IsTrue(newStack.top() == 3);
						
		}
		
		
		
		
		
		TEST_METHOD(insertBinaryHeapTest) 
		{
			BinaryHeap newHeap;
			stringstream output1;
			stringstream output2;
			stringstream output3;
			newHeap.insert(3);
			Iterator* newIteratorB1 = newHeap.breadth_search();
			while (newIteratorB1->has_next()) {
				output1 << newIteratorB1->next() << " ";
			}
			Assert::IsTrue(output1.str() == "3 ");
			newHeap.insert(4);
			Iterator* newIteratorB2 = newHeap.breadth_search();
			while (newIteratorB2->has_next()) {
				output2 << newIteratorB2->next() << " ";
			}
			Assert::IsTrue(output2.str() == "4 3 ");
			newHeap.insert(16);
			Iterator* newIteratorB3 = newHeap.breadth_search();
			while (newIteratorB3->has_next()) {
				output3 << newIteratorB3->next() << " ";
			}
			Assert::IsTrue(output3.str() == "16 3 4 ");
		}
		TEST_METHOD(ContainsBinaryHeap) 
		{
			BinaryHeap newHeap;
			try
			{
				newHeap.Contains(3);
			}
			catch (const invalid_argument error) 
			{
				Assert::AreEqual("BinaryHeap is empty", error.what());
			}

			newHeap.insert(8);
						Assert::IsTrue(newHeap.Contains(8) == 1);
			
		}
		TEST_METHOD(RemoveBinaryHeap) {
			BinaryHeap MyHeap;
			stringstream output1;
			stringstream output2;
			stringstream output3;
			stringstream output4;
			try 
			{
				MyHeap.remove(1);
			}
			catch (const invalid_argument error) 
			{
				Assert::AreEqual("BinaryHeap is empty", error.what());
			}
			MyHeap.insert(3);
			MyHeap.insert(4);
			MyHeap.insert(16);
			MyHeap.insert(1);
			Iterator* newIteratorB1 = MyHeap.breadth_search();
			while (newIteratorB1->has_next()) {
				output1 << newIteratorB1->next() << " ";
			}
			Assert::IsTrue(output1.str() == "16 3 4 1 ");
			try {
				MyHeap.remove(1);
			}
			catch (const invalid_argument error) {
				Assert::AreEqual("BinaryHeap is empty", error.what());
			}
			MyHeap.remove(1);
			Iterator* newIteratorB2 = MyHeap.breadth_search();
			while (newIteratorB2->has_next()) {
				output2 << newIteratorB2->next() << " ";
			}
			Assert::IsTrue(output2.str() == "16 3 4 ");
			int array1[10] = { 16, 11, 9, 10, 5, 6, 8, 1, 2, 4 };
			BinaryHeap MyBinaryHeap1;
			for (int i = 0; i < 10; i++)
				MyBinaryHeap1.insert(array1[i]);
			Iterator* newIteratorB3 = MyBinaryHeap1.breadth_search();
			while (newIteratorB3->has_next()) {
				output3 << newIteratorB3->next() << " ";
			}
			Assert::IsTrue(output3.str() == "16 11 9 10 5 6 8 1 2 4 ");
			try {
				MyBinaryHeap1.remove(16);
			}
			catch (const invalid_argument error) {
				Assert::AreEqual("BinaryHeap is empty", error.what());
			}
			MyBinaryHeap1.remove(16);
			Iterator* newIteratorB4 = MyBinaryHeap1.breadth_search();
			while (newIteratorB4->has_next()) {
				output4 << newIteratorB4->next() << " ";
			}
			Assert::IsTrue(output4.str() == "11 10 9 4 5 6 8 1 2 ");
		}
		TEST_METHOD(restoring) 
		{
			BinaryHeap newHeap;
			stringstream firstoutput;
			stringstream secondoutput;
			int array1[10] = { 16, 11, 9, 10, 5, 6, 8, 1, 2, 4 };
			for (int i = 0; i < 10; i++)
				newHeap.insert(array1[i]);
			newHeap.binaryconrainer.swap(0, 9);
			newHeap.binaryconrainer.pop_back();
			Iterator* newIteratorB1 = newHeap.breadth_search();
			while (newIteratorB1->has_next()) 
			{
				firstoutput << newIteratorB1->next() << " ";
			}
			Assert::IsTrue(firstoutput.str() == "4 11 9 10 5 6 8 1 2 ");

			newHeap.restoring(0);
			Iterator* newIteratorB2 = newHeap.breadth_search();
			while (newIteratorB2->has_next()) {
				secondoutput << newIteratorB2->next() << " ";
			}
			Assert::IsTrue(secondoutput.str() == "11 10 9 4 5 6 8 1 2 ");
		}
		TEST_METHOD(breadth_search_IteratorHasNext) 
		{
			BinaryHeap newHeap;
			newHeap.insert(3);
			Iterator* newIteratorB = newHeap.breadth_search();
			Assert::IsTrue(newIteratorB->has_next() == 1);
			newIteratorB->next();
			Assert::IsTrue(newIteratorB->has_next() == 0);
		}
		TEST_METHOD(Bbreadth_search_IteratorNext) 
		{
			BinaryHeap newHeap;
			newHeap.insert(3);
			newHeap.insert(7);
			Iterator* newIteratorB = newHeap.breadth_search();
			try {
				int temp = newIteratorB->next();
				Assert::IsTrue(temp == 7);
			}
			catch (const out_of_range error) {
				Assert::AreEqual("No more elements", error.what());
			}
			try {
				int temp = newIteratorB->next();
				Assert::IsTrue(temp == 3);
			}
			catch (const out_of_range error) {
				Assert::AreEqual("No more elements", error.what());
			}
			try {
				newIteratorB->next();
			}
			catch (const out_of_range error) {
				Assert::AreEqual("No more elements", error.what());
			}
		}
		TEST_METHOD(depth_search_IteratorHasNext)
		{
			BinaryHeap newHeap;
			newHeap.insert(3);
			Iterator* newIteratorB = newHeap.depth_search();
			Assert::IsTrue(newIteratorB->has_next() == 1);
			newIteratorB->next();
			Assert::IsTrue(newIteratorB->has_next() == 0);
		}
		TEST_METHOD(depth_search_IteratorNext) 
		{
			BinaryHeap newHeap;
			newHeap.insert(7);
			newHeap.insert(2);
			Iterator* newIteratorB = newHeap.depth_search();
			Assert::IsTrue(newIteratorB->next() == 2);
			Assert::IsTrue(newIteratorB->next() == 7);
		}
				
		TEST_METHOD(ConsrtructorContainer) {
			Container newContainer;
			Assert::IsTrue(newContainer.size() == 0);
			newContainer.puch_to_end(3);
			Assert::IsTrue(newContainer.size() == 1);
		}
		TEST_METHOD(DesrtructorContainer)
		{
			Container newContainer;
			Assert::IsTrue(newContainer.size() == 0);
			newContainer.puch_to_end(1);
			Assert::IsTrue(newContainer.size() == 1);
			newContainer.~Container();
			Assert::IsTrue(newContainer.size() == 0);
		}
		TEST_METHOD(puch_to_endContainer) 
		{
			Container newContainer;
			Assert::IsTrue(newContainer.size() == 0);
			newContainer.puch_to_end(9);
			Assert::IsTrue(newContainer.size() == 1);
			Assert::IsTrue(newContainer.at(0) == 9);
			newContainer.puch_to_end(1);
			Assert::IsTrue(newContainer.size() == 2);
			Assert::IsTrue(newContainer.at(0) == 9);
			Assert::IsTrue(newContainer.at(1) == 1);
		}
		TEST_METHOD(sizeContainer)
		{
			Container newContainer;
			Assert::IsTrue(newContainer.size() == 0);
			newContainer.puch_to_end(1);
			Assert::IsTrue(newContainer.size() == 1);
			
		}
		TEST_METHOD(atContainer) 
		{
			Container newContainer;
			try 
			{
				newContainer.at(7);
			}
			catch (const out_of_range error) {
				Assert::AreEqual("Invalid index", error.what());
			}
			newContainer.puch_to_end(9);
			Assert::IsTrue(newContainer.at(0) == 9);
		}
		TEST_METHOD(pop_backContainer) 
		{
			Container newContainer;

			Assert::IsTrue(newContainer.size() == 0);
			newContainer.puch_to_end(3);
			Assert::IsTrue(newContainer.size() == 1);
			newContainer.puch_to_end(7);
			Assert::IsTrue(newContainer.size() == 2);
			newContainer.pop_back();
			newContainer.pop_back();
			Assert::IsTrue(newContainer.size() == 0);
						
			try {
				newContainer.pop_back();
			}
			catch (const out_of_range error) {
				Assert::AreEqual("Container is empty", error.what());
			}
		}
		TEST_METHOD(swapContainer) {
			Container newContainer;
			newContainer.puch_to_end(1);
			newContainer.puch_to_end(2);
			try
			{
				newContainer.swap(0, 3);
			}
			catch (const out_of_range error) {
				Assert::AreEqual("Invalid index", error.what());
			}
			try 
			{
				newContainer.swap(17, 1);
			}
			catch (const out_of_range error) 
			{
				Assert::AreEqual("Invalid index", error.what());
			}
			Assert::IsTrue(newContainer.at(0) == 1);
			Assert::IsTrue(newContainer.at(1) == 2);
			
			newContainer.swap(0, 1);
			Assert::IsTrue(newContainer.at(0) == 2);
			Assert::IsTrue(newContainer.at(1) == 1);
			 
		}
	};
};
