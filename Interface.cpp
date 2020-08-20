#include "MyRational.h"
#include <cstdlib>
#include <string>
#include <iostream>
#include <fstream>

int Winmain() {
	fstream storage;
	storage.open("storage.bin");
	MyRational rational(2,5);
	rational.simplify();
	;
	storage.close();

	return 0;
}