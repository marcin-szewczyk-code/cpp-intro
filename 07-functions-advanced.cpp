#include <iostream>
using namespace std;

double pole(double r) {
 double p;
 if (r < 0) {
	cout<<"UWAGA - wpisano r < 0"<<endl;
	p = 0;
 } else {
	p = 3.14*r*r;
 }
 return p;
}

int wypisz(double a, double b) {
 cout<<"Pole okregu o promieniu "<<a<<" wynosi "<<b<<endl;
 return 0;
}

int main()
{

 double r, p;

 for (; 1; ) {
	cout<<"Podaj promien (0 - koniec programu): ";
	cin>>r;
	if (r == 0) {
		cout<<"Podales 0, a wiec koniec programu."<<endl;
		break;
	} else {
		p = pole(r);
		wypisz(r, p);
	}
 }

 return 0;
}


