#include <iostream>
#include <string.h>
#include <stdlib.h>
using namespace std;

/*
  1. Dziedziczenie
     klasa podstawowa, klasy pochodne, etykieta protected
  2. tablice obiektów, przyk³ad u¿ycia
  3. prze³adowanie konstruktorów
*/

// klasa podstawowa
class osoba {
 protected:        // sk³adniki dostêpne w klasie pochodnej
 char imie[40];
 char nazwisko[40];

 public:
 // konstruktor
 osoba(char *napis1, char* napis2) {
      strcpy(imie, napis1);
      strcpy(nazwisko, napis2);
 }
 
 virtual float podajWage() {
         return 0;
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
      student(char* napis1, char* napis2, float f) : osoba(napis1, napis2) {
          ocena = f;
      }
      
      void przypiszOcene(float f) {
           ocena = f;
      }

      float podajOcene() {
           return ocena;
      }

      float podajWage() {
           return ocena;
      }

      void wypisz() {
           cout<<"Student: "<<imie<<" "<<nazwisko<<",\t ocena: "<<ocena<<endl;
      }
};

// klasa pochadna 2
class nauczyciel : public osoba {
      private:
      float stawka_za_godzine;
      int liczba_godzin;
      
      public:
      // konstruktor 1
      nauczyciel(char* napis1, char* napis2, float f) : osoba(napis1, napis2) {
           stawka_za_godzine = f;
           liczba_godzin = 0;
      }
      
      nauczyciel(char* napis1, char* napis2, float f, int i) : osoba(napis1, napis2) {
           stawka_za_godzine = f;
           liczba_godzin = i;
      }

      void przypiszLiczbeGodzin(int f) {
           liczba_godzin = f;
      }

      float podajPensje() {
           return liczba_godzin*stawka_za_godzine;
      }

      float podajWage() {
           return liczba_godzin*stawka_za_godzine;
      }

      void wypisz() {
           cout<<"Nauczyciel: "<<imie<<" "<<nazwisko<<",\t pensja: "<<podajPensje()<<" PLN"<<endl;
      }
};

void sortuj(student* os, int rozmiar) {
 // sortowanie przez wybieranie:
 //  1. wyszukaj maksymaln¹ wartoœæ z tablicy spoœród elementów od i+1 do koñca tablicy
 //  2. zamieñ wartoœæ maksymaln¹, z elementem na pozycji i
 int max;
 for (int i = 0; i < rozmiar - 1; i++) {
     max = i;
     for (int j = i + 1; j < rozmiar; j++) {
          if (os[j].podajWage() > os[max].podajWage()) {
             max = j;
          }
     }
     student tmp = os[i];
     os[i] = os[max];
     os[max] = tmp;
 }
     
}

int main() {
 student s[4] =
 {
         student("Jan", "Kowalski", 4),
         student("Krzysztof", "Nowakowski", 3),
         student("Anna", "Jagiellonka", 4.5),
         student("Stefan", "Batory", 5.0)
 };
 
 sortuj(s, 4); // dodatek
 
 for (int i = 0; i < 4; i++) {
     s[i].wypisz();
 }
 
 cout<<"------"<<endl;

 nauczyciel n1("Zenon", "Iksinski", 50);
 n1.przypiszLiczbeGodzin(42);
 nauczyciel n2("Zenon", "Iksinski", 45, 84);

 n1.wypisz();
 n2.wypisz();

 system("pause");
 return 0;
}
