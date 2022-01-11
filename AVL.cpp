/**
* @file AVL.cpp
* @description AVL ağacı
* @course 1.Öğretim 1-A 
* @assignment 2.Ödev
* @date 23.12.2021
* @author Enes Bekkaya
*/

#include "AVL.hpp"
	
	AVLnode* AVL::SearchAndAdd(AVLnode *altDugum,DogruKuyrugu *item){	
			if(altDugum==NULL) altDugum=new AVLnode(item);
			
			else if(item->dogruUzunlugu()<=altDugum->data->dogruUzunlugu()) {
				altDugum->left=SearchAndAdd(altDugum->left,item);
				if(Yukseklik(altDugum->left)==Yukseklik(altDugum->right)+2){
					
					if(item->dogruUzunlugu()<altDugum->left->data->dogruUzunlugu())
						altDugum=SolCocukIleDegistir(altDugum);
					
					else{
					altDugum->left=SagCocukIleDegistir(altDugum->left);
					altDugum=SolCocukIleDegistir(altDugum);
					}
				}			
			}
			else if(item->dogruUzunlugu()>altDugum->data->dogruUzunlugu()) {
				altDugum->right=SearchAndAdd(altDugum->right,item);
				if(Yukseklik(altDugum->right)==Yukseklik(altDugum->left)+2){
					
					if(item->dogruUzunlugu()>altDugum->right->data->dogruUzunlugu())
						altDugum=SagCocukIleDegistir(altDugum);
					else{
					altDugum->right=SolCocukIleDegistir(altDugum->right);
					altDugum=SagCocukIleDegistir(altDugum);
					}
				}
				
			}
			else{}
			
			altDugum->yukseklik=Yukseklik(altDugum);			
			return altDugum;

		}
		AVLnode* AVL::SolCocukIleDegistir(AVLnode*altDugum){
			AVLnode *tmp=altDugum->left;
			altDugum->left=tmp->right;
			tmp->right=altDugum;
			
			altDugum->yukseklik=Yukseklik(altDugum);
			tmp->yukseklik=1+max(Yukseklik(tmp->left),altDugum->yukseklik);
			return tmp;
		}
		
		AVLnode* AVL::SagCocukIleDegistir(AVLnode*altDugum){
			AVLnode *tmp=altDugum->right;
			altDugum->right=tmp->left;
			tmp->left=altDugum;
			
			altDugum->yukseklik=Yukseklik(altDugum);
			tmp->yukseklik=1+max(Yukseklik(tmp->right),altDugum->yukseklik);
			return tmp;
		}
		
		AVL::AVLnodeDelete(AVLnode* &altDugum){
			AVLnode*silinecekDugum=altDugum;
			
			if(altDugum->right==NULL) altDugum=altDugum->left;
			else if(altDugum->left==NULL) altDugum=altDugum->right;
			else {
				silinecekDugum=altDugum->left;
				AVLnode *ebeveynDugum=altDugum;
				while(silinecekDugum->right!=NULL){
					ebeveynDugum=silinecekDugum;
					silinecekDugum=silinecekDugum->right;
				}
				altDugum->data=silinecekDugum->data;
				if(ebeveynDugum==altDugum) altDugum->left=silinecekDugum->left; 
				else ebeveynDugum->right=silinecekDugum->left;
			}
			delete silinecekDugum;
			return true;
		}
			
		void AVL::postorder(AVLnode *altDugum){
			
			if(altDugum!=NULL){
				postorder(altDugum->left);
				postorder(altDugum->right);
				altDugum->data->yazdir();
				//cout<<altDugum->uzunluk<<endl;
			}
		}
		
		int AVL::Yukseklik(AVLnode*altDugum){
			
			if(altDugum==NULL) return -1;
			return 1+max(Yukseklik(altDugum->left),Yukseklik(altDugum->right));
		}
		
		AVL::AVL(){
			root=NULL;
		}
	
		bool AVL::isEmpty(){
			return root==NULL;
		}
	
		void AVL::add( DogruKuyrugu *item){
			root=SearchAndAdd(root,item);
		}
		
		
		void AVL::postorder()	{
			
			
			postorder(root);
		}
		
		
		int AVL::Yukseklik(){
			return Yukseklik(root);
		}
		
		
		void AVL::Temizle(){
			while(!isEmpty()){
				AVLnodeDelete(root);
			}
		}
		AVL::~AVL(){
			Temizle();

		}
