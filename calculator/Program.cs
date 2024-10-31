using System;

namespace Calculator
{
	class Program
	{
		static void Prompt()
		{
			string Answer = " ";
			char Operator = ' ';
			double Num1 = 0;
			double Num2 = 0;
			try
			{
				Console.Write("Please enter the first number: ");
				Num1 = Convert.ToDouble(Console.ReadLine());
				Console.WriteLine("--------------------------------");
				Console.Write("Please enter the second number: ");
				Num2 = Convert.ToDouble(Console.ReadLine());
				Console.WriteLine("--------------------------------");
				Console.WriteLine("Choose a valid operation :-");
				Console.WriteLine("+ , - , * , / , ^"); 
				Console.Write("--> ");
				Operator = Convert.ToChar(Console.ReadLine());
				Console.WriteLine("--------------------------------");
			}
			catch(FormatException ex) 
			{
				Console.WriteLine("You did not enter valid input!");
				Answer = "Err";
			}
					
				if(Operator == '+') {
				Answer = Convert.ToString(Num1 + Num2);
			} else if(Operator == '-') {
				Answer = Convert.ToString(Num1 - Num2);
			} else if(Operator == '*') {
				Answer = Convert.ToString(Num1 * Num2);
			} else if(Operator == '/') {
					if(Num2 == 0) {
						Console.WriteLine("Cannot divide by zero!");
						Answer = "Err";
					} else {
						Answer = Convert.ToString(Num1 / Num2);
					}
			} else if(Operator == '^') {
				Answer = Convert.ToString(Math.Pow(Num1,Num2));
			}
			
			Console.WriteLine($"Ans : {Answer}");
			Console.WriteLine("--------------------------------");
		}
		static void Main()
		{
			Prompt();	

						
			while(true) {
				Console.WriteLine("Do you want another calculation?");
				Console.Write("yes/no : ");
				string? input = Console.ReadLine();
				input = input.ToLower();
				if(input.Substring(0,1) == "y") {
					Prompt();
				} else if (input.Substring(0,1) == "n") {
					Console.WriteLine("See You Later!");
					break;
				} else {
					Console.WriteLine("Please enter a valid choice!");
					Console.Write("yes/no : ");
				}
			}
		}
	}
}
