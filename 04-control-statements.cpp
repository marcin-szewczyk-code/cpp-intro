#include <iostream>
using namespace std;

/*
	Instrukcje sterujące: warunkowe (`if`, `switch`) oraz pętle (`for`, `while`, `do-while`).
*/

int main()
{
 double r;
 cout<<"Podaj promien: ";
 cin>>r;

 if (r < 0) {
	cout<<"Hej! - promien nie moze byc ujemny!"<<endl;
 } else {
	double p;
	p = 3.14*r*r;
	cout<<"Pole okregu o promieniu "<<r<<" wynosi "<<p<<endl;
 }


 cout<<"Wpisz 1 aby wypisac petle: ";
 int i;
 cin>>i;

 if (i == 1) {
	cout<<"Oto petla:"<<endl;
	for (int j = 0; j < 10; j++) {
		cout<<"j = "<<j<<endl;
	}
 } else {
	cout<<"Bez petli"<<endl;
 }


 return 0;
}


