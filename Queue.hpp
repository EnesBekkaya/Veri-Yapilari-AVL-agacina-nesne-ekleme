#ifndef QUEUE_HPP
#define QUEUE_HPP

#include<iostream>
#include "Node.hpp"
using namespace std;




class Queue{
	private:
		Node*front;
		Node *back;
		int lenght;
		
		Node *previousMaxNode()const;
	public:
		Queue();
		bool isEmpty()const;
		int Count() const;
		Nokta peek()const;
		void clear();
		void Enqueue(const Nokta item);
		void Dequeue();
		Nokta peekMax()const;
		void DequeueMax();
		~Queue();
};


#endif