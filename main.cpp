#include <iostream>
#include <ctime>

#include "Sort.h"
#include "BubbleSort.h"
#include "OddEvenSort.h"
#include "QuickSort3Way.h"

void testSortAuto(int *n, int number);
void testSortBad(int number);
void testSortBest(int number);

int main()
{
	setlocale(0, "");
	srand(time(0));
	
	int n[16] = { 15, 1, 2, 3, 4, 5, 10, 15, 20, 25, 30, 50, 75, 100, 250, 500 };

	printf("Test BubbleSort\n");
	testSortAuto(n, 1);
	system("pause");

	system("cls");
	printf("Test 'OddEvenSort'\n");
	testSortAuto(n, 2);
	system("pause");

	system("cls");
	printf("Test 'QuickSort3Way'\n");
	testSortAuto(n, 3);
	system("pause");

	system("cls");
	printf("Test 'Худший BubbleSort'\n");
	testSortBad(1);
	system("pause");

	system("cls");
	printf("Test 'Худший OddEvenSort'\n");
	testSortBad(2);
	system("pause");

	system("cls");
	printf("Test 'Худший QuickSort3Way'\n");
	testSortBad(3);
	system("pause");

	system("cls");
	printf("Test 'Лучший BubbleSort'\n");
	testSortBest(1);
	system("pause");

	system("cls");
	printf("Test 'Лучший OddEvenSort'\n");
	testSortBest(2);
	system("pause");

	system("cls");
	printf("Test 'Лучший QuickSort3Way'\n");
	testSortBest(3);
	system("pause");


	return 0;
}

void testSortAuto(int *n, int number)
{
	for (int i = 1; i <= n[0]; i++)
	{
		float reshuffle = 0;
		float compare = 0;
		unsigned int primClock = clock();

		for (int j = 0; j < 100; j++)
		{
			int *mas = new int[n[i]];
			for (int j = 0; j < n[i]; j++)
			{
				mas[j] = rand() % 200 - rand() % 200;
			}

			if (number == 1)
			{
				Sort* testS = new BubbleSort(mas, n[i]);
				testS->sort();
				reshuffle += testS->GetReshuffle();
				delete testS;
			}
			else if (number == 2)
			{
				Sort* testS = new OddEvenSort(mas, n[i]);
				testS->sort();
				reshuffle += testS->GetReshuffle();
				delete testS;
			}
			else if (number == 3)
			{
				Sort* testS = new QuickSort3Way(mas, n[i]);
				testS->sort();
				reshuffle += testS->GetReshuffle();
				delete testS;
			}
		}

		printf("Размер массива: %i\nСр. кол-во: %.2f\n", n[i], reshuffle/100);
		std::cout << "Ср. время : " << (clock() - primClock) / 1000.0 << "\n" << std::endl;
	}
}

void testSortBad(int number)
{
	const int n = 30;
	int reshuffle = 0;

	unsigned int primClock = clock();

	if (number == 1)
	{
		int mas[n] = {30, 29, 28, 27, 26, 25, 24, 23, 22, 21, 20, 19, 18, 17, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};

		Sort* testS = new BubbleSort(mas, n);
		testS->sort();
		reshuffle += testS->GetReshuffle();
		delete testS;
	}
	else if (number == 2)
	{
		int mas[n] = {29, 30, 27, 28, 25, 26, 23, 24, 21, 22, 19, 20, 17, 18, 15, 16, 13, 14, 11, 12, 9, 10, 7, 8, 5, 6, 3, 4, 1, 2};
		Sort* testS = new OddEvenSort(mas, n);
		testS->sort();
		reshuffle += testS->GetReshuffle();
		delete testS;
	}
	else if (number == 3)
	{
		int mas[n] = { 29, 30, 1, 28, 2, 27, 3, 26, 4, 25, 5, 24, 6, 23, 7, 22, 8, 21, 9, 20, 10, 19, 11, 18, 12, 17, 13, 16, 14, 15 };

		Sort* testS = new QuickSort3Way(mas, n);
		testS->sort();
		reshuffle += testS->GetReshuffle();
		delete testS;
	}

	printf("Размер массива: %i\nСр. кол-во: %i\n", n, reshuffle);
	std::cout << "Ср. время : " << (clock() - primClock) / 1000.0 << "\n" << std::endl;
};

void testSortBest(int number)
{
	const int n = 30;
	int reshuffle = 0;

	unsigned int primClock = clock();

	if (number == 1)
	{
		int mas[n] = {2, 1, 4, 3, 6, 5, 8, 7, 10, 9, 12, 11, 14, 13, 16, 15, 18, 17, 20, 19, 22, 21, 24, 23, 26, 25, 28, 27, 30, 29};
		Sort* testS = new BubbleSort(mas, n);
		testS->sort();
		reshuffle += testS->GetReshuffle();
		delete testS;
	}
	else if (number == 2)
	{
		int mas[n] = {2, 1, 4, 3, 6, 5, 8, 7, 10, 9, 12, 11, 14, 13, 16, 15, 18, 17, 20, 19, 22, 21, 24, 23, 26, 25, 28, 27, 30, 29};

		Sort* testS = new OddEvenSort(mas, n);
		testS->sort();
		reshuffle += testS->GetReshuffle();
		delete testS;
	}
	else if (number == 3)
	{
		int mas[n] = {15, 23, 14, 27, 13, 22, 12, 29, 11, 21, 10, 26, 9, 20, 8, 30, 7, 19, 6, 25, 5, 18, 4, 28, 3, 17, 24, 2, 16, 1};
		Sort* testS = new QuickSort3Way(mas, n);
		testS->sort();
		reshuffle += testS->GetReshuffle();
		delete testS;
	}

	printf("Размер массива: %i\nСр. кол-во: %i\n", n, reshuffle);
	std::cout << "Ср. время : " << (clock() - primClock) / 1000.0 << "\n" << std::endl;
};