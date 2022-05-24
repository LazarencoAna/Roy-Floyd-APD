namespace RoyFloydV2
{
    public static class RoyFloyd
    {
        public static readonly long INFINIT = 900000;

        private static List<List<long>>? _matrix;
        private static long[][]? _arrayMatrix;

        public static void ReadData(int fileIndex)
        {
            int i, j, x, y, c;
            try
            {
                var fileName = System.IO.Path.GetFullPath("..\\..\\..\\..\\input\\" + fileIndex.ToString() + ".txt");

                if (!File.Exists(fileName))
                {
                    throw new Exception("File dosen`t exist");
                }

                _matrix = new List<List<long>>();

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


                    for (i = 0; i < n; i++)
                    {
                        _matrix.Add(new List<long>(new long[n]));
                    }
                    for (i = 0; i < n; i++)
                    {
                        for (j = 0; j < n; j++)
                        {
                            _matrix[i][j] = i != j ? INFINIT : 0;
                        }
                    }

                    for (i = 0; i < m; i++)
                    {
                        text = reader.ReadLine();
                        bits = text.Split(' ');
                        x = int.Parse(bits[0]);
                        y = int.Parse(bits[1]);
                        c = int.Parse(bits[2]);

                        _matrix[x - 1][y - 1] = c;
                    }
                }
                _arrayMatrix = new long[_matrix.Count][];

                for (i = 0; i < _matrix.Count; i++)
                {
                    _arrayMatrix[i] = new long[_matrix.Count];
                    for (j = 0; j < _matrix.Count; j++)
                    {
                        _arrayMatrix[i][j] = _matrix[i][j];
                    }
                }
            }
            catch (Exception)
            {
                throw;
            }
        }

        public static void RoyFloydList()
        {
            var n = _matrix.Count();
            for (int k = 0; k < n; k++)
            {
                for (int i = 0; i < n; i++)
                {
                    for (int j = 0; j < n; j++)
                    {
                        if (_matrix[i][j] > _matrix[i][k] + _matrix[k][j])
                        {
                            _matrix[i][j] = _matrix[i][k] + _matrix[k][j];
                        }
                    }
                }
            }
        }


        public static void RoyFloydArray()
        {
            var n = _matrix?.Count();
            for (int k = 0; k < n; k++)
            {
                for (int i = 0; i < n; i++)
                {
                    for (int j = 0; j < n; j++)
                    {
                        if (_arrayMatrix[i][j] > _arrayMatrix[i][k] + _arrayMatrix[k][j])
                        {
                            _arrayMatrix[i][j] = _arrayMatrix[i][k] + _arrayMatrix[k][j];
                        }
                    }
                }
            }
        }

        public static int GetGraphSize()
        {
            return _matrix.Count();
        }
    }
}
