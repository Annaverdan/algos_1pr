#include "Reverse_Polish_Notation.h"
#include "Double_Linked_List.h"
#include "Stach.h"

#include <iostream>
#include <string>
using namespace std;


//сократила character на ch, operand на op для удобства
int Reverse_Polish_Notation::get_priority(const string& ch) {
    if (ch == "+" || ch == "-") return 1;
    if (ch == "*" || ch == "/") return 2;
    if (ch == "^") return 3;
    return 0;
}

bool Reverse_Polish_Notation::Degree(const string& ch) {
    return ch == "^";
}

bool Reverse_Polish_Notation::Function(const string& ch) {
    return ch == "sin" || ch == "cos";
}

bool Reverse_Polish_Notation::Operator(const string& ch) {
    return ch == "+" || ch == "-" || ch == "*" || ch == "/" || ch == "^";
}

bool Reverse_Polish_Notation::Number(const string& ch) {
    if (ch.empty()) {
        return false;
    }
    for (char c : ch) {
        if (!isdigit(c)) {
            return false;
        }
    }
    return true;
}

void Reverse_Polish_Notation::convert(const string& input) {
    Double_Linked_List<string> inputCh;
    string curr;
    for (int i = 0; i < input.length(); i++) {
        char ch = input[i];
        if (ch == ' ') {
            if (!curr.empty()) {
                inputCh.add(curr);
                curr.clear();
            }
        }
        else if (isdigit(ch)) {
            curr += ch;
        }
        else if (isalpha(ch)) {
            curr += ch;
        }
        else {
            if (!curr.empty()) {
                inputCh.add(curr);
                curr.clear();
            }
            string op(1, ch);
            inputCh.add(op);
        }
    }
    if (!curr.empty()) {
        inputCh.add(curr);
    }

    Double_Linked_List<string> outputList;
    Stack<string> chStack;

    int chSize = inputCh.get_size();
    for (int i = 0; i < chSize; i++) {
        string ch = inputCh.get(i);
        if (Number(ch)) {
            outputList.add(ch);
        }
        else if (Function(ch)) {
            chStack.push(ch);
        }
        else if (Operator(ch)) {
            while (!chStack.empty() &&
                Operator(chStack.peek()) &&
                (get_priority(chStack.peek()) > get_priority(ch) ||
                    (get_priority(chStack.peek()) == get_priority(ch) && !Degree(ch)))) {
                outputList.add(chStack.pop());
            }
            chStack.push(ch);
        }
        else if (ch == "(") {
            chStack.push(ch);
        }
        else if (ch == ")") {
            while (!chStack.empty() && chStack.peek() != "(") {
                outputList.add(chStack.pop());
            }
            if (!chStack.empty()) {
                chStack.pop();
            }
            if (!chStack.empty() && Function(chStack.peek())) {
                outputList.add(chStack.pop());
            }
        }
    }
    while (!chStack.empty()) {
        outputList.add(chStack.pop());
    }
    
    int size = outputList.get_size();
    cout << "Обратная польская нотация: ";
    for (int i = 0; i < size; i++) {
        cout << outputList.get(i) << " ";
    }
    cout << endl;
}
