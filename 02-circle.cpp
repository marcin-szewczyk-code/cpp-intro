#include <iostream>
using namespace std;

/*
	Proste obliczenia – wyznaczanie własności okręgu (pole, obwód).

	Wczytywanie danych z klawiatury. Wysyłanie danych na ekran.
*/

int main() {

 float r;	// deklaracja zmiennej o nazwie r, typu rzeczywistego float
 cout<<"Podaj promien okregu: ";
 cin>>r;
 cout<<"Wpisales: "<<r<<endl;

 float pole, obwod;
 float pi = 3.14;	// mozna tez uzyc stalej M_PI z biblioteki math.h

 pole = pi*r*r;
 obwod = 2*pi*r;
 cout<<"pole = "<<pole<<endl;
 cout<<"obwod = "<<obwod<<endl;

 return 0;
}
