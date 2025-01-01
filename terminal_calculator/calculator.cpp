#include <cmath>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <stdexcept>
#include <cctype>

#define euler_const 2.718281828459045

double eval(double a, char operation, double b) {
  if (operation == '+') {
    return a + b;
  } else if (operation == '-') {
    return a - b;
  } else if (operation == 'x') {
    return a * b;
  } else if (operation == '/') {
      double result = a / b;
      if(std::isnan(result) || std::isinf(result)) {
          std::cout << "Error: Cannot divide by zero" << std::endl;
      } else {
          return result;
      }
  } else if (operation == '^') {
    return std::pow(a, b);
  } else if(operation == '=') {
      return (a == b);
  }
  return -1;
}

void tokenize(std::string problem, std::vector<std::string> *tokens) {
  std::stringstream s(problem);
  std::string token;

  while (s >> token) {
    tokens->push_back(token);
  }
}

int main() {
  std::string problem;
  double a, b, ans = 0;
  char operation;

  std::cout << "--> ";
  std::getline(std::cin, problem);

  while (problem != "exit") {
    std::vector<std::string> tokens;
    tokenize(problem, &tokens);
    double result = 0;

    for (int i = 0; i < tokens.size(); i++) {
      if (tokens[i] == "ans") {
        tokens[i] = std::to_string(ans);
      } else if(tokens[i] == "e") {
          tokens[i] = std::to_string(euler_const);
      }
    }

    if (tokens.size() == 1 && std::isdigit(((int)tokens[0][0])))  {
        std::cout << " " << tokens[0] << std::endl;
    } else if(tokens.size() < 3 || tokens.size() % 2 == 0) {
        std::cout << "Error: Invalid Syntax" << std::endl;
    } else {
      try {
        while (tokens.size() > 3) {
          a = std::stod(tokens[0]);
          operation = tokens[1][0];
          b = std::stod(tokens[2]);
          result = eval(a, operation, b);
          tokens.erase(tokens.begin(), tokens.begin() + 3);
          tokens.insert(tokens.begin(), std::to_string(result));
        }
        a = std::stod(tokens[0]);
        operation = tokens[1][0];
        b = std::stod(tokens[2]);

        result = eval(a, operation, b);
        ans = result;
        
        std::cout << " " << result << std::endl;
      } catch (...) {
        std::cout << "Error: Invalid Syntax!" << std::endl;
      }
    }
    std::cout << "--> ";
    
    std::getline(std::cin, problem);
  }
}
