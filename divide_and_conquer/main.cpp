#include <iostream>

#include "BigNumberOps.hpp"

static char convertFromInt(unsigned int i)
{
  return i + '0';
}
static unsigned int convertToInt(char c)
{
  return c - '0';
}


int test();

int main(int argc, char** argv)
{
  if (argc == 1)
  {
    std::cout << "test\n";
    return test();
  }
  if (argc != 4)
  {
    std::cout << "usage: ./bignumcal  left  operator  right\n";
    std::cout << "left and right must be zero or positive integer.\n";
    std::cout << "'-' for subtraction and '*' or 'x' for multiplication are currently supported operators.\n";
    return 1;
  }
  BigNumberOps<std::string, convertFromInt, convertToInt> ops;
  std::string op(argv[2]);
  std::string result;
  std::string left(argv[1]);
  std::string right(argv[3]);

  if (op.size() > 1)
  {
    std::cout << "invalid operator " << op << "\n";
    return 1;
  }
  switch (op[0])
  {
    case '+':
      std::cout << "addition is not supported\n";
      break;
    case '-':
      result = ops.sub(left, right);
      break;
    case 'x':
    case '*':
      result = ops.mul(left, right);
      break;
    case '/':
      std::cout << "division is not supported\n";
      break;
    default:
      std::cout << "invalid operator " << op[0] << "\n";
      break;
  }
  std::cout << result << '\n';
}

int test()
{
  return 1;
}
