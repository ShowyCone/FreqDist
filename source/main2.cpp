#include <iostream>
#include "main2.h"
#include "menu.h"

using namespace std;

int main() {
	Stats s;
	float x = 50,Num=0;
	for (int i=0;i<x;i++){
		cin>>Num;
		s.XD(Num,i);
	}
	//s.fillDataAuto(x);
	
/*	
	cout << "Peso: " << endl;
	for (int i = 0; i < x; i++)
		cout << endl << s.getWeight(i);
	
	cout << endl << "Clase: " << s.getClass(x);
	
	cout << endl << "Numero menor: " << s.getFloorWeight(x);
	
	cout << endl << "Numero mayor: " << s.getMostWeight(x) << endl << endl;
	
	cout << "Altura: " << endl;
		for (int i = 0; i < x; i++)
		cout << endl << s.getHeight(i);
	
	cout << endl << "Clase: " << s.getClass(x);
	
	cout << endl << "Numero menor: " << s.getFloorHeight(x);
	
	cout << endl << "Numero mayor: " << s.getMostHeight(x) << endl << endl;
	
	cout << "Edad: " << endl;
	for (int i = 0; i < x; i++)
		cout << endl << s.getAge(i);
	
	cout << endl << "Clase: " << s.getClass(x);
	
	cout << endl << "Numero menor: " << s.getFloorAge(x);
	
	cout << endl << "Numero mayor: " << s.getMostAge(x) << endl << endl;
	
	cout << "Tablad de edades: " << endl; */
	
	cout << endl << endl;
	s.getTableAge(x);
	s.showAgeTable(x);
	
	return 0;
}