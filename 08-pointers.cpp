#include <iostream>
#include <stdlib.h>
using namespace std;

/*
  Wskazniki

  1. Adres zmiennej (komórki pamiêcie w której zapisano warto¶æ zmiennej)
     uzyskujemy przy uzyciu operatura &, np. &a jest adresem zmiennej a.
     Adres nie zawiera informacji o typie zmiennej.
  2. Adres moze byc zapamietany w zmienych specjalnego typu, zwanego wskaznikiem (typ pochodnego).
     Wskaznik do zmiennej typu T deklarujemy jako T*, np. wskaznik do zmiennej o nazwie "a" typu 
     "int" deklarujemy jako: int* pa; (p jak pointer - wskaznik) i przypisujemy mu warto¶æ bêd±c±
     adresem zmiennej a, czyli: pa = &a;
     Wskaznik zawiera informacje o typie zmiennej: jest takiego typu, jakiego typu jest zmienna 
     na ktora wskazuje.
  3. Jesli pa jest wskaznikiem do zmiennej a, to *pa jest wartoscia zmiennej 
     wskazywanej przez wskaznik pa (czyli wartoscia zmiennej a).
*/

int main()
{
      int a;
      a = 15;
      int* pa;
      pa = &a;

      cout<<"wartosc zmiennej a: a = "<<a<<endl;
      cout<<"adres zmiennej a: &a = "<<&a<<endl;
      cout<<"wskaznik do zmiennej a: pa = "<<pa<<" (przechowuje adres zmiennej)"<<endl;
      cout<<"wartosc zmiennej wskazywanej przez wskaznik pa: *pa = "<<*pa<<endl;
      system("PAUSE");
      return 0;
}


