#pragma once

#include <time.h>
#include <iostream>
using namespace std;

class DynamicCollatz
{
private:
	bool isDynamic;
	int SIZE;
	int * counts;
	int CollatzConjecture(int);
	int DynCollatzConjecture(int);
	int StnCollatzConjecture(int);
public:
	DynamicCollatz(int, bool);
	~DynamicCollatz(void);
	void CollatzConjecture();
	void printTop10();
};

