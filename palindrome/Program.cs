using System;
using System.Text;

namespace Palindrome
{
	class Program
	{
		static void PalinCheck(string Input)
		{
			StringBuilder sb = new StringBuilder();
			for(int i = Input.Length - 1; i >= 0; i--)
			{
				sb.Append(Input[i]);
			}
			Console.WriteLine("-------------------------------------");
			string Inverse = Convert.ToString(sb);		
			if(Inverse == Input){
				Console.WriteLine($"The word {Input} is a Palindrome");
			} else {
				Console.WriteLine($"The word {Input} is NOT a Palindrome.");
			}
			Console.WriteLine("-------------------------------------");
		}
		static void Prompt()
		{
			Console.Write("Enter a word to check if it is a Palindrome: ");
			string Input = Console.ReadLine().ToLower().Trim();
			PalinCheck(Input);	
		}
		static void Main()
		{
			Prompt();
			while(true){
				Console.WriteLine("Do you want to check another word?");
				Console.Write("yes/no : ");
				string Approval = Console.ReadLine().ToLower().Trim();
				if(Approval.Substring(0,1) == "y" || Approval == "ok") {
					Prompt();
				} else if(Approval.Substring(0,1) == "n") {
					break;
				} else {
					Console.WriteLine("Please enter a valid option!");
				}
			}				
		}
	}
}
