#include <iostream>
#include <string.h>
#include <stdlib.h>
using namespace std;

/*
  1. Konstruktor i destruktor
     Konstruktor pozwala na inicjalizację obiektu w momencie jego tworzenia
     (nadanie wartości danym składowym).
     Destruktor wykonuje się przed zniszczeniem obiektu (np. przy wyjściu z zakresu).

  2. Składnik statyczny
     Składnik statyczny należy do klasy, a nie do pojedynczego obiektu.
     W tym przykładzie zliczamy liczbę istniejących obiektów klasy student.

  3. Czas życia obiektu
     Obiekt istnieje do końca zakresu (bloku w { }).
     Po wyjściu z bloku wywoływany jest destruktor.
*/


class student {
 private:
 char nazwisko[40];
 float ocena;

 public:
 static int liczba_egzemplarzy;
 // konstruktor (definicja konstruktora nie zawiera typu zwracanego, nawet void),
 // nazwa konstruktora jest taka sama jak nazwa klasy
 student(char *napis) {
      strcpy(nazwisko, napis);
      ocena = 2;
      liczba_egzemplarzy++;
 }
 
 // destruktor (definicja destruktora nie zawiera typu zwracanego,
 // nazwa jest taka sama jak nazwa klasy i poprzedzona jest tyldą)
  ~student() {
      liczba_egzemplarzy--;
      // ten destruktor nie czyści, tylko gada że czyści
      cout<<"Czyszcze: "<<nazwisko<<endl;
 }
 
 void przypiszOcene(float f) {
      ocena = f;
 }

 void wypisz() {
      cout<<nazwisko<<"\t"<<ocena<<endl;
 }

 static int podajLiczbeEgzemplarzy() {
      return liczba_egzemplarzy;
 }
};


int student::liczba_egzemplarzy = 0;

int main() {
 student a = student("Kowalski");    // pierwszy sposób deklaracji i inicjalizacji obiektu przy użyciu konstruktora
 cout<<"Liczba studentow: "<<student::podajLiczbeEgzemplarzy()<<endl;
 student b("Nowakowski");          // drugi sposób
 cout<<"Liczba studentow: "<<student::podajLiczbeEgzemplarzy()<<endl;

 a.przypiszOcene(4.5);
 
 a.wypisz();
 b.wypisz();
 
 // czas życia obiektu ograniczają nawiasy klamrowe
 {
   student a("Iksinski");            // zasłanianie nazwy
   a.wypisz();
   a.przypiszOcene(3.0);
   cout<<"Liczba studentow: "<<student::podajLiczbeEgzemplarzy()<<endl;
 }
 
 a.wypisz();

 cout<<"Liczba studentow: "<<student::podajLiczbeEgzemplarzy()<<endl;

// system("pause"); 
 return 0;
}
