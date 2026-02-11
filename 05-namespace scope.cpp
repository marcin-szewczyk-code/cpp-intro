#include <iostream>
#include <stdlib.h>
using namespace std;

/*
	Zakres zmiennych: zakres blokowy, zmienne lokalne i globalne oraz czas życia obiektów.

	Czas życia obiektu - okres od zdefiniowania obiektu (rezerwacji pami�ci)
	do momentu w którym obiekt przestaje istnieć (pamięć jest zwalniana).

	Zakres ważności nazwy obiektu - to część programu, w którym nazwa obiektu
	znana jest kompilatorowi.
*/

int g;	// obiekt zdefiniowany poza funkcją main (obiekt globalny),

int main() {

 int k = 15;	// obiekt zdefiniowany w funkcji main

 cout<<"Jestem w main: k = "<<k<<endl;

 // blok instrukcji - nawiasy klamrowe
 {
	int k = 3;	// obiekt w bloku zasłania obiekt zdefiniowany w funkcji main
			// obiekt k zdefiniowany w main żyje, ale jest zasłonięty przez obiekt k zdefiniowany wewnątrz bloku
	cout<<"Jestem w bloku: k = "<<k<<endl;
 }

 cout<<"Jestem w main: k = "<<k<<endl;

 // znowu blok
 {
	k = 4;	// tym razem bez zaslaniania
 }

 cout<<"Jestem w main: k = "<<k<<endl;

 // kolejny blok
 {
	int m = 10;
 }

 // cout<<"Jestem w main: m = "<<m<<endl;	// uwaga: tu kompilator wyświetli błąd

 return 0;
}
