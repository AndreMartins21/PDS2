#include <iostream>
#include "list.hpp"

void List::insertNode(int data) {
  Node* aux = new Node;
  aux->data = data;
  aux->next = nullptr;
  if (head == nullptr) {
    head = aux;
    tail = aux;
  } else {
    tail->next = aux;
    tail = aux;
  }
}

void List::display() {
  Node *aux = head;
  while (aux != nullptr) {
    cout << aux->data << " ";
    aux = aux->next;
  }
  cout << endl;
}

  // Você deverá implementar apenas esse método
  void List::inverte(){
    if(this->head == nullptr || this->head->next == nullptr){
      // Lista vazia ou somente com um elemento, não faz sentido inverter!
      return;
    }

    Node* previous = nullptr;
    Node* current = head;  
    Node* next_node = nullptr;

    this->tail = head;  

    while (current != nullptr){
      next_node = current->next; 
      current->next = previous;  

      previous = current;  
      current = next_node;  
    }
    
    head = previous;
  }



