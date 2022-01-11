#ifndef AVLNODE_HPP
#define AVLNODE_HPP
#include "DogruKuyrugu.hpp"



class AVLnode{
	public:
	DogruKuyrugu *data;
	AVLnode *left;
	AVLnode *right;
	int yukseklik;
	
	AVLnode(DogruKuyrugu *data,AVLnode *lf=NULL,AVLnode *rg=NULL);
		
};



#endif