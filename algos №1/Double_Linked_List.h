#ifndef DOUBLE_LINKED_LIST_H
#define DOUBLE_LINKED_LIST_H

#include <iostream>
#include <string>
using namespace std;

template <typename List>
class Double_Linked_List {

public:
    struct Node {
        List data;
        Node* next;
        Node* prev;
        Node(List num);
    };

    void add(List num);
    void add_index(int index, List num);
    List get(int index) const;
    List remove(int index);
    List set(int index, List num);
    bool empty() const;
    int get_size() const;
    Node* get_tail() const;
    Node* get_head() const;
    ~Double_Linked_List();

private:
    double size = 0;
    Node* head = nullptr;
    Node* tail = nullptr;
};

template <typename List>
Double_Linked_List<List>::Node::Node(List num) {
    this->data = num;
    this->next = nullptr;
    this->prev = nullptr;
}

template <typename List>
void Double_Linked_List<List>::add(List num) {
    Node* newNode = new Node(num);
    if (head == nullptr) {
        head = tail = newNode;
    }
    else {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
    size++;
}

template <typename List>
void Double_Linked_List<List>::add_index(int index, List num) {
    if (index < 0 || index > size) {
        cout << "¬веден некорректный индекс";
    }
    if (index == size) {
        add(num);
        return;
    }
    if (index == 0) {
        Node* newNode = new Node(num);
        newNode->next = head;
        if (head != nullptr) {
            head->prev = newNode;
        }
        head = newNode;
        if (tail == nullptr) {
            tail = head;
        }
        size++;
        return;
    }

    Node* curr = head;
    for (int i = 0; i < index; i++) {
        curr = curr->next;
    }

    Node* newNode = new Node(num);

    newNode->next = curr;
    newNode->prev = curr->prev;
    curr->prev->next = newNode;
    curr->prev = newNode;
    size++;
}

template <typename List>
List Double_Linked_List<List>::get(int index) const {
    if (index < 0 || index >= size) {
        cout << "¬веден некорректный индекс";
    }
    Node* curr = head;
    for (int i = 0; i < index; i++) {
        curr = curr->next;
    }
    return curr->data;
}

template <typename List>
List Double_Linked_List<List>::remove(int index) {
    if (index < 0 || index >= size) {
        cout << "¬веден некорректный индекс";
    }

    Node* curr = head;
    for (int i = 0; i < index; i++) {
        curr = curr->next;
    }

    List num = curr->data;
    if (curr->prev != nullptr) {
        curr->prev->next = curr->next;
    }
    else {
        head = curr->next;
    }
    if (curr->next != nullptr) {
        curr->next->prev = curr->prev;
    }
    else {
        tail = curr->prev;
    }
    delete curr;
    size--;
    return num;
}

template <typename List>
List Double_Linked_List<List>::set(int index, List num) {
    if (index < 0 || index >= size) {
        cout << "¬веден некорректный индекс";
    }

    Node* curr = head;
    for (int i = 0; i < index; i++) {
        curr = curr->next;
    }

    List oldNum = curr->num;
    curr->num = num;
    return oldNum;
}

template <typename List>
bool Double_Linked_List<List>::empty() const {
    return size == 0;
}

template <typename List>
int Double_Linked_List<List>::get_size() const {
    return size;
}

//получить хвост
template <typename List>
typename Double_Linked_List<List>::Node* Double_Linked_List<List>::get_tail() const {
    return tail;
}

//получить голову
template <typename List>
typename Double_Linked_List<List>::Node* Double_Linked_List<List>::get_head() const {
    return head;
}

template <typename List>
Double_Linked_List<List>::~Double_Linked_List() {
    Node* curr = head;
    while (curr != nullptr) {
        Node* next = curr->next;
        delete curr;
        curr = next;
    }
    head = nullptr;
    tail = nullptr;
    size = 0;
}

#endif //DOUBLE_LINKED_LIST_H