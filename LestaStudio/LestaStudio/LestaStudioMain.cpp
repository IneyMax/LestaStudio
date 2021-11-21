#include "LestaStudioMain.h"
#include <iostream>
#include <random>

// Битовая проверка чётности чисел
bool is_even(int number)
{
    return number & 1;
}

// Выбор случайного числа. (Использую данный алгоритм, так как у него можно задать seed, есть ограничение диапозона и достаточно равномерное распределение чисел)
int get_random_number()
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(0,127);
    return dist(gen);
}

// Функция для заполнения массива случайными числами
void r_init_array(std::array<int, ARRAY_SIZE> &my_array)
{
    for (auto &element : my_array)
    {
        element = get_random_number();
    }
}

// Вывод массива
void print_array(std::array<int, ARRAY_SIZE>& my_array)
{
    for (const auto array : my_array)
    {
        std::cout << array << " ";
    }
    std::cout << "\n";
}

// Алгоритм быстрой сортировки
void quick_sort_array (std::array<int, ARRAY_SIZE> &my_array, int start, int end)
{
    int left_index {start};
    int right_index {end - 1};
    int pivot_value {my_array[((start + end)/2)]};
    
    /*
    std::cout <<"Start: " << left_index << " End: " << end << "\n";
    print_piace_array(my_array, left_index, right_index, pivot_value);
    */

    do
    {
        while (my_array[left_index] < pivot_value )
        {
            left_index ++;
        }

        while (my_array [right_index] > pivot_value)
        {
            right_index --;
        }
        
        if (left_index <= right_index) 
        {
            //std::cout <<"Left index value: " << my_array [left_index] << " Right index value: " << my_array [right_index] << "\n";
            std::swap (my_array[left_index++], my_array[right_index--]);
        }
    }
    while (left_index <= right_index);

    if (right_index > start)
    {
        // std::cout << "\n Left \n";
        quick_sort_array(my_array, (start), (right_index + 1));
    }
    
    if (left_index < end)
    {
        // std::cout << "\n Right \n";
        quick_sort_array(my_array, (left_index), (end));
    }
}


