#include <iostream>
#include <queue>
#include <string>
#include <vector>
using namespace std;

int main() {
  priority_queue<long, vector<long>, greater<long>> zu;
  int n, k;
  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    long x;
    cin >> x;
    zu.push(x);
  }
  if (n == 1) {
    cout << zu.top();
    return 0;
  }
  long sum = 0;
  // if(n%k==0){
  //    long s=0;
  //   for(int i=0;i<k;i++){

  //       s+=zu.top();
  //       zu.pop();
  //   }
  //   sum+=s;
  //  // cout<<s<<endl;
  //   zu.push(s);
  //   n=n-k+1;
  // }

  if ((n - 1) % (k - 1) != 0) {
    long s = 0;
    // k-[(k-1)- (n - 1) % (k - 1)]
    for (int i = 0; i < (n - 1) % (k - 1) + 1; i++) {
      s += zu.top();
      zu.pop();
    }
    sum += s;
    cout << s << endl;
    // cout<<s<<endl;
    zu.push(s);
  }
  while (zu.size() > 1) {
    long s = 0;
    for (int i = 0; i < k; i++) {
      if (!zu.empty()) {
        s += zu.top();
        zu.pop();
      }
    }
    cout << s << endl;
    sum += s;
    // cout<<s<<endl;
    zu.push(s);
  }

  cout << sum;
  return 0;
}