#include <iostream>
#include "FirstCircleBuffer.h"
#include "SecondCircleBuffer.h"
#include "LestaStudioMain.h"

int main()
{
    {
        /* Логика проверки числа на чётность: проверяем последний бит.
         * Этот способ быстрее, чем стандартная проверка на чётность, т.к. используется битовая операция
        */
        int x;
        std::cout << "Enter a number to check for parity:" << std::endl;
        std::cin >> x;
        if (is_even(x))
        {
            std::cout << "This number is not even \n";
        }
        else
        {
            std::cout << "This number is even \n";
        }
    }

    {
        int x;
        std::cin >> x;
        //SecondCircleBuffer main_stack (5); // Раскомментировать это, чтобы проверить реализацию через динамический массив и индексы
        FirstCircleBuffer main_stack (x); // Реализация через std::list
        main_stack.push(3);
        main_stack.push(7);
        main_stack.push(5);
        main_stack.push(8);
        main_stack.push(1);
        main_stack.print();
        main_stack.push(4);
        main_stack.print();
        main_stack.push(2);
        main_stack.print();
        main_stack.push(6);
        main_stack.print();
        main_stack.pop();
        main_stack.pop();
        main_stack.pop();
        main_stack.pop();
        main_stack.pop();
        main_stack.pop();
        main_stack.pop();
        main_stack.push(3);
        main_stack.print();
        main_stack.push(7);
        main_stack.print();
        main_stack.push(5);
        main_stack.print();
        main_stack.pop();
        main_stack.push(7);
        main_stack.print();
        main_stack.push(5);
        main_stack.print();
        main_stack.push(8);
        main_stack.print();
        main_stack.push(1);
        main_stack.print();
        main_stack.pop();
        main_stack.pop();
        main_stack.pop();
        main_stack.pop();
        main_stack.pop();
        main_stack.pop();
        main_stack.pop();
        /* Резюмируя:
         * 1) Реализация алгоритма, основанная на std::list проще. Т.к. циклический буфер - это по сути структура очередь (Last In Last Out),
         * а она основана на списке (list). В связи с этим мы получаем все преимущества списка как стандартного контейнера.
         * Кроме того это обеспечивает более высокую скорость работы, нежели реализация с помощью индексов/указателей
         * 2) Моя собственная реализация (основанная на индексах или указателях ) - имеет скорее больше недостатков.
         * Она имеет больше создаваемых переменных и будет достаточно сложна для дальнейших возможных расширений.
         */
    }

    { // task 3
        /* В данном задании мною был выбран алгоритм быстрой сортировки.
         * Данный алгоритм не является самым быстрым, однако это моя реализация
         * В целом, самого быстрого алгоритма сортировки нет - есть алгоритмы под определённые задачи.
         * Например, если мы знаем диапазон чисел в сортируемом массиве - я бы выбрал просто сортировку подсчётом.
         */
        
        std::array<int, ARRAY_SIZE> my_array;
        r_init_array(my_array);
        print_array(my_array);
        quick_sort_array(my_array, 0, ARRAY_SIZE);
        print_array(my_array);
    }
    return 0;
}
