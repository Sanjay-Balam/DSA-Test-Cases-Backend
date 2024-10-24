#include "../include/ReverseDoubleLinkedList.hpp"

DoublyLinkedlist::DoublyLinkedlist() {
    head = nullptr;
    tail = nullptr;
}



void DoublyLinkedlist::reverse() {
    Node* current = head;
    Node* temp = nullptr;


    while (current != nullptr) {

        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev; 
    }


    if (temp != nullptr) {
        head = temp->prev; 
    }
}
