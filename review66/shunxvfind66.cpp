#include <iostream>
using namespace std;
int main()
{
  int hi[] = {175,
              161,
              162,
              169,
              147,
              170,
              170,
              152,
              171,
              155,
              157,
              166,
              157,
              158,
              160,
              161,
              161,
              163,
              164,
              165, 175, 161, 162, 169, 147, 170, 170, 152, 171, 155, 157, 166, 157, 158, 160, 161, 161, 163, 164, 165};
  int N = sizeof(hi) / sizeof(hi[0]);
  int im = -1;
  int ifind;
  cin >> ifind;
  int n = 0;
  for (int i = 0; i < N; i++)
  {
    if (hi[i] == ifind)
    {
      im = i;
      n++;
    }
    if (n == 2)
      break;
    // 要用中括号把if后的语句括起来，否则系统识别错误第一次就break
  }
  if (im == -1)
    cout << "not find" << endl;
  else
    cout << "h[" << im << "]=" << ifind << endl;
  cout << N << endl;
  cout << n;
  return 0;
}