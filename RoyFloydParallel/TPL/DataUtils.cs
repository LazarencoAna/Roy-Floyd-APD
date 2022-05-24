using System;
using System.IO;

namespace TPL
{
    public class DataUtils
    {
        public static readonly int INFINIT = 900000;

        public static int[][] ReadData(int fileIndex)
        {
            int i, j, x, y, c;

            try
            {
                var fileName = System.IO.Path.GetFullPath("..\\..\\input\\" + fileIndex.ToString() + ".txt");

                if (!File.Exists(fileName))
                {
                    throw new Exception("File dosen`t exist");
                }

                var matrix = new int[1][];

                using (TextReader reader = File.OpenText(fileName))
                {
                    string text = reader.ReadLine();
                    string[] bits = text.Split(' ');
                    var n = int.Parse(bits[0]);
                    var m = int.Parse(bits[1]);

                    if (n <= 0 || m <= 0)
                    {
                        throw new Exception("Invalid data");
                    }
                    matrix = new int[n][];
                    for (i = 0; i < n; i++)
                    {
                        matrix[i] = new int[n];
                    }
                    for (i = 0; i < n; i++)
                    {
                        for (j = 0; j < n; j++)
                        {
                            matrix[i][j] = i != j ? INFINIT : 0;
                        }
                    }

                    for (i = 0; i < m; i++)
                    {
                        text = reader.ReadLine();
                        bits = text.Split(' ');
                        x = int.Parse(bits[0]);
                        y = int.Parse(bits[1]);
                        c = int.Parse(bits[2]);

                        matrix[x - 1][y - 1] = c;
                    }
                }

                return matrix;
            }
            catch (Exception e)
            {
                throw e;
            }
        }
        public static void WriteMatrixInFile(int fileIndex, string type, int[][] matrix, int n)
        {
            int i, j;
            try
            {
                var fileName = Path.GetFullPath("..\\..\\output\\" + fileIndex.ToString() + type + ".txt");

                if (File.Exists(fileName))
                {
                    File.Delete(fileName);
                }

                using (StreamWriter sw = File.CreateText(fileName))
                {
                    for (i = 0; i < n; i++)
                    {
                        for (j = 0; j < n; j++)
                        {
                            sw.Write("{0}\t", matrix[i][j] == INFINIT ? '~' : matrix[i][j]);
                        }
                        sw.WriteLine("  ");
                    }
                }
            }
            catch (Exception e)
            {
                throw e;
            }
        }

        public static void PrintMatrix(int[][] _matrix, int n)
        {
            Console.WriteLine(" matrix : ");
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    Console.Write(_matrix[i][j] + "  ");
                }
                Console.WriteLine("  ");
            }
        }
    }
}
