#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
  int max = 0;
  int zu[6];
  for (int i = 0; i < 6; i++)
  {
    int number = 0;
    cin >> number;
    zu[i] = number;
    if (i == 0)
    {
      max = number;
    }
    else if (max < number)
    {
      max = number;
    }
  }
  sort(zu, zu + 6);
  int da = *max_element(zu, zu + 6);
  cout << zu[5] << endl;
  cout
      << (max) << endl;
  cout << da << endl;
}