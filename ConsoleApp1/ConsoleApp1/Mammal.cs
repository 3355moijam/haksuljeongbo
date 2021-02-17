using System;
using System.Collections.Generic;
using System.Text;

namespace TypeCasting	
{
	class Mammal
	{
		public void Nurse()
		{
			Console.WriteLine("Nurse()");
		}
	}

	class Dog : Mammal
	{
		public void Bark()
		{
			Console.WriteLine("Bark()");
		}
	}

	class Cat : Mammal
	{
		public void Meow()
		{
			Console.WriteLine("Meow()");
		}
	}
}
