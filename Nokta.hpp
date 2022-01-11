#ifndef NOKTA_HPP
#define NOKTA_HPP

#include <iostream>
using namespace std;
class Nokta{
	private:
		int x,y,z;
		int oncelik;
	public:
	
		Nokta();
		
		Nokta(int x,int y,int z,int oncelik);
		void oncelikk();
		friend ostream& operator<<(ostream& ekran,Nokta r);
		
		bool operator<(Nokta& r);
		
};

#endif