using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;

namespace TPL
{
    public static class RoyFloyd
    {
        public static readonly int NUMBER_OF_TASK = 5;

        public static int[][] Matrix = new int[1][];
      
        public static void RoyFloyd2ParallelFor()
        {
            var n = Matrix.Count();
            for (int k = 0; k < n; k++)
            {
                Parallel.For(0, n,
                  i =>
                  {
                      Parallel.For(0, n,
                        j =>
                        {
                            if (Matrix[i][j] > Matrix[i][k] + Matrix[k][j])
                            {
                                Matrix[i][j] = Matrix[i][k] + Matrix[k][j];
                            }
                        });
                  });
            }
        }
        public static void RoyFloydParallelFor()
        {
            var n = Matrix.Count();
            for (int k = 0; k < n; k++)
            {
                Parallel.For(0, n,
                  i =>
                  {
                      for (int j = 0; j < n; j++)
                      {
                          if (Matrix[i][j] > Matrix[i][k] + Matrix[k][j])
                          {
                              Matrix[i][j] = Matrix[i][k] + Matrix[k][j];
                          }
                      }
                  });
            }
        }

        public static void RoyFloydTask()
        {
            var n = Matrix.Count();
            var royFloydTasks = new List<RoyFloydTask>();
            var numberOfRows = n / NUMBER_OF_TASK;

            for (int taskIndex = 0; taskIndex < NUMBER_OF_TASK; taskIndex++)
            {
                var taskMatrix = new int[numberOfRows][];
                    Array.Copy(Matrix, taskIndex * numberOfRows, taskMatrix, 0, numberOfRows);

                var royFloyd = new RoyFloydTask()
                {
                    TaskIndex = taskIndex,
                    Matrix = taskMatrix,
                    NumberOfRows = numberOfRows,
                    N = n,
                    RowK = Matrix[0],
                    K = 0,
                };
                royFloydTasks.Add(royFloyd);
            }


            for (int k = 0; k < n; k++)
            {
                var rowK = royFloydTasks[k / numberOfRows].Matrix[k % numberOfRows];
                List<Task> tasks = new List<Task>();

                for (int taskIndex = 0; taskIndex < NUMBER_OF_TASK; taskIndex++)
                {
                    royFloydTasks[taskIndex].RowK = rowK;
                    var royFloyd = royFloydTasks[taskIndex];
                    tasks.Add(Task.Factory.StartNew(() => royFloyd.RoyFloyd()));
                }

                Task.WaitAll(tasks.ToArray());
            }
        }
        public static void RoyFloydTask2()
        {
            var n = Matrix.Count();
            var royFloydTasks = new List<RoyFloydTask>();
            var numberOfRows = (int)n / NUMBER_OF_TASK;

            for (int taskIndex = 0; taskIndex < NUMBER_OF_TASK; taskIndex++)
            {
                var royFloyd = new RoyFloydTask()
                {
                    TaskIndex = taskIndex,
                    Matrix = Matrix,
                    NumberOfRows = numberOfRows,
                    N = n,
                    K=0,
                };
                royFloydTasks.Add(royFloyd);
            }


            for (int k = 0; k < n; k++)
            {
                List<Task> tasks = new List<Task>();

                for (int taskIndex = 0; taskIndex < NUMBER_OF_TASK; taskIndex++)
                {
                    var royFloyd = royFloydTasks[taskIndex];
                    tasks.Add(Task.Factory.StartNew(() => royFloyd.RoyFloyd1()));
                }

                Task.WaitAll(tasks.ToArray());
            }
        }

        public static void RoyFloydSequentially()
        {
            var n = Matrix.Count();
            for (int k = 0; k < n; k++)
            {
                for (int i = 0; i < n; i++)
                {
                    for (int j = 0; j < n; j++)
                    {
                        if (Matrix[i][j] > Matrix[i][k] + Matrix[k][j])
                        {
                            Matrix[i][j] = Matrix[i][k] + Matrix[k][j];
                        }
                    }
                }
            }
        }
        public static int GetGraphSize()
        {
            return Matrix.GetLength(0); 
        }
    }
}
