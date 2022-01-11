/**
* @file DogruKuyrugu.cpp
* @description Dogruları tuttugum sınıf
* @course 1.Öğretim 1-A 
* @assignment 2.Ödev
* @date 23.11.2021
* @author Enes Bekkaya
*/

#include "DogruKuyrugu.hpp"

DogruKuyrugu::DogruKuyrugu(Queue *satir,int toplamUzunluk){

		this->satir=satir;
		this->toplamUzunluk=toplamUzunluk;
	}
		
	
	int DogruKuyrugu::dogruUzunlugu(){
		return toplamUzunluk;
	}
	
	void DogruKuyrugu::yazdir(){
		
		while(!(satir->isEmpty())){
		cout<<satir->peekMax()<<" ";	
		satir->DequeueMax();
			
		}
		cout<<endl;

	}
	
	
	