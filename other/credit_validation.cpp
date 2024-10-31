#include <iostream>
#include <string>
#include <vector>

bool validation() {
  std::string cardNumber = "";

  std::cout << "Please enter your card number: ";

  std::cin >> cardNumber;

  std::vector<int> cardNumberInt;
  int sum = 0;
  // Converting String into int.
  for (int i = 0; i < cardNumber.length(); i++) {
    cardNumberInt.push_back(cardNumber[i] - '0');
  }
  for (int i = cardNumber.length() - 2; i >= 0; i -= 2) {
    int tempValue = cardNumberInt[i];
    tempValue = tempValue * 2;
    if (tempValue > 9) {
      tempValue -= 9;
    }
    cardNumberInt[i] = tempValue;
  }
  for (int i = 0; i < cardNumberInt.size(); i++) {
    sum += cardNumberInt[i];
  }
  bool result;
  if (sum % 10 == 0) {
    result = true;
  } else {
    result = false;
  }

  if (result) {
    std::cout << "This card number is valid." << std::endl;
  } else {
    std::cout << "This card number is not valid." << std::endl;
  }
  return result;
}

int main() {
  validation();

  char rerun = '-';

  std::cout << "Press (R) to check another number.";

  std::cin >> rerun;

  do {
    validation();

    std::cout << "Press (R) to check another number.";

    std::cin >> rerun;
  } while (rerun == 'r' || rerun == 'R');

  return 0;
}
