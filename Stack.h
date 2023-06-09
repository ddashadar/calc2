#ifndef CALC2_STACK_H
#define CALC2_STACK_H

#include "LinearList.h"

class Stack {
private:
    LinearList stack;
public:
    Stack() = default;
    ~Stack() = default;

    void push(int value) {
        stack.pushTop(value);
    }

    int pop() {
        int value = stack.searchOnPosition(0);
        stack.deleteOnPosition(0);
        return value;
    }

    int top() {
        return stack.searchOnPosition(0);
    }

    bool isEmpty() {
        return stack.isEmpty();
    }
};

#endif //CALC2_STACK_H
