#ifndef CALC2_QUEUE_H
#define CALC2_QUEUE_H

#include "LinearList.h"

class Queue {
private:
    LinearList queue;
public:
    Queue() = default;
    ~Queue() = default;

    void push(int value) {
        queue.pushBot(value);
    }

    int pop() {
        int value = queue.searchOnPosition(0);
        queue.deleteOnPosition(0);
        return value;
    }

    int top() {
        return queue.searchOnPosition(0);
    }

    bool isEmpty() {
        return queue.isEmpty();
    }
};

#endif //CALC2_QUEUE_H
