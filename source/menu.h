#ifndef Menu
#define Menu
#include <iostream>
#include <windows.h>

using namespace std;


void gotoxy(int, int);
void frame(int);

template <size_t n>	// Get lenght of "options" array
int menu(string title, string (&options)[n]) {
	//system("mode con: cols=100 lines=30");
	int selectedOption = 0;
	int length = n-1;
	
	gotoxy(45, 3);
	cout << title;

	frame(length);

	int space = 0;
	for(int i = 0; i <= length; i++) {
		space += 1;
		gotoxy(20, space+4);
		if((i%2) == 0) 	cout << "(" << i+1 << ") " << options[i];
		else 			cout << "(" << i+1 << ") " << options[i];
		space++;
	}
	
	gotoxy(42, length + 15);
	cout << "OPCION A ELEGIR";
	gotoxy(42, length + 17);
	cin >> selectedOption;
	return selectedOption;
}

void gotoxy(int x, int y) {
	HANDLE hcon = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD dwPos;
	dwPos.X = x;
	dwPos.Y = y;
	SetConsoleCursorPosition(hcon, dwPos);
}

void frame(int length) {
	// corner 1
	gotoxy(14, 1);
	printf("%c", 201);

	// corner 2
	gotoxy(86, 1);
	printf("%c", 187);

	// corner 3
	gotoxy(86, (length+20)+1);
	printf("%c", 188);
	
	// corner 4
	gotoxy(14, (length+20)+1);
	printf("%c", 200);

	// top
	for(int i = 15; i <= 85; i++) {
		gotoxy(i, 1);
		printf("%c", 205);
	}
	
	// bottom
	for(int i = 15; i <= 85; i++) {
		gotoxy(i, (length+20)+1);
		printf("%c", 205);
	}

	// right
	for(int i = 2; i <= (length+20); i++) {
		gotoxy(14, i);
		printf("%c", 186);
	}
	
	// left
	for(int i = 2; i <= (length+20); i++) {
		gotoxy(86, i);
		printf("%c", 186);
	}
}

int inOut(string title) {
	system("cls");
	frame(1);
	int in;
	gotoxy(25, 5);
	cout << title;
	for(int i = 0; i <= 25; i++) {
		gotoxy(37+i, 10);
		printf("%c", 196);	
	}
	gotoxy(40, 9);
	cin >> in;
	gotoxy(30, 13);
	system("pause");
	return in;
}

void onlyOut(string out[], int len, string clasi) {
	system("cls");
	frame(1);
	for(int i = 0; i < len; i++){
		gotoxy(37, 8+i);
		cout << clasi << " " << i << ": " << out[i];
	}
	gotoxy(30, 20);
	system("pause");
}

void showMatrix(int indx) {
	frame(8);
	
	// Corner
	gotoxy(16, 3);
	printf("%c", 218);
	//Side
	gotoxy(16+indx, 4);
	printf("%c", 179);
	
	// Score
	gotoxy(17+indx, 4);
	printf("%c", 196);
	gotoxy(17+indx, 6);
	printf("%c", 196);
	
	gotoxy(16+indx, 4);
	printf("%c", 179);
}

#endif