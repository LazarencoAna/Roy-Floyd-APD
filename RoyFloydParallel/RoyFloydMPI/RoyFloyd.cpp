#include <stdio.h>
#include <chrono>

#include "Floyd.h"

#define NUMBER_OF_TESTS 24

using namespace std;
using namespace std::chrono;

int main(int argc, char** argv)
{
	int nr_of_rocess, rank;
	chrono::steady_clock::time_point start, stop;

	MPI_Init(&argc, &argv);

	MPI_Comm_size(MPI_COMM_WORLD, &nr_of_rocess);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);

	for (int i = 1; i < NUMBER_OF_TESTS; i++)
	{
		int* mat, * result, * matrix;
		int N=0;

		mat = (int*)malloc(sizeof(int) * 1);
		result = (int*)malloc(sizeof(int) * 1);

		if (rank == 0)
		{
			// read matrix from file
			mat = GenMatrix( &N, i);

			// result
			result = (int*)malloc(sizeof(int) * N * N);
		}

		// N 
		MPI_Bcast(&N, 1, MPI_INT, 0, MPI_COMM_WORLD);

		if (rank != 0) {
			mat = (int*) malloc(sizeof(int) * N * N);
		}

		matrix = (int*)malloc(sizeof(int) * N * (N / nr_of_rocess));

		// sync process
		MPI_Barrier(MPI_COMM_WORLD);

		if (rank == 0) {
			start = high_resolution_clock::now();
		}

		// run the parallel implementation
		Roy_Floyd(mat, N, matrix, result, nr_of_rocess, rank);

		if (rank == 0)
		{
			stop = high_resolution_clock::now();

			auto duration = duration_cast<microseconds>(stop - start);
			cout << "N: " << N << endl;

			cout << "\t Duration: " << duration.count() << " microseconds ~ " << duration.count() / 1000 << " milliseconds ~ " << duration.count() / 1000000 << " seconds " << endl;	
		}
		free(mat);
		free(result);
		free(matrix); 
		MPI_Barrier(MPI_COMM_WORLD);
	}

	MPI_Finalize();
}

