#include "Data.h"
#include <iostream>
using namespace std;

int main()
{
	Data data1;
	data1.llegeix();

	Data data2;
	data2.llegeix();

	if (data1 < data2)
	{
		cout << "data 1 MENOR que data2" << endl << endl;
	}
	else
	{
		cout << "data1 MAJOR que data2" << endl << endl;
	}

	return 0;
}