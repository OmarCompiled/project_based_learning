using System;

namespace AgeInDays
{
	class Program
	{ 
		static double AgeCalculator(int Day, int Month, int Year)
		{
			double TotalYears = DateTime.Now.Year - Year;
			double TotalMonths;
			double TotalDays;
			
			if(Day > DateTime.Now.Day)
			{
				TotalDays = Day - DateTime.Now.Day;
			} else if(Day < DateTime.Now.Day)
			{
				TotalDays = DateTime.Now.Day - Day;
			} else
			{
				TotalDays = 0;
			}

			if(Month > DateTime.Now.Month)
			{
				TotalMonths = Month - DateTime.Now.Month;
			} else if(Month < DateTime.Now.Month)
			{
				TotalMonths = DateTime.Now.Month - Month;
			} else
			{
				TotalMonths = 0;
			}
			
			double AgeInDays = (TotalYears * 365)+ (TotalMonths * 28) + TotalDays;

			return AgeInDays;
		}
		static void Main()
		{
			Console.WriteLine("What is your birthdate?");
			Console.Write("Year: ");

			int Year = Convert.ToInt32(Console.ReadLine());
			
			Console.Write("Month: ");

			int Month = Convert.ToInt32(Console.ReadLine());

			Console.Write("Day: ");

			int Day = Convert.ToInt32(Console.ReadLine());

			string Birthdate = $"{Day}/{Month}/{Year}";
			
			double Age = AgeCalculator(Day, Month, Year);

			Console.WriteLine($"You were born {Birthdate}, which means you are {Age} days old.");

		}
	}
}
