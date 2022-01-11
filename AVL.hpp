#ifndef AVL_HPP
#define AVL_HPP
#include <iostream>
//#include"DogruKuyrugu.hpp"
#include "AVLnode.hpp"
using namespace std;




class AVL{
	private:
		AVLnode* root;

		AVLnode* SearchAndAdd(AVLnode *altDugum,DogruKuyrugu *item);
		AVLnode* SolCocukIleDegistir(AVLnode*altDugum);	
		AVLnode* SagCocukIleDegistir(AVLnode*altDugum);
		AVLnodeDelete(AVLnode* &altDugum);	
		void postorder(AVLnode *altDugum);
		int Yukseklik(AVLnode*altDugum); 
	public:
		AVL();
		bool isEmpty();
		void add(DogruKuyrugu *item);
		void postorder();
		int Yukseklik();
		void Temizle();
		~AVL();
};
#endif