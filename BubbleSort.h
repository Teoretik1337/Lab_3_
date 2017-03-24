#pragma once

#include "Sort.h"

class BubbleSort: public Sort
{
public:
	BubbleSort(int *m, int c)
	{
		mas = m;
		count = c;
		Reshuffle = 0;
	};

    void sort();
};

void BubbleSort:: sort()
{
	for (int i = 1; i < count; ++i)
	{
		for (int r = 0; r < count - i; r++)
		{
			if (mas[r] > mas[r + 1])
			{
				int temp = mas[r];
				mas[r] = mas[r + 1];
				mas[r + 1] = temp;
				Reshuffle++;
			}
		}
	}
}
