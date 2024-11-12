#include <iostream>

int main(){
	int count = 0;
	char input = '-';
	input = std::cin.get();
	while(input != 10){
		if(input == 'a' || input == 'i' || input == 'o' || input == 'u' || input == 'e'){count ++;}
		input = std::cin.get();
	}
	std::cout << "The word you entered has " << count << " vowels." << std::endl;
	return 0;
}
