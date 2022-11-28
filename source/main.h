#ifndef Estad
#define Estad
#include <iostream>
#include <random>

using namespace std;

class Stats {
	float weight;
	float height;
	int age;
	
	public:
		Stats() {
			this -> weight = 0;
			this -> height = 0;
			this -> age = 0;
		}
		void fillDataAuto() {
			default_random_engine genInt;
			uniform_int_distribution<int> distribution(1,6);
			
			random_device rd;
    		mt19937 genFloat(rd());
    		uniform_real_distribution<> dist(60, 90);
    		
			this -> weight = dist(genFloat);
			this -> height = dist(genFloat);
			this -> age = distribution(genInt);
		}
		float getWeight() 	{ return this -> weight; }
		float getHeight() 	{ return this -> height; }
		int getAge() 		{ return this -> age; }
};


#endif