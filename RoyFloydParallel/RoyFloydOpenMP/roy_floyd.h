#ifndef __HEADER_H__
#define __HEADER_H__

#include <stdio.h>
#include <conio.h>
#include <iostream>

#define Infinit 90000

using namespace std;

void initial_cost(int*& cost, int& n, int& m, int file_index);

void roy_floyd(int* matrix, int size);

#endif;