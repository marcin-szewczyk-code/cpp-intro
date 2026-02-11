#include <iostream>
#include <stdlib.h>
using namespace std;

/*
	Podstawowe typy zmiennych, oraz elementarne operacje wejścia/wyjścia.
*/

int main() {

 // deklaracje zmiennych typu calkowitego
 short s;	// zmienna o nazwie s typu short
 int i;		// zmienna o nazwie i typu int

 // i = 3.14;	// wyswietli sie ostrzezenie
 // cout<<i<<endl;
 
 cout<<"rozmiar s: "<<sizeof(s)<<" bajty"<<endl;
 cout<<"rozmiar i: "<<sizeof(i)<<" bajty"<<endl;

 // 2^(16-1) = 32768, czyli od 0 do 32767
 // 2^(32-1) = 2147483648, czyli od 0 do 2147483647

 s = 32767;
 cout<<"s = "<<s<<endl;
 s = 32768;
 cout<<"s = "<<s<<endl;
 i = 32768;
 cout<<"i = "<<i<<endl;

 system("pause");
 return 0;
}
