#include "roy_floyd.h"

#include <stdio.h>
#include <conio.h>
#include <iostream>
#include <fstream>
#include <string>
#include <omp.h>

using namespace std;

void initial_cost(int*& cost, int& n, int& m, int file_index)
{
	int i, j, x, y, c;
	fstream myfile;
	try {

		//open file
		myfile.open("..//input//" + (to_string(file_index) + ".txt"), ios::in);

		if (!myfile.is_open())
		{
			throw new exception("Error opening file! ");
		}

		myfile >> n;
		myfile >> m;

		cost = new int[n * n];

		for (i = 0; i < n * n; i++)
		{
			cost[i] = Infinit;
		}

		for (i = 0; i < n; i++)
		{
			cost[i * n + i] = 0;
		}

		for (i = 0; i < m; i++)
		{
			myfile >> x >> y >> c;
			cost[(x - 1) * n + y - 1] = c;
		}

		myfile.close();
	}
	catch (exception e) {
		throw e;
	}

}

void roy_floyd(int* matrix, int size)
{
	int* row_k = (int*)malloc(sizeof(int) * size);
#pragma omp parallel
	for (int k = 0; k < size; k++) {
#pragma omp master
		memcpy(row_k, matrix + (k * size), sizeof(int) * size);
#pragma omp for schedule(static)
		for (int i = 0; i < size; ++i) {
			for (int j = 0; j < size; ++j) {
				if (matrix[i * size + k] != -1 && row_k[j] != -1) {
					int new_path = matrix[i * size + k] + row_k[j];
					if (new_path < matrix[i * size + j] || matrix[i * size + j] == -1)
						matrix[i * size + j] = new_path;
				}
			}
		}
	}
}