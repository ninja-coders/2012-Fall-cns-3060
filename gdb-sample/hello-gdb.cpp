#include <iostream>

int main(int argc, char* argv[], char* env[])
{
  std::cout << "Enter a numeric value: ";
  int number;
  std::cin >> number;

  int sum = 1;
  for (int i = 1; i <= number; ++i) {
    sum *= i;
  }

  std::cout << "Final Value: " << sum << std::endl;

  return 0;
}


