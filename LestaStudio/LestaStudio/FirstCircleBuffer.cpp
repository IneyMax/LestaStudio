#include "FirstCircleBuffer.h"
#include <iostream>

// Добавляем элемент в стек
void FirstCircleBuffer::push(const int value)
{
    if (last_in_ == last_out_ && elements_in_stack_ > 0) // Если мы уже полностью заполнили список - сдвигаем счётчик последнего элемента
        {
        last_out_ = ++last_out_ % stack_size_;
        }
    if (elements_in_stack_ < stack_size_)
    {
        elements_in_stack_ ++;
    }
    stack_array_[last_in_] = value;
    last_in_ = ++ last_in_ % stack_size_;
    std::cout << "You add: " << value  << std::endl;
}

// берём самый старый элемент списка
void FirstCircleBuffer::pop()
{
    if (elements_in_stack_ > 0)
    {
        elements_in_stack_ --; // Уменьшаем значение счётчика количества элементов
        const int temple = last_out_; // переменнная temple нужна на случай, если мы захотим добавить возвратное значение у функции 
        last_out_ = ++last_out_ % stack_size_;
        std::cout << "You take: " << stack_array_[temple] << " Elements in stack: " << elements_in_stack_ << std::endl;
    }
}

// Вывод стека на экран
void FirstCircleBuffer::print()
{
    std::cout << "( ";
    int index {};
    while (index < stack_size_)
    {
        std::cout << stack_array_[index] << " ";
        index ++;
    }
    std::cout << ")" << " Elements in stack: " << elements_in_stack_ << std::endl;
}
    