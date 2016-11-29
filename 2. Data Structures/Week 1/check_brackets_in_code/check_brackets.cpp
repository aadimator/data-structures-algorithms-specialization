#include <iostream>
#include <stack>
#include <string>

struct Bracket {
    Bracket(char type, int position) :
            type(type),
            position(position) {}

    bool Matchc(char c) {
        if (type == '[' && c == ']')
            return true;
        if (type == '{' && c == '}')
            return true;
        if (type == '(' && c == ')')
            return true;
        return false;
    }

    char type;
    int position;
};

int main() {
    std::string text;
    getline(std::cin, text);

    bool success = true;
    int faulty_position = -1;

    std::stack<Bracket> opening_brackets_stack;
    for (int position = 0; position < text.length(); ++position) {
        char next = text[position];

        if (next == '(' || next == '[' || next == '{') {
            // Process opening bracket
            opening_brackets_stack.push(Bracket(next, position + 1));
        }

        if (next == ')' || next == ']' || next == '}') {
            // Process closing bracket
            if (opening_brackets_stack.empty()) {
                success = false;
                faulty_position = position + 1;
                break;
            }

            Bracket last = opening_brackets_stack.top();
            opening_brackets_stack.pop();
            if (!last.Matchc(next)) {
                success = false;
                faulty_position = position + 1;
                break;
            }
        }
    }

    // If no errors and still some opening brackets are left behind
    if (success && !opening_brackets_stack.empty()) {
        Bracket last = opening_brackets_stack.top();
        success = false;
        faulty_position = last.position;
    }

    // Printing answer
    if (success) {
        std::cout << "Success" << std::endl;
    } else {
        std::cout << faulty_position << std::endl;
    }

    return 0;
}
