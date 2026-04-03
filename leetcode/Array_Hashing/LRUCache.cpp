#include <bits/stdc++.h>
using namespace std;
class LRUCache {
private:
  int capacity = 0;
  int lowest = -1;
  int highest = 0;
  unordered_map<int, int> data;
  unordered_map<int, int> keyToOrder;
  unordered_map<int, int> orderToKey;

public:
  LRUCache(int capacity) {
    this->capacity = capacity;
    data.reserve(capacity);
    keyToOrder.reserve(capacity);
    orderToKey.reserve(capacity);
  }

  int get(int key) {
    if (data.find(key) != data.end()) {
      if (lowest == key) {
        int oldOrder = keyToOrder[key];
        orderToKey.erase(orderToKey.find(oldOrder));
        for (int i = oldOrder; i <= keyToOrder[highest]; i++) {
          if (orderToKey.find(i) != orderToKey.end()) {
            lowest = orderToKey[i];
            break;
          }
        }
      }
      int newOrder = keyToOrder[highest] + 1;
      keyToOrder[key] = newOrder;
      orderToKey[newOrder] = key;
      highest = key;

      return data[key];
    } else {
      return -1;
    }
  }

  void put(int key, int value) {
    int size = data.size();
    if (size >= capacity) {
      int old_lowest_order = keyToOrder[lowest];
      //   cout << size << "done\n";
      data.erase(data.find(lowest));
      keyToOrder.erase(keyToOrder.find(lowest));
      orderToKey.erase(orderToKey.find(old_lowest_order));
      for (int i = old_lowest_order; i <= keyToOrder[highest]; i++) {
        if (orderToKey.find(i) != orderToKey.end()) {
          lowest = orderToKey[i];
          break;
        }
      }

    } else {
      if (size == 0) {
        lowest = key;
        highest = key;
      }
    }
    int new_highest_order = keyToOrder[highest] + 1;
    data[key] = value;
    keyToOrder[key] = new_highest_order;
    orderToKey[new_highest_order] = key;
    highest = key;
  }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
int main() {
  LRUCache obj(2);
  obj.put(1, 1);
  obj.put(2, 2);
  cout << obj.get(1) << endl;
  obj.put(3, 3);
  cout << obj.get(2) << endl;
  obj.put(4, 4);
  cout << obj.get(1) << endl;
  cout << obj.get(3) << endl;
  cout << obj.get(4) << endl;
}

// ["LRUCache","get","put","get","put","put","get","get"]
// [[2],[2],[2,6],[1],[1,5],[1,2],[1],[2]]