#include "SecondCircleBuffer.h"
#include <iostream>

// Добавляем элемент в конец списка. Если в результате список больше положенного - убираем элемент с начала
void SecondCircleBuffer::push(int value)
{
    stack_list_.emplace_back(value);
    if (stack_list_.size() > stack_size_)
    {
        stack_list_.pop_front();
    }
    std::cout << "You add: " << value  << std::endl;
}

// Читаем, а затем удаляем элемент с начала списка, при условии, что список не пуст
void SecondCircleBuffer::pop()
{
    if (!stack_list_.empty())
    {
        int temple = stack_list_.front();
        stack_list_.pop_front();
        std::cout << "You take: " << temple << " Elements in stack: " << stack_list_.size() << std::endl;
    }
}

// Вывод стека на экран
void SecondCircleBuffer::print()
{
    std::cout << "( ";
    for (auto element : stack_list_)
    {
        std::cout << element << " ";
    }
    std::cout << ")" << " Elements in stack: " << stack_list_.size() << std::endl;
}
