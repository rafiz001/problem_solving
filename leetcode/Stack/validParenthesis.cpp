// problem: https://leetcode.com/problems/valid-parentheses/

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  bool isValid(string s) {
    stack<char> st;
    for (auto c : s) {
      if (c == ')' || c == '}' || c == ']') {
        if (st.size() == 0)
          return false;
        else if ((c == ')' && st.top() == '(') ||
                 (c == '}' && st.top() == '{') || (c == ']' && st.top() == '[')

        ) {
          st.pop();
        } else {
          return false;
        }
      } else {
        st.push(c);
      }
    }
    if (st.size() == 0)
      return true;
    else
      return false;
  }
};

int main() {
  Solution sl;
  cout << sl.isValid("()") << endl;
  return 0;
}