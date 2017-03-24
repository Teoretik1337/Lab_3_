#pragma once

#include "Sort.h"

class OddEvenSort: public Sort
{
public:
	OddEvenSort(int *m, int c)
	{
		mas = m;
		count = c;
		Reshuffle = 0;
	};

	void sort();

};

void OddEvenSort::sort()
{
	int m = count / 2;
	int temp = 0;
	for (int k = 0; k < count; k++)
	{
		if (k % 2 == 0)
			for (int j = count - 1; j > 0; j -= 2)
			{
				if (mas[j] < mas[j - 1])
				{
					temp = mas[j];
					mas[j] = mas[j - 1];
					mas[j - 1] = temp;
					Reshuffle++;
				}
			}
		else
			for (int j = count - 2; j > 0; j -= 2)
			{
				if (mas[j] < mas[j - 1])
				{
					temp = mas[j];
					mas[j] = mas[j - 1];
					mas[j - 1] = temp;
					Reshuffle++;
				}
			}
	}
}