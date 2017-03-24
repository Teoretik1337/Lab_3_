#pragma once

#include "Sort.h"

class QuickSort3Way: public Sort
{
public:
	QuickSort3Way(int *m, int c)
	{
		mas = m;
		count = c;
		Reshuffle = 0;
	};

	void sort();
	void quickSort(int *mas, int low, int count);

private:
	void swap(int* a, int i, int j);
	int min(int a, int b);
};

void QuickSort3Way::sort()
{
	quickSort(mas, 0, count);
}

void QuickSort3Way::quickSort(int *mas, int low, int count)
{
	int pivot = mas[count];

	int lt = low;
	int reader = low;
	int gt = count;

	while (reader < gt) {
		if (mas[reader] < pivot) {
			swap(mas, reader, lt);
			reader++;
			lt++;
			Reshuffle++;
		}
		else if (mas[reader] == pivot) {
			gt--;
			swap(mas, reader, gt);
			Reshuffle++;
		}
		else {
			reader++;
		}
	}

	int minimum = min(gt - lt, count - gt + 1);
	for (int i = 0; i<minimum; i++) {
		swap(mas, lt + i, count - minimum + 1 + i);
	}

	if (low < count)
	{
		quickSort(mas, low, lt - 1);
		quickSort(mas, count - gt + lt, count);
	}
}

void QuickSort3Way::swap(int* a, int i, int j)
{
	int temp = a[i];
	a[i] = a[j];
	a[j] = temp;
}

int QuickSort3Way::min(int a, int b)
{
	if (a > b)
		return b;
	return a;
}