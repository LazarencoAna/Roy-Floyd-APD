#ifndef FLOYD
#define FLOYD

#include <mpi.h>
#include <stdlib.h>
#include <string>
#include <fstream>
#include <iostream>
#include <algorithm>

#define Infinit 90000

void Roy_Floyd(int* mat, int N, int* matrix, int* result, int process_count, int process_rank);

int* GenMatrix(int* n, const int file_index);

#endif // FLOYD
