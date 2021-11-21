#pragma once

class FirstCircleBuffer
{
private:
    int stack_size_; // размер стека
    int last_out_; // счётчик индекса последнего элемента
    int last_in_; // счётчик индекса первого элемента
    int elements_in_stack_; // текущее количество элементов
    int *stack_array_;
    
public:
    FirstCircleBuffer(const int stack_lenght)
        : stack_size_(stack_lenght), last_out_(0), last_in_(0), elements_in_stack_(0)
    {
        stack_array_ = new int[stack_size_];
        int index{};
        while (index < stack_size_)
        {
            stack_array_[index] = 0;
            index++;
        }
    }

    ~FirstCircleBuffer()
    {
        delete[] stack_array_; // переделать
    }

public:
    
    void push(int value);
    void pop();
    void print();
};
