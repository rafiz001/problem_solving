// https://codeforces.com/contest/2227/problem/A
#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  while (n--) {
    int x, y;
    cin >> x >> y;
    if(x&1 && y&1){
        cout<<"NO\n";
    }else{
        cout<<"YES\n";
    }
  }
}