#pragma once
#include <array>
#define ARRAY_SIZE 10

bool is_even(int number);

void r_init_array(std::array<int, ARRAY_SIZE> &my_array);
void print_array(std::array<int, ARRAY_SIZE>& my_array);
void quick_sort_array (std::array<int, ARRAY_SIZE> &my_array, int start, int end);
