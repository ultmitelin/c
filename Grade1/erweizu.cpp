#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
  double zu[3][5] = {{15, 16, 18, 99, 16}, {19, 11, 1155, 18, 99999}, {36, 17, 666, 33, 6}};
  for (int i = 0; i < 3; i++)
  {
    for (int j = 0; j < 5; j++)
    {
      cout << zu[i][j] << ' ';
    }
    cout << endl;
  }
  sort(*zu, *zu + 15); // jia*
  for (int i = 0; i < 3; i++)
  {
    for (int j = 0; j < 5; j++)
    {
      cout << zu[i][j] << ' ';
    }
    cout << endl;
  }
  cout << zu[0][14];
}