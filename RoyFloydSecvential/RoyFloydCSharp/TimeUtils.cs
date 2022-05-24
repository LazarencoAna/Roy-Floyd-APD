using System.Diagnostics;

namespace RoyFloydV2
{
    public static class TimeUtils
	{
		public static long GetMicroseconds()
		{
			double timestamp = Stopwatch.GetTimestamp();
			double microseconds = 1_000_000.0 * timestamp / Stopwatch.Frequency;

			return (long)microseconds;
		}
	}
}