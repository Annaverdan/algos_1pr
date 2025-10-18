#include "Double_Linked_List.h"
#ifndef STACK_H
#define STACK_H

#include <string>
#include <iostream>
using namespace std;

template <typename List>
class Stack {
public:
    Stack() = default;
    ~Stack() = default;

    void push(List data);
    List pop();
    List peek() const;
    bool empty() const;
    int size() const;

private:
    Double_Linked_List<List> list;
};

template <typename List>
void Stack<List>::push(List data) {
    list.add(data);
}

template <typename List>
List Stack<List>::pop() {
    if (empty()) {
        cout << "Stack is empty";
    }
    int lastIndex = list.get_size() - 1;
    return list.remove(lastIndex);
}

template <typename List>
List Stack<List>::peek() const {
    if (empty()) {
        cout << "Stack is empty";
    }
    int lastIndex = list.get_size() - 1;
    return list.get(lastIndex);
}

template <typename List>
bool Stack<List>::empty() const {
    return list.empty();
}

template <typename List>
int Stack<List>::size() const {
    return list.get_size();
}

#endif //STACK_H
