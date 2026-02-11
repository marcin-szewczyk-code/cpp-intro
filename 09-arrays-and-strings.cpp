#include <iostream>
#include <stdlib.h>	// funkcja sizeof
using namespace std;

/*
  Tablice (i napisy)

  1. Deklarowanie tablic: np. int a[10]; - deklaracja dziesiecioelementowej (od 0 do 9)
	tablicy zmiennych typu int
  2. Nazwa tablicy jest wskaznikiem do pierwszego elementu tej tablicy
  3. Inkrementacja wskaznikow - zwiekszaj±c wartroi¶c wska¿nika uzyskujê dostêp
	do kolejnych elementów tablicy
  4. Napis to tablica znakow, czyli zmiennych typu char. Ostatnim znakiem napisu jest zero.
     Np. napis "abc" zapisywany jest w czteroelementowej tablicy o elementach: a, b, c, 0.

*/

 void wypisz(int* p, int rozmiar) {
	cout<<"Wypisujê tablicê typu int:"<<endl;
	for (int i = 0; i < rozmiar; i++) {
		//cout<<*(p++)<<endl;
		cout<<p[i]<<endl;
	}
 }

 // prze³adowanie nazwy funkcji
 void wypisz(char* p, int rozmiar) {
	cout<<"Wypisujê tablicê typu char:"<<endl;
	for (int i = 0; i < rozmiar; i++) {
		//cout<<*(p++)<<endl;
		cout<<p[i]<<endl;
	}
 }


int main() {

 // deklaracja zmiennej typu int
 int i;
 cout<<"rozmiar i: "<<sizeof(i)<<" bajty"<<endl;	// dla 4 bajtów: 2^(4*8-1) = 2147483648, czyli od 0 do 2147483647
 i = 2147483647;
 cout<<"i = "<<i<<endl;
 i = i + 1;
 cout<<"i = "<<i<<endl;

 // deklaracja tablicy czteroelementowej zmiennych typu int
 int a[4];
 a[0] = 20;
 a[1] = 30;
 a[2] = 40;
 a[3] = 50;

 // nazwa tablicy to wskaznik (adres) do jej pierwszego elementu
 cout<<"a[0] = "<<*a<<endl;
 cout<<"a[1] = "<<*(a+1)<<endl;
 cout<<"a[1] = "<<*a+1<<endl;	// tu uwaga
 cout<<"a[2] = "<<a[2]<<endl;
 cout<<"a[3] = "<<a[3]<<endl;

 cout<<"wypisz a: "<<endl;
 wypisz(a, 4);

 cout<<"rozmiar wska¼nika: sizeof(*a): "<<sizeof(*a)<<" bajty"<<endl;

 // inny sposób - definicja tablicy (definicja to deklaracja i przypisanie warto¶ci)
 int b[4] = {8, 15, 36, 2};
 cout<<"wypisz b: "<<endl;
 wypisz(b, 4);

 // napis to tablica zmiennych typu char
 char c[4];
 c[0] = 'a';
 c[1] = 'b';
 c[2] = 99;
 c[3] = '\0';
 cout<<"wypisz c: "<<endl;
 wypisz(c, 4);
 cout<<"c = "<<c<<endl;

 // cout<<"!!! = "<<(int)c[0]<<endl;

 // ³atwy sposób definiowania i wypisywania napisów:
 char* napis = "Ala ma kota";
 cout<<"napis = "<<napis<<endl;
 wypisz(napis,5);

// system("PAUSE");
 return 0;
}

