#include <iostream>
#include <stdlib.h>	// funkcja sizeof
using namespace std;

/*
  Tablice (i napisy)

  1. Deklarowanie tablic, np. int a[10]; oznacza tablicę 10 elementów (indeksy od 0 do 9)
     typu int.

  2. Nazwa tablicy w wyrażeniu zachowuje się jak wskaźnik (adres) do pierwszego elementu,
     np. a to adres a[0].

  3. Arytmetyka wskaźników: zwiększając wskaźnik (np. a + 1) przechodzimy do kolejnego
     elementu tablicy. Przesunięcie jest liczone w elementach, a nie w bajtach.

  4. Napis to tablica znaków (char) zakończona znakiem '\0'.
     Np. napis "abc" jest zapisany jako: 'a', 'b', 'c', '\0'.

  5. W tym przykładzie pokazane jest też przeciążanie funkcji (wypisz dla int* i char*).
*/

 void wypisz(int* p, int rozmiar) {
	cout<<"Wypisuje tablice typu int:"<<endl;
	for (int i = 0; i < rozmiar; i++) {
		//cout<<*(p++)<<endl;
		cout<<p[i]<<endl;
	}
 }

 // prze�adowanie nazwy funkcji
 void wypisz(char* p, int rozmiar) {
	cout<<"Wypisuje tablice typu char:"<<endl;
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

 cout<<"rozmiar wskaźnika: sizeof(*a): "<<sizeof(*a)<<" bajty"<<endl;

 // inny sposób - definicja tablicy (definicja to deklaracja i przypisanie wartości)
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

 // łatwy sposób definiowania i wypisywania napisów:
 char* napis = "Ala ma kota";
 cout<<"napis = "<<napis<<endl;
 wypisz(napis,5);

// system("PAUSE");
 return 0;
}

