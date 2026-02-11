#include <iostream>
#include <string.h>
#include <stdlib.h>
using namespace std;

/*
  0. Typy:
     - podstawowe (inaczej fundamentalne), np. int, float, double, char
     - pochodne, np. wskaŸniki: int*, float*, char*; tablice: char ch[10]
     - definiowane przez uzytkownika: KLASY
  1. Klasy to typy definiowane przez u¿ytkownika.
  2. Programowanie przy u¿yciu klas pozwala na tworzenie programów, które s¹
     odzwierciedleniem rzeczywistoœci - ka¿demu rzeczywistemu obiektowi
     przyporz¹dkowany jest obiekt klasy zdefiniowanej przez u¿ytkownika.
  3. Definicja klasy zawiera sk³adniki klasy: dane sk³adowe (pola) i funkcje
     sk³adowe (metody) - enkapsulacja
  4. Dostêp do sk³adników klasy mo¿e byæ ograniczony etykietami: public, protected, private.
  5. Dostêp do danych sk³adowych lub wywo³anie funkcji sk³adowej odbywa siê
     na rzecz konkretnego obiektu klasy (operatory . oraz ->).
  6. Pos³ugiwanie siê obiektami klas zdefiniowanych przez u¿ytkownika jest identyczne
     jak pos³ugiwanie siê obiektami typów fundamentalnych.
*/

// definicja klasy
class student {
 // enkapsulacja: definicja klasy zawiera dane sk³adowe (pola) oraz funkcje
 // sk³adowe (metody) - s¹ to sk³adniki klasy
 // dostêp do sk³adników klasy okreœlany przy u¿yciu etykiet: private, protected, public.
 private:     // sk³adniki prywatne, dostêpne wewn¹trz definicji klasy
 int skladnik_probny;

 public:
 char nazwisko[40];
 float ocena;

 public:      // sk³adniki publiczne, dostêpne spoza definicji klasy
 void zapamietaj(char* napis, float f) {
      // funkcje sk³adowe maj¹ pe³ny dostêp do wszystkich sk³adników klasy
      strcpy(nazwisko, napis);
      if (f < 2) f = 2;
      else if (f > 5) f = 5;
      ocena = f;
 }

 void wypisz() {
      cout<<nazwisko<<"\t"<<ocena<<endl;
 }
};

 void wypisz(student* s, int rozmiar) {
	for (int i = 0; i < rozmiar; i++) {
		s[i].wypisz();
	}
 }

int porownaj(student* s1, student* s2) {
 if (s1->ocena > s2->ocena) {
	return 1;
 } else if (s1->ocena < s2->ocena) {
 	return -1;
 } else {
	return 0;
 }
}

int main() {
 // powtórzenie wiadomoœci o typach
 // deklaracja zmienej o nazwie i typu int:
 int i; // i jest zmienn¹ typu int, inaczej: egzemplarzem klasy int, inaczej: obiektem klasy int
 // inicjalizacja zmiennej i, czyli przypisanie wartoœci do zmiennej i
 i = 15;
 // definicja to deklaracja + przypisanie wartoœci:
 int j = 12;
 
 // deklaracja obiektów klasy student
 student a;      // a jest egzemplarzem klasy student, inaczej: obiektem klasy student
 student b;      // b jest egzemplarzem klasy student, inaczej: obiektem klasy student

 // pos³ugiwanie siê sk³adnikami klasy
 // dostêp do danych sk³adowych lub wywo³anie funkcji sk³adowych odbywa siê
 // na rzecz obiektu danej klasy, przy u¿yciu sk³adni:
 // obiekt.pole; obiekt.funkcja(argumenty);
 // wskaznik->pole; wskaznik->funkcja(argumenty);

 //a.skladnik_probny = 2.3;  // b³¹d! - ten sk³adnik jest prywatny
 
 a.zapamietaj("Kowalski", 4.5);
 b.zapamietaj("Nowakowski", 5);
 
 a.wypisz();
 b.wypisz();

 cout<<endl;

 // rozmiar obiektu a:
 cout<<"Rozmiar obiektu a: "<<sizeof(a)<<" bajty"<<endl;
 // zatem warto pos³ugiwaæ siê wskaŸnikami
 student *pa, *pb;
 pa = &a;
 pa->wypisz();	// wywo³anie funkcji wypisz na rzecz obiektu, na który wskazuje wska¼nik pa
 pb = &b;
 cout<<"Rozmiar wska¼nika pa: "<<sizeof(pa)<<" bajty"<<endl<<endl;


 cout<<"PORÓWNANIE: "<<a.nazwisko;
 if (porownaj(pa, pb) > 1) {
	cout<<" ma lepszy wynik od ";
 } else if (porownaj(pa, pb) < 1) {
	cout<<" ma gorszy wynik od ";
 } else {
	cout<<" ma taki sam wynik jak ";
 }
 cout<<b.nazwisko<<endl<<endl;

 // deklarujê nowy obiekt klasy student:
 student c;
 //c.wypisz();  // uwaga! - wyœwietli siê c¶œ przypadkowego - to nas prowadzi do konstruktorów

 //tablica obiektów typu student
 c.zapamietaj("Iksiñski", 3);
 student tab[3] = {a, b, c};

 cout<<"Wypisz tablicê obiektów typu student:"<<endl;
 wypisz(tab, 3);

// system("pause");    
 return 0;
}
