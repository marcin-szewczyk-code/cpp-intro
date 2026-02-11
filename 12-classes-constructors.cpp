#include <iostream>
#include <string.h>
#include <stdlib.h>
using namespace std;

/*
  1. Konstruktor i destruktor
     Konstruktor - pozwala na inicjalizacjê obiektu (czyli nadanie wartoœci danym
                   sk³adowym obiektu), w momencie deklaracji obiektu.
     Destruktor  - wykonywany jest przed zlikwidowaniem obiektu (np. zamazuje punkt
                   na ekranie, reprezentuj¹cy dany obiekt, np. samolot)
  2. Sk³adnik statyczny
     Dotyczy klasy a nie egzemplarza klasy.
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
 // nazwa jest taka sama jak nazwa klasy i poprzedzona jest tyld¹)
  ~student() {
      liczba_egzemplarzy--;
      // tak naprawdê ten destruktor nie czyœci, tylko gada ¿e czyœci
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
 student a = student("Kowalski");    // pierwszy sposób deklaracji i inicjalizacji obiektu przy u¿yciu konstruktora
 cout<<"Liczba studentow: "<<student::podajLiczbeEgzemplarzy()<<endl;
 student b("Nowakowski");          // drugi sposób
 cout<<"Liczba studentow: "<<student::podajLiczbeEgzemplarzy()<<endl;

 a.przypiszOcene(4.5);
 
 a.wypisz();
 b.wypisz();
 
 // czas ¿ycia obiektu ograniczaj¹ nawiasy klamrowe
 {
   student a("Iksinski");            // zas³anianie nazwy
   a.wypisz();
   a.przypiszOcene(3.0);
   cout<<"Liczba studentow: "<<student::podajLiczbeEgzemplarzy()<<endl;
 }
 
 a.wypisz();

 cout<<"Liczba studentow: "<<student::podajLiczbeEgzemplarzy()<<endl;

// system("pause"); 
 return 0;
}
