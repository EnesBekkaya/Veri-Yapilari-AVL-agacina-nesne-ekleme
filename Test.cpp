#include "Queue.hpp"
#include <iostream>
#include<fstream>
#include <math.h>
#include <sstream>  
#include "DogruKuyrugu.hpp"
 #include "AVL.hpp"
using namespace std;

int main(){
	AVL *avl=new AVL();
	DogruKuyrugu *kuyruk;
	Nokta *nokta;
	Queue  *oncelikliKuyruk;
	
	ifstream dosyayioku;
	dosyayioku.open("./doc/Noktalar.txt");
	string okunanSayi;
	string okunanSatir;
	int tekrar=0;
	int x,y,z;
	int x2,y2,z2;
	int oncelik;
	int toplam=0;
	int sayac=0;
	int sayac2=0;
		
	while(!dosyayioku.eof()){
		
		int ikinciNoktaAlindi=0;
			int kontrol=0;
		int indekseKadarOku=0;
		int okunanSayiAdet=0;
		int baslananIndeks=0;
		int geciciIndeksTutan=0;
		getline(dosyayioku,okunanSatir,'\n');
			int adet=0;
			toplam=0;

		for(int i=0;i<okunanSatir.length();i++){
			if(okunanSatir[i]==' ')
				
				adet++;
				
		}
		
		oncelikliKuyruk=new Queue();
		for(int i=0;i<adet;i++){
			tekrar++;
			indekseKadarOku=okunanSatir.find(" ",indekseKadarOku);//boşluğun yerini buldum.
		
			okunanSayi=okunanSatir.substr(baslananIndeks,indekseKadarOku-baslananIndeks);//sayıyı boşluğa kadar olan kısmını aldım.
			
						if(tekrar==1) x=stoi(okunanSayi);
			if(tekrar==2) y=stoi(okunanSayi);
			if(tekrar==3){
				z=stoi(okunanSayi);
			
				if(ikinciNoktaAlindi==0){
				x2=x;
				y2=y;
				z2=z;
			
				}
				int kareToplam=x*x+y*y+z*z;
				oncelik=sqrt(kareToplam);
					
					
				nokta=new Nokta(x,y,z,oncelik);
				oncelikliKuyruk->Enqueue(*nokta);
				
				tekrar=0;
				ikinciNoktaAlindi++;
				if((adet+1)/3>=kontrol&&i!=0){
				
					int dogruUzunlugu=sqrt(pow(x2-x,2)+pow(y2-y,2)+pow(z2-z,2));			
					toplam=toplam+dogruUzunlugu;
					
					x2=x;
					y2=y;
					z2=z;		
					kontrol++;
					
				}	
			
			}
							
			indekseKadarOku=indekseKadarOku+1;//boşluğu bulmak için boşluktan 1 karakter ileri gittim.
		
			baslananIndeks=indekseKadarOku;//başlangıç yerini boşluktan sonraki karaktere ilerletmiş oldum.
			
		}
		
		kuyruk =new DogruKuyrugu(oncelikliKuyruk,toplam);
		
		
		avl->add(kuyruk);
	}
	
	avl->postorder();
		
		
delete kuyruk;
delete oncelikliKuyruk;
delete nokta;
delete avl;
return 0;
}