#include <iostream>
using namespace std;
int main()
{
  int time, date = 666666;
  while (1)
  {
    if (time == 0)
    {
      cout << "请输入密码" << endl;
    }
    else
    {
      cout << "请再次输入密码" << endl;
    }
    time++;
    int a = 0;
    cin >> a;
    if (a == date)
    {
      cout << "accept" << endl;
      break;
    }
    else
    {
      if (time == 3)
      {
        cout << "连续错误3次，账号被冻结。" << endl;
        break;
      }
      cout << "输入错误" << endl;
    }
  }
}