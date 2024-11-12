#include <iostream>
#include <string>

int main(){
	std::cout << "Enter a string: ";
	char input = '-';
	input = std::cin.get();
	std::string reverse1;
	while(input != 10){
		reverse1.append(1, input);
		input = std::cin.get();
	}
	std::string reverse2;
	for(int i = reverse1.length(); i >= 0; i--){
		reverse2.append(1,reverse1[i]);
	}
	std::cout << reverse2;
	return 0;
}
