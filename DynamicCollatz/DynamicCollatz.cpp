#include "DynamicCollatz.h"


DynamicCollatz::DynamicCollatz(int size, bool isDyn)
{
	isDynamic = isDyn;
	SIZE = size;
	counts = new int[size];
}


DynamicCollatz::~DynamicCollatz(void)
{
}


void DynamicCollatz::CollatzConjecture()
{
	if(isDynamic)
	{
		for(int i = 1; i <= SIZE;i++)
		{
			DynCollatzConjecture(i);
		}
	}
	else
	{
		for(int i = 1; i <= SIZE;i++)
		{
			StnCollatzConjecture(i);
		}
	}
}

int DynamicCollatz::StnCollatzConjecture(int n)
{
	int currNum = n;
	int count = 0;
	while (n > 1)
	{
		if(n % 2 == 1)
		{
			n = 3*n+1;
		}
		else
		{
			n = n/2;
		}
		count++; 
	}
	counts[currNum] = count;
	return count;
}


int DynamicCollatz::DynCollatzConjecture(int n)
{
	int currNum = n;
	int count = 0;
	while (n > 1)
	{
		if (n >= currNum)
		{
			if(n % 2 == 1)
			{
				n = 3*n+1;
			}
			else
			{
				n = n/2;
			}
			count++; 
		}
		else
		{
			count+=counts[n];
			n = 1;
		}
	}
	counts[currNum] = count;
	return count;
}

void DynamicCollatz::printTop10()
{
	for(int i = SIZE; i >= SIZE - 100 ;i--)
	{
		cout << "num " << i << " took " << counts[i] << " cycles " << endl;
	}
}


double diffclock(clock_t clock1,clock_t clock2)
{
	double diffticks=clock1-clock2;
	double diffms=(diffticks*10)/CLOCKS_PER_SEC;
	return diffms;
}

int main()
{
	clock_t begin1=clock();
	DynamicCollatz dc1(1000000, false);
	dc1.CollatzConjecture();
	clock_t end1=clock();
	cout << "isDynamic == false" << endl;
	cout << "Time elapsed: " << double(diffclock(end1,begin1)) << " ms"<< endl << endl;

	clock_t begin2=clock();
	DynamicCollatz dc2(1000000, true);
	dc2.CollatzConjecture();
	clock_t end2=clock();
	cout << "isDynamic == true" << endl;
	cout << "Time elapsed: " << double(diffclock(end2,begin2)) << " ms"<< endl << endl;




	return 0;
};