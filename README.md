# cpp-intro

Moje dawne notatki z C++, powstałe z fascynacji *Symfonią C++* Jerzego Grębosza (sprzed ponad 15 lat).

Moje dawne spojrzenie na podstawy podstaw programowania w C++.

## Zawartość

Repozytorium zawiera krótkie, samodzielne przykłady ilustrujące podstawowe zagadnienia języka C++:

- struktura programu, typy i zakres zmiennych
- instrukcje sterujące i funkcje
- wskaźniki, tablice i napisy
- macierze i operacje na tablicach
- klasy, enkapsulacja, konstruktory i destruktory
- dziedziczenie i polimorfizm
- tablice obiektów i proste sortowanie

Każdy plik jest osobnym przykładem możliwym do kompilacji niezależnie od pozostałych.

## Kompilacja i uruchomienie

Wariant podstawowy:

```bash
g++ 01-hello.cpp
```

Uruchomienie:
- Unix / macOS: `./a.out`
- Windows: `a.exe`

Wariant z flagami:

```bash
g++ -std=c++17 -O2 -Wall -Wextra 01-hello.cpp -o 01-hello
```
Uruchomienie:
- Unix / macOS: `./01-hello`
- Windows: `01-hello.exe`
