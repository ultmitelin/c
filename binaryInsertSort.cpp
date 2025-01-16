#include<iostream>
#include<vector>
#include<random>
using namespace std;

// void generateList(vector<int>* v1);

// int main() {
//     vector<int> v1 (50, 0);
//     auto it = v1.begin();
//     while (it != v1.end()) {cout << (*it) << ' '; it ++;}
//     cout << endl;
//     return 0;
// }

// void generateList(vector<int>* v1) {
//     random_device rd;
//     mt19937 gen(rd());
//     uniform_int_distribution<> distrib(1, 50);
//     for (int i = 0; i < 50; i ++) {
//         v1[i] = int(distrib(gen));
//     }
// }