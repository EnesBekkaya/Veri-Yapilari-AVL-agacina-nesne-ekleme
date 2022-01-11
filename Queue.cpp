/**
* @file Nokta.cpp
* @description Öncelikli kuyruk sınıfı.
* @course 1.Öğretim 1-A 
* @assignment 2.Ödev
* @date 23.11.2021
* @author Enes Bekkaya
*/

#include "Queue.hpp"

Node*Queue::previousMaxNode()const{
			Node*prev=NULL;
			Node*tmp=front;
			Nokta max=front->item;
			while(tmp->next!=NULL){			
				if(tmp->next->item <max){
					max=tmp->next->item;
					prev=tmp;
				}
				tmp=tmp->next;
			}
			return prev;
		}
		
	
		Queue::Queue(){
			
			front=back=NULL;
			lenght=0;
		}
	
	bool Queue::isEmpty()const{
		return lenght==0;
	}
	
	int Queue::Count() const{
		return lenght;
	}
	
	Nokta Queue::peek()const{
		if(isEmpty()) throw "HATA";
		return front->item;
	}
	void Queue::clear(){
		while(!isEmpty()){ 
		Dequeue();
		}
	}
	void Queue::Enqueue(const Nokta item){
		Node *last=new Node(item);
		if(isEmpty()) front=back=last;
		else{
			back->next=last;
			back=last;
		}
		lenght++;

	}
	void Queue::Dequeue(){
		if(isEmpty()) throw "HATA";
		Node*del=front;
		front=front->next;
		delete del;
		lenght--;
	}
	 Nokta Queue::peekMax()const{
		if(isEmpty()) throw "HATA";
		Node *prev=previousMaxNode();
		if(prev==NULL) return peek();
		return prev->next->item;

	}
	void Queue::DequeueMax(){
		if(isEmpty()) throw "HATA";
			Node*prev=previousMaxNode();
			Node *tmp;
			if(prev==NULL)
				Dequeue();
			else{
				if(prev->next==back) back=prev;
				tmp=prev->next;
				prev->next=tmp->next;
				delete tmp;
				lenght--;
			}
	}
	Queue::~Queue(){
		clear();
		
	}