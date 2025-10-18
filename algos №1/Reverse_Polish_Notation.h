#ifndef REVERSE_POLISH_NOTATION_H
#define REVERSE_POLISH_NOTATION_H

#include <string>
using namespace std;

class Reverse_Polish_Notation {
private:
    static int get_priority(const string& ch);
    static bool Degree(const string& op);
    static bool Function(const string& token);
    static bool Operator(const string& ch);
    static bool Number(const string& token);
public:
    static void convert(const string& input);
};

#endif //REVERSE_POLISH_NOTATION_H
