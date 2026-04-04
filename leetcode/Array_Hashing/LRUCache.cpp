// https://leetcode.com/problems/lru-cache
#include <bits/stdc++.h>
using namespace std;
class LRUCache {
private:
  int capacity = 0;
  int lowest = -1;
  int highest = -1;
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
      int oldOrder = keyToOrder[key];
      orderToKey.erase(orderToKey.find(oldOrder));
      if (lowest == key) {
        findLowest(oldOrder+1, keyToOrder[highest]);
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
    if (data.find(key) != data.end()) {
      int new_order = keyToOrder[highest] + 1;
      int previous_order = keyToOrder[key];
      data[key] = value;
      keyToOrder[key] = new_order;
      orderToKey[new_order] = key;

      orderToKey.erase(orderToKey.find(previous_order));
      if (key == lowest)
        findLowest(previous_order, new_order);
      highest=key;
      return;
    }
    int size = data.size();
    if (size >= capacity) {
      int old_lowest_order = keyToOrder[lowest];
      data.erase(data.find(lowest));
      keyToOrder.erase(keyToOrder.find(lowest));
      orderToKey.erase(orderToKey.find(old_lowest_order));
      if(capacity==1){
          lowest=key;
        }else{
      findLowest(old_lowest_order, keyToOrder[highest]);
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
  void findLowest(int from, int to) {
    // cout<<"searching lowest: "<<from<<"-"<<to<<endl;
    for (int i = from; i <= to; i++) {
      if (orderToKey.find(i) != orderToKey.end()) {
        lowest = orderToKey[i];
        break;
      }
      // else{cout<<"skipping: "<<i<<endl;}
    }
  }
  void d(){
    printf("H: %d(%d), L: %d(%d)\n",highest,keyToOrder[highest],lowest,keyToOrder[lowest]);
    printf("otk: %zu, kto: %zu, data: %zu\n",orderToKey.size(),keyToOrder.size(),data.size());
  }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
int main() {
  LRUCache *obj = nullptr;
  string commands[] = {"LRUCache","put","put","put","put","put","get","put","get","get","put","get","put","put","put","get","put","get","get","get","get","put","put","get","get","get","put","put","get","put","get","put","get","get","get","put","put","put","get","put","get","get","put","put","get","put","put","put","put","get","put","put","get","put","put","get","put","put","put","put","put","get","put","put","get","put","get","get","get","put","get","get","put","put","put","put","get","put","put","put","put","get","get","get","put","put","put","get","put","put","put","get","put","put","put","get","get","get","put","put","put","put","get","put","put","put","put","put","put","put"};
  int const inputSize = sizeof(commands) / sizeof(commands[0]);
  int value[inputSize][2] = {{10},{10,13},{3,17},{6,11},{10,5},{9,10},{13},{2,19},{2},{3},{5,25},{8},{9,22},{5,5},{1,30},{11},{9,12},{7},{5},{8},{9},{4,30},{9,3},{9},{10},{10},{6,14},{3,1},{3},{10,11},{8},{2,14},{1},{5},{4},{11,4},{12,24},{5,18},{13},{7,23},{8},{12},{3,27},{2,12},{5},{2,9},{13,4},{8,18},{1,7},{6},{9,29},{8,21},{5},{6,30},{1,12},{10},{4,15},{7,22},{11,26},{8,17},{9,29},{5},{3,4},{11,30},{12},{4,29},{3},{9},{6},{3,4},{1},{10},{3,29},{10,28},{1,20},{11,13},{3},{3,12},{3,8},{10,9},{3,26},{8},{7},{5},{13,17},{2,27},{11,15},{12},{9,19},{2,15},{3,16},{1},{12,17},{9,1},{6,19},{4},{5},{5},{8,1},{11,7},{5,2},{9,28},{1},{2,2},{7,4},{4,22},{7,24},{9,26},{13,28},{11,26}};
  for (int i = 0; i < inputSize; i++) {
    if (commands[i] == "LRUCache") {
      obj = new LRUCache(value[i][0]);
    } else if (commands[i] == "get") {
      cout<<"(get) "<<value[i][0]<<endl;
      cout << obj->get(value[i][0]) << endl;
      obj->d();
    } else if (commands[i] == "put") {
      cout<<"(put) "<<value[i][0]<<","<<value[i][1]<<endl;
      obj->put(value[i][0], value[i][1]);
      cout << "null" << endl;
      obj->d();
    }
  }
}

// ["LRUCache","get","put","get","put","put","get","get"]
// [[2],[2],[2,6],[1],[1,5],[1,2],[1],[2]]
// ["LRUCache","put","put","put","put","get","get"]
// [[2],[2,1],[1,1],[2,3],[4,1],[1],[2]]
// "LRUCache","get","get","put","get","put","put","put","put","get","put"
// [[1],[6],[8],[12,1],[2],[15,11],[5,2],[1,15],[4,2],[4],[15,15]]
// ["LRUCache","put","put","put","put","get","get","get","get","put","get","get","get","get","get"]
// [[3],[1,1],[2,2],[3,3],[4,4],[4],[3],[2],[1],[5,5],[1],[2],[3],[4],[5]]
// ["LRUCache","put","put","put","put","put","get","put","get","get","put","get","put","put","put","get","put","get","get","get","get","put","put","get","get","get","put","put","get","put","get","put","get","get","get","put","put","put","get","put","get","get","put","put","get","put","put","put","put","get","put","put","get","put","put","get","put","put","put","put","put","get","put","put","get","put","get","get","get","put","get","get","put","put","put","put","get","put","put","put","put","get","get","get","put","put","put","get","put","put","put","get","put","put","put","get","get","get","put","put","put","put","get","put","put","put","put","put","put","put"]
// [[10],[10,13],[3,17],[6,11],[10,5],[9,10],[13],[2,19],[2],[3],[5,25],[8],[9,22],[5,5],[1,30],[11],[9,12],[7],[5],[8],[9],[4,30],[9,3],[9],[10],[10],[6,14],[3,1],[3],[10,11],[8],[2,14],[1],[5],[4],[11,4],[12,24],[5,18],[13],[7,23],[8],[12],[3,27],[2,12],[5],[2,9],[13,4],[8,18],[1,7],[6],[9,29],[8,21],[5],[6,30],[1,12],[10],[4,15],[7,22],[11,26],[8,17],[9,29],[5],[3,4],[11,30],[12],[4,29],[3],[9],[6],[3,4],[1],[10],[3,29],[10,28],[1,20],[11,13],[3],[3,12],[3,8],[10,9],[3,26],[8],[7],[5],[13,17],[2,27],[11,15],[12],[9,19],[2,15],[3,16],[1],[12,17],[9,1],[6,19],[4],[5],[5],[8,1],[11,7],[5,2],[9,28],[1],[2,2],[7,4],[4,22],[7,24],[9,26],[13,28],[11,26]]