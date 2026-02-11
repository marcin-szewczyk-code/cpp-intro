#include <iostream>
using namespace std;

/*
  Funkcje

  1. Funkcje to podprogramy we wlasciwym programie.
     Funkcj� nazywamy podprogram, ktory jako rezultat zwraca jak�� warto��.
  2. Funkcj� wywo�uje si� przez podanie jej nazwy i umieszczonych w nawiasach argument�w.
  3. W ka�dym programie napisanym w j�zyku C++ znajduje si� funkcja g��wna, o nazwie main,
     kt�ra wykonywana jest jako pierwsza po uruchomieniu programu.


*/

double pole(double r) {
 double w;
 if (r < 0) {
	cout<<"Uwaga: r < 0!"<<endl;
	w = 0;
 } else {
	w = 3.14*r*r;
 }
 return w;
}

void wypisz(double a, double b) {
 cout<<"Pole okregu o promieniu "<<a<<" wynosi "<<b<<endl;
}

int main()
{
 double d = 3.2;
 double p;

 p = pole(d);
 wypisz(d, p);

 d = 5.8;
 p = pole(d);
 wypisz(d, p);

 return 0;
}
