using System;

namespace csharp_test
{
	class Program
	{
		static void Main(string[] args)
		{
			int a = 1;
			int b = ++a * 10;
			int c = a++ * 10;
			Console.WriteLine("a : " + a);
			Console.WriteLine("b : " + b);
			Console.WriteLine("c : " + c);

			int? bob = 1;
			int? joe = null;
			Console.WriteLine("{0}", bob ?? joe);
		}
	}
}
