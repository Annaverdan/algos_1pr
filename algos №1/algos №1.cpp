#include "Reverse_Polish_Notation.h"
#include <iostream>
#include <string>
#include <windows.h>
using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");
    Reverse_Polish_Notation expression;
    string input;
    
    while (true) {
        cout << "Введите выражение: ";
        getline(cin, input);
        expression.convert(input);
    }
    return 0;
}