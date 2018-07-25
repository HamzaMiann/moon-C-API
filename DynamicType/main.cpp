

#include <iostream>
#include <string>
#include "moon.h"


using namespace std;
using namespace moon;


int main() {

	dynamic a;

	a = 10;
	cout << a.cast<int>() << endl;

	a = "hello";
	cout << a.cast<const char*>() << endl;
	cout << a.size_bytes() << endl;

	a = 12.35f;

	cout << a.cast<float>() << endl;

	a = a * 5.f;

	cout << a.cast<float>() << endl;
	cout << a.size_bytes() << endl;

}