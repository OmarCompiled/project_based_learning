﻿using System;

namespace fizzBuzz
{
	class Program
	{
		static void Main()
		{
			for(int i = 1; i <= 100; i++)
			{
				if(i % 3 == 0 && i % 5 ==0) {
					Console.WriteLine("Fizz Buzz");
				} else if(i % 5 == 0 && i % 3 != 0) {
					Console.WriteLine("Buzz");
				}	else if(i % 3 == 0 && i % 5 != 0) {
					Console.WriteLine("Fizz");
				} else {
					Console.WriteLine(i);
				}
			}
		}
	}
}
