#include "ArrayLib.h"

// ArrayLib.cpp

void ArrayInit(int* array, int size)
{
	srand(time(nullptr));
	for (int i = 0; i < size; i++)
		array[i] = rand() % 100;
}

void ArrayPrint(int* array, int size)
{
	for (int i = 0; i < size; i++)
		std::cout << array[i] << " ";
	std::cout << "\n";
}

int ArrayMinIndex(int* array, int size)
{
	int minIndex{};
	for (int i = 1; i < size; i++)
		if (array[i] < array[minIndex])
			minIndex = i;
	return minIndex;
}

void Swap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}

void ArraySortSelect(int* array, int size)
{
	for (int i = 0; i < size; i++)
	{
		int minIndex{ i };
		for (int j = i + 1; j < size; j++)
			if (array[j] < array[minIndex])
				minIndex = j;
		Swap(array[i], array[minIndex]);
	}
}

void ArraySortBubble(int* array, int size)
{
	for (int i = 0; i < size; i++)
	{
		bool isSort{ true };

		for (int j = size - 1; j > i; j--)
			if (array[j] < array[j - 1])
			{
				Swap(array[j], array[j - 1]);
				isSort = false;
			}
		if (isSort)
			break;
	}
}

void ArraySortShacker(int* array, int size)
{
	int levelTop{};
	int levelBottom{ size - 1 };
	bool isSort;
	while (levelTop <= levelBottom)
	{
		isSort = true;
		for(int i = levelBottom; i > levelTop; i--)
			if (array[i] < array[i - 1])
			{
				Swap(array[i], array[i - 1]);
				isSort = false;
			}
		if (isSort)
			break;
		levelTop--;

		isSort = true;
		for(int i = levelTop; i < levelBottom; i++)
			if (array[i] > array[i + 1])
			{
				Swap(array[i], array[i + 1]);
				isSort = false;
			}
		if (isSort)
			break;
		levelBottom++;
	}
}

void ArraySortInsert(int* array, int size)
{
	for (int i = 1; i < size; i++)
	{
		int pocket = array[i];
		int j;
		for (j = i - 1; j >= 0; j--)
		{
			if (array[j] > pocket)
				array[j + 1] = array[j];
			else
				break;
		}
		array[j + 1] = pocket;
	}
}

void QuickReq(int* array, int begin, int end)
{
	int pivot = array[(begin + end) / 2];
	int left = begin;
	int right = end;
	
	do
	{
		while (array[left] < pivot) left++;
		while (array[right] > pivot) right--;
		if (left <= right)
		{
			Swap(array[left], array[right]);
			left++;
			right--;
		}
	} while (left <= right);
	if (begin < right) QuickReq(array, begin, right);
	if (left < end) QuickReq(array, left, end);  
}

void ArraySortQuick(int* array, int size)
{
	QuickReq(array, 0, size - 1);
}

int SearchBin(int* array, int size, int key)
{
	int index{ -1 };
	int left{};
	int right{ size - 1 };

	while (left <= right)
	{
		int middle{ (left + right) / 2 };
		if (key == array[middle])
		{
			index = middle;
			break;
		}
		if (key > array[middle])
			left = middle + 1;
		else
			right = middle - 1;
	}

	return index;
}
