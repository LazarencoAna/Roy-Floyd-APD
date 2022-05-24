namespace TPL
{
    public class RoyFloydTask
    {
        public int[][] Matrix = new int[1][];
        public int[] RowK = new int[1];

        public int NumberOfRows;
        public int TaskIndex;
        public int N;
        public volatile int K = 0;

        public void RoyFloyd()
        {
            for (int i = 0; i < NumberOfRows; i++)
            {
                for (int j = 0; j < N; j++)
                {
                    if (Matrix[i][j] > Matrix[i][K] + RowK[j])
                    {
                        Matrix[i][j] = Matrix[i][K] + RowK[j];
                    }
                }
            }
            K++;
        }
        public void RoyFloyd1()
        {
            for (int i = 0; i < NumberOfRows; i++)
            {
                var newI = i + TaskIndex * NumberOfRows;
                for (int j = 0; j < N; j++)
                {
                    if (Matrix[newI][j] > Matrix[newI][K] + Matrix[K][j])
                    {
                        Matrix[newI][j] = Matrix[newI][K] + Matrix[K][j];
                    }
                }
            }
            K++;
        }
    }
}
