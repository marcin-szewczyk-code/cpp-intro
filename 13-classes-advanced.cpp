#include <iostream>
#include <string.h>
#include <stdlib.h>
using namespace std;

/*
  1. Dziedziczenie
     Klasa podstawowa (osoba) i klasy pochodne (student, nauczyciel).
     Etykieta protected pozwala klasom pochodnym korzystać z pól klasy bazowej.

  2. Konstruktory klas pochodnych
     Konstruktor klasy pochodnej wywołuje konstruktor klasy bazowej
     na liście inicjalizacyjnej, np. : osoba(n1, n2).

  3. Przeciążanie konstruktorów
     Klasa nauczyciel ma dwa konstruktory (różne listy argumentów).

  4. Polimorfizm (funkcje wirtualne)
     Funkcja wypisz() jest wirtualna w klasie bazowej.
     Wywołanie po wskaźniku do osoby (osoba*) uruchamia wersję z odpowiedniej klasy.
*/

// klasa podstawowa
class osoba {
 protected:        // składniki dostąpne w klasach pochodnych
 char imie[40];
 char nazwisko[40];

 public:
 // konstruktor
 osoba(char *n1, char* n2) {
      strcpy(imie, n1);
      strcpy(nazwisko, n2);
 }
 
 virtual void wypisz() {
    cout<<imie<<" "<<nazwisko<<endl;
 }
 
};

// klasa pochadna 1
class student : public osoba {
      private:
      float ocena;
      
      public:
      // konstruktor (konstruktora się nie dziedziczy)
      student(char* n1, char* n2, float f) : osoba(n1, n2) {
          ocena = f;
      }
      
      void wypisz() {
           cout<<"Student: "<<imie<<" "<<nazwisko<<", ocena: "<<ocena<<endl;
      }
};

// klasa pochadna 2
class nauczyciel : public osoba {
      private:
      float stawka_za_godzine;
      int liczba_godzin;
      
      float podajPensje() {
           return liczba_godzin*stawka_za_godzine;
      }

      public:
      // konstruktor 1
      nauczyciel(char* n1, char* n2, float f) : osoba(n1, n2) {
           stawka_za_godzine = f;
           liczba_godzin = 0;
      }
      
      // konstruktor 2
      nauczyciel(char* n1, char* n2, float f, int i) : osoba(n1, n2) {
           stawka_za_godzine = f;
           liczba_godzin = i;
      }

      void przypiszLiczbeGodzin(int i) {
           liczba_godzin = i;
      }

      virtual void wypisz() {
           cout<<"Nauczyciel: "<<imie<<" "<<nazwisko<<", pensja: "<<podajPensje()<<" PLN"<<endl;
      }
};

// funkcja nie będąca składnikiem żadnej klasy
void wypisz(osoba* po) {          // argumentem jest wskaźnik do obiektu klasy osoba
     po->wypisz();     // polimorficzny fragment kodu
                       // na rzecz obiektu klasy osoba wywoływana jest wirtualna funkcja wypisz
}

int main() {

 student s1 = student("Jan", "Kowalski", 4);
 student s2 = student("Krzysztof", "Nowakowski", 3);
 student s3 = student("Anna", "Jagiellonka", 4.5);
 student s4 = student("Stefan", "Batory", 5.0);
  
 nauczyciel n1("Zenon", "Iksinski", 50);
 n1.przypiszLiczbeGodzin(42);
 nauczyciel n2("Robert", "Igrekowski", 45, 84);

 wypisz(&s1);
 wypisz(&s2);
 wypisz(&s3);
 wypisz(&s4);
 cout<<"------------"<<endl;
 wypisz(&n1);
 wypisz(&n2);

// system("pause");
 return 0;
}
