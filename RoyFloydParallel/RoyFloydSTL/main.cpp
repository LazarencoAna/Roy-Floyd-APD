#include <stdio.h>
#include <conio.h>
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>
#include <chrono>

#include "roy_floyd.h"

using namespace std;
using namespace std::chrono;

int main()

{
	char ch;
	int x, y, n, m;
	vector< vector<int>> cost;
	vector< vector<int>> matrice_in;

	try {
		for (int i = 1; i < 24; i++)
		{

			initial_cost(cost, n, m, i);

			matrice_in = cost;

			cout << "N = " << n << " M = " << m << endl;

			int** cos = vector_to_array(cost);

			auto start1 = high_resolution_clock::now();

			roy_floyd_array(cos, n);

			auto stop1 = high_resolution_clock::now();
			auto duration = duration_cast<microseconds>(stop1 - start1);

			cout << "\t seq: " << duration.count() << " microseconds ~ " << duration.count() / 1000 << " milliseconds ~ " << duration.count() / 1000000 << " seconds " << endl;


			cos = vector_to_array(cost);

			start1 = high_resolution_clock::now();

			roy_floyd_parallel(cos, n);

			stop1 = high_resolution_clock::now();
			duration = duration_cast<microseconds>(stop1 - start1);

			cout << "\t parallel: " << duration.count() << " microseconds ~ " << duration.count() / 1000 << " milliseconds ~ " << duration.count() / 1000000 << " seconds " << endl;

		}
		_getch();
	}
	catch (exception e)
	{

	}

	return 0;
}
