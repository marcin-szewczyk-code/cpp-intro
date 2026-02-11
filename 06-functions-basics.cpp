#include <iostream>
using namespace std;

/*
    Funkcje

    1. Funkcje to podprogramy wydzielone z głównego programu.
       Mogą zwracać wartość (np. typu double) lub nie zwracać żadnej wartości (void).

    2. Funkcję wywołuje się przez podanie jej nazwy oraz argumentów
       umieszczonych w nawiasach.

    3. W każdym programie napisanym w języku C++ znajduje się funkcja główna
       o nazwie main, która wykonywana jest jako pierwsza po uruchomieniu programu.
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
