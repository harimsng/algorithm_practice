#include <iostream>

#include "multiplication.hpp"

std::string multiply(std::string left, std::string right);

int main(int argc, char** argv)
{
  if (argc != 3)
  {
    std::cout << "usage: ./multiplication  left  right";
    std::cout << "left and right must be zero or positive integer.";
    std::cout << "it will output result of 'left * right' to stdout";
    return 1;
  }
  std::string result;

  result = multiply(argv[1], argv[2]);
  std::cout << result << '\n';
}

std::string multiply(std::string left, std::string right) {
  return multiply(left, right,
    [](unsigned int i) {
      return static_cast<char>(i + '0');
    },
    [](char c) {
      return static_cast<unsigned int>(c - '0');
    }
  );
}

