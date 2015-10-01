#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <set>
#include <cassert>
using namespace std;

struct Node{
   Node* next;
   Node* prev;
   int value;
   int key;
   Node(Node* p, Node* n, int k, int val):prev(p),next(n),key(k),value(val){};
   Node(int k, int val):prev(NULL),next(NULL),key(k),value(val){};
};

class Cache{

   protected:
   map<int,Node*> mp; //map the key to the node in the linked list
   int cp;  //capacity
   Node* tail; // double linked list tail pointer
   Node* head; // double linked list head pointer
   virtual void set(int, int) = 0; //set function
   virtual int get(int) = 0; //get function

};

class LRUCache : public Cache {
private:
   void to_head(Node* node) {
      if (node == head) return;
      else if (node == tail) {
         tail = node->prev;
         node->prev->next = NULL;
         node->next = head;
         node->prev = NULL;
         head->prev = node;
         head = node;
         return;
      }
      else {
         node->prev->next = node->next;
         node->next->prev = node->prev;
         node->next = head;
         head->prev = node;
         node->prev = NULL;
         head = node;
      }
   }
public:
   LRUCache(int cap) {
      this->cp = cap;
      this->head = this->tail = NULL;
   }
   void set(int key, int val) {
      if (mp.find(key) != mp.end()) {
         mp[key]->value = val;
         to_head(mp[key]);
      }
      else {
         if (mp.size() < cp) {
            mp[key] = new Node(NULL, head, key, val);
            if (head != NULL) {
               head->prev = mp[key];
            }
            if (tail == NULL) tail = mp[key];
            head = mp[key];
         }
         else {
            mp.erase(tail->key);
            mp[key] = tail;
            tail->key = key;
            tail->value = val;
            to_head(tail);
         }
      }
   }
   int get(int key) {
      if (mp.find(key) == mp.end()) {
         return -1;
      }
      else {
         to_head(mp[key]);
         return head->value;
      }
   }
};
int main() {
   int n, capacity,i;
   cin >> n >> capacity;
   LRUCache l(capacity);
   for(i=0;i<n;i++) {
      string command;
      cin >> command;
      if(command == "get") {
         int key;
         cin >> key;
         cout << l.get(key) << endl;
      }
      else if(command == "set") {
         int key, value;
         cin >> key >> value;
         l.set(key,value);
      }
   }
   return 0;
}
