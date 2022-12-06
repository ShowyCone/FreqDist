#ifndef Estad
#define Estad
#include <iostream>
#include <random>

using namespace std;

class Stats {
	float weight[100];
	float height[100];
	int age[100];
	float ageTable[43][6];
	
	public:
		Stats() {
			for(int i = 0; i <= 100; i++) {
				this -> weight[i] = 0;
				this -> height[i] = 0;
				this -> age[i] = 0;
			}
		}
		void fillDataAuto(float x) {
			default_random_engine genInt;
			uniform_int_distribution<int> distribution(18,60);
			
			random_device rd;
    		mt19937 genFloat(rd());
    		uniform_real_distribution<> dist(60, 90);
    		
    		for(int i = 0; i < x; i++) {
				this -> weight[i] = dist(genFloat);
				this -> height[i] = dist(genFloat);
				this -> age[i] = distribution(genInt);
			}
		}
		float getWeight(int i) 	{ return this -> weight[i]; }
		float getHeight(int i) 	{ return this -> height[i]; }
		int getAge(int i) 		{ return this -> age[i]; }
		void XD(float x, int i){
			this -> age[i] =x;
		}
		int getClass(float x) {
			int aux = 1, c = 0;
			while(aux < x) {
				aux *= 2;
				c++;
			}
			return c;
		}
		
		// Retorna el numero menor de los datos
		float getFloorWeight(float x) {
			float aux = 1000;
			for(int i = 0; i < x; i++) {
				if(aux > this -> weight[i])
					aux = weight[i];
			}
			return aux;
		}
		float getFloorHeight(float x) {
			float aux = 1000;
			for(int i = 0; i < x; i++) {
				if(aux > this -> height[i])
					aux = height[i];
			}
			return aux;
		}
		int getFloorAge(float x) {
			int aux = 1000;
			for(int i = 0; i < x; i++) {
				if(aux > this -> age[i])
					aux = age[i];
			}
			return aux;
		}
		
		// Retorna el numero mayor de cada dato
		float getMostWeight(float x) {
			float aux = 0;
			for(int i = 0; i < x; i++) {
				if(aux < this -> weight[i])
					aux = weight[i];
			}
			return aux;
		}
		float getMostHeight(float x) {
			float aux = 0;
			for(int i = 0; i < x; i++) {
				if(aux < this -> height[i])
					aux = height[i];
			}
			return aux;
		}
		int getMostAge(float x) {
			int aux = 0;
			for(int i = 0; i < x; i++) {
				if(aux < this -> age[i])
					aux = age[i];
			}
			return aux;
		}
		
		void getTableAge(float x) {
			float cont = 0;
			for(int i = getFloorAge(x)-1; i < getMostAge(x); i++) {
				for(int j = 0; j < x; j++) {
					if(i+1 == this -> age[j])
						cont++;
				}
				this -> ageTable[i][1] = cont;
				this -> ageTable[i][0] = i+1;
				this -> ageTable[i][2] = (this -> ageTable[i][1] / x)*100;
				this -> ageTable[43][1] = x;
				this -> ageTable[43][2] = 100;
				if(i == 0) {
					this -> ageTable[0][3] = cont;
					this -> ageTable[0][4] = this ->ageTable[0][2];
					//cout << endl << "Cuando i es 0: " << endl << (this -> ageTable[i][2] / x)*100 << endl << x;
				} else if(i != 43) {
					this -> ageTable[i][3] = this -> ageTable[i-1][3] + cont;
					//cout << endl << "Cuando i no es 0: " << endl << this -> ageTable[0][4] << endl << this -> ageTable[i][2] << endl <<  i;
					this -> ageTable[i][4] = (this -> ageTable[i-1][4]) + (this -> ageTable[i][2]);
				}
				cont = 0;
			}	
		}
		
		void showAgeTable(float x) {
			for(int i =getFloorAge(x)-1; i <= getMostAge(x); i++) {
				for(int j = 0; j < 5; j++) {
					cout << "\t\t|" << this -> ageTable[i][j];
				}
				cout << endl;
			}
		}
};


#endif