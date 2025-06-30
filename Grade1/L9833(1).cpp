#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int getNum(string str);

int main()
{
  // i/o
  char _operator;
  string oper1, oper2;
  cin >> _operator >> oper1 >> oper2;

  // getNum
  int num1 = getNum(oper1), num2 = getNum(oper2), prod;

  // operation
  switch (_operator)
  {
  case '+':
    prod = num1 + num2;
    break;

  case '-':
    prod = num1 - num2;
    break;

  case '*':
    prod = num1 * num2;
    break;

  case '/':
    if (num2 == 0)
      prod = -1;
    else
      prod = num1 / num2;
    break;

  default:
    prod = -1;
    break;
  }

  if (prod == -1)
    cout << "Divided by zero!" << endl;
  else
    cout << prod << endl;

  return 0;
}

int getNum(string str)
{
  unordered_map<string, int> map =
      {{"DEC", 10},
       {"BIN", 2},
       {"OCT", 8},
       {"HEX", 16}};
  int prod = 0;
  string event = "START";
  for (char digit : str)
  {
    if (event == "START")
    {
      if (digit == '0')
        event = "OCT";
      else
        event = "DEC";
    }
    if (digit == 'B' || digit == 'b')
    {
      if (event == "OCT")
        event = "BIN";
    }
    if (digit == 'X' || digit == 'x')
    {
      if (event == "OCT")
        event = "HEX";
    }
    if (digit >= 'A' && digit <= 'F')
    {
      if (event == "HEX")
        prod = prod * 16 + digit - 'A' + 10;
    }
    if (digit >= 'a' && digit <= 'f')
    {
      if (event == "HEX")
        prod = prod * 16 + digit - 'a' + 10;
    }
    if (digit >= '0' && digit <= '9')
    {
      prod = prod * map[event] + digit - '0';
    }
  }
  return prod;
}