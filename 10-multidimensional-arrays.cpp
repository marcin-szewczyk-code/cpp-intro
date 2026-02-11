#include <iostream>
//#include <stdlib.h>
using namespace std;

/*
  Macierze

  1. Macierz dwuwymiarowa jest tablicą dwuwymiarową,
     np. double a[2][2] oznacza macierz 2x2 typu double.

  2. Element macierzy odczytujemy przez podanie dwóch indeksów,
     np. a[i][j], gdzie i oznacza wiersz, a j kolumnę.

  3. Funkcja wypisz przyjmuje nazwę macierzy oraz jej rozmiar
     i wypisuje wszystkie elementy przy użyciu zagnieżdżonych pętli.

  4. Mnożenie macierzy realizowane jest za pomocą trzech pętli:
     - i oznacza numer wiersza,
     - j oznacza numer kolumny,
     - k służy do sumowania iloczynów odpowiednich elementów.
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


 // mnożenie macierzy
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
