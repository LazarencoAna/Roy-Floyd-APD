#ifndef __HEADER_H__
#define __HEADER_H__

#include <stdio.h>
#include <conio.h>
#include <iostream>
#include <vector>

#define Infinit 90000

using namespace std;

void initial_cost(vector<vector<int>> &cost, int& n, int& m, int file_index);

void display_matrix(vector<vector<int>> cost, int n);

void roy_floyd(vector<vector<int>>& cost, int n);

void roy_floyd_array(int** cost, int n);

void roy_floyd_parallel(int** cost, int n);

void print_path(int first, int last, vector<vector<int>>& cost, int n);

void compute_path(int node1, int node2, int n, vector<vector<int>>& cost);

int** vector_to_array(vector<vector<int>>& cost);

#endif;
