#ifndef File
#define File
#include <iostream>

using namespace std;

template <size_t n>	// Get lenght of "toSave" array
void saveFloatFile(float (&toSave)[n]) {
	ofstream sdata;
	sdata.open("test123.txt", ios::app);
	for(i = 0; i < 20; i++) {
		sdata << i << " = " << toSave[i]<< endl;
	}
	sdata.close();
}

#endif