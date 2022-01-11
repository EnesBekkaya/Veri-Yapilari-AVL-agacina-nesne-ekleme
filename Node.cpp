/**
* @file Nokta.cpp
* @description Noktaların düğüm sınıfı
* @course 1.Öğretim 1-A 
* @assignment 2.Ödev
* @date 23.11.2021
* @author Enes Bekkaya
*/

#include "Node.hpp"
Node::Node( Nokta item,Node *nx){
			next=nx;
			this->item=item;			
		}	