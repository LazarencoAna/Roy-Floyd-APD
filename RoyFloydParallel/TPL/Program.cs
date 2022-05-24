using System;

namespace TPL
{
    public class Program
    {
        private static readonly int NUMBER_OF_TESTS = 24;
        static void Main(string[] args)
        {
            var start = TimeUtils.GetMicroseconds();
            var end = TimeUtils.GetMicroseconds();

            for (int i = 1; i < NUMBER_OF_TESTS; i++)
            {
                var matrix = DataUtils.ReadData(i);

                Console.WriteLine(" N = " + matrix.Length);

                RunRoyFloyd(i, "task", matrix, RoyFloyd.RoyFloydTask);

                RunRoyFloyd(i, "task2", matrix, RoyFloyd.RoyFloydTask2);

                RunRoyFloyd(i, "secq", matrix, RoyFloyd.RoyFloydSequentially);

                RunRoyFloyd(i, "forP", matrix, RoyFloyd.RoyFloydParallelFor);

                RunRoyFloyd(i, "2forP", matrix, RoyFloyd.RoyFloyd2ParallelFor);


            }
            Console.Read();
        }
        static void RunRoyFloyd(int fileIndex, string type, int[][] matrix, Action action)
        {

            RoyFloyd.Matrix = new int[matrix.Length][];
            Array.Copy(matrix, 0, RoyFloyd.Matrix, 0, matrix.Length);

            var start = TimeUtils.GetMicroseconds();

            action();

            var end = TimeUtils.GetMicroseconds();

            var duration = end - start;

            DataUtils.WriteMatrixInFile(fileIndex, type, RoyFloyd.Matrix, RoyFloyd.Matrix.Length);

            Console.WriteLine(" \t Time taken by function " + type + " : " + duration + " microseconds ~ " + (duration / 1000) + " milliseconds ~ " + (duration / 1000000) + " seconds ");

        }
    }
}