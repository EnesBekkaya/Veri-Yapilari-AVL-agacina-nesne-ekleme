/**
* @file Nokta.cpp
* @description Noktaları tuttuğum sınıf
* @course 1.Öğretim 1-A 
* @assignment 2.Ödev
* @date 23.11.2021
* @author Enes Bekkaya
*/

#include "Nokta.hpp"
		Nokta::Nokta(){
			
		}
		
		Nokta::Nokta(int x,int y,int z,int oncelik){	
			this->x=x;
			this->y=y;
			this->z=z;
			this->oncelik=oncelik;
			
		}
		
		
		ostream& operator<<(ostream& ekran,Nokta r){
		
		ekran<<r.oncelik<<" ";
		return ekran;
		}
		
		bool Nokta::operator<(Nokta& r){
		return  this->oncelik<r.oncelik	;
	}
	
