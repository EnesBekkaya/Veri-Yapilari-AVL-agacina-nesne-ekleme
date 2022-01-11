#ifndef DOGRUKUYUGU_HPP
#define DOGRUKUYUGU_HPP
#include<iostream>

#include "Queue.hpp"

using namespace std;

class DogruKuyrugu{
	private:
	Queue  *satir;
	int toplamUzunluk;
	public:
	
	DogruKuyrugu(Queue *satir,int toplamUzunluk);
	int dogruUzunlugu();
	void yazdir();	
};


#endif