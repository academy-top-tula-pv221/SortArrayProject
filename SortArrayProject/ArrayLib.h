#pragma once
#include <iostream>
// ArrayLib.h

void ArrayInit(int* array, int size);
void ArrayPrint(int* array, int size);
int ArrayMinIndex(int* array, int size);
void Swap(int& a, int& b);

void ArraySortSelect(int* array, int size);
void ArraySortBubble(int* array, int size);
void ArraySortShacker(int* array, int size);
void ArraySortInsert(int* array, int size);

void ArraySortQuick(int* array, int size);

int SearchBin(int* array, int size, int key);