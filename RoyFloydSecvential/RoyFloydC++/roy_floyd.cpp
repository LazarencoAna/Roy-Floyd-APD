#include "roy_floyd.h"

#include <stdio.h>
#include <conio.h>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void initial_cost(vector<vector<int>>& cost, int& n, int& m, int file_index)
{
	int i, j, x, y, c;
	fstream myfile;
	try {

		//open file
		myfile.open(("..//input//"+to_string(file_index) + ".txt"), ios::in);

		if (!myfile.is_open())
		{
			throw new exception("Error opening file! ");
		}

		myfile >> n;
		myfile >> m;

		cost = vector<vector<int>>(n, vector<int>(n, Infinit));

		for (i = 0; i < n; i++)
		{
			cost[i][i] = 0;
		}

		for (i = 0; i < m; i++)
		{
			myfile >> x >> y >> c;
			cost[x - 1][y - 1] = c;
		}

		myfile.close();
	}
	catch (exception e) {
		throw e;
	}

}


void display_matrix(vector<vector<int>> cost, int n)
{
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			if (cost[i][j] == Infinit)
				printf("   -");
			else
				printf("%4d", cost[i][j]);
		printf("\n");
	}
}


void roy_floyd(vector<vector<int>>& cost, int n)
{
	for (int k = 0; k < n; k++)
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				if (cost[i][j] > cost[i][k] + cost[k][j])
					cost[i][j] = cost[i][k] + cost[k][j];
}

void roy_floyd_array(int**cost, int n)

{
	for (int k = 0; k < n; k++)
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				if (cost[i][j] > cost[i][k] + cost[k][j])
					cost[i][j] = cost[i][k] + cost[k][j];
}


int** vector_to_array(vector<vector<int>>& cost) {
	int n =cost.size();

	auto cos = new  int* [n];

	for (int i = 0; i < n; i++) {
		cos[i] = new int[n];
		for (int j = 0; j < n; j++)
		{
			cos[i][j] = cost[i][j];
		}
	}

	return cos;
}


void print_path(int first, int last, vector<vector<int>>& cost, int n)
{
	if (cost[first][last] < Infinit)
	{
		printf("\n The path from %d to %d has the weight %d", first, last, cost[first][last]);
		printf("\n The minimum cost path is: %d  ", first);
		compute_path(first, last, n, cost);
	}
	else
		printf("\n There is no path between %d to %d", first, last);
}


void compute_path(int i, int j, int n, vector<vector<int>>& cost)
{
	int ok = 0, k = 0;

	while (k < n && !ok)
	{
		if (i != k && j != k)
			if (cost[i][j] == cost[i][k] + cost[k][j])
			{
				compute_path(i, k, n, cost);
				compute_path(k, j, n, cost);
				ok = 1;
			}
		k++;
	}
	if (!ok)
	{
		printf("%d   ", j);
	}
}

