#include <iostream>

class Vertex {
public:
  float value;
  Vertex *next;
  Vertex() { next = nullptr; }
};

// Clase Stack
class Stack {
public:
  Stack();
  void push(float value);
  void pop();
  void top();
  void print();

private:
  Vertex *head;
};

Stack::Stack() { head = nullptr; }

// Stack::push()
void Stack::push(float value) {
  Vertex *vtx = new Vertex();
  vtx->value = value;
  vtx->next = head;
  head = vtx;
}

// Stack::pop()
void Stack::pop() {
  Vertex *del = head;
  if (head == nullptr) {
    std::cout << "La pila está vacia" << std::endl;
  } else {
    head = head->next;
    delete del;
  }
}

// Stack::top()
void Stack::top() {
  std::cout << head->value << std::endl;
};

// Stack::print()
void Stack::print() {
  Vertex *v = head;
  while (v != nullptr) {
    std::cout << v->value << "->";
    v = v->next;
  }
  std::cout << std::endl;
}

int main() {
  Stack pila;
  pila.push(1);
  pila.push(2);
  pila.push(3);
  pila.print();
  pila.pop();
  pila.push(4);
  pila.print();
  pila.top();
}