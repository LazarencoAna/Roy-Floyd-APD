#include <stdio.h>
#include <conio.h>
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>
#include <chrono>
#include "roy_floyd.h"

#define NUMBER_OF_TESTS 24

using namespace std;
using namespace std::chrono;

int main()
{
	char ch;
	int x, y, n, m;
	vector< vector<int>> vector_matrix;

	try {

		for (int i = 1; i < NUMBER_OF_TESTS; i++)
		{
			initial_cost(vector_matrix, n, m, i);
			int** array_matrix = vector_to_array(vector_matrix);

			cout << "N = " << n << " M = " << m << endl;

			auto start = high_resolution_clock::now();
			roy_floyd(vector_matrix, n);
			auto end = high_resolution_clock::now();
			auto duration = duration_cast<microseconds>(end - start);
			cout << "\t vector: " << duration.count() << " microseconds ~ " << duration.count() / 1000 << " milliseconds ~ " << duration.count() / 1000000 << " seconds " << endl;

			start = high_resolution_clock::now();
			roy_floyd_array(array_matrix, n);
			end = high_resolution_clock::now();
			duration = duration_cast<microseconds>(end - start);
			cout << "\t array: " << duration.count() << " microseconds ~ " << duration.count() / 1000 << " milliseconds ~ " << duration.count() / 1000000 << " seconds " << endl;


			vector_matrix.clear();
			free(array_matrix);
		}
		_getch();
	}
	catch (exception e)
	{
		throw e;
	}

	return 0;
}
