//problem: https://leetcode.com/problems/roman-to-integer/


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char,int> romans;
        romans.insert({'I',1});
        romans.insert({'V',5});
        romans.insert({'X',10});
        romans.insert({'L',50});
        romans.insert({'C',100});
        romans.insert({'D',500});
        romans.insert({'M',1000});
        
        
        int ans = romans[s[s.size()-1]];
        for(int i=s.size()-2;i>=0;i--){
            if(romans[s[i]] >= romans[s[i+1]]){
                ans+=romans[s[i]];
            }else{
                ans-=romans[s[i]];

            }
        }
        return ans;

    }
};

int main() {
    Solution sl;
    cout<<sl.romanToInt("MCMXCIV")<<endl;
  return 0;
}