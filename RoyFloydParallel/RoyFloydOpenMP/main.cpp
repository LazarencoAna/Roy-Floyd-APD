#include <stdio.h>
#include <conio.h>
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <chrono>

#include "roy_floyd.h"

#define NUMBER_OF_TESTS 24

using namespace std;
using namespace std::chrono;

int main(int argc, char** argv)
{
	int x, y, n, m;
	int* matrix;

	try {
		for (int i = 1; i < NUMBER_OF_TESTS; i++)
		{
			matrix = new int[1];
			initial_cost(matrix, n, m, i);

			cout << "N = " << n << " M = " << m << endl;

			auto start = high_resolution_clock::now();
			roy_floyd(matrix, n);
			auto end = high_resolution_clock::now();
			auto duration = duration_cast<microseconds>(end - start);

			cout << "\t OpenMP: " << duration.count() << " microseconds ~ " << duration.count() / 1000 << " milliseconds ~ " << duration.count() / 1000000 << " seconds " << endl;
			

		}
		_getch();
	}
	catch (exception e)
	{

	}

	return 0;
}
