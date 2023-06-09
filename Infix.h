#ifndef CALC2_INFIX_H
#define CALC2_INFIX_H

#include <string>
#include "Stack.h"
#include "Queue.h"
#include "Postfix.h"

class Infix {
private:
    string expression;
    Stack operation;
    Queue values;
    Postfix postfix;

    bool isOperation(char op) {
        return (op == '+') || (op == '-') || (op == '*') || (op == '/');
    }

    int getPriority(int op) {
        if ((op == -(int)('+')) || (op == -(int)('-')))
            return 1;
        return 2;
    }

public:
    Infix() = default;
    Infix(const string& expression) {
        this->expression = expression + ' ';
    }
    ~Infix() = default;

    bool calculate() {
        for (size_t i = 0; i < this->expression.size(); ++i) {
            if (this->expression[i] != ' ') {
                if (this->expression[i] == '(') {
                    operation.push(-(int)(this->expression[i]));
                } else if (this->expression[i] == ')') {
                    while ((!operation.isEmpty()) && (operation.top() != -(int)('('))) {
                        values.push(operation.pop());
                    }
                    if (operation.isEmpty())
                        return false;
                    operation.pop();
                } else if (isOperation(this->expression[i])) {
                    while ((!operation.isEmpty()) && (operation.top() != -(int)('(')) && (getPriority(operation.top()) >= getPriority(this->expression[i]))) {
                        values.push(operation.pop());
                    }
                    operation.push(-(int)(this->expression[i]));
                } else {
                    int number = 0;
                    while ((!isOperation(this->expression[i])) && (this->expression[i] != ')') && (this->expression[i] != ' ')) {
                        if ('0' <= this->expression[i] && this->expression[i] <= '9') {
                            number *= 10;
                            number += (int)(this->expression[i] - '0');
                        } else {
                            number = -1;
                            break;
                        }
                        ++i;
                    }
                    if (number == -1)
                        return false;
                    values.push(number);
                    --i;
                }
            }
        }
        while (!operation.isEmpty()) {
            if (operation.top() == -(int)('('))
                return false;
            values.push(operation.pop());
        }
        if (!postfix.calculateByQueue(this->values))
            return false;
        return true;
    }

    int getResult() {
        return this->postfix.getResult();
    }

    void setExpression(const string& new_expression) {
        this->expression = new_expression + ' ';
    }
};

#endif //CALC2_INFIX_H
