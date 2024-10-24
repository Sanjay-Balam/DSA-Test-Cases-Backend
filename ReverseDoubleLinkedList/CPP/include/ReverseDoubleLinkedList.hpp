#ifndef REVERSEDOUBLYLINKEDLIST_HPP
#define REVERSEDOUBLYLINKEDLIST_HPP

#include<vector>
#include<string>


class Node{
  public:
    int val;
    Node* next;
    Node* prev;

    Node(int val){
      this->val = val;
      this->next = nullptr;
      this->prev = nullptr;
    }
};

class DoublyLinkedlist{
private:
  Node* head;
  Node* tail;

public:
  DoublyLinkedlist();
  void insertAtBegin(int val);
  void insertAtEnd(int val);
  int remove(int val);
  bool empty();
  std::vector<int> get();
  void reverse();
};

#endif
