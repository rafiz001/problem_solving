//problem: https://leetcode.com/problems/design-hashmap/submissions/


#include <bits/stdc++.h>
using namespace std;

class MyHashMap {
private:
  const static int TOTAL_BUCKET = 100000;

  vector<pair<int, int>> fizMap[TOTAL_BUCKET];

  int getBucketIndex(int key) { return (key + 1 * 7) % TOTAL_BUCKET; }

public:
  MyHashMap() {
    for (auto bucket : fizMap) {
      bucket.clear();
    }
  }

  void put(int key, int value) {
    int bucketIndex = getBucketIndex(key);
    for (auto &entry : fizMap[bucketIndex]) {
      if (entry.first == key) {
        // found and replacing
        entry.second = value;
        return;
      }
    }
    fizMap[bucketIndex].push_back({key, value});
  }

  int get(int key) {
    int bucketIndex = getBucketIndex(key);
    for (auto entry : fizMap[bucketIndex]) {
      if (entry.first == key) {
        // found
        return entry.second;
      }
    }
    return -1;
  }

  void remove(int key) {
    int bucketIndex = getBucketIndex(key);
    for (auto entry : fizMap[bucketIndex]) {
      if (entry.first == key) {
        // found
        swap(entry, fizMap[bucketIndex].back());
        fizMap[bucketIndex].pop_back();
      }
    }
  }
};

int main() {
  MyHashMap hm;
  hm.put(1, 1);
  hm.put(2, 2);
  hm.put(2, 1);
  cout << hm.get(2) << endl;
  return 0;
}