#ifndef CALC2_POSTFIX_H
#define CALC2_POSTFIX_H

#include <string>
#include "Stack.h"
#include "Queue.h"

class Postfix {
private:
    string expression;
    Stack prefix;

    bool doOperation(char operation) {
        if (this->prefix.isEmpty())
            return false;
        int second = this->prefix.pop();
        if (this->prefix.isEmpty())
            return false;
        int first = this->prefix.pop();
        if (operation == '+')
            first += second;
        else if (operation == '-')
            first -= second;
        else if (operation == '*')
            first *= second;
        else if (operation == '/' && second != 0)
            first /= second;
        else
            return false;
        this->prefix.push(first);
        return true;
    }

    int getNumber(size_t i, size_t probel) {
        int number = 0;
        for (; i < probel; ++i) {
            if ('0' <= this->expression[i] && this->expression[i] <= '9') {
                number *= 10;
                number += (int)(this->expression[i] - '0');
            } else {
                return -1;
            }
        }
        return number;
    }

public:
    Postfix() = default;
    Postfix(const string& expression) {
        this->expression = expression + ' ';
    }
    ~Postfix() = default;

    bool calculate() {
        for (size_t i = 0; i < this->expression.size(); ++i) {
            if (this->expression[i] != ' ') {
                size_t probel = this->expression.find(' ', i);
                if (probel != string::npos) {
                    if (probel - i == 1) {
                        if ('0' <= this->expression[i] && this->expression[i] <= '9') {
                            this->prefix.push((int)(this->expression[i] - '0'));
                        } else {
                            if (!doOperation(this->expression[i]))
                                return false;
                        }
                    } else {
                        int number = getNumber(i, probel);
                        if (number != -1) {
                            this->prefix.push(number);
                        } else {
                            return false;
                        }
                    }
                } else {
                    break;
                }
            }
        }
        if (this->prefix.isEmpty())
            return false;
        int result = this->prefix.pop();
        if (!this->prefix.isEmpty())
            return false;
        this->prefix.push(result);
        return true;
    }

    int getResult() {
        return this->prefix.top();
    }

    void setExpression(const string& new_expression) {
        this->expression = new_expression + ' ';
    }

    bool calculateByQueue(Queue& queue) {
        while (!queue.isEmpty()) {
            int value = queue.pop();
            if (value < 0) {
                if (!doOperation((char)(-value)))
                    return false;
            } else {
                this->prefix.push(value);
            }
        }
        if (this->prefix.isEmpty())
            return false;
        int result = this->prefix.pop();
        if (!this->prefix.isEmpty())
            return false;
        this->prefix.push(result);
        return true;
    }
};

#endif //CALC2_POSTFIX_H
