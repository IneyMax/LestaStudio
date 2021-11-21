#pragma once
#include <list>

class SecondCircleBuffer
{
    std::list<int> stack_list_ {};
    int stack_size_;

public:
    SecondCircleBuffer(int stack_size)
        : stack_size_(stack_size)
    {
    }

    void push(int value);
    void pop();
    void print();
};
