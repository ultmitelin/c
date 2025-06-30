// #include <algorithm>
// #include <cmath>
// #include <iostream>
// #include <vector>
// using namespace std;
// bool isInteger(double num) { return floor(num) == ceil(num); }

// struct keshu {
//   int x;
//   int y;
// };
// bool cmp(keshu a, keshu b) { return a.y > b.y; }
// int main() {
//   int t;
//   cin >> t;
//   for (int i = 0; i < t; i++) {
//     int n;
//     cin >> n;
//     vector<int> ke;
//     double x[n * 3];
//     for (int k = 0; k < n * 3; cin >> x[k], k++);
//     for (int l = n; l <= n * 2 - 1; l++) {
//       for (int m = n * 2; m <= n * 3 - 1; m++) {
//         for (int k = 0; k < n; k++) {
//           double x1 = (x[m] - x[l]) / x[k];
//           if (isInteger(x1) && (x1 != 0)) {
//             ke.push_back(x1);
//           }
//         }
//       }
//     }
//     keshu aaa[ke.size()];
//     for (int j = 0; j < ke.size(); j++) {
//       aaa[j].x = ke[j];
//       aaa[j].y = count(ke.begin(), ke.end(), ke[j]);
//     };
//     sort(aaa, aaa + ke.size(), cmp);
//     // for (int j = 0; j < ke.size(); cout << aaa[j].x << endl, j++);
//     cout << aaa[0].x << endl;
//   }
// // }
// #include <algorithm>
// #include <cmath>
// #include <iostream>
// #include <unordered_map>
// #include <vector>
// using namespace std;

// bool isInteger(double num) { return floor(num) == ceil(num); }

// int main() {
//   int t;
//   cin >> t;
//   for (int i = 0; i < t; i++) {
//     int n;
//     cin >> n;
//     vector<double> x(n * 3);
//     for (int k = 0; k < n * 3; k++) {
//       cin >> x[k];
//     }

//     unordered_map<int, int> frequencyMap;

//     for (int l = n; l < 2 * n; l++) {
//       for (int m = 2 * n; m < 3 * n; m++) {
//         double diff = x[m] - x[l];
//         if (diff == 0) continue;  // 如果差值为0，直接跳过
//         for (int k = 0; k < n; k++) {
//           if (x[k] != 0 && isInteger(diff / x[k])) {
//             int result = static_cast<int>(diff / x[k]);
//             if (result != 0) {
//               frequencyMap[result]++;
//             }
//           }
//         }
//       }
//     }

//     int maxCount = 0;
//     int maxElement = 0;
//     for (const auto& pair : frequencyMap) {
//       if (pair.second > maxCount) {
//         maxCount = pair.second;
//         maxElement = pair.first;
//       }
//     }

//     cout << maxElement << endl;
//   }
// }
// #include <algorithm>
// #include <iostream>
// #include <unordered_map>
// #include <vector>

// using namespace std;

// int main() {
//   int T;
//   cin >> T;
//   while (T--) {
//     int n;
//     cin >> n;

//     vector<int> A(n), B(n), C(n);
//     for (int i = 0; i < n; i++) cin >> A[i];
//     for (int i = 0; i < n; i++) cin >> B[i];
//     for (int i = 0; i < n; i++) cin >> C[i];

//     unordered_map<long long, int> xCounts;

//     for (int i = 0; i < n; i++) {
//       for (int j = 0; j < n; j++) {
//         for (int k = 0; k < n; k++) {
//           if (A[i] != 0) {
//             long long x = (C[k] - B[j]) / A[i];
//             if ((C[k] - B[j]) % A[i] == 0) {
//               xCounts[x]++;
//             }
//           }
//         }
//       }
//     }

//     long long ans = -1;
//     int maxCount = 0;

//     for (const auto& [x, count] : xCounts) {
//       if (count > maxCount) {
//         maxCount = count;
//         ans = x;
//       }
//     }
//     cout << ans<<endk;
// if (maxCount == n) {
//   cout << ans << endl;
// } else {
//   cout << "No solution" << endl;
// }
//   }
//   return 0;
// }
#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int main() {
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;

    vector<int> A(n), B(n), C(n);
    for (int i = 0; i < n; i++) cin >> A[i];
    for (int i = 0; i < n; i++) cin >> B[i];
    for (int i = 0; i < n; i++) cin >> C[i];

    unordered_map<long long, int> xCounts;

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        for (int k = 0; k < n; k++) {
          if (A[i] != 0) {
            long long x = (C[j] - B[k]) / A[i];
            if ((C[j] - B[k]) % A[i] == 0) {
              xCounts[x]++;
            }
          }
        }
      }
    }

    long long maxCount = 0;
    long long ans = 0;
    for (const auto& pair : xCounts) {
      if (pair.second > maxCount) {
        maxCount = pair.second;
        ans = pair.first;
      }
    }

    cout << ans << endl;
  }
  return 0;
}