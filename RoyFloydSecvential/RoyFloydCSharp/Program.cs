
using RoyFloydV2;

namespace Programs
{
    public static class Programs
    {
        public static readonly int NUMBER_OF_TESTS = 24;
        static public void Main(String[] args)
        {
            try
            {
                for (int i = 1; i < NUMBER_OF_TESTS; i++)
                {
                    RoyFloyd.ReadData(i);

                    Console.WriteLine(" N = " + RoyFloyd.GetGraphSize());

                    var start = TimeUtils.GetMicroseconds();
                    RoyFloyd.RoyFloydList();
                    var end = TimeUtils.GetMicroseconds();
                    var duration = end - start;
                    Console.WriteLine(" \t Time taken by function: (List) " + duration + " microseconds ~ " + (duration / 1000) + " milliseconds ~ " + (duration / 1000000) + " seconds ");

                    start = TimeUtils.GetMicroseconds();
                    RoyFloyd.RoyFloydArray();
                    end = TimeUtils.GetMicroseconds();
                    duration = end - start;
                    Console.WriteLine(" \t Time taken by function: (array) " + duration + " microseconds ~ " + (duration / 1000) + " milliseconds ~ " + (duration / 1000000) + " seconds ");

                }
            }
            catch (Exception e)
            {
                Console.WriteLine(e.Message);
            }
        }

    }
}


