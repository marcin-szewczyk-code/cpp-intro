#include <iostream>
#include <string.h>
#include <stdlib.h>
using namespace std;

/*
  1. Dziedziczenie
     Klasa podstawowa (osoba) i klasy pochodne (student, nauczyciel).
     Etykieta protected umożliwia klasom pochodnym dostęp do pól imie i nazwisko.

  2. Tablice obiektów
     W programie tworzona jest tablica obiektów typu student i wykonywane są na niej operacje
     (wywołanie metod, sortowanie, wypisywanie).

  3. Przeciążanie konstruktorów
     Klasa nauczyciel ma dwa konstruktory (różne listy argumentów).

  4. Sortowanie tablicy
     Funkcja sortuj sortuje tablicę studentów metodą wyboru (selection sort),
     porównując wartości zwracane przez podajWage() (tu: ocena).
*/


// klasa podstawowa
class osoba {
 protected:        // składniki dostępne w klasie pochodnej
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
      // konstruktor (konstruktora się nie dziedziczy)
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
 //  1. wyszukaj maksymalną wartość z tablicy spośród elementów od i+1 do końca tablicy
 //  2. zamień wartość maksymalną, z elementem na pozycji i
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
