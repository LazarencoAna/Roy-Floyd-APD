#include "Floyd.h"
#include <iostream>

using namespace std;

void Roy_Floyd(int* mat, int N, int* matrix, int* result, int nr_of_rocess, int rank)
{
	int rows_for_process = N / nr_of_rocess;

	MPI_Scatter(mat, N * rows_for_process, MPI_INT, matrix, N * rows_for_process, MPI_INT, 0, MPI_COMM_WORLD);

	int newSumPath;

	int* row_k = (int*)malloc(sizeof(int) * N); 

	for (int k = 0; k < N; ++k)
	{
		if (rank == k / rows_for_process)
			memcpy(row_k, matrix + (k % rows_for_process) * N, sizeof(int) * N);

		//sync row k
		MPI_Bcast(row_k, N, MPI_INT, k / rows_for_process, MPI_COMM_WORLD);

		for ( int i = 0; i < rows_for_process; ++i)
		{
			for (int j = 0; j < N; ++j)
			{
				newSumPath = matrix[i * N + k] + row_k[j];
				if (matrix[i * N + j] > newSumPath)
					matrix[i * N + j] = newSumPath;
			}
		}
	}

	//get result matrix
	MPI_Gather(matrix, N * rows_for_process, MPI_INT, result, N * rows_for_process, MPI_INT, 0, MPI_COMM_WORLD);

}


int* GenMatrix(int* size, const int file_index)
{
	int i, x, y, c, m, n;
	fstream myfile;

	try {

		//open file
		myfile.open(("..//input//" + to_string(file_index) + ".txt"), ios::in);

		if (!myfile.is_open())
		{
			throw new exception("Error opening file! ");
		}

		myfile >> *size;
		myfile >> m;

		n = (int)*size;
		int* mat = new  int[n * n];

		fill_n(mat, n * n, Infinit);

		for (i = 0; i < n; i++)
		{
			mat[i * n + i] = 0;
		}

		for (i = 0; i < m; i++)
		{
			myfile >> x >> y >> c;
			mat[(x - 1) * n + (y - 1)] = c;
		}

		myfile.close();
		return mat;
	}
	catch (exception e) {
		throw e;
	}
}
