// https://codeforces.com/contest/2227/problem/B
#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  while (n--) {
    int m;
    cin >> m;
    long count = 0;
    while (m--) {
      char brace;
      cin >> brace;
      (brace == '(') ? count++ : count--;
    }
    cout << ((count == 0) ? "YES\n" : "NO\n");
  }
}