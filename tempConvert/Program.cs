using System;
using System.Collections.Generic;

namespace tempConvert
{
	class Program
	{
		static void prompt()
		{
			// List with the possible conversions (Perhaps not the best solution :| )
			List<string> conversions = new List<string> ();
			conversions.Add("f to c");
			conversions.Add("f to k");
			conversions.Add("c to f");
			conversions.Add("c to k");
			conversions.Add("k to f");
			conversions.Add("k to c");

			Console.Write("~~]>");
      		string? input = Console.ReadLine();
			input = input?.ToLower().Trim();
			while(!conversions.Contains(input)) {
				Console.WriteLine("Please choose a valid conversion!");
				Console.Write("~~]>");
				input = Console.ReadLine();
			}
			
			try
			{
				if(input == conversions[0]) {
				FtoC();
			} else if(input == conversions[1]) {
				FtoK();
			} else if(input == conversions[2]) {
				CtoF();
			} else if(input == conversions[3]) {
				CtoK();
			} else if(input == conversions[4]) {
				KtoF();
			}
			 else if(input == conversions[5]) {
				KtoC(); 	
			}		
			} // Catching Format Exceptions so the program Does not crash.
			catch(FormatException ex)
			{
				Console.WriteLine("The input you entered was not a temperature!");
			}	
		}
		// Made a function for every conversion
		static void FtoC()
		{	
			Console.Write("Enter the temperature in F: ");
			double tempInF = Convert.ToDouble(Console.ReadLine());
			double tempInC = (tempInF - 32) * 5/9;
			Console.WriteLine($"The temperature in C is {tempInC}");
		}

		static void FtoK()
		{
			Console.Write("Enter the temperature in F: ");
			double tempInF = Convert.ToDouble(Console.ReadLine());
			double tempInK = (273.15 + (tempInF - 32) * 5/9);
			Console.WriteLine($"The temperature in K is {tempInK}");
		}

		static void CtoF()
		{
			Console.Write("Enter the temperature in C: ");
			double tempInC = Convert.ToDouble(Console.ReadLine());
			double tempInF = (tempInC * 9/5) + 32;
			Console.WriteLine($"The temperature in F is {tempInF}");
		}

		static void CtoK()
		{
			Console.Write("Enter the temperature in C: ");			
			double tempInC = Convert.ToDouble(Console.ReadLine());
			double tempInK = tempInC + 273.15;
			Console.WriteLine($"The temperature in K is {tempInK}");
		}

		static void KtoF()
		{
			Console.Write("Enter the temperature in K: ");
			double tempInK = Convert.ToDouble(Console.ReadLine());
			double tempInF = (tempInK - 273.15) * 9/5 + 32;
			Console.WriteLine($"The temperature in F is {tempInF}");
		}

		static void KtoC()
		{
			Console.Write("Enter the temperature in K: ");
			double tempInK = Convert.ToDouble(Console.ReadLine());
			double tempInC = tempInK - 273.15;
			Console.WriteLine($"The temperature in C is {tempInC}");
		}

		static void Main()
		{
			Console.WriteLine("-----------------------------");
			Console.WriteLine("Please choose a conversion :-");
			Console.WriteLine("-->F to C");
			Console.WriteLine("-->F to K");
			Console.WriteLine("-->C to F");
			Console.WriteLine("-->C to K");
			Console.WriteLine("-->K to F");
			Console.WriteLine("-->K to C");
			Console.WriteLine("-----------------------------");	
			
			prompt();
			
			while(true){ // While loop so user can convert multiple times
				Console.WriteLine("Do you want another conversion?");
				Console.Write("yes/no: ");

				string? approval = Console.ReadLine();
				approval = approval?.ToLower();
				if(approval?.Substring(0,1) == "y"){
					Console.WriteLine("-----------------------------");
					Console.WriteLine("Please choose a conversion :-");
					Console.WriteLine("-->F to C");
					Console.WriteLine("-->F to K");
					Console.WriteLine("-->C to F");
					Console.WriteLine("-->C to K");
					Console.WriteLine("-->K to F");
					Console.WriteLine("-->K to C");
					Console.WriteLine("-----------------------------");
					prompt();
				} else if(approval?.Substring(0,1) == "n") {
					break;
				} else {
					Console.WriteLine("Please enter yes or no!");
				}
			}
		}
	}
}
