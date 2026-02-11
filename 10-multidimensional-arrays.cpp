#include <iostream>
//#include <stdlib.h>
using namespace std;

/*
  Macierze
*/

void wypisz(char *nazwa, double a[2][2], int rows, int cols) {
 cout<<nazwa<<" = "<<endl;
 for (int i = 0; i < rows; i++) {
	cout<<"   ";
	for (int j = 0; j < cols; j++) {
		cout<<a[i][j]<<" ";
	}
	cout<<endl;
 }
}

int main() {

 double a[2][2] = {{1,2},{3,4}};
 double b[2][2] = {{5,6},{7,8}};
 double c[2][2] = {0};

 wypisz("a", a, 2, 2);
 wypisz("b", b, 2, 2);
 wypisz("c", c, 2, 2);


 // mno¿enie macierzy
 for (int i = 0; i < 2; i++) {
	for (int j = 0; j < 2; j++) {
		for (int k = 0; k < 2; k++) {
			c[i][j] = c[i][j] + a[i][k]*b[k][j];
		}
	}
 }

 wypisz("c", c, 2, 2);

 return 0;
}
