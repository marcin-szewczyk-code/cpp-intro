#include <iostream>
#include <stdlib.h>
using namespace std;

/*
  Wskaźniki

  1. Adres zmiennej (komórki pamięci, w której zapisana jest jej wartość)
     uzyskujemy przy użyciu operatora &, np. &a jest adresem zmiennej a.
     Sam adres nie zawiera informacji o typie zmiennej.

  2. Adres może być przechowywany w zmiennej specjalnego typu,
     zwanej wskaźnikiem. Wskaźnik do zmiennej typu T deklarujemy jako T*.
     Na przykład wskaźnik do zmiennej typu int deklarujemy jako:
     int* pa;
     Następnie przypisujemy mu adres zmiennej a:
     pa = &a;
     Typ wskaźnika określa typ zmiennej, na którą wskazuje.

  3. Jeżeli pa jest wskaźnikiem do zmiennej a,
     to wyrażenie *pa oznacza wartość zmiennej wskazywanej przez pa,
     czyli wartość zmiennej a.
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


