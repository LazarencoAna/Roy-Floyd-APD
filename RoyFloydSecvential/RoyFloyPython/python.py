
from array import *
import numpy as np
import time
import os

INFINIT = 900000
NUMBER_OF_TESTS = 24


def printDoubleMatrix(double_matrix):
    for line in double_matrix:
        print (','.join(map(str, line)))
    print ('\n')

for indexFile in range(1,NUMBER_OF_TESTS):

    path = os.getcwd()
    path=os.path.abspath(os.path.join(path, os.pardir))
    with open(path+"/input/"+str(indexFile)+".txt") as textFile:
        matrix = [[int(numeric_string) for numeric_string in line.split()] for line in textFile]

    n = matrix[0][0];
    m = matrix[0][1];

    if n <= 0 or m <= 0:
        raise Exception("Invalid data")

    work_matrix = [[(0 if x==y else INFINIT) for x in range(n)] for y in range(n)]

    for i in range(m):
        x = matrix[i+1][0]
        y = matrix[i+1][1]
        c = matrix[i+1][2]
        work_matrix[x-1][y-1] = c

    start_time = time.time()

    for k in range(n):
        for i in range(n):
            for j in range(n):
                if work_matrix[i][j] > work_matrix[i][k] + work_matrix[k][j]:
                    work_matrix[i][j] =  work_matrix[i][k] + work_matrix[k][j]

    end_time = time.time()
        
    print("N=  %s " % n)
    print("Time taken by function:")
    print("--- %s seconds ---" % (end_time - start_time))
    print("--- %s millisecond ---" % ((end_time - start_time)*1000))