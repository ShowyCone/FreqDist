#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include "main.h"
#include "menu.h"

using namespace std;

void testManualFill();

int main() {
	vector<Stats> stats;
	int option, dataLength;
	string options[4] = {"Ingresar", "Mostrar Altura", "Ingresar Datos manual", "Salir"};
	
	do {
		system("cls");
		option = menu("Menu", options);
		
		if(option == 1) {
			system("cls");
			dataLength = inOut("Cuantos datos desea guardar (60 datos como minimo)?");
			if(dataLength >= 60) {
				for(int i = 0; i < dataLength; i++) {
					Stats s = Stats();
					s.fillDataAuto();
					stats.push_back(s);
				}
			} else cout << "Error, tiene que ser como minimo 60 datos";
			system("pause");
			
		} else if(option == 2) {
			system("cls");
			frame(6);
			int yendl = 0;
			int xendl = 0;
			for(int i = 0; i < stats.size(); i++) {
				if((i % 5) == 0) {
					yendl++;
					xendl = 0;
				}
				gotoxy(22+xendl, 4+yendl);
				cout << stats[i].getHeight();
				xendl += 10;
			}
			gotoxy(20, 20);
			system("pause");
		} else if(option == 3) {
			testManualFill();
		}
	} while(option != 4);	
	return 0;
}

// De momento es solo un test, cuando este listo el programa estara como un metodo de la clase, modularizado correctamente
void testManualFill() {
	system("cls");
	int m, n, i, j, k;
	
	cout << "Numero de filas: ";
	cin >> m;
	
	cout << "Numero de columnas: ";
	cin >> n;
	
	int A[m][n], B[20];
	
	for(i = 0; i<m; i++) {
		for(j = 0; j < n; j++) {
			gotoxy(j*5, i+3);
			cin >> A[i][j];
		}
	}

	for(i = 0; i <20; i++)
		B[i] = 0;
	
	// Conteo de la frecuencia de los numeros
	for(i = 0; i<m; i++) {
		for(j = 0; j < n; j++) {
			k = A[i][j];
			B[k] = B[k] + 1;
		}
	}
	
	cout << endl;
	
	for(i = 0; i < 20; i++) {
		cout << i << " = " << B[i]<< endl;
	}

	int a = 5;
	for(i = 0; i < 20; i++) {
		k = B[i];
		for(j = 0; j < k; j++) {
			gotoxy((4+i)+a, 32-j);
			cout << char(219);
			gotoxy((4+i)+(a+1), 32-j);
			cout << char(219);
			gotoxy((4+i)+(a+2), 32-j);
			cout << char(219);
		}
		gotoxy((4+i)+(a+1), 33);
		cout << i;
		a+=4;
	}
	gotoxy(1, 35);
	system("pause");
	
	// Test guardar los valores de la distribucion de frecuencias en archivo txt
	ofstream sdata;
	sdata.open("test123.txt", ios::app);
	for(i = 0; i < 20; i++) {
		sdata << i << " = " << B[i]<< endl;
	}
	sdata.close();
}