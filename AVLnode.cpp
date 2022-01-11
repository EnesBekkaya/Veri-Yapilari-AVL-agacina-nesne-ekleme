/**
* @file Nokta.cpp
* @description AVL ağacının düğüm sınıfı
* @course 1.Öğretim 1-A 
* @assignment 2.Ödev
* @date 23.11.2021
* @author Enes Bekkaya
*/


#include "AVLnode.hpp"
	AVLnode::AVLnode(DogruKuyrugu *data,AVLnode *lf,AVLnode *rg){	
		this->data=data;
		left=lf;
		right=rg;
		yukseklik=0;
		
	}