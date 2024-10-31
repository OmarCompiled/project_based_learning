#include<iostream>
#include<string>

void test(int &height);

int main() {
	int height = 0;
       	test(height);
}

void test(int &height) {
	while (height < 1 || height > 8) {
		std::cout << "Height: ";

		std::cin >> height;
	}
	for (int row = 1; row <= height; row++) {
		for (int first_space = 1; first_space <= height - row; first_space++){
			std::cout << " ";
		}	
		for (int left =1; left <= row; left++) {
			std::cout << "#";
		}
		std::cout << "  ";
		for (int right = 1; right <= row; right++) {
			std::cout << "#";
		}
		std::cout << std::endl;
	}
}
