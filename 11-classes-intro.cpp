#include <iostream>
#include <string.h>
#include <stdlib.h>
using namespace std;

/*
  Klasy

  0. Typy w C++:
     - podstawowe (fundamentalne), np. int, float, double, char
     - pochodne, np. wskaźniki (int*, float*, char*) oraz tablice (np. char ch[10])
     - definiowane przez użytkownika, np. klasy

  1. Klasa to typ definiowany przez użytkownika. Obiekt to zmienna (egzemplarz) danej klasy.

  2. Klasa może zawierać:
     - dane składowe (pola)
     - funkcje składowe (metody)
     Jest to przykład enkapsulacji (zamknięcia danych i funkcji w jednym typie).

  3. Dostęp do składników klasy kontrolują etykiety: public, protected, private.

  4. Dostęp do pól i metod odbywa się na rzecz konkretnego obiektu:
     - obiekt.pole oraz obiekt.metoda()
     - wskaźnik->pole oraz wskaźnik->metoda()

  5. Z obiektów klas korzysta się podobnie jak z typów podstawowych: można je deklarować,
     przekazywać do funkcji i tworzyć tablice obiektów.
*/

// definicja klasy
class student {
 // enkapsulacja: definicja klasy zawiera dane składowe (pola) oraz funkcje
 // składowe (metody) - są to składniki klasy
 // dostęp do składników klasy określany przy użyciu etykiet: private, protected, public.
 private:     // składniki prywatne, dostępne wewnątrz definicji klasy
 int skladnik_probny;

 public:
 char nazwisko[40];
 float ocena;

 public:      // składniki publiczne, dostępne spoza definicji klasy
 void zapamietaj(char* napis, float f) {
      // funkcje składowe mają pełny dostęp do wszystkich składników klasy
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
 // powtórzenie wiadomości o typach
 // deklaracja zmienej o nazwie i typu int:
 int i; // i jest zmienną typu int, inaczej: egzemplarzem klasy int, inaczej: obiektem klasy int
 // inicjalizacja zmiennej i, czyli przypisanie wartości do zmiennej i
 i = 15;
 // definicja to deklaracja + przypisanie wartości:
 int j = 12;
 
 // deklaracja obiektów klasy student
 student a;      // a jest egzemplarzem klasy student, inaczej: obiektem klasy student
 student b;      // b jest egzemplarzem klasy student, inaczej: obiektem klasy student

 // posługiwanie się składnikami klasy
 // dostęp do danych składowych lub wywołanie funkcji składowych odbywa się
 // na rzecz obiektu danej klasy, przy użyciu składni:
 // obiekt.pole; obiekt.funkcja(argumenty);
 // wskaznik->pole; wskaznik->funkcja(argumenty);

 //a.skladnik_probny = 2.3;  // błąd! - ten składnik jest prywatny
 
 a.zapamietaj("Kowalski", 4.5);
 b.zapamietaj("Nowakowski", 5);
 
 a.wypisz();
 b.wypisz();

 cout<<endl;

 // rozmiar obiektu a:
 cout<<"Rozmiar obiektu a: "<<sizeof(a)<<" bajty"<<endl;
 // zatem warto posługiwać się wskaźnikami
 student *pa, *pb;
 pa = &a;
 pa->wypisz();	// wywołanie funkcji wypisz na rzecz obiektu, na który wskazuje wskaźnik pa
 pb = &b;
 cout<<"Rozmiar wskaznika pa: "<<sizeof(pa)<<" bajty"<<endl<<endl;


 cout<<"POROWNANIE: "<<a.nazwisko;
 if (porownaj(pa, pb) > 1) {
	cout<<" ma lepszy wynik od ";
 } else if (porownaj(pa, pb) < 1) {
	cout<<" ma gorszy wynik od ";
 } else {
	cout<<" ma taki sam wynik jak ";
 }
 cout<<b.nazwisko<<endl<<endl;

 // deklaruję nowy obiekt klasy student:
 student c;
 //c.wypisz();  // uwaga! - wyświetli się coś przypadkowego - to nas prowadzi do konstruktorów

 //tablica obiektów typu student
 c.zapamietaj("Iksi�ski", 3);
 student tab[3] = {a, b, c};

 cout<<"Wypisz tablice obiektow typu student:"<<endl;
 wypisz(tab, 3);

// system("pause");
 return 0;
}
