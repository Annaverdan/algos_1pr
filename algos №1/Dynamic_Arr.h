#ifndef DYNAMIC_ARR_H
#define DYNAMIC_ARR_H

#include <string>
#include <iostream>
using namespace std;

template <typename List>
class Dynamic_Arr {
private:
    List* arr = new List[size];
    int tsize = 0;
    int size = 2;
    void resize();

public:
    Dynamic_Arr();
    ~Dynamic_Arr();
    Dynamic_Arr(int size);

    void add(List value);
    void add_index(int index, List value);
    void remove(int index);
    void set(int index, List value);

    List get(int index) const;
    int get_size() const;
    int get_capacity() const;
    bool empty() const;
};

template <typename List>
Dynamic_Arr<List>::Dynamic_Arr() {}

template <typename List>
Dynamic_Arr<List>::~Dynamic_Arr() {
    delete[] arr;
    arr = nullptr;
}

template <typename List>
Dynamic_Arr<List>::Dynamic_Arr(int size) {
    if (!(size <= 0)) {
        this->size = size;
    }
    arr = new List[size];
}

template <typename List>
void Dynamic_Arr<List>::resize() {
    size *= 2;
    List* newArr = new List[size];
    for (int i = 0; i < tsize; i++) {
        newArr[i] = arr[i];
    }
    delete[] arr;
    arr = newArr;
}

template <typename List>
void Dynamic_Arr<List>::add(List value) {
    if (tsize >= size) {
        resize();
    }
    arr[tsize] = value;
    tsize++;
}

template <typename List>
void Dynamic_Arr<List>::add_index(int index, List value) {
    if (index < 0 || index > tsize) {
        cout << "Введен некорректный индекс";
    }
    if (tsize >= size) {
        resize();
    }
    for (int i = tsize; i > index; i--) {
        arr[i] = arr[i - 1];
    }
    arr[index] = value;
    tsize++;
}

template <typename List>
void Dynamic_Arr<List>::remove(int index) {
    if (index < 0 || index >= tsize) {
        cout << "Введен некорректный индекс";
    }
    for (int i = index; i < tsize - 1; i++) {
        arr[i] = arr[i + 1];
    }
    tsize--;
}

template <typename List>
List Dynamic_Arr<List>::get(int index) const {
    if (index < 0 || index >= tsize) {
        cout << "Введен некорректный индекс";
    }
    return arr[index];
}

template <typename List>
void Dynamic_Arr<List>::set(int index, List value) {
    if (index < 0 || index >= tsize) {
        cout << "Введен некорректный индекс";
    }
    arr[index] = value;
}

template <typename List>
int Dynamic_Arr<List>::get_size() const {
    return tsize;
}

template <typename List>
int Dynamic_Arr<List>::get_capacity() const {
    return size;
}

template <typename List>
bool Dynamic_Arr<List>::empty() const {
    return tsize == 0;
}

#endif //DYNAMIC_ARR_H
