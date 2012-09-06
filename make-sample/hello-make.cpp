#include <iostream>

int main(int argc, char* argv[], char* env[])
{
  std::cout << env[0] << std::endl;
  std::cout << "Hello, from make file" << std::endl;

  return 0;
}

