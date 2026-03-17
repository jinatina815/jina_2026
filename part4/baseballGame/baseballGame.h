#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#define SIZE 3

void generate_number(int* question);
void input_numbers(int* answer);
bool check_result(const int* question, const int* answer, int* strike, int* ball);