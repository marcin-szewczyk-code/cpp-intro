#include <iostream>
#include <string.h>
#include <stdlib.h>
using namespace std;

/*
  1. Dziedziczenie
     klasa podstawowa, klasy pochodne, etykieta protected
  2. prze³adowanie konstruktorów
  3. Polimorfizm - wieloœæ form (funkcje wirtualne)
*/

// klasa podstawowa
class osoba {
 protected:        // sk³adniki dostêpne w klasach pochodnych
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
      // konstruktor (konstruktora siê nie dziedziczy)
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

// funkcja nie bêd¹ca sk³adnikiem ¿adnej klasy
void wypisz(osoba* po) {          // argumentem jest wskaŸnik do obiektu klasy osoba
     po->wypisz();     // polimorficzny fragment kodu
                       // na rzecz obiektu klasy osoba wywo³ywana jest wirtualna funkcja wypisz
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
